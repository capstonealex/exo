/*
 * CANopen main program file for Linux SocketCAN.
 *
 * @file        main
 * @author      Janez Paternoster
 * @copyright   2015 Janez Paternoster
 *
 * This file is part of CANopenSocket, a Linux implementation of CANopen
 * stack with master functionality. Project home page is
 * <https://github.com/CANopenNode/CANopenSocket>. CANopenSocket is based
 * on CANopenNode: <https://github.com/CANopenNode/CANopenNode>.
 *
 * CANopenSocket is free and open source software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CANopen.h"
#include "CO_OD_storage.h"
#include "CO_Linux_tasks.h"
#include "CO_time.h"
#include "application.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include <signal.h>
#include <errno.h>
#include <sys/epoll.h>
#include <net/if.h>
#include <linux/reboot.h>
#include <sys/reboot.h>
#include "CO_command.h"
#include <pthread.h>
/*Non canopenNode + Socket libraries*/
//#include "Robot.h"
#include "Joint.h"
#include "GPIOManager.h"
#include "GPIOConst.h"
#include "Toy.h"

/*For master-> code SDO direct messaging*/
// #define CO_COMMAND_SDO_BUFFER_SIZE 100000
// #define STRING_BUFFER_SIZE (CO_COMMAND_SDO_BUFFER_SIZE * 4 + 100)

#define NSEC_PER_SEC (1000000000)      /* The number of nanoseconds per second. */
#define NSEC_PER_MSEC (1000000)        /* The number of nanoseconds per millisecond. */
#define TMR_TASK_INTERVAL_NS (1000000) /* Interval of taskTmr in nanoseconds */
#define TMR_TASK_OVERFLOW_US (5000)    /* Overflow detect limit for taskTmr in microseconds */
#define INCREMENT_1MS(var) (var++)     /* Increment 1ms variable in taskTmr */
#define NODEID (100)
/* Global variable increments each millisecond. */
volatile uint16_t CO_timer1ms = 0U;

/* Mutex is locked, when CAN is not valid (configuration state). May be used
 *  from other threads. RT threads may use CO->CANmodule[0]->CANnormal instead. */
pthread_mutex_t CO_CAN_VALID_mtx = PTHREAD_MUTEX_INITIALIZER;

/* Other variables and objects */
static int rtPriority = -1;                          /* Real time priority, configurable by arguments. (-1=RT disabled) */
static int mainline_epoll_fd;                        /* epoll file descriptor for mainline */
static CO_OD_storage_t odStor;                       /* Object Dictionary storage object for CO_OD_ROM */
static CO_OD_storage_t odStorAuto;                   /* Object Dictionary storage object for CO_OD_EEPROM */
static char *odStorFile_rom = "od4_storage";         /* Name of the file */
static char *odStorFile_eeprom = "od4_storage_auto"; /* Name of the file */
static CO_time_t CO_time;                            /* Object for current time */
static char *BUTTON1 = "P9_23";
/*For master-> node SDO message sending*/
// char buf[STRING_BUFFER_SIZE];
// char ret[STRING_BUFFER_SIZE];
//char message[STRING_BUFFER_SIZE] = "[1] 2 read 0x6063 0 i32"; // Read J2 position
//char message[STRING_BUFFER_SIZE] = "[1] 100 read 0x1017  0 i32"; // Read bbb HB//

/* Realtime thread */
static void *rt_thread(void *arg);
static pthread_t rt_thread_id;
static int rt_thread_epoll_fd;

/* Signal handler */
volatile sig_atomic_t CO_endProgram = 0;
static void sigHandler(int sig)
{
    CO_endProgram = 1;
}

/* Helper functions ***********************************************************/
void CO_errExit(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* send CANopen generic emergency message */
void CO_error(const uint32_t info)
{
    CO_errorReport(CO->em, CO_EM_GENERIC_SOFTWARE_ERROR, CO_EMC_SOFTWARE_INTERNAL, info);
    fprintf(stderr, "canopend generic error: 0x%X\n", info);
}

/******************************************************************************/
/** Mainline and RT thread                                                   **/
/******************************************************************************/
int main(int argc, char *argv[])
{
    CO_NMT_reset_cmd_t reset = CO_RESET_NOT;
    CO_ReturnError_t odStorStatus_rom, odStorStatus_eeprom;
    int CANdevice0Index = 0;
    int opt;
    bool_t firstRun = true;
    bool_t nodeIdFromArgs = true; /* True, if program arguments are used for CANopen Node Id */
    int nodeId = -1;              /* Use value from Object Dictionary or set to 1..127 by arguments */
    bool_t rebootEnable = false;  /* Configurable by arguments */
    /*GPIO pin set up*/
    // GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
    // int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
    // gp->setDirection(pin, GPIO::INPUT);

    /*set up command line arguments as variables*/
    char CANdevice[10] = "can1"; /* change to can1 for bbb vcan0 for virtual can*/
    nodeId = NODEID;
    CANdevice0Index = if_nametoindex(CANdevice);
    bool_t commandEnable = false; /* Configurable by arguments */
    opt = 'c';
    /* Get program options */
    switch (opt)
    {

    case 'p':
        rtPriority = strtol(optarg, NULL, 0);
        break;

    case 'c':
        /* In case of empty string keep default name, just enable interface. */
        if (strlen(optarg) != 0)
        {
            // CO_command_socketPath = "/tmp/CO_command_socket";
        }
        commandEnable = true;
        break;
    }

    if (nodeId < 1 || nodeId > 127)
    {
        fprintf(stderr, "Wrong node ID (%d)\n", nodeId);
        exit(EXIT_FAILURE);
    }

    if (rtPriority != -1 && (rtPriority < sched_get_priority_min(SCHED_FIFO) || rtPriority > sched_get_priority_max(SCHED_FIFO)))
    {
        fprintf(stderr, "Wrong RT priority (%d)\n", rtPriority);
        exit(EXIT_FAILURE);
    }

    if (CANdevice0Index == 0)
    {
        char s[120];
        snprintf(s, 120, "Can't find CAN device \"%s\"", CANdevice);
        CO_errExit(s);
    }

    printf("starting CANopen device with Node ID %d(0x%02X)", nodeId, nodeId);

    /* Verify, if OD structures have proper alignment of initial values */
    if (CO_OD_RAM.FirstWord != CO_OD_RAM.LastWord)
    {
        fprintf(stderr, "Program init - Canopend- Error in CO_OD_RAM.\n");
        exit(EXIT_FAILURE);
    }
    if (CO_OD_EEPROM.FirstWord != CO_OD_EEPROM.LastWord)
    {
        fprintf(stderr, "Program init - Canopend - Error in CO_OD_EEPROM.\n");
        exit(EXIT_FAILURE);
    }
    if (CO_OD_ROM.FirstWord != CO_OD_ROM.LastWord)
    {
        fprintf(stderr, "Program init - Canopend - Error in CO_OD_ROM.\n");
        exit(EXIT_FAILURE);
    }

    /* initialize Object Dictionary storage */
    odStorStatus_rom = CO_OD_storage_init(&odStor, (uint8_t *)&CO_OD_ROM, sizeof(CO_OD_ROM), odStorFile_rom);
    odStorStatus_eeprom = CO_OD_storage_init(&odStorAuto, (uint8_t *)&CO_OD_EEPROM, sizeof(CO_OD_EEPROM), odStorFile_eeprom);

    /* Catch signals SIGINT and SIGTERM */
    if (signal(SIGINT, sigHandler) == SIG_ERR)
        CO_errExit("Program init - SIGINIT handler creation failed");
    if (signal(SIGTERM, sigHandler) == SIG_ERR)
        CO_errExit("Program init - SIGTERM handler creation failed");

    /* increase variable each startup. Variable is automatically stored in non-volatile memory. */
    printf(", count=%u ...\n", ++OD_powerOnCounter);

    while (reset != CO_RESET_APP && reset != CO_RESET_QUIT && CO_endProgram == 0)
    {
        /* CANopen communication reset - initialize CANopen objects *******************/
        CO_ReturnError_t err;

        printf("Canopend- communication reset ...\n");

        /* Wait other threads (command interface). */
        pthread_mutex_lock(&CO_CAN_VALID_mtx);

        /* Wait rt_thread. */
        if (!firstRun)
        {
            CO_LOCK_OD();
            CO->CANmodule[0]->CANnormal = false;
            CO_UNLOCK_OD();
        }

        /* Enter CAN configuration. */
        CO_CANsetConfigurationMode(CANdevice0Index);

        /* initialize CANopen */
        if (!nodeIdFromArgs)
        {
            /* use value from Object dictionary, if not set by program arguments */
            nodeId = OD_CANNodeID;
        }
        err = CO_init(CANdevice0Index, nodeId, 0);
        if (err != CO_ERROR_NO)
        {
            char s[120];
            snprintf(s, 120, "Communication reset - CANopen initialization failed, err=%d", err);
            CO_errExit(s);
        }

        /* initialize OD objects 1010 and 1011 and verify errors. */
        CO_OD_configure(CO->SDO[0], OD_H1010_STORE_PARAM_FUNC, CO_ODF_1010, (void *)&odStor, 0, 0U);
        CO_OD_configure(CO->SDO[0], OD_H1011_REST_PARAM_FUNC, CO_ODF_1011, (void *)&odStor, 0, 0U);
        if (odStorStatus_rom != CO_ERROR_NO)
        {
            CO_errorReport(CO->em, CO_EM_NON_VOLATILE_MEMORY, CO_EMC_HARDWARE, (uint32_t)odStorStatus_rom);
        }
        if (odStorStatus_eeprom != CO_ERROR_NO)
        {
            CO_errorReport(CO->em, CO_EM_NON_VOLATILE_MEMORY, CO_EMC_HARDWARE, (uint32_t)odStorStatus_eeprom + 1000);
        }

        /* Configure callback functions for task control */
        CO_EM_initCallback(CO->em, taskMain_cbSignal);
        CO_SDO_initCallback(CO->SDO[0], taskMain_cbSignal);
        CO_SDOclient_initCallback(CO->SDOclient, taskMain_cbSignal);

        /* Initialize time */
        CO_time_init(&CO_time, CO->SDO[0], &OD_time.epochTimeBaseMs, &OD_time.epochTimeOffsetMs, 0x2130);

        /* First time only initialization. */
        if (firstRun)
        {
            firstRun = false;

            /* Configure epoll for mainline */
            mainline_epoll_fd = epoll_create(4);
            if (mainline_epoll_fd == -1)
                CO_errExit("Program init - epoll_create mainline failed");

            /* Init mainline */
            taskMain_init(mainline_epoll_fd, &OD_performance[ODA_performance_mainCycleMaxTime]);
            /* Configure epoll for rt_thread */
            rt_thread_epoll_fd = epoll_create(2);
            if (rt_thread_epoll_fd == -1)
                CO_errExit("Program init - epoll_create rt_thread failed");

            /* Init taskRT */
            CANrx_taskTmr_init(rt_thread_epoll_fd, TMR_TASK_INTERVAL_NS, &OD_performance[ODA_performance_timerCycleMaxTime]);

            OD_performance[ODA_performance_timerCycleTime] = TMR_TASK_INTERVAL_NS / 1000; /* informative */

            /* Create rt_thread */
            if (pthread_create(&rt_thread_id, NULL, rt_thread, NULL) != 0)
                CO_errExit("Program init - rt_thread creation failed");

            /* Set priority for rt_thread */
            if (rtPriority > 0)
            {
                struct sched_param param;

                param.sched_priority = rtPriority;
                if (pthread_setschedparam(rt_thread_id, SCHED_FIFO, &param) != 0)
                    CO_errExit("Program init - rt_thread set scheduler failed");
            }

            /* Initialize socket command interface */
            if (commandEnable)
            {
                if (CO_command_init() != 0)
                {
                    CO_errExit("Socket command interface initialization failed");
                }
                printf("Canopend - Command interface on socket '%s' started ...\n", CO_command_socketPath);
            }

            /* Execute optional additional application code */
            app_programStart();
        }

        /* Execute optional additional application code */
        app_communicationReset();

        /* start CAN */
        CO_CANsetNormalMode(CO->CANmodule[0]);
        pthread_mutex_unlock(&CO_CAN_VALID_mtx);

        reset = CO_RESET_NOT;
        /*State machine testing 123*/
        // Create Statemachine Object -> will be loaded by taskmanager in end program.
        Toy bear;
        bear.init();
        bear.activate();
        printf("Canopend- running ...\n");
        while (reset == CO_RESET_NOT && CO_endProgram == 0)
        {
            /* loop for normal program execution ******************************************/
            int ready;
            int first = 0;
            struct epoll_event ev;

            ready = epoll_wait(mainline_epoll_fd, &ev, 1, -1);

            if (ready != 1)
            {
                if (errno != EINTR)
                {
                    CO_error(0x11100000L + errno);
                }
            }

            else if (taskMain_process(ev.data.fd, &reset, CO_timer1ms))
            {
                uint16_t timer1msDiff;
                static uint16_t tmr1msPrev = 0;

                /* Calculate time difference */
                timer1msDiff = CO_timer1ms - tmr1msPrev;
                tmr1msPrev = CO_timer1ms;

                /* code was processed in the above function. Additional code process below */

                /* Execute optional additional application code */
                // Update loop counter -> Can run in Async or RT thread for faster execution.
                bear.toyUpdate();
                bear.update();
                app_programAsync(timer1msDiff);
                /*GPIO FUNCTIONALITY*/
                //                GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
                //                int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
                //                gp->setDirection(pin, GPIO::INPUT);
                //                printf("Pin 9.23 value: %d\n", gp->getValue(pin));
                //                gp->~GPIOManager();

                CO_OD_storage_autoSave(&odStorAuto, CO_timer1ms, 60000);
            }

            else
            {
                /* No file descriptor was processed. */
                CO_error(0x11200000L);
                /* CHANGE TO FILE!*/
            }
        }
    }

    /* program exit ***************************************************************/
    /* join threads */
    if (commandEnable)
    {
        if (CO_command_clear() != 0)
        {
            CO_errExit("Socket command interface removal failed");
        }
    }

    CO_endProgram = 1;
    if (pthread_join(rt_thread_id, NULL) != 0)
    {
        CO_errExit("Program end - pthread_join failed");
    }

    /* Execute optional additional application code */
    app_programEnd();

    /* Store CO_OD_EEPROM */
    CO_OD_storage_autoSave(&odStorAuto, 0, 0);
    CO_OD_storage_autoSaveClose(&odStorAuto);

    /* delete objects from memory */
    CANrx_taskTmr_close();
    taskMain_close();
    CO_delete(CANdevice0Index);

    printf("Canopend on %s (nodeId=0x%02X) - finished.\n\n", CANdevice, nodeId);
    /* Flush all buffers (and reboot) */
    if (rebootEnable && reset == CO_RESET_APP)
    {
        sync();
        if (reboot(LINUX_REBOOT_CMD_RESTART) != 0)
        {
            CO_errExit("Program end - reboot failed");
        }
    }

    exit(EXIT_SUCCESS);
}

/* Realtime thread for CAN receive and taskTmr ********************************/
static void *rt_thread(void *arg)
{
    /* Endless loop */
    while (CO_endProgram == 0)
    {
        int ready;
        struct epoll_event ev;

        ready = epoll_wait(rt_thread_epoll_fd, &ev, 1, -1);

        if (ready != 1)
        {
            if (errno != EINTR)
            {
                CO_error(0x12100000L + errno);
            }
        }

        else if (CANrx_taskTmr_process(ev.data.fd))
        {

            /* code was processed in the above function. Additional code process below */
            INCREMENT_1MS(CO_timer1ms);

            /* Monitor variables with trace objects */
            CO_time_process(&CO_time);
#if CO_NO_TRACE > 0
            for (i = 0; i < OD_traceEnable && i < CO_NO_TRACE; i++)
            {
                CO_trace_process(CO->trace[i], *CO_time.epochTimeOffsetMs);
            }
#endif

            /* Execute optional additional application code */
            /*create OBJECT DICTIONARY ADRESS INDEX FOR A JOINT -> generic function after teat 1*/
            app_program1ms();
            /*Get the current LKnee position*/
            // Mirror Joint
            // mirrorJoint(lKnee);
            if (CO_timer1ms % 1000 == 0)
            {
            }

            /* Detect timer large overflow */
            if (OD_performance[ODA_performance_timerCycleMaxTime] > TMR_TASK_OVERFLOW_US && rtPriority > 0 && CO->CANmodule[0]->CANnormal)
            {
                CO_errorReport(CO->em, CO_EM_ISR_TIMER_OVERFLOW, CO_EMC_SOFTWARE_INTERNAL, 0x22400000L | OD_performance[ODA_performance_timerCycleMaxTime]);
            }
        }

        else
        {
            /* No file descriptor was processed. */
            CO_error(0x12200000L);
        }
    }

    return NULL;
}

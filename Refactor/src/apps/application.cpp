/*
 * Application interface for Alex Exoskeleton Software
 *
 * @file        application.c
 * @author      William Campbell
 *

 */
#include "application.h"

/*For master-> node SDO message sending*/
#define CO_COMMAND_SDO_BUFFER_SIZE 100000
#define STRING_BUFFER_SIZE (CO_COMMAND_SDO_BUFFER_SIZE * 4 + 100)
char buf[STRING_BUFFER_SIZE];
char ret[STRING_BUFFER_SIZE];
ExoTestMachine testMachine;

/******************************************************************************/
void app_programStart(void) {
    printf("app_Program Start \n");
    testMachine.init();
    ((StateMachine)testMachine).activate();
}
/******************************************************************************/
void app_communicationReset(void) {
}
/******************************************************************************/
void app_programEnd(void) {
    printf("app_programEnd \n");
}
/******************************************************************************/
void app_programAsync(uint16_t timer1msDiffy) {
}

void app_program1ms(void) {
    if (testMachine.running) {
        testMachine.hwStateUpdate();
        testMachine.update();
    }
}

void configureCANopen(int nodeId, int rtPriority, int CANdevice0Index, char* CANdevice) {
    if (nodeId < 1 || nodeId > 127) {
        fprintf(stderr, "NODE ID outside range (%d)\n", nodeId);
        exit(EXIT_FAILURE);
    }
    // rt Thread priority sanity check
    if (rtPriority != -1 && (rtPriority < sched_get_priority_min(SCHED_FIFO) || rtPriority > sched_get_priority_max(SCHED_FIFO))) {
        fprintf(stderr, "Wrong RT priority (%d)\n", rtPriority);
        exit(EXIT_FAILURE);
    }

    if (CANdevice0Index == 0) {
        char s[120];
        snprintf(s, 120, "Can't find CAN device \"%s\"", CANdevice);
        CO_errExit(s);
    }

    /* Verify, if OD structures have proper alignment of initial values */
    if (CO_OD_RAM.FirstWord != CO_OD_RAM.LastWord) {
        fprintf(stderr, "Program init - Canopend- Error in CO_OD_RAM.\n");
        exit(EXIT_FAILURE);
    }
};

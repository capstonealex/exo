/**
 * Application interface for RobotCANControl main.
 *
 * /file        application.h
 * /author      William Campbell
 *
 * This file is an adaptation of CANopenSocket, a Linux implementation of CANopen
 * stack with master functionality. Project home page is
 * <https://github.com/CANopenNode/CANopenSocket>. CANopenSocket is based
 * on CANopenNode: <https://github.com/CANopenNode/CANopenNode>.
 *
 * The adaptation is specifically designed for use with the RobotCANControl design stack and
 * a multi limbed robot. It has been tested using a Beagle Bone black and the Fourier Intelligence X2 
 * exoskelton in a lab testing setting.It can be addapted for use with other CANopen enabled linux based robotic projects.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <errno.h>
#include <fcntl.h>
#include <linux/reboot.h>
#include <net/if.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/reboot.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>

#include "CANopen.h"
#include "CO_Linux_tasks.h"
#include "CO_OD_storage.h"
#include "CO_command.h"
#include "CO_time.h"
#include "stdio.h"

/*Non canopenNode + Socket libraries*/
#include "ExoRobot.h"
#include "ExoTestMachine.h"

#ifndef CO_APPLICATION_H
#define CO_APPLICATION_H

#define NSEC_PER_SEC (1000000000)      /* The number of nanoseconds per second. */
#define NSEC_PER_MSEC (1000000)        /* The number of nanoseconds per millisecond. */
#define TMR_TASK_INTERVAL_NS (1000000) /* Interval of taskTmr in nanoseconds */
#define TMR_TASK_OVERFLOW_US (5000)    /* Overflow detect limit for taskTmr in microseconds */
#define INCREMENT_1MS(var) (var++)     /* Increment 1ms variable in taskTmr */
#define NODEID (100)
#define CANMESSAGELENGTH (100)
/**
 * Function is called on program startup.
 */
void app_programStart(void);

/**
 * Function is called after CANopen communication reset.
 */
void app_communicationReset(void);

/**
 * Function is called just before program ends.
 */
void app_programEnd(void);

/**
 * Function is called cyclically from main.
 *
 * @param timer1msDiff Time difference since last call
 */
void app_programAsync(uint16_t timer1msDiff);

/**
 * Function is called cyclically from realtime thread at constant intervals.
 *
 * Code inside this function must be executed fast. Take care on race conditions.
 */
void app_programControlLoop(void);

#endif /*APP_H*/

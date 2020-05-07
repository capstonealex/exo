/**
 * Application interface for ALEX exoskeleton main.
 *
 * @file        application.h
 * @author      William Campbell
 *
 * This file is part of AlexOpen, a Linux implementation of CANopen
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
#include "TestMachine.h"
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
void app_program1ms(void);

void configureCANopen(int nodeId, int rtPriority, int CANdevice0Index, char* CANdevice);

#endif /*APP_H*/

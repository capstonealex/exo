/*
 * Application interface for CANopenSocket.
 *
 * @file        application.c
 * @author      Janez Paternoster
 * @copyright   2016 Janez Paternoster
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
#include "CO_command.h"
#include "stdio.h"
#include <stdint.h>
#include <sys/time.h>

/*Non canopenNode + Socket libraries*/
#include "Robot.h"
#include "sitStand.h"


/*For master-> node SDO message sending*/
#define CO_COMMAND_SDO_BUFFER_SIZE 100000
#define STRING_BUFFER_SIZE (CO_COMMAND_SDO_BUFFER_SIZE * 4 + 100)
#include <string.h>
char buf[STRING_BUFFER_SIZE];
char ret[STRING_BUFFER_SIZE];


Robot exo;
sitStand sitStandMachine;

/******************************************************************************/
void app_programStart(void)
{
    printf("app_Program Start \n");
    sitStandMachine.initRobot(&exo);
    sitStandMachine.init();
    sitStandMachine.activate();
}
/******************************************************************************/
void app_communicationReset(void)
{
}
/******************************************************************************/
void app_programEnd(void)
{
    printf("app_programEnd \n");
}
/******************************************************************************/
void app_programAsync(uint16_t timer1msDiffy)
{
    //printf("App_programAsync \n");
}

/******************************************************************************/
void app_program1ms(void)
{
    sitStandMachine.hwStateUpdate();
    sitStandMachine.update();
}
/******************************************************************************/
void fileLogger()
{

}
void fileLogHeader()
{

}
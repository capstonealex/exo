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
#include "stdio.h"
#include <stdint.h>
#include <sys/time.h>
#include "GPIOManager.h"
#include "GPIOConst.h"

static char *BUTTON1 = "P9_23";

void strreverse(char *begin, char *end);
void itoa(int value, char *str, int base);
/******************************************************************************/
void app_programStart(void){
}
/******************************************************************************/
void app_communicationReset(void){
}
/******************************************************************************/
void app_programEnd(void){
}
/******************************************************************************/
void app_programAsync(uint16_t timer1msDiff){

GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
gp->setDirection(pin, GPIO::INPUT);
printf("Pin 9.23 value: %d\n", gp->getValue(pin));
gp->~GPIOManager();

}

/******************************************************************************/
void app_program1ms(void){
}
/******************************************************************************/
void itoa(int value, char *str, int base)
{
    static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *wstr = str;
    int sign;
    // Validate base
    if (base < 2 || base > 35)
    {
        *wstr = '\0';
        return;
    }
    // Take care of sign
    if ((sign = value) < 0)
        value = -value;
    // Conversion. Number is reversed.
    do
        *wstr++ = num[value % base];
    while (value /= base);
    if (sign < 0)
        *wstr++ = '-';
    *wstr = '\0';
    // Reverse string
    strreverse(str, wstr - 1);
}
/******************************************************************************/
void strreverse(char *begin, char *end)
{
    char aux;
    while (end > begin)
        aux = *end, *end-- = *begin, *begin++ = aux;
}
/******************************************************************************/
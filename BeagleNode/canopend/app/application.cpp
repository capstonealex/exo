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
static char *BUTTON1 = "P9_25";
static int button1_add=1;//add 1 for button 1, 2 for 2, 4 for 3, 8 for 4 etc.
static int button2_add=2;


int buttonRead();
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
    printf("\n Button state: %d \n", buttonRead());
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

int buttonRead(){
    int buttonState =0;
    GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
    int pin1 = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
    int pin2 = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON2);
    gp->setDirection(pin1, GPIO::INPUT);
    gp->setDirection(pin2, GPIO::INPUT);
    printf("Pin 9.23 value: %d\n", gp->getValue(pin1));
    printf("Pin 9.25 value: %d\n", gp->getValue(pin2));
    if(gp->getValue(pin1)==1)
        buttonState+=button1_add;
    if(gp->getValue(pin2)==1)
        buttonState+=button2_add;
    gp->~GPIOManager();
    return buttonState;
}
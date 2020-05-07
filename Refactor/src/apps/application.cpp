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
TestMachine testMachine;
ExoRobot exo;
/******************************************************************************/
void app_programStart(void) {
    printf("app_Program Start \n");
    testMachine.initRobot(&exo);
    testMachine.init();
    testMachine.activate();
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
    if (testMachine.running != 0) {
        testMachine.hwStateUpdate();
        testMachine.update();
    }
}

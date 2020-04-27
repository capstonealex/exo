/**
 * @file testSM.cpp
 * @author William Campbell
 * @brief Test for the statemachine class and associated classes: state, event and transition
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "ExoRobot.h"
#include "TestMachine.h"
using namespace std;

int main(void) {
    // Create Exo object + initialise derived Joints + trajectory Generator
    bool exit = false;
    cout << ">>> Creating Test state machine" << endl;
    ExoRobot exo;
    TestMachine testMachine;
    printf("app_Program Start \n");
    testMachine.initRobot(&exo);
    testMachine.init();
    testMachine.activate();
    while (!exo.keyboard.getQ()) {
        usleep(500000);
        testMachine.hwStateUpdate();
        testMachine.update();
    }

    // exit(0);
}
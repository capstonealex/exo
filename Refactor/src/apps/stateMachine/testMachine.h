//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_SM_H
#define EXO_SM_H

#include <sys/time.h>

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

#include "ExoRobot.h"
#include "StateMachine.h"
#define OWNER ((TestMachine *)owner)
// Designed State and event classes
#include "InitState.h"
#include "Sitting.h"
#include "SittingDwn.h"
#include "Standing.h"
#include "StandingUp.h"

class TestMachine : public StateMachine {
   public:
    int running = 0;
    TestMachine(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void update(void);
    State *gettCurState(void);
    void initRobot(ExoRobot *rb);
    ExoRobot *robot;
    bool trajComplete;

    // State Object pointers
    InitState *initState;
    SittingDwn *sittingDwn;
    StandingUp *standingUp;
    Sitting *sitting;
    Standing *standing;

   private:
    // events
    EventObject(EndTraj) * endTraj;
    EventObject(IsAPressed) * isAPressed;
    EventObject(StartButtonsPressed) * startButtonsPressed;
    EventObject(StartExo) * startExo;
    EventObject(StartSit) * startSit;
    EventObject(StartStand) * startStand;
};

#endif /*EXO_SM_H*/

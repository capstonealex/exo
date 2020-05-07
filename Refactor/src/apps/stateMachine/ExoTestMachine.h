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
#include "ExoTestState.h"
#include "StateMachine.h"

//#define OWNER ((ExoTestMachine *)owner)

// Designed State and event classes
#include "InitState.h"
#include "Sitting.h"
#include "SittingDwn.h"
#include "Standing.h"
#include "StandingUp.h"

class ExoTestMachine : public StateMachine {
   public:
    int running = 0;
    ExoTestMachine();
    void init();
    void activate();
    void deactivate();

    void hwStateUpdate();
    void update();
    State *gettCurState();
    void initRobot(ExoRobot *rb);
    bool trajComplete;
    DummyTrajectoryGenerator *trajectoryGenerator;

    // State Object pointers
    InitState *initState;
    SittingDwn *sittingDwn;
    StandingUp *standingUp;
    Sitting *sitting;
    Standing *standing;

   protected:
    ExoRobot *robot;

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

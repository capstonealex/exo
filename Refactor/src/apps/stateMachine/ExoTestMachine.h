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

// State Classes
#include "InitState.h"
#include "Sitting.h"
#include "SittingDwn.h"
#include "Standing.h"
#include "StandingUp.h"

/**
 * @brief Example implementation of a StateMachine for the ExoRobot class. States should implemented ExoTestState
 * 
 */
class ExoTestMachine : public StateMachine {
   public:
    bool running = false;
    ExoTestMachine();
    void init();
    void activate();
    void deactivate();

    void hwStateUpdate();
    State *gettCurState();
    void initRobot(ExoRobot *rb);
    bool trajComplete;
    DummyTrajectoryGenerator *trajectoryGenerator;

    // Pointers to the relevant states - initialised in init
    InitState *initState;
    SittingDwn *sittingDwn;
    StandingUp *standingUp;
    Sitting *sitting;
    Standing *standing;

   protected:
    // Pointer to the Robot
    ExoRobot *robot;

   private:
    // Event Objects defined using Macro defined in StateMachine.h
    // Defines the Class itself, as well as initialises an object of that class
    // Checks are defined in the .cpp file
    EventObject(EndTraj) * endTraj;
    EventObject(IsAPressed) * isAPressed;
    EventObject(StartButtonsPressed) * startButtonsPressed;
    EventObject(StartExo) * startExo;
    EventObject(StartSit) * startSit;
    EventObject(StartStand) * startStand;
};

#endif /*EXO_SM_H*/

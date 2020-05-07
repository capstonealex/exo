/**
 * @file ExoTestState.h
 * @author Justin Fong
 * @brief Virtual Class to include all required classes for ExoTestStates
 * @version 0.1
 * @date 2020-05-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EXOTESTSTATE_H_DEF
#define EXOTESTSTATE_H_DEF

#include <time.h>

#include <iostream>

#include "DebugMacro.h"
#include "DummyTrajectoryGenerator.h"
#include "ExoRobot.h"
#include "State.h"

class ExoTestState : public State {
   protected:
    ExoRobot *robot;
    DummyTrajectoryGenerator *trajectoryGenerator;

   public:
    virtual void entry() = 0;
    virtual void during() = 0;
    virtual void exit() = 0;
    ExoTestState(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL);
};

#endif
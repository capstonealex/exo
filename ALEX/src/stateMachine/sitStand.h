//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_SITSTAND_H
#define EXO_SITSTAND_H

#include "StateMachine.h"
#include "Robot.h"
#include "GPIOManager.h"
#include "GPIOConst.h"

#define OWNER ((sitStand *)owner)
// Designed State and event classes
#include "InitState.h"
#include "SittingDwn.h"
#include "StandingUp.h"
#include "Sitting.h"
#include "Standing.h"
#include "SteppingFirstLeft.h"
#include "SteppingLastLeft.h"
#include "SteppingLastRight.h"
#include "SteppingLeft.h"
#include "SteppingRight.h"
#include "LeftForward.h"
#include "RightForward.h"
#include "ErrorState.h"

double getDegPos(int jointInd, int desiredIndex, Robot *rob);

class sitStand : public StateMachine
{
public:
    int running = 0;
    sitStand(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void update(void);
    void initRobot(Robot *rb);
    //bool bitFlip(int i);
    bool initPositionControl();
    void startNewTraj();
    void moveThroughTraj(double (*trajFunction)(int, double, Robot *), double trajTime);
    // Robot interface to be used by states to interact with hardware
    Robot *robot;
    int mark;

    // State Object pointers
    //  Used by transition objects for transition direction + safety
    InitState *initState;
    SittingDwn *sittingDwn;
    StandingUp *standingUp;
    Sitting *sitting;
    Standing *standing;
    SteppingFirstLeft *steppingFirstLeft;
    LeftForward *leftForward;
    SteppingRight *steppingRight;
    RightForward *rightForward;
    SteppingLeft *steppingLeft;
    SteppingLastRight *steppingLastRight;
    SteppingLastLeft *steppingLastLeft;
    ErrorState *errorState;

private:
    // events
    EventObject(EndTraj) * endTraj;
    EventObject(IsYPressed) * isYPressed;
    EventObject(IsBPressed) * isBPressed;
    EventObject(IsRPressed) * isRPressed;
    EventObject(StartButtonsPressed) * startButtonsPressed;
    EventObject(ResetButtonsPressed) * resetButtonsPressed;
    EventObject(DummyTrue) * dummyTrue;

    // data;
    int calibrated;
    int gButton;
    int yButton;
    int bButton;
    int rButton;
    int arrayIndex;
    int bitFlipState;
    GPIO::GPIOManager *gp;
};

#endif //EXO_SITSTAND_H

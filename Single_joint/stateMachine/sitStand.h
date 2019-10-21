//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_SITSTAND_H
#define EXO_SITSTAND_H

#include "StateMachine.h"
#include "Robot.h"
#include "GPIOManager.h"
#include "GPIOConst.h"

class sitStand : public StateMachine
{
public:
    sitStand(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void initRobot(Robot *rb);
    bool bitFlip(int i);
    bool initPositionControl();

private:
    // events
    EventObject(IsSitting) * isSitting;
    EventObject(IsStanding) * isStanding;
    EventObject(IsYPressed) * isYPressed;

    //
    //    // states
    StateObject(SittingDwn) * sittingDwn;
    StateObject(StandingUp) * standingUp;
    StateObject(Sitting) * sitting;
    StateObject(Standing) * standing;

    // data
    double mark;
    int calibrated;
    int gButton;
    int yButton;
    int bButton;
    int rButton;
    int arrayIndex;
    int bitFlipState;
    // Robot interface to be used by states to interact with hardware
    Robot *robot;
};

#endif //EXO_SITSTAND_H

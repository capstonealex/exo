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
    //bool bitFlip(int i);
    bool initPositionControl();
    void moveThroughTraj();

private:
    // events
  //  EventObject(IsSitting) * isSitting;
    EventObject(EndTraj) * endTraj;
    EventObject(IsYPressed) * isYPressed;
    EventObject(IsBPressed) * isBPressed;
    EventObject(IsRPressed) * isRPressed;

    //
    //    // states
    StateObject(SittingDwn) * sittingDwn;
    StateObject(StandingUp) * standingUp;
    StateObject(Sitting) * sitting;
    StateObject(Standing) * standing;
    StateObject(SteppingFirstLeft) * steppingFirstLeft;
    StateObject(LeftForward) * leftForward;
    StateObject(SteppingRight) * steppingRight;
    StateObject(RightForward) * rightForward;
    StateObject(SteppingLeft) * steppingLeft;
    StateObject(SteppingLastRight) * steppingLastRight;
    
    StateObject(ErrorState) * errorState;

    // data
    double mark;
    int calibrated;
    int gButton;
    int yButton;
    int bButton;
    int rButton;
    int arrayIndex;
    int bitFlipState;
    GPIO::GPIOManager *gp;
    // Robot interface to be used by states to interact with hardware
    Robot *robot;
};

#endif //EXO_SITSTAND_H

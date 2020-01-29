//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_SITSTAND_H
#define EXO_SITSTAND_H

#include "StateMachine.h"
#include "Robot.h"
#include "GPIOManager.h"
#include "GPIOConst.h"

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
    void initRobot(Robot *rb);
    //bool bitFlip(int i);
    bool initPositionControl();
    void startNewTraj();
    void moveThroughTraj(double (*trajFunction)(int, double, Robot*), double trajTime);
    bool waitForInput();

private:
    // events
    EventObject(EndTraj) * endTraj;
    EventObject(IsYPressed) * isYPressed;
    EventObject(IsBPressed) * isBPressed;
    EventObject(IsRPressed) * isRPressed;
    EventObject(StartButtonsPressed) * startButtonsPressed;
    EventObject(ResetButtonsPressed) * resetButtonsPressed;
    EventObject(DummyTrue) * dummyTrue;
    EventObject(Backstep) * backStep;
    
    // states
    StateObject(InitState) * initState;
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
    StateObject(SteppingLastLeft) * steppingLastLeft;
    
    StateObject(ErrorState) * errorState;

    // data
    int mark;
    int calibrated;
    int gButton;
    int yButton;
    int bButton;
    int rButton;
    bool backstep;
    int arrayIndex;
    int bitFlipState;
    GPIO::GPIOManager *gp;
    // Robot interface to be used by states to interact with hardware
    Robot *robot;
};

#endif //EXO_SITSTAND_H

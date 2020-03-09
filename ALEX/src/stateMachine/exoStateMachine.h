//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_SITSTAND_H
#define EXO_SITSTAND_H

#include "StateMachine.h"
#include "Robot.h"
#define OWNER ((exoStateMachine *)owner)
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
#include "StairStanding.h"
#include "StairStandingTop.h"
#include "StairLeftLegUp.h"
#include "StairLeftLegUp2.h"
#include "WalkSelect.h"
#include "SteppingLeftStair.h"
#include "SteppingRightStair.h"
#include "SteppingLeftStairDown.h"
#include "SteppingRightStairDown.h"

double getDegPos(int jointInd, int desiredIndex, Robot *rob);

class exoStateMachine : public StateMachine
{
public:
    int running = 0;
    exoStateMachine(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void update(void);
    State *gettCurState(void);
    void initRobot(Robot *rb);
    bool initPositionControl();
    void startNewTraj();
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
	SteppingLeftStair *steppingLeftStair;
	SteppingLeftStairDown *steppingLeftStairDown;
	SteppingRightStair *steppingRightStair;
	SteppingRightStairDown *steppingRightStairDown;
	StairStanding *stairStanding;
	StairLeftLegUp *stairLeftLegUp;
	StairLeftLegUp2 *stairLeftLegUp2;
	StairStandingTop *stairStandingTop;
	WalkSelect *walkSelect;
private:
    // events
    EventObject(EndTraj) * endTraj;
    EventObject(IsYPressed) * isYPressed;
    EventObject(IsBPressed) * isBPressed;
    EventObject(IsRPressed) * isRPressed;
    EventObject(IsGPressed) * isGPressed;
    EventObject(StartButtonsPressed) * startButtonsPressed;
    EventObject(ResetButtonsPressed) * resetButtonsPressed;

    // data;
    int calibrated;
    int arrayIndex;
    int bitFlipState;
};

#endif //EXO_SITSTAND_H

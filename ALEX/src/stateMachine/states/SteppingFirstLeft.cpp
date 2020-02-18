#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping First Left
////////////////////////////////////
void SteppingFirstLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingFirstLeft State Entered at Time %d\n", OWNER->mark);
    // OWNER->startNewTraj();
    OWNER->robot->startNewTraj();
}

void SteppingFirstLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->trajTime = STEPTIME;
    OWNER->robot->moveThroughTraj(OWNER->robot->steppingFirstLeftTrajFunc, OWNER->robot->trajTime);
}

void SteppingFirstLeft::exit(void)
{
    printf("SteppingFirstLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

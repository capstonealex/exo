#include "SteppingRight.h"
////////// STATE ////////////////////
// Stepping Right
///////////////////////////////////////////////
void SteppingRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingRight State Entered at Time %d\n", owner->mark);
    // owner->startNewTraj();
    owner->robot->startNewTraj();
}

void SteppingRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->moveThroughTraj(owner->robot->steppingRightTrajFunc, STEPTIME);
}

void SteppingRight::exit(void)
{
    printf("SteppingRight State Exited at Time %d\n", owner->mark);
    // do nothing
}
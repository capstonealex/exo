#include "SteppingLastRight.h"
///////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastRight State Entered at Time %d\n", owner->mark);

    owner->robot->startNewTraj();
}

void SteppingLastRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->moveThroughTraj(owner->robot->steppingLastRightTrajFunc, STEPTIME);
}

void SteppingLastRight::exit(void)
{
    printf("SteppingLastRight State Exited at Time %d\n", owner->mark);
    // do nothing
}

#include "SteppingLastLeft.h"
/////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void SteppingLastLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastLeft State Entered at Time %d\n", owner->mark);

    owner->robot->startNewTraj();
}

void SteppingLastLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->moveThroughTraj(owner->robot->steppingLastLeftTrajFunc, STEPTIME);
}

void SteppingLastLeft::exit(void)
{
    printf("SteppingLastLeft State Exited at Time %d\n", owner->mark);
    // do nothing
}
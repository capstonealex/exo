#include "SteppingLeft.h"
////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLeft State Entered at Time %d\n", owner->mark);
    owner->robot->startNewTraj();
}

void SteppingLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->moveThroughTraj(&owner->robot->steppingLeftTrajFunc, STEPTIME);
}

void SteppingLeft::exit(void)
{
    printf("SteppingLeft State Exited at Time %d\n", owner->mark);
    // do nothing
}
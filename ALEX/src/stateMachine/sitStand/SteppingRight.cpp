#include "sitStand.h"
////////// STATE ////////////////////
// Stepping Right
///////////////////////////////////////////////
void SteppingRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingRight State Entered at Time %d\n", OWNER->mark);
    OWNER->robot->startNewTraj();
}

void SteppingRight::during(void)
{
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj(OWNER->robot->steppingRightTrajFunc, STEPTIME);
}

void SteppingRight::exit(void)
{
    printf("SteppingRight State Exited at Time %d\n", OWNER->mark);
    // do nothing
}
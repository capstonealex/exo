#include "SteppingFirstLeft.h"
////////// STATE ////////////////////
// Stepping First Left
////////////////////////////////////
void SteppingFirstLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingFirstLeft State Entered at Time %d\n", owner->mark);
    // owner->startNewTraj();
    owner->robot->startNewTraj();
}

void SteppingFirstLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->trajTime =  STEPTIME;
    owner->robot->moveThroughTraj(owner->robot->steppingFirstLeftTrajFunc);
}

void SteppingFirstLeft::exit(void)
{
    printf("SteppingFirstLeft State Exited at Time %d\n", owner->mark);
    // do nothing
}

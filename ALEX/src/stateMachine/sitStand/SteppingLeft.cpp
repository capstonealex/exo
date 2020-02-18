#include "sitStand.h"
////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLeft State Entered at Time %d\n", OWNER->mark);
    OWNER->robot->startNewTraj();
}

void SteppingLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj(&OWNER->robot->steppingLeftTrajFunc, STEPTIME);
}

void SteppingLeft::exit(void)
{
    printf("SteppingLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}
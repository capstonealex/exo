#include "sitStand.h"
///////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastRight State Entered at Time %d\n", OWNER->mark);

    OWNER->robot->startNewTraj();
}

void SteppingLastRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj(OWNER->robot->steppingLastRightTrajFunc, STEPTIME);
}

void SteppingLastRight::exit(void)
{
    printf("SteppingLastRight State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

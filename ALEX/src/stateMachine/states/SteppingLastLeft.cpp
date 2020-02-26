#include "exoStateMachine.h"
/////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void SteppingLastLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastLeft State Entered at Time %d\n", OWNER->mark);

    OWNER->robot->startNewTraj();
}

void SteppingLastLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj();
}

void SteppingLastLeft::exit(void)
{
    printf("SteppingLastLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}
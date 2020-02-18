#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void Sitting::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Forcing to Sitting State\n");
    OWNER->robot->startNewTraj();
}
void Sitting::during(void)
{
    OWNER->robot->moveThroughTraj(OWNER->robot->sittingTrajFunc, 10);
}
void Sitting::exit(void)
{
    printf("Sitting State Exited at Time %d\n", OWNER->mark);
}
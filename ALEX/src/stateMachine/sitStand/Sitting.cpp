#include "Sitting.h"
////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void Sitting::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting State Entered at Time %d\n", owner->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Forcing to Sitting State\n");
    owner->robot->startNewTraj();
}
void Sitting::during(void)
{
    owner->robot->moveThroughTraj(owner->robot->sittingTrajFunc, 10);
}
void Sitting::exit(void)
{
    printf("Sitting State Exited at Time %d\n", owner->mark);
}
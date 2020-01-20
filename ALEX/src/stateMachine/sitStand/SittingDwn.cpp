#include "SittingDwn.h"

////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting Down State Entered at Time %d\n", owner->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN SITTING DOWN\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    owner->robot->startNewTraj();
}
void SittingDwn::during(void)
{
    // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    owner->robot->moveThroughTraj(sitDownTrajFunc, SITSTANDTIME);
}
void SittingDwn::exit(void)
{
    printf("Sitting Down State Exited at Time %d\n", owner->mark);
}
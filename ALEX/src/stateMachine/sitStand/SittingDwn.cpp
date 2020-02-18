#include "sitStand.h"

////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting Down State Entered at Time %d\n", OWNER->mark);
    std::cout << "INIT STATE Robot object address: " << OWNER->robot << endl;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN SITTING DOWN\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    OWNER->robot->startNewTraj();
}
void SittingDwn::during(void)
{
    // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj(OWNER->robot->sitDownTrajFunc, SITSTANDTIME);
}
void SittingDwn::exit(void)
{
    printf("Sitting Down State Exited at Time %d\n", OWNER->mark);
}
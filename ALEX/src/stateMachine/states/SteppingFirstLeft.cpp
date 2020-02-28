#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping First Left
////////////////////////////////////
void SteppingFirstLeft::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping 1st Left" << endl
        << "==================" << endl;

    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[1]);
    OWNER->robot->trajectoryObj.setTrajectoryStanceRight();
    OWNER->robot->startNewTraj();
}

void SteppingFirstLeft::during(void)
{

    OWNER->robot->moveThroughTraj();
}

void SteppingFirstLeft::exit(void)
{
    std::cout
        << "SteppingFirstLeft State Exited at Time: " << OWNER->mark << endl;
}

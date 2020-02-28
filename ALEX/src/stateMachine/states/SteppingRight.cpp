#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping Right
///////////////////////////////////////////////
void SteppingRight::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Right" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[2]);
    OWNER->robot->trajectoryObj.setTrajectoryStanceLeft();
    OWNER->robot->startNewTraj();
}

void SteppingRight::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingRight::exit(void)
{
    std::cout
        << "SteppingRight State Exited at Time:" << OWNER->mark;
}
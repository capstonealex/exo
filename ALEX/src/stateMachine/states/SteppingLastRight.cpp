#include "exoStateMachine.h"
///////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Last Right" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[2]);
    OWNER->robot->trajectoryObj.setTrajectoryStanceLeft();
    OWNER->robot->startNewTraj();
    //TODO, when OD WORKING: OD.CS = StateODMap[this.getName()]
}

void SteppingLastRight::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLastRight::exit(void)
{
    std::cout
        << "SteppingLastRight State Exited at Time: " << OWNER->mark << endl;
}

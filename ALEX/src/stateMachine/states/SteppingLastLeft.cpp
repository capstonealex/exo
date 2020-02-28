#include "exoStateMachine.h"
/////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void SteppingLastLeft::entry(void)
{
    std::cout
        << "==================" << endl
        << " Stepping Last Left" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[2]);
    OWNER->robot->trajectoryObj.setTrajectoryStanceRight();
    OWNER->robot->startNewTraj();
    //TODO, when OD WORKING: OD.CS = StateODMap[this.getName()]
}

void SteppingLastLeft::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLastLeft::exit(void)
{
    std::cout
        << "SteppingLastLeft State Exited at Time: " << OWNER->mark << endl;
}
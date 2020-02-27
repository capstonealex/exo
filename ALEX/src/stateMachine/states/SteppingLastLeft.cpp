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
    Trajectory::trajectory_parameters stance_param{.stance_foot = Trajectory::Foot::Right};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(stance_param);
    OWNER->robot->startNewTraj();
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
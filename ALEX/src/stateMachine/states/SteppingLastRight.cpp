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
    Trajectory::trajectory_parameters stance_param{.stance_foot = Trajectory::Foot::Left};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(stance_param);
    OWNER->robot->startNewTraj();
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

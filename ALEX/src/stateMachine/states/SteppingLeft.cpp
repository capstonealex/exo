#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Left" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[2]);
    Trajectory::trajectory_parameters stance_param{.stance_foot = Trajectory::Foot::Right};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(stance_param);
    OWNER->robot->startNewTraj();
}

void SteppingLeft::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLeft::exit(void)
{
    std::cout
        << "SteppingLeft State Exited at Time: " << OWNER->mark << endl;
}
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
    Trajectory::trajectory_parameters stance_param{.stance_foot = Trajectory::Foot::Right};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(stance_param);
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

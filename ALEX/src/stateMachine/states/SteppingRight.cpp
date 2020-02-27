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
    //TODO: seTrajStanding FootParam based on state and move above function to event
    Trajectory::trajectory_parameters stance_param{.stance_foot = Trajectory::Foot::Left};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(stance_param);
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
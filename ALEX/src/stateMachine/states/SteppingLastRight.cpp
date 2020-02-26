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
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPTGTLENGTH,
        .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Left,
        .movement = Trajectory::Movement::Back,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

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

#include "exoStateMachine.h"
/////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void SteppingLastLeft::entry(void)
{
    std::cout
        << "SteppingLastLeft State Entered at Time: " << OWNER->mark << endl;
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPTGTLENGTH,
        .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);
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
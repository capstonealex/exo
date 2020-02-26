#include "exoStateMachine.h"
// Negative bending control machine
void StandingUp::entry(void)
{
    std::cout << "Standing Up State Entered at Time:" << OWNER->mark << endl
              << "===================" << endl
              << " GREEN -> STAND UP" << endl
              << "===================" << endl;

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STANDTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Stand,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->robot->startNewTraj();
}

void StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    OWNER->robot->moveThroughTraj();
}
void StandingUp::exit(void)
{
    std::cout
        << "Standing up motion State Exited at Time: " << OWNER->mark << endl;
}
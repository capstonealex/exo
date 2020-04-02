#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping First Left
////////////////////////////////////
void SteppingLeftStair::entry(void)
{
    //READ TIME OF MAIN
    std::cout 
        << "==================" << endl
        << " Stepping Left Stair" << endl
        << "==================" << endl;
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STAIRTIME,
        .step_height = STEPHEIGHT, 
        .step_length = STAIRSSTEP, 
        .hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE,
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Stair,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = STAIRSHEIGHT, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);
    OWNER->robot->startNewTraj();
}

void SteppingLeftStair::during(void)
{

    OWNER->robot->moveThroughTraj();
}

void SteppingLeftStair::exit(void)
{
    std::cout
        << "SteppingFirstLeft State Exited at Time: " << OWNER->mark << endl;
}
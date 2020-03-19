#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void SteppingLeftHigh::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Left High" << endl
        << "==================" << endl;
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        //.step_duration = UNEVENSTEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE,
        //.torso_forward_angle = UNEVENTORSO,
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        //.movement = Trajectory::Movement::Walk,
        .movement = Trajectory::Movement::Uneven,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = 0.04, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);
    OWNER->robot->startNewTraj();
}

void SteppingLeftHigh::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLeftHigh::exit(void)
{
    std::cout
        << "SteppingLeft State Exited at Time: " << OWNER->mark << endl;
}
#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void)
{
    std::cout << "Sitting Down State Entered at Time:" << OWNER->mark << endl
              << "===================" << endl
              << " GREEN -> SIT DOWN " << endl
              << "===================" << endl;
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = SITTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Sit,
        .seat_height = 0.42,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};

    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->robot->startNewTraj();
}
void SittingDwn::during(void)
{
    // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj();
}
void SittingDwn::exit(void)
{
    std::cout
        << "Sitting Down State Exited at Time: " << OWNER->mark << endl;
}
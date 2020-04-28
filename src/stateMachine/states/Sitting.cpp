#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void Sitting::entry(void) {
    //READ TIME OF MAIN
    std::cout << "Sitting State Entered at Time:" << OWNER->mark << endl
              << "=======================" << endl
              << " YELLOW -> STAND UP" << endl
              << "=======================" << endl
              << "Forcing to Sitting State"
              << endl;
    TrajectoryGenerator::Ttrajectory_parametersmovement_trajectory_parameters = {
        .step_duration = SITTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = TrajectoryGenerator::Foot::Right,
        .movement = TrajectoryGenerator::Movement::Sitting,
        .seat_height = 0.42,     // sit-stand
        .step_end_height = 0.0,  // stairs
        .slope_angle = 0.0,      // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryGenerator.setTrajectoryParameter(movement_trajectory_parameters);
    OWNER->robot->startNewTraj();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()];
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Sitting"];
}
void Sitting::during(void) {
    OWNER->robot->moveThroughTraj();
}
void Sitting::exit(void) {
    std::cout
        << "Sitting State Exited at Time:" << OWNER->mark << endl;
}
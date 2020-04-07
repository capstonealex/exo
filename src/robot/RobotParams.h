
#ifndef ROBOT_PARAMS_H
#define ROBOT_PARAMS_H
#include <map>
#include "Robot.h"

// Next MOTION Map values
#define NORMALWALK 1
#define UPSTAIR 2
#define DWNSTAIR 3
#define TILTUP 4
#define TILTDWN 5
#define FTTG 6
#define BKSTEP 7
#define SITDWN 8
#define STNDUP 9
#define UNEVEN 10
/**
   * Map between OD.nextmotion dictionary values to trajectory paramater 
   * structs defined for use in designed trajectory generation.
   *
   * @param[in] int OD.nextmotion entry
   * @return trajectory paramater object
   */
// TODO:: ADD IN CORRECT PARAMS FOR 4-7
// std::map<int, Trajectory::trajectory_parameters> TrajParamMap = {
//     {NORMALWALK, {.step_duration = UNEVENSTEPTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
//                   .hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//                   //.torso_forward_angle = TORSOANGLE,
//                   .torso_forward_angle = UNEVENTORSO,
//                   .swing_ankle_down_angle = 0,
//                   .stance_foot = Trajectory::Foot::Right,
//                   //.movement = Trajectory::Movement::Walk,
//                   .movement = Trajectory::Movement::Uneven,
//                   .seat_height = 0.42,    // sit-stand
//                   .step_end_height = 0.0, // stairs
//                   .slope_angle = 0.0,     // tilted path
//                   .left_foot_on_tilt = false,
//                   .right_foot_on_tilt = false}},
//     {UPSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = STEPTGTLENGTH,
//                .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//                .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//                .swing_ankle_down_angle = 0,
//                .stance_foot = Trajectory::Foot::Right,
//                .movement = Trajectory::Movement::Walk,
//                .seat_height = 0.42,    // sit-stand
//                .step_end_height = 0.0, // stairs
//                .slope_angle = 0.0,     // tilted path
//                .left_foot_on_tilt = false,
//                .right_foot_on_tilt = false}},
//     {DWNSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
//                 .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//                 .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//                 .swing_ankle_down_angle = 0,
//                 .stance_foot = Trajectory::Foot::Left,
//                 .movement = Trajectory::Movement::Back,
//                 .seat_height = 0.42,    // sit-stand
//                 .step_end_height = 0.0, // stairs
//                 .slope_angle = 0.0,     // tilted path
//                 .left_foot_on_tilt = false,
//                 .right_foot_on_tilt = false}},
//     {TILTUP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
//               .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//               .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//               .swing_ankle_down_angle = 0,
//               .stance_foot = Trajectory::Foot::Left,
//               .movement = Trajectory::Movement::Back,
//               .seat_height = 0.42,    // sit-stand
//               .step_end_height = 0.0, // stairs
//               .slope_angle = 5.0,     // tilted path
//               .left_foot_on_tilt = false,
//               .right_foot_on_tilt = false}},
//     {TILTDWN, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
//                .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//                .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//                .swing_ankle_down_angle = 0,
//                .stance_foot = Trajectory::Foot::Left,
//                .movement = Trajectory::Movement::Back,
//                .seat_height = 0.42,    // sit-stand
//                .step_end_height = 0.0, // stairs
//                .slope_angle = 0.0,     // tilted path
//                .left_foot_on_tilt = false,
//                .right_foot_on_tilt = false}},
//     {FTTG, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
//             .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//             .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//             .swing_ankle_down_angle = 0,
//             .stance_foot = Trajectory::Foot::Left,
//             .movement = Trajectory::Movement::Back,
//             .seat_height = 0.42,    // sit-stand
//             .step_end_height = 0.0, // stairs
//             .slope_angle = 0.0,     // tilted path
//             .left_foot_on_tilt = false,
//             .right_foot_on_tilt = false}},
//     {BKSTEP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
//               .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//               .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//               .swing_ankle_down_angle = 0,
//               .stance_foot = Trajectory::Foot::Left,
//               .movement = Trajectory::Movement::Back,
//               .seat_height = 0.42,    // sit-stand
//               .step_end_height = 0.0, // stairs
//               .slope_angle = 0.0,     // tilted path
//               .left_foot_on_tilt = false,
//               .right_foot_on_tilt = false}},
//     {SITDWN, {.step_duration = SITTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
//               .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//               .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//               .swing_ankle_down_angle = 0,
//               .stance_foot = Trajectory::Foot::Right,
//               .movement = Trajectory::Movement::Sit,
//               .seat_height = 0.42,    // sit-stand
//               .step_end_height = 0.0, // stairs
//               .slope_angle = 0.0,     // tilted path
//               .left_foot_on_tilt = false,
//               .right_foot_on_tilt = false}},
//     {STNDUP, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
//               .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//               .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//               .swing_ankle_down_angle = 0,
//               .stance_foot = Trajectory::Foot::Right,
//               .movement = Trajectory::Movement::Stand,
//               .seat_height = 0.42,    // sit-stand
//               .step_end_height = 0.0, // stairs
//               .slope_angle = 0.0,     // tilted path
//               .left_foot_on_tilt = false,
//               .right_foot_on_tilt = false}},
//     {UNEVEN, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
//               .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//               .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
//               .swing_ankle_down_angle = 0,
//               .stance_foot = Trajectory::Foot::Right,
//               .movement = Trajectory::Movement::Stand,
//               .seat_height = 0.42,    // sit-stand
//               .step_end_height = 0.0, // stairs
//               .slope_angle = 0.0,     // tilted path
//               .left_foot_on_tilt = false,
//               .right_foot_on_tilt = false}}};
/**
   * Exoskeleton model paramaters for use in Trajectory generation
   *
   * @param
   */
//TODO: exoParams or name Brad Params?
// Trajectory::pilot_parameters exoParamaters = {
//     .lowerleg_length = 0.44,
//     .upperleg_length = 0.44,
//     .ankle_height = 0.12,
//     .foot_length = 0.30,
//     .hip_width = 0.43,
//     .torso_length = 0.4,
//     .buttocks_height = 0.05};
/**
   * Initial trajectory paramaters for use in Trajectory generation
   *
   * @param trajectory paramater object
   */
// initial_trajectory_parameters = {
//     .step_duration = 1,
//     .step_height = 0.2,
//     .step_length = 0.3,
//     .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
//     .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
//     .swing_ankle_down_angle = 0,
//     .stance_foot = Trajectory::Foot::Right,
//     .movement = Trajectory::Movement::Sitting,
//     .seat_height = 0.45,    // sit-stand
//     .step_end_height = 0.0, // stairs
//     .slope_angle = 0.0,     // tilted path
//     .left_foot_on_tilt = false,
//     .right_foot_on_tilt = false};

#endif /*ROBOT_PARAMS_H*/
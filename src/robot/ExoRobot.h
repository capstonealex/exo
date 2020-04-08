/**
 * The <code>ExoRobot</code> class represents an ExoSkeleton Robot in terms of its 
 * representation of the Alex exoskeleton hardware whose memory
 * is managed in this class.
 * 
 * 
 * Version 0.1
 * Date: 07/04/2020
 *
 */
/*Header Guard*/
#ifndef EXOROBOT_H
#define EXOROBOT_H
#include "RobotParams.h"

class ExoRobot : public Robot
{
private:
    //TODO: Load in paramaters and dictionary entries from JSON file.
    /**
 * Trajectory paramater variables for the initial state of the exoskeleton in sitting position.
 * Note this variable is used by the trajectory generator object.
 */
    Trajectory::trajectory_parameters initial_trajectory_parameters = {
        .step_duration = 1,
        .step_height = 0.2,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Sitting,
        .seat_height = 0.45,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    /**
 * Trajectory pilot paramaters dictate the specific real world link lengths of the 3 joint exoskeleton robot.
 * These paramaters must be specifically changed for the pilot using the Exoskeleton.
 */
    Trajectory::pilot_parameters exoParamaters = {
        .lowerleg_length = 0.44,
        .upperleg_length = 0.44,
        .ankle_height = 0.12,
        .foot_length = 0.30,
        .hip_width = 0.43,
        .torso_length = 0.4,
        .buttocks_height = 0.05};
    // Trajectory::pilot_parameters exoParamaters;

public:
    /**
   * @brief Default <code>ExoRobot</code> constructor.
   * Initialize memory for the Exoskelton joints + sensors 
   * and load in exoskeleton paramaters to trajectory generator.
   */
    ExoRobot();
    /** 
   * For each joint, move through(send appropriate commands to joints) the Currently 
   * generated trajectory of the Trajectory object. 
   *
   */
    void moveThroughTraj();
    /** 
   * 
   *
   */
    void startNewTraj();
    /** 
   * Determine if the currently generated trajectory is complete.
   *@return bool
   */
    bool isTrajFinished();
    /** 
   * Getter method for exoSkeleton defined Paramaters
   *@return Trajectory::pilot_paramaters
   */
    bool getExoParamaters();
    /** 
   * Getter method for currently loaded motion trajectory paramaters
   *@return Trajectory::trajectory_parameters
   */
    bool getTrajParamaters();

    //
    ////TEST CODE: MOVE TO ROBOT LEVEL ONCE WORKING

    /** 
   * Setter method for exoSkeleton Trajectory Paramaters
   * Set trajectory paramaters to those coresponding to the current Next Motion value from user
   *
   */
    void setTrajectory();
    /** 
   * Print out the currently loaded trajectory paramater values stored in the ExoRobots trajectory object.
   *
   */
    void printTrajectoryParam();
    /**
 * Map between int values for specific trajectory motion paramaters. These paramaters are fed into the
 * Trajectory generator object to create unique trajectories. The map is constructed for ease of loading 
 * in new trajectories dictated by an external CAN enabled controller in the exoskeleton State machine. 
 */
    std::map<int, Trajectory::trajectory_parameters> TrajParamMap = {
        {NORMALWALK, {.step_duration = UNEVENSTEPTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                      .hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      //.torso_forward_angle = TORSOANGLE,
                      .torso_forward_angle = UNEVENTORSO,
                      .swing_ankle_down_angle = 0,
                      .stance_foot = Trajectory::Foot::Right,
                      //.movement = Trajectory::Movement::Walk,
                      .movement = Trajectory::Movement::Uneven,
                      .seat_height = 0.42,    // sit-stand
                      .step_end_height = 0.0, // stairs
                      .slope_angle = 0.0,     // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}},
        {UPSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = STEPTGTLENGTH,
                   .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                   .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                   .swing_ankle_down_angle = 0,
                   .stance_foot = Trajectory::Foot::Right,
                   .movement = Trajectory::Movement::Walk,
                   .seat_height = 0.42,    // sit-stand
                   .step_end_height = 0.0, // stairs
                   .slope_angle = 0.0,     // tilted path
                   .left_foot_on_tilt = false,
                   .right_foot_on_tilt = false}},
        {DWNSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                    .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                    .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                    .swing_ankle_down_angle = 0,
                    .stance_foot = Trajectory::Foot::Left,
                    .movement = Trajectory::Movement::Back,
                    .seat_height = 0.42,    // sit-stand
                    .step_end_height = 0.0, // stairs
                    .slope_angle = 0.0,     // tilted path
                    .left_foot_on_tilt = false,
                    .right_foot_on_tilt = false}},
        {TILTUP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                  .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                  .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                  .swing_ankle_down_angle = 0,
                  .stance_foot = Trajectory::Foot::Left,
                  .movement = Trajectory::Movement::Back,
                  .seat_height = 0.42,    // sit-stand
                  .step_end_height = 0.0, // stairs
                  .slope_angle = 5.0,     // tilted path
                  .left_foot_on_tilt = false,
                  .right_foot_on_tilt = false}},
        {TILTDWN, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                   .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                   .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                   .swing_ankle_down_angle = 0,
                   .stance_foot = Trajectory::Foot::Left,
                   .movement = Trajectory::Movement::Back,
                   .seat_height = 0.42,    // sit-stand
                   .step_end_height = 0.0, // stairs
                   .slope_angle = 0.0,     // tilted path
                   .left_foot_on_tilt = false,
                   .right_foot_on_tilt = false}},
        {FTTG, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                .swing_ankle_down_angle = 0,
                .stance_foot = Trajectory::Foot::Left,
                .movement = Trajectory::Movement::Back,
                .seat_height = 0.42,    // sit-stand
                .step_end_height = 0.0, // stairs
                .slope_angle = 0.0,     // tilted path
                .left_foot_on_tilt = false,
                .right_foot_on_tilt = false}},
        {BKSTEP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                  .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                  .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                  .swing_ankle_down_angle = 0,
                  .stance_foot = Trajectory::Foot::Left,
                  .movement = Trajectory::Movement::Back,
                  .seat_height = 0.42,    // sit-stand
                  .step_end_height = 0.0, // stairs
                  .slope_angle = 0.0,     // tilted path
                  .left_foot_on_tilt = false,
                  .right_foot_on_tilt = false}},
        {SITDWN, {.step_duration = SITTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                  .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                  .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                  .swing_ankle_down_angle = 0,
                  .stance_foot = Trajectory::Foot::Right,
                  .movement = Trajectory::Movement::Sit,
                  .seat_height = 0.42,    // sit-stand
                  .step_end_height = 0.0, // stairs
                  .slope_angle = 0.0,     // tilted path
                  .left_foot_on_tilt = false,
                  .right_foot_on_tilt = false}},
        {STNDUP, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                  .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                  .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                  .swing_ankle_down_angle = 0,
                  .stance_foot = Trajectory::Foot::Right,
                  .movement = Trajectory::Movement::Stand,
                  .seat_height = 0.42,    // sit-stand
                  .step_end_height = 0.0, // stairs
                  .slope_angle = 0.0,     // tilted path
                  .left_foot_on_tilt = false,
                  .right_foot_on_tilt = false}},
        {UNEVEN, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                  .hip_height_slack = LEGSLACK,      // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                  .torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
                  .swing_ankle_down_angle = 0,
                  .stance_foot = Trajectory::Foot::Right,
                  .movement = Trajectory::Movement::Stand,
                  .seat_height = 0.42,    // sit-stand
                  .step_end_height = 0.0, // stairs
                  .slope_angle = 0.0,     // tilted path
                  .left_foot_on_tilt = false,
                  .right_foot_on_tilt = false}}};
};
#endif /*EXOROBOT_H*/
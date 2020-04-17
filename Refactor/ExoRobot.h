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
#include <map>

#include "CopleyDrive.h"
#include "DummyActJoint.h"
#include "Robot.h"
#include "RobotParams.h"

class ExoRobot : public Robot {
   private:
    //TODO: Load in paramaters and dictionary entries from JSON file.
    /**
 * TrajectoryGenerator pilot paramaters dictate the specific real world link lengths of the 3 joint exoskeleton robot.
 * These paramaters must be specifically changed for the pilot using the Exoskeleton.
 */
    TrajectoryGenerator::pilot_parameters exoParams = {
        .lowerleg_length = 0.44,
        .upperleg_length = 0.44,
        .ankle_height = 0.12,
        .foot_length = 0.30,
        .hip_width = 0.43,
        .torso_length = 0.4,
        .buttocks_height = 0.05};

   public:
    /**
   * @brief Default <code>ExoRobot</code> constructor.
   * Initialize memory for the Exoskelton <code>Joint</code> + sensors. 
   * Load in exoskeleton paramaters to  <code>TrajectoryGenerator.</code>.
   */
    ExoRobot();
    ~ExoRobot();

    vector<CopleyDrive *> copleyDrives;

    // /**
    //  * @brief Timer Variables for moving through trajectories
    //  *
    //  */
    struct timeval tv, tv_diff, moving_tv, tv_changed, stationary_tv, start_traj, last_tv;

    /**
    * @brief Initialises all joints to position control mode. 
    * 
    * @return true If all joints are successfully configured
    * @return false  If some or all joints fail the configuration
    */
    bool initPositionControl();
    /** 
   * @brief For each joint, move through(send appropriate commands to joints) the Currently 
   * generated trajectory of the TrajectoryGenerator object. 
   *
   */
    bool moveThroughTraj();
    /** 
   *  @brief Begin a new trajectory with the currently loaded trajectory paramaters. 
   * Using the <code>ExoRobot</code> current configuration (read in from joint objects) 
   * and the trajecotry generator object, generate and save a spline to move from current 
   * to desired position.
   * 
   */
    void startNewTraj();
    /** 
   * Determine if the currently generated trajectory is complete.
   *@return bool
   */
    bool isTrajFinished();
    /** 
   * @brief Implementation of <code>Robot</code> class setTrajectory function, takes the currently selected
   * motion from the user (via the robots I/O crutch object) and using the exoskeletons 
   * movementTrajMap loads in the correct trajectory paramaters into the <code>TrajectoryGenerator</code> object.
   *
   */
    void setTrajectory();

    /**
    * @brief Prints the parameters for the defined trajectory
    * 
    */
    void printTrajectoryParam();

    /**
     * @brief Implementation of Pure Virtual function from <code>Robot</code> Base class.
     * Create designed <code>Joint</Joint> and <code>Driver</code> objects and load into 
     * Robot joint vector.

     */
    bool initialiseJoints();
    /**
     * @brief Implementation of Pure Virtual function from <code>Robot</code> Base class.
     * Create designed <code>Joint</Joint> and <code>Driver</code> objects and load into 
     * Robot joint vector.

     */
    bool initialiseNetwork();

    /**
 * @brief Joint Limit Map between Joint value and min Degrees possible
 * @param int Joint value
 * @return double minDeg 
 */
    //TODO CHANGE FROM MOTOR COMMANDS TO DEGREES
    std::map<int, double> jointMinMap = {{LEFT_HIP, 0.0},
                                         {RIGHT_HIP, 0.0},
                                         {LEFT_KNEE, 0.0},
                                         {RIGHT_KNEE, 0.0},
                                         {LEFT_ANKLE, -800000},
                                         {RIGHT_ANKLE, -800000}};
    /**
 * @brief Joint Limit Map between Joint value and max Degrees possible
 * @param int Joint value
 * @return int maxDeg 
 */
    std::map<int, double> jointMaxMap = {{LEFT_HIP, (HIP_MOTOR_POS1 * 1.5)},
                                         {RIGHT_HIP, (HIP_MOTOR_POS1 * 1.5)},
                                         {LEFT_KNEE, (KNEE_MOTOR_POS1 * 1.5)},
                                         {RIGHT_KNEE, (KNEE_MOTOR_POS1 * 1.5)},
                                         {LEFT_ANKLE, -800000},
                                         {RIGHT_ANKLE, -800000}};
    /**
 * @brief Map between int values for specific trajectory motion paramaters. These paramaters are fed into the
 * TrajectoryGenerator object to create unique trajectories. The map is constructed for ease of loading 
 * in new trajectories dictated by an external CAN enabled controller in the exoskeleton State machine. The paramater
 * map is constructed at runtime from trajectoryParam.JSON
 * @param int Movement type
 * @return TrajectoryGenerator::trajectory_parameters 
 */
    std::map<int, TrajectoryGenerator::trajectory_parameters>
        movementTrajMap = {
            {INITIAL, {.step_duration = 1, .step_height = 0.2, .step_length = 0.3,
                       .hip_height_slack = 0.0001,         // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                       .torso_forward_angle = deg2rad(5),  // TODO: make this a vector/array?
                       .swing_ankle_down_angle = 0,
                       .stance_foot = TrajectoryGenerator::Foot::Right,
                       .movement = TrajectoryGenerator::Movement::Sitting,
                       .seat_height = 0.45,     // sit-stand
                       .step_end_height = 0.0,  // stairs
                       .slope_angle = 0.0,      // tilted path
                       .left_foot_on_tilt = false,
                       .right_foot_on_tilt = false}},
            {NORMALWALK, {.step_duration = UNEVENSTEPTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                          .hip_height_slack = LEGSLACK,  // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                          //.torso_forward_angle = TORSOANGLE,
                          .torso_forward_angle = UNEVENTORSO,
                          .swing_ankle_down_angle = 0,
                          .stance_foot = TrajectoryGenerator::Foot::Right,
                          //.movement = TrajectoryGenerator::Movement::Walk,
                          .movement = TrajectoryGenerator::Movement::Uneven,
                          .seat_height = 0.42,     // sit-stand
                          .step_end_height = 0.0,  // stairs
                          .slope_angle = 0.0,      // tilted path
                          .left_foot_on_tilt = false,
                          .right_foot_on_tilt = false}},
            {UPSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = STEPTGTLENGTH,
                       .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                       .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                       .swing_ankle_down_angle = 0,
                       .stance_foot = TrajectoryGenerator::Foot::Right,
                       .movement = TrajectoryGenerator::Movement::Walk,
                       .seat_height = 0.42,     // sit-stand
                       .step_end_height = 0.0,  // stairs
                       .slope_angle = 0.0,      // tilted path
                       .left_foot_on_tilt = false,
                       .right_foot_on_tilt = false}},
            {DWNSTAIR, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                        .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                        .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                        .swing_ankle_down_angle = 0,
                        .stance_foot = TrajectoryGenerator::Foot::Left,
                        .movement = TrajectoryGenerator::Movement::Back,
                        .seat_height = 0.42,     // sit-stand
                        .step_end_height = 0.0,  // stairs
                        .slope_angle = 0.0,      // tilted path
                        .left_foot_on_tilt = false,
                        .right_foot_on_tilt = false}},
            {TILTUP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                      .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                      .swing_ankle_down_angle = 0,
                      .stance_foot = TrajectoryGenerator::Foot::Left,
                      .movement = TrajectoryGenerator::Movement::Back,
                      .seat_height = 0.42,     // sit-stand
                      .step_end_height = 0.0,  // stairs
                      .slope_angle = 5.0,      // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}},
            {TILTDWN, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                       .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                       .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                       .swing_ankle_down_angle = 0,
                       .stance_foot = TrajectoryGenerator::Foot::Left,
                       .movement = TrajectoryGenerator::Movement::Back,
                       .seat_height = 0.42,     // sit-stand
                       .step_end_height = 0.0,  // stairs
                       .slope_angle = 0.0,      // tilted path
                       .left_foot_on_tilt = false,
                       .right_foot_on_tilt = false}},
            {FTTG, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                    .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                    .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                    .swing_ankle_down_angle = 0,
                    .stance_foot = TrajectoryGenerator::Foot::Left,
                    .movement = TrajectoryGenerator::Movement::Back,
                    .seat_height = 0.42,     // sit-stand
                    .step_end_height = 0.0,  // stairs
                    .slope_angle = 0.0,      // tilted path
                    .left_foot_on_tilt = false,
                    .right_foot_on_tilt = false}},
            {BKSTEP, {.step_duration = STEPTIME, .step_height = STEPHEIGHT, .step_length = BACKLENGTH,
                      .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                      .swing_ankle_down_angle = 0,
                      .stance_foot = TrajectoryGenerator::Foot::Left,
                      .movement = TrajectoryGenerator::Movement::Back,
                      .seat_height = 0.42,     // sit-stand
                      .step_end_height = 0.0,  // stairs
                      .slope_angle = 0.0,      // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}},
            {SITDWN, {.step_duration = SITTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                      .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                      .swing_ankle_down_angle = 0,
                      .stance_foot = TrajectoryGenerator::Foot::Right,
                      .movement = TrajectoryGenerator::Movement::Sit,
                      .seat_height = 0.42,     // sit-stand
                      .step_end_height = 0.0,  // stairs
                      .slope_angle = 0.0,      // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}},
            {STNDUP, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                      .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                      .swing_ankle_down_angle = 0,
                      .stance_foot = TrajectoryGenerator::Foot::Right,
                      .movement = TrajectoryGenerator::Movement::Stand,
                      .seat_height = 0.42,     // sit-stand
                      .step_end_height = 0.0,  // stairs
                      .slope_angle = 0.0,      // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}},
            {UNEVEN, {.step_duration = STANDTIME, .step_height = STEPHEIGHT, .step_length = STEPLENGTH,
                      .hip_height_slack = LEGSLACK,       // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
                      .torso_forward_angle = TORSOANGLE,  // TODO: make this a vector/array?
                      .swing_ankle_down_angle = 0,
                      .stance_foot = TrajectoryGenerator::Foot::Right,
                      .movement = TrajectoryGenerator::Movement::Stand,
                      .seat_height = 0.42,     // sit-stand
                      .step_end_height = 0.0,  // stairs
                      .slope_angle = 0.0,      // tilted path
                      .left_foot_on_tilt = false,
                      .right_foot_on_tilt = false}}};
};

#endif /*EXOROBOT_H*/
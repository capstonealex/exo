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
#ifndef EXOROBOT_H_INCLUDED
#define EXOROBOT_H_INCLUDED

#include <time.h>

#include <map>

#include "ALEXTrajectoryGenerator.h"
#include "CopleyDrive.h"
#include "DummyActJoint.h"
#include "Keyboard.h"
#include "Robot.h"
#include "RobotParams.h"
#define NOROBOT
class ExoRobot : public Robot {
   private:
    //TODO: Load in paramaters and dictionary entries from JSON file.
    /**
    * TrajectoryGenerator pilot paramaters dictate the specific real world link lengths of the 3 joint exoskeleton robot.
    * These paramaters must be specifically changed for the pilot using the Exoskeleton.
    */
    PilotParameters exoParams = {
        .lowerleg_length = 0.44,
        .upperleg_length = 0.44,
        .ankle_height = 0.12,
        .foot_length = 0.30,
        .hip_width = 0.43,
        .torso_length = 0.4,
        .buttocks_height = 0.05};

    /** Parameters associated with Trajectory Progression */
    time_tt currTrajProgress = 0;
    timespec prevTime;

   public:
    /**
      * @brief Default <code>ExoRobot</code> constructor.
      * Initialize memory for the Exoskelton <code>Joint</code> + sensors. 
      * Load in exoskeleton paramaters to  <code>TrajectoryGenerator.</code>.
      */
    ExoRobot();
    ~ExoRobot();
    Keyboard keyboard;
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
    // set trajectory from input int traj value -> must have coresponding map entry
    void setSpecificTrajectory(RobotMode mode);
    /**
       * @brief Prints the parameters for the defined trajectory
       * 
       */
    void
    printTrajectoryParam();

    /**
       * @brief Implementation of Pure Virtual function from <code>Robot</code> Base class.
       * Create designed <code>Joint</code> and <code>Driver</code> objects and load into 
       * Robot joint vector.
       */
    bool initialiseJoints();

    /**
       * @brief Implementation of Pure Virtual function from <code>Robot</code> Base class.
       * Initialize each <code>Drive</code> Objects underlying CANOpen Networking.

      */
    bool initialiseNetwork();
    /**
       * @brief Implementation of Pure Virtual function from <code>Robot</code> Base class.
       * Initialize each <code>Input</code> Object.

      */
    bool initialiseInputs();
    /**
       * @brief Free robot objects vector pointer memory.
       */
    void freeMemory();
    /**
       * @brief run intialise after construction, inherited from robot class 
       */
    void start();
    /**
       * @brief update current state of the robot, including input and output devices. 
       * Overloaded Method from the Robot Class. 
       * Example. for a keyboard input this would poll the keyboard for any button presses at this moment in time.
       */
    void updateRobot();
    /**
       * @brief Joint Limit Map between Joint value and min Degrees possible
       * @param int Joint value
       * @return double minDeg 
       */
    //TODO CHANGE FROM MOTOR COMMANDS TO DEGREES
    std::map<int, double>
        jointMinMap = {{LEFT_HIP, 0.0},
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
};
#endif /*EXOROBOT_H*/
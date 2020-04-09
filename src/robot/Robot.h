/**
*  The <code>Robot</code> class is a abstract class which represents a Robot
 * with a flexible representation in terms of number of joints, number of sensors and type of I/O 
 * the real world or virtual robot has. 
 * 
 * Version 0.1
 * Date: 07/04/2020
 * 
 */

/*Header Guard*/
#ifndef ROBOT_H
#define ROBOT_H
#include "Joint.h"
#include "spline.h"
#include "TrajectoryGenerator.h"
#include "Buttons.h"
#include "CO_command.h"
#include <array>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <cmath>

#define CANMESSAGELENGTH (100)
#define NOFLIP (100)
#define _NOANKLES w / o ankles
#ifndef _NOANKLES
#define NUM_JOINTS 6
#else
#define NUM_JOINTS 4
#endif

class Robot
{
private:
    bool positionControlConfigured;

public:
    //Setup
    /**
 * @brief Default <code>Robot</code> constructor.
 */
    Robot();
    /**
     * @brief Initialize memory for the designed <code>Robot<code> classes specific
     * <class>Joint<class> objects + sensors (if available) using the pure virtual initialiseJoints()
     * implemented by the robot designer. Based on the given Joints, initNetwork() will configure 
     * these joints for CAN PDO messaging and Load the specififed Controller, by default set to Positio.
     * 
     * 
     * @return true 
     * @return false 
     */
    bool initialise();
    /**
     * @brief Pure Virtual function, implemeted by robot designer with specified number of each concrete joint classes
     * for the robot hardware desired.
     * 
     * @return true 
     * @return false 
     */
    bool initialiseJoints();
    /**
     * @brief Fore the given designed robot layout, initialise CANopen network messaging.
     * 
     * @return true 
     * @return false 
     */
    bool initialiseNetwork();
    //TODO: move bellow function messaging down to CANDevice level.
    bool initPositionControl(void);
    bool initPositionControlAnkles(void);
    bool remapPDO(void);
    bool remapPDOAnkles(void);
    bool preop(void);
    bool resetTrackingError(void);

    //Robot objects
    /**
 * @brief Vector of Abstract <class>Joint<class> Objects, number and type must be specified by 
 * Software design in <class>Robot<class> Implementation
 * 
 */
    Joint joints[NUM_JOINTS];
    /**
 * @brief Trajectory Object 
 * 
 */
    TrajectoryGenerator trajectoryGenerator;
    Buttons buttons;

    //Core  functions
    /**
 * @brief Update all of this <code>Robot<code> software joint positions 
 * from object dictionary entries.
 * 
 */
    void updateRobot();
    //TODO: TYPE OF STATUS returned? bool or value for different status types: error, moving, ready etc.
    void getStatus();
    void getJointStatus(Joint J_i);

    //Movement
    //setTrajectories();//TODO: Make this an abstract function call - currently in exoROBOT
    //
    //Logging
    /**
 * @brief Initialises Logging to specified file
 * 
 */
    void initialiseLog();
    /**
 * @brief Log input data point to currently open log file
 * 
 */
    void logDataPoint(auto data);
    /**
 * @brief Save and close any currently open logging files
 * 
 */
    bool closeLog();
    //helper vars and functions
    bool positionControl;
    double trajTime;
    double fracTrajProgress = 0;
    void printInfo();
    bool sdoMSG(void); // TODO: PUT IN CANDEVICE LEVEL
    // void printTrajectories();
    void configurePosControl();
    void disablePosControl();
};

#endif //ROBOT_H

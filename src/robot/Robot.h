//
// Created by William Campbell on 2019-07-30.
//

#ifndef CANOPENBEAGLE_ROBOT_H
#define CANOPENBEAGLE_ROBOT_H
#include "Joint.h"
#include "spline.h"
#include "Trajectory.h"
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
//////////////// For testing  ///////////////////////////
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
    int desiredIndex = 0;
    double steptime = STEPTIME;

public:
    bool positionControlConfigured;
    /**
 * @brief Construct a new Robot object
 * 
 */
    Robot();
    /**
 * @brief Trajectory Object 
 * 
 */
    Trajectory trajectoryObj;
    Joint joints[NUM_JOINTS];
    double fracTrajProgress = 0;
    double trajTime;
    void printInfo();
    Buttons buttons;
    void updateJoints();
    bool positionControl;
    bool initPositionControl(void);
    bool initPositionControlAnkles(void);
    bool sdoMSG(void);
    bool remapPDO(void);
    bool remapPDOAnkles(void);
    bool preop(void);
    bool resetTrackingError(void);
    // void printTrajectories();
    void configurePosControl();
    void disablePosControl();

    //canFeasat constants
    unsigned int MAX_RECONNECTS = 10;
    unsigned int DECIMAL = 10;
    // Exo user buttons
    unsigned int BUTTON_ONE = 1;
    unsigned int BUTTON_TWO = 2;
    unsigned int BUTTON_THREE = 3;
    unsigned int BUTTON_FOUR = 4;
    //Node ID for the 4 joints
    // Variable for moving through trajectories
    struct timeval moving_tv;
    struct timeval stationary_tv;
    struct timeval start_traj;
    struct timeval last_tv;
    // Trajectory functions - should move to trajectory object
    void startNewTraj();
};

#endif //CAPSTONE_ROBOT_H

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
    /**
 * @brief Default <code>Robot</code> constructor.
 * Initialize memory for the Robot joints + sensors 
 */
    Robot();
    /**
 * @brief Trajectory Object 
 * 
 */
    TrajectoryGenerator trajectoryGenerator;
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
};

#endif //ROBOT_H

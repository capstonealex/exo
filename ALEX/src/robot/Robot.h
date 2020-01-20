//
// Created by William Campbell on 2019-07-30.
//

#ifndef CANOPENBEAGLE_ROBOT_H
#define CANOPENBEAGLE_ROBOT_H
#include "Joint.h"

class Robot
{
private:
    enum
    {
        NUM_JOINTS = 6
    };
    bool positionControlConfigured;

    double fracTrajProgress = 0;
    int desiredIndex = 0;
    int running = 0;

public:
    Robot();
    Joint joints[NUM_JOINTS];
    void printInfo();
    //void jointIncrement();
    void updateJoints();
    bool initPositionControl(void);
    bool initPositionControlAnkles(void);
    bool homeCalibration(void);
    bool sdoMSG(void);
    bool remapPDO(void);
    bool remapPDOAnkles(void);
    bool preop(void);
    bool resetTrackingError(void);
    // void printTrajectories();

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
    void moveThroughTraj(double (*trajFunction)(int, double, Robot *), double trajTime);
};

#endif //CAPSTONE_ROBOT_H

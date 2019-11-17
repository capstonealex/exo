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
        NUM_JOINTS = 4
    };

public:
    Robot();
    Joint joints[NUM_JOINTS];
    void printInfo();
    //void jointIncrement();
    void updateJoints();
    bool initPositionControl(void);
    bool homeCalibration(void);
    bool sdoMSG(void);
    bool remapPDO(void);
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
 //   unsigned int LHIP = 1;
 //   unsigned int LKNEE = 2;
 //   unsigned int RHIP = 3;
 //   unsigned int RKNEE = 4;
    int positionControl;
};

#endif //CAPSTONE_ROBOT_H

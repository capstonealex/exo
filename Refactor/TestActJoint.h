/**
 * @file TestActJoint.h
 * @author Justin Fong
 * @brief A dummy class to test whether the actuated joint inheritence stuff works
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef TESTACTJOINT_H_DEFINED
#define TESTACTJOINT_H_DEFINED

#include "ActuatedJoint.h"
class TestActJoint : public ActuatedJoint {
    private:
        double fromDriveUnits(int driveValue){return driveValue;};
        int toDriveUnits(double jointValue){return jointValue;};
    public:
        TestActJoint(int jointID, double jointMin, double jointMax, Drive drive);
};

#endif
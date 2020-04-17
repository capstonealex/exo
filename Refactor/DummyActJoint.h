/**
 * @file DummyActJoint.h
 * @author Justin Fong
 * @brief A dummy class to test whether the actuated joint inheritence stuff works
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef DUMMYACTJOINT_H_DEFINED
#define DUMMYACTJOINT_H_DEFINED

#include "ActuatedJoint.h"
class DummyActJoint : public ActuatedJoint {
   private:
    double lastQCommand = 0;

    // These functions are defined here to do essentially nothing - it's a straight 1:1 relation between drive and motor units
    double fromDriveUnits(int driveValue) { return driveValue; };
    int toDriveUnits(double jointValue) { return jointValue; };

   public:
    DummyActJoint(int jointID, double jointMin, double jointMax, Drive *drive);
    bool updateValue();
    setMovementReturnCode_t setPosition(double desQ);
    bool initNetwork();
};

#endif
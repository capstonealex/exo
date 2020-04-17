/**
 * @file DummyActJoint.cpp
 * @author Justin Fong
 * @brief 
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "DummyActJoint.h"

#include <iostream>
DummyActJoint::DummyActJoint(int jointID, double jointMin, double jointMax, Drive *drive) : ActuatedJoint(jointID, jointMin, jointMax, drive) {
    std::cout << "MY JOINT ID: " << this->id << std::endl;
    // Do nothing else
}

bool DummyActJoint::updateValue() {
    drive->getPos();
    q = lastQCommand;
    return true;
}

setMovementReturnCode_t DummyActJoint::setPosition(double desQ) {
    lastQCommand = desQ;
    return ActuatedJoint::setPosition(desQ);
}
bool DummyActJoint::initNetwork() {
    return true;
}
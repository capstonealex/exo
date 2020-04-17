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
DummyActJoint::DummyActJoint(int jointID, double jointMin, double jointMax, Drive *drive) : ActuatedJoint(jointID, jointMin, jointMax, drive){
    // Do nothing else
}

bool DummyActJoint::updateValue(){
    drive->getPos();
    q = lastQCommand;
    return true;
}

setMovementReturnCode_t DummyActJoint::setPosition(double desQ){
    lastQCommand = desQ;
    return ActuatedJoint::setPosition(desQ);
}
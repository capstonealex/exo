/**
 * The <code>ActuatedJoint</code> class is a abstract class which represents a joint in a
 * <code>Robot</code> objec. This class implements the Joint class, and specifically 
 * represents a joint which is actuated. This therefore requires a Drive object
 * which will be used to interact with the physical hardware.  
 * 
 *
 * Version 0.1
 * Date: 09/04/2020
 */


#ifndef ACTUATEDJOINT_H_INCLUDED
#define ACTUATEDJOINT_H_INCLUDED
#include "ActuatedJoint.h"

ActuatedJoint::ActuatedJoint(int jointID, double jointMin, double jointMax, Drive drive) : Joint(jointID, jointMin, jointMax){
    this->drive = drive;
}

ControlMode ActuatedJoint::setMode(ControlMode driveMode){

    if (driveMode == POSITION_CONTROL){
        if(drive.initPosControl());
        return POSITION_CONTROL;
    }
    return ERROR;
}

setMovementReturnCode_t ActuatedJoint::setPosition(double desQ){
    drive.setPos(toDriveUnits(desQ));

    // Replace once complete
    return UNKNOWN_ERROR;
}

setMovementReturnCode_t ActuatedJoint::setVelocity(double velocity){
    drive.setVel(toDriveUnits(velocity));
   
    // Replace once complete
    return UNKNOWN_ERROR;
}

setMovementReturnCode_t ActuatedJoint::setTorque(double torque){

    // Replace once complete
    return UNKNOWN_ERROR;
}
#endif
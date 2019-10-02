//
// Created by William Campbell on 2019-07-24.
//
#include "CANopen.h"
#include "Joint.h"
#include <stdlib.h>
#include <string>
const int STRING_LENGTH = 50;
Joint::Joint()
{
    //Default constructor - SHOULD THROW AN ERROR
    q = 0;
    id = 0;
    // THESE MUST BE HARD SET AT OBJECT INITIALIZATION
    maxq = 360;
    minq = 0;
}
Joint::Joint(float q_init, int ID)
{
    cout << "Initializing joint WITH INPUTS \n";
    q = q_init;
    id = ID;
}
void Joint::applyPos(float qd)
{
    //Safety checks.
    // Is joint where we think it is? or within safe range of it?
    // are we trying to move to a pos within the joints limits?
    ///// Testing for PDOs

    if (qd >= minq && qd <= maxq)
    {
        Joint::setPos(qd);
    }
    else
    {
        cout << "Positions outside of joint limits"
             << "\n";
    }
}
void Joint::setPos(float qd)
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position
    CO_OD_RAM.targetMotorPositions.motor2 = qd;
    cout << "Joint address set to" << CO_OD_RAM.actualMotorPositions.motor2 << "\n";
}
void Joint::setId(int ID)
{
    id = ID;
}
int Joint::getId()
{
    return id;
}
int Joint::getPos()
{
    return q;
}

void Joint::printInfo()
{
    cout << "Joint id number " << id << " @ pos " << q << "\n";
}
//// Robot motion and state update functions
void Joint::updateJoint()
{
    /// Update current joint position from object dictionary
    /// This should be internally mapped from object dictionary
    // Construct obj dictionary entry message for this motor id
    //CO_OD_RAM.actualMotorPositions.motor<id_goes_here>
    q = CO_OD_RAM.actualMotorPositions.motor2;
}
/*
 * bitflip High changes the specified control Word for this joints motor to HIGH
 * Returns true if successfull or false if not 
*/  
bool bitflipHigh(){
    //TODO: 1. Set up caseses for position, velocity and Torque controlWorkds 
    //      2. generalize to create .motor<motorID> dynamically
    //      3. error check control word has been changed in the actual motor.
    CO_OD_RAM.controlWords.motor2 = 63;
    return true;
}
/*
 * bitflip Low changes the specified control Word for this joints motor to HIGH
 * Returns true if successfull or false if not 
*/  
bool bitflipLow(){
    //TODO: 1. Set up caseses for position, velocity and Torque controlWorkds 
    //      2. generalize to create .motor<motorID> dynamically
    //      3. error check control word has been changed in the actual motor.
    CO_OD_RAM.controlWords.motor2 = 47;
    return true;
}

void Joint::testWrite()
{
    double pos = CO_OD_RAM.actualMotorPositions.motor2;
    std::cout << "that worked actualMotorPos is:" << pos << "\n";
    CO_OD_RAM.actualMotorPositions.motor2 = pos +1;
    
}

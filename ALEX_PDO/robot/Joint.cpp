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
{
    CO_OD_RAM.actualMotorPositions.motor4 = qd;

    cout << "Joint address set to" << CO_OD_RAM.actualMotorPositions.motor4 << "\n";
    //Send off to CANDEV or DIRECTLY Adress
    // if (commCount % 2 == 0)
    // {
    // QUESTION: HOW TO PROPERLY CONSTRUCT dynamic variable names motor<id_goes_here>
    //     CO_OD_RAM.controlWords.motor4 = 47;
    //     CO_OD_RAM.targetMotorPositions.motor4 = qd;
    // }
    // else if (commCount % 2 == 1)
    // {
    //     CO_OD_RAM.controlWords.motor4 = 63;
    // }
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
//// For testing object dictionary
void Joint::updateJoint()
{
    /// Update current joint position from object dictionary
    /// This should be internally mapped from object dictionary
    // Construct obj dictionary entry message for this motor id
    //CO_OD_RAM.actualMotorPositions.motor<id_goes_here>
    q = CO_OD_RAM.actualMotorPositions.motor4;
}
void Joint::testWrite()
{
    double pos = CO_OD_RAM.actualMotorPositions.motor4;
    std::cout << "that worked actualMotorPos is:" << pos << "\n";
    CO_OD_RAM.actualMotorPositions.motor4 = pos +1;
    
}
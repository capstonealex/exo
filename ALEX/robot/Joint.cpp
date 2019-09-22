//
// Created by William Campbell on 2019-07-24.
//

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

    if (q > minq && q < maxq)
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

    cout << "Joint id: " << id << " Go to position: " << qd << "\n";
    //Send off to CANDEV or DIRECTLY Adress
    // if (commCount % 2 == 0)
    // {
    //     CO_OD_RAM.controlWords.motor4 = 47;
    //     CO_OD_RAM.targetMotorPositions.motor4 = lKnee.q;
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
void Joint::updateJoint(int qread)
{
    /// Update current joint position from object dictionary
    /// This should be internally mapped from object dictionary
    // Construct obj dictionary entry message for this motor id
    //CO_OD_RAM.actualMotorPositions.motor<id_goes_here>
    q = qread;
    // cout << "Joint id number " << id << "read in value:" << qread " Thinks it's @ pos " << q << "\n";
}
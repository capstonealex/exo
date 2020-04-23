/**
 * @file Robot.cpp
 * @author Justin Fong
 * @brief Generic Abstract Robot class, which includes joints and a trajectory generator, to be used
 *          with a CAN-based robot device
 * @version 0.1
 * @date 2020-04-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Robot.h"
#include "DebugMacro.h"

Robot::Robot(){
    DEBUG_OUT("Robot object created")} Robot::~Robot()
{
    DEBUG_OUT("Robot object deleted")
}
bool Robot::initialise()
{
    if (initialiseJoints())
    {
        if (initialiseNetwork())
        {
            return true;
        }
    }
    else
        return false;
}

void Robot::updateRobot()
{
    for (auto joint : joints)
        joint->updateValue();
}

void Robot::getStatus()
{
    for (auto joint : joints)
        joint->getStatus();
}

void Robot::getJointStatus(int J_i)
{
    joints[J_i]->getStatus();
}
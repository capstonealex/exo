#include "Robot.h"

Robot::Robot()
{
    int i = 0;
    for (auto joint : joints)
    {
        joint.applyPos(0);
        i++;
    }
}
bool Robot::initialise()
{
    if (initialiseJoints() && initialiseNetwork())
    {
        return true;
    }
    else
        return false;
}
bool Robot::initialiseNetwork()
{
    return true;
}
void Robot::updateRobot()
{
    for (auto joint : joints)
        joint.updateJoint();
}
void Robot::getStatus()
{
    for (auto joint : joints)
        joint.Joint::getStatus();
}
void Robot::getJointStatus(Joint J_i)
{
    J_i.getStatus();
}
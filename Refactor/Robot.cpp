#include "Robot.h"

Robot::Robot()
{
    std::cout << "Robot object created" << std::endl;
    // int i = 0;
    // for (auto joint : joints)
    // {
    //     joint->testSet(0);
    //     i++;
    // }
}
Robot::~Robot()
{
    std::cout << "Robot object deleted" << std::endl;
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
        joint->updateValue();
}
void Robot::getStatus()
{
    for (auto joint : joints)
        joint->Joint::getStatus();
}
void Robot::getJointStatus(Joint J_i)
{
    J_i.getStatus();
}
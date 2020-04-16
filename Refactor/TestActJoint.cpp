/**
 * @file TestActJoint.cpp
 * @author Justin Fong
 * @brief 
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "TestActJoint.h"
TestActJoint::TestActJoint(int jointID, double jointMin, double jointMax, Drive drive) : ActuatedJoint(jointID, jointMin, jointMax, drive)
{
    std::cout << "TestAct Joint created" << std::endl;
    // Do nothing else
}
TestActJoint::~TestActJoint()
{
    std::cout << "TestAct Joint deleted" << std::endl;
}
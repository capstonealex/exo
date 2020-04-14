/**
 * @file testJoints.cpp
 * @author Justin Fong
 * @brief Tests for the Joint, ActuatedJoint, ExoJoint and Drive classes 
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include "Joint.h"
#include "ActuatedJoint.h"
#include "Drive.h"
#include "CopleyDrive.h"
#include "testActJoint.h"

int main() {
    // Construct different types of joints
    CopleyDrive *testDrive = new CopleyDrive(100);
    ActuatedJoint *normalJoint = new TestActJoint(1, -1, 1, *testDrive);

    std::cout << "This is a script to test the implementation of the Joints, ActuatedJoints and Drive Classes! \n";

    std::cout << normalJoint->setPosition(1) << "\n";
    return 0;
}
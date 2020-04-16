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
#include "DummyActJoint.h"

int main() {
    std::cout << "This is a script to test the implementation of the Joints, ActuatedJoints and Drive Classes! \n";
    
    std::cout << "1. Construct a CopleyDrive Object (which implements Drive Class) \n";
    // Construct different types of joints
    Drive *testDrive = new CopleyDrive(100);

    std::cout << "2. Construct a TestActJoint Object (Cast as a ActuatedJoint), using the testDrive Object \n";
    ActuatedJoint *normalJoint = new DummyActJoint(1, -1, 1, testDrive);

    std::cout << "Read the ID of the Joint (Expected Value 1): " << normalJoint->getId() << "\n";
    std::cout << "Read Node ID of the Drive (Expected Value 100): " << testDrive->getNodeID() << "\n";

    std::cout << "Read Value of the Joint (Expected Value 0): " << normalJoint->getQ() << "\n";

    std::cout << "Set the Joint into Position Control Mode: " << normalJoint->setMode(POSITION_CONTROL) << "\n";

    std::cout << "Set the position of the Joint to 1 (expected result: true): "  << normalJoint->setPosition(1) << "\n";

    std::cout << "Read Value of the Joint (Expected Value 0): " << normalJoint->getQ() << "\n";

    std::cout << "Call a updateValue() defined in Joint: " << normalJoint->updateValue() << "\n";

    std::cout << "Read Value of the Joint (Expected Value 1): " << normalJoint->getQ() << "\n";

    return 0;
}
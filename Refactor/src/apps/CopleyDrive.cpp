/**
 * @brief An implementation of the Drive Object, specifically for the Copley Drive
 * 
 */
#include "CopleyDrive.h"

#include <iostream>

#include "DebugMacro.h"

CopleyDrive::CopleyDrive(int NodeID) : Drive::Drive(NodeID) {
    this->NodeID = NodeID;
}
CopleyDrive::~CopleyDrive() {
    DEBUG_OUT(" CopleyDrive Deleted ")
}

bool CopleyDrive::Init() {
    return false;
}

bool CopleyDrive::initPosControl() {
    // TODO: Complete
    //DEBUG_OUT("NodeID " << NodeID << " Initialising Position Control")

    return true;
}

bool CopleyDrive::initVelControl() {
    return true;
}

bool CopleyDrive::initTorqControl() {
    return true;
}

bool CopleyDrive::updateDriveStatus() {
    return true;
}

// Drive State Modifiers
bool CopleyDrive::readyToSwitchOn() {
    return true;
}

bool CopleyDrive::enable() {
    return true;
}

bool CopleyDrive::disable() {
    return true;
}
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
    // TODO: Complete SDO messaging somethin like DRIVE. initNetwork()
    DEBUG_OUT("Copley drive initiPosControl");
    DEBUG_OUT("NodeID " << NodeID << " Initialising Position Control")
    sendSDOMessages(generatePosControlConfigSDO(copleyMotorProfile));
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
std::vector<std::string> CopleyDrive::generatePosControlConfigSDO(motorProfile positionProfile) {
    // Define Vector to be returned as part of this method
    std::vector<std::string> CANCommands;
    // Define stringstream for ease of constructing hex strings
    std::stringstream sstream;
    // start drive
    sstream << "[1] " << NodeID << " start";
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());
    //enable profile position mode
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x6060 << " 0 i8 1";
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    //Set velocity profile
    std::cout << "VARIABLE Velocity " << positionProfile.profileVelocity;
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x6081 << " 0 i32 " << positionProfile.profileVelocity;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    //Set acceleration profile
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x6083 << " 0 i32 " << positionProfile.profileAccelreation;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    //Set deceleration profile
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x6084 << " 0 i32 " << positionProfile.profileDeceleration;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    return CANCommands;
}
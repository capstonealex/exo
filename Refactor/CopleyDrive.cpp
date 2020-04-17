/**
 * @brief An implementation of the Drive Object, specifically for the Copley Drive
 * 
 */
#include "CopleyDrive.h"
#include <iostream>

CopleyDrive::CopleyDrive(int NodeID): Drive::Drive(NodeID){
    this->NodeID = NodeID;
}
CopleyDrive::~CopleyDrive(){
    std::cout << " CopleyDrive Deleted " << std::endl;
}

bool CopleyDrive::Init(){
    return false;
}

bool CopleyDrive::initPosControl(){
    // TODO: Complete 
    std::cout << "NodeID " << NodeID << " Initialising Position Control" << std::endl; 
    return true;
}

bool CopleyDrive::initVelControl(){
    return true;
}

bool CopleyDrive::initTorqControl(){
    return true;
}

bool CopleyDrive::updateDriveStatus(){
    return true;
}

bool CopleyDrive::setPos(int position){
    return true;
}

bool CopleyDrive::setVel(int velocity){
    return true;
}

bool CopleyDrive::setTorque(int torque){
    return true;
}

int CopleyDrive::getPos(){
    return 0;
}

int CopleyDrive::getVel(){
    return 0;
}

int CopleyDrive::getTorque(){
    return 0;
}

// Drive State Modifiers
bool CopleyDrive::readyToSwitchOn(){
    return true;
}

bool CopleyDrive::enable(){
    return true;
}

bool CopleyDrive::disable(){
    return true;
}

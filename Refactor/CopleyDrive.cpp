/**
 * @brief An implementation of the Drive Object, specifically for the Copley Drive
 * 
 */
#include "CopleyDrive.h"

CopleyDrive::CopleyDrive(int NodeID): Drive::Drive(NodeID){
    this->NodeID = NodeID;
}
CopleyDrive::~CopleyDrive(){}

bool CopleyDrive::Init(){
    return false;
}

bool CopleyDrive::initPosControl(){
    // TODO: Complete 
    return false;
}

bool CopleyDrive::initVelControl(){
    return false;
}

bool CopleyDrive::initTorqControl(){
    return false;
}

bool CopleyDrive::updateDriveStatus(){
    return false;
}

bool CopleyDrive::setPos(int position){
    return false;
}

bool CopleyDrive::setVel(int velocity){
    return false;
}

bool CopleyDrive::setTorque(int torque){
    return false;
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
    return false;
}

bool CopleyDrive::enable(){
    return false;
}

bool CopleyDrive::disable(){
    return false;
}

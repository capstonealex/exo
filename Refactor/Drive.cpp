/**
 * @brief General functions for the drive object
 * 
 */
#include "Drive.h"

Drive::Drive(){
    status = 0;
    error = 0;
    this->NodeID = -1;
}

Drive::Drive(int NodeID){
    status = 0;
    error =0;
    this->NodeID = NodeID;
}

int Drive::getNodeID(){
    return NodeID;
}
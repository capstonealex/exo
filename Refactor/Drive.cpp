#include "Drive.h"

#include "DebugMacro.h"

Drive::Drive() {
    status = 0;
    error = 0;
    this->NodeID = -1;
}

Drive::Drive(int NodeID) {
    status = 0;
    error = 0;
    this->NodeID = NodeID;
}

int Drive::getNodeID() {
    return NodeID;
}

bool Drive::setPos(int position) {
    DEBUG_OUT("Drive " << this->NodeID << " Writing " << position << " to 0x607A");
    return true;
}

bool Drive::setVel(int velocity) {
    DEBUG_OUT("Drive " << NodeID << " Writing " << velocity << " to 0x60FF");
    return true;
}

bool Drive::setTorque(int torque) {
    DEBUG_OUT("Drive " << NodeID << " Writing " << torque << " to 0x6071");
    return true;
}

int Drive::getPos() {
    return 0;
}

int Drive::getVel() {
    return 0;
}

int Drive::getTorque() {
    return 0;
}

bool Drive::initPDOs() {
    DEBUG_OUT("Set up STATUS_WORD TPDO")
    sendSDOMessages(generateTPDOConfigSDO({STATUS_WORD}, 1, 0xFF));

    DEBUG_OUT("Set up ACTUAL_POS and ACTUAL_VEL TPDO")
    sendSDOMessages(generateTPDOConfigSDO({ACTUAL_POS, ACTUAL_VEL}, 2, 1));

    DEBUG_OUT("Set up ACTUAL_TOR TPDO")
    sendSDOMessages(generateTPDOConfigSDO({ACTUAL_TOR}, 3, 1));

    DEBUG_OUT("Set up TARGET_POS RPDO")
    sendSDOMessages(generateRPDOConfigSDO({TARGET_POS}, 1, 0xff));

    DEBUG_OUT("Set up TARGET_VEL RPDO")
    sendSDOMessages(generateRPDOConfigSDO({TARGET_VEL}, 2, 0xff));

    return true;
}

std::vector<std::string> Drive::generateTPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_Num, int SyncRate) {
    // TODO: Do a check to make sure that the OD_Entry_t items can be transmitted.

    // Calculate COB_ID. If TPDO:
    int COB_ID = 0x100 * PDO_Num + 0x80 + NodeID;

    // Define Vector to be returned as part of this method
    std::vector<std::string> CANCommands;

    // Define stringstream for ease of constructing hex strings
    std::stringstream sstream;

    // Disable PDO
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_Num - 1 << " 1 u32 0x" << std::hex << 0x800000000 + COB_ID;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Set so that there no PDO items, enable mapping change
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_Num - 1 << " 0 u8 0";
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Set the PDO so that it triggers every SYNC Message
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_Num - 1 << " 2 u8 0x" << SyncRate;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    for (int i = 1; i <= items.size(); i++) {
        // Set transmit parameters
        sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_Num - 1 << " " << i << " u32 0x" << std::hex << OD_Addresses[items[i - 1]] * 0x10000 + OD_Data_Size[items[i - 1]];
        CANCommands.push_back(sstream.str());
        sstream.str(std::string());
    }

    // Sets Number of PDO items to reenable
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_Num - 1 << " 0 u8 " << items.size();
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Enable  PDO
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_Num - 1 << " 1 u32 0x" << std::hex << COB_ID;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    return CANCommands;
}

std::vector<std::string> Drive::generateRPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_Num, int UpdateTiming) {
    // TODO: Do a check to make sure that the OD_Entry_t items can be Received.

    // Calculate COB_ID. If TPDO:
    int COB_ID = 0x100 * PDO_Num + NodeID;

    // Define Vector to be returned as part of this method
    std::vector<std::string> CANCommands;

    // Define stringstream for ease of constructing hex strings

    std::stringstream sstream;
    // Disable PDO
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_Num - 1 << " 1 u32 0x" << std::hex << 0x800000000 + COB_ID;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Set so that there no PDO items, enable mapping change
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_Num - 1 << " 0 u8 0";
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Set the PDO so that it triggers every SYNC Message
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_Num - 1 << " 2 u8 0x" << UpdateTiming;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    for (int i = 1; i <= items.size(); i++) {
        // Set transmit parameters
        sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_Num - 1 << " " << i << " u32 0x" << std::hex << OD_Addresses[items[i - 1]] * 0x10000 + OD_Data_Size[items[i - 1]];
        CANCommands.push_back(sstream.str());
        sstream.str(std::string());
    }

    // Sets Number of PDO items to reenable
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_Num - 1 << " 0 u8 " << items.size();
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    // Enable  PDO
    sstream << "[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_Num - 1 << " 1 u32 0x" << std::hex << COB_ID;
    CANCommands.push_back(sstream.str());
    sstream.str(std::string());

    return CANCommands;
}

int Drive::sendSDOMessages(std::vector<std::string> messages) {
    char *returnMessage;
    int successfulMessages = 0;
    for (auto strCommand : messages) {
        //cancomm_socketFree(strCommand[i].c_str(), returnMessage);
        DEBUG_OUT(strCommand.c_str())

        //TEST THIS - SEG FAULT OCCURS
        /*if (strcmp(returnMessage, "OK") == 0)
        {
            successfulMessages++;
        }*/
    }
    return successfulMessages;
}

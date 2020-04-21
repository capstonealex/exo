#include "Drive.h"
#include "DebugMacro.h"

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

bool Drive::initPDOs(){
    DEBUG_OUT("Set up STATUS_WORD TPDO")
    generateTPDOConfigSDO({STATUS_WORD}, 1, 0xFF);

    DEBUG_OUT("Set up ACTUAL_POS and ACTUAL_VEL TPDO")
    generateTPDOConfigSDO({ACTUAL_POS, ACTUAL_VEL}, 2, 1);

    DEBUG_OUT("Set up ACTUAL_TOR TPDO")
    generateTPDOConfigSDO({ACTUAL_TOR}, 3, 1);

    DEBUG_OUT("Set up TARGET_POS RPDO")
    generateRPDOConfigSDO({TARGET_POS}, 1, 1);

    DEBUG_OUT("Set up TARGET_VEL RPDO")
    generateRPDOConfigSDO({TARGET_VEL}, 2, 1);

    return true;
}

std::string Drive::generateTPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_NUM, int SyncRate){
    // TODO: Do a check to make sure that the OD_Entry_t items can be transmitted. 

    // Calculate COB_ID. If TPDO:
    int COB_ID = 0x100*PDO_NUM + 0x80 + NodeID;    
    
    // Disable PDO 
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_NUM-1 << " 1 u32 0x" <<  std::hex << 0x800000000 + COB_ID)

    // Set so that there no PDO items, enable mapping change
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_NUM-1 << " 0 u8 0")

    // Set the PDO so that it triggers every SYNC Message
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_NUM-1 << " 2 u8 0x" <<  SyncRate)

    for (int i = 1; i <= items.size(); i++){
        // Set transmit parameters
        DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_NUM-1 << " " <<  i << " u32 0x" << std::hex << OD_Addresses[items[i-1]]*0x10000 + OD_Data_Size[items[i-1]])
    }

    // Sets Number of PDO items to reenable
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1A00 + PDO_NUM-1 << " 0 u8 " << items.size())

    // Enable  PDO
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1800 + PDO_NUM-1 << " 1 u32 0x" <<  std::hex << COB_ID)

    return "testString";
}


std::string Drive::generateRPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_NUM, int UpdateTiming){
    // TODO: Do a check to make sure that the OD_Entry_t items can be Received. 



    // Calculate COB_ID. If TPDO:
    int COB_ID = 0x100*PDO_NUM  + NodeID;
    
    // Disable PDO 
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_NUM-1 << " 1 u32 0x" <<  std::hex << 0x800000000 + COB_ID)

    // Set so that there no PDO items, enable mapping change
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_NUM-1 << " 0 u8 0")

    // Set the PDO so that it triggers every SYNC Message
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_NUM-1 << " 2 u8 0x" <<  UpdateTiming)

    for (int i = 1; i <= items.size(); i++){
        // Set transmit parameters
        DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_NUM-1 << " " <<  i << " u32 0x" << std::hex << OD_Addresses[items[i-1]]*0x10000 + OD_Data_Size[items[i-1]])
    }

    // Sets Number of PDO items to reenable
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1600 + PDO_NUM-1 << " 0 u8 " << items.size())

    // Enable  PDO
    DEBUG_OUT("[1] " << NodeID << " write 0x" << std::hex << 0x1400 + PDO_NUM-1 << " 1 u32 0x" <<  std::hex << COB_ID)

    return "testString";
}
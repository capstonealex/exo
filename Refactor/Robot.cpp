#include "Robot.h"

Robot::Robot()
{
    disablePosControl();
    // Array version
    // for (auto i = 0; i < NUM_JOINTS; i++)
    // {
    //     joints[i].applyPos(0);
    //     joints[i].setId(i + 1);
    // }
    // Vector version
    int i = 0;
    for (auto joint : joints)
    {
        joint.applyPos(0);
        joint.setId(i + 1);
        i++;
    }
}
bool Robot::initialise()
{
}
void Robot::printInfo()
{
    cout << "This is an X2 robot with: \n";
    // Array version
    // for (auto i = 0; i < NUM_JOINTS; i++)
    // {
    //     // cout << "Joint address:" << &joints[i] << endl;
    //     this->joints[i].printInfo();
    // }
    // Vector version
    for (auto joint : joints)
        joint.printInfo();
}

void Robot::updateRobot()
{
    // array version
    // for (auto i = 0; i < NUM_JOINTS; i++)
    // {
    //     joints[i].updateJoint();
    // }
    //Vector version
    for (auto joint : joints)
        joint.updateJoint();
}
void Robot::configurePosControl()
{
    this->positionControlConfigured = true;
}
void Robot::disablePosControl()
{
    this->positionControlConfigured = false;
}

/****************************************************************/
/****************************************************************/
// sdo Messaging functions
// TODO: change to INDIVIDUAL MOTOR DRIVE
// bool Robot::sdoMSG(void)
// {
//     char *returnMessage;
//     char SDO_Message[CANMESSAGELENGTH];
//     strcpy(SDO_Message, "[1] 100 read 0x1017 0 i16");
//     cancomm_socketFree(SDO_Message, returnMessage);
//     printf("Heart beat read!\n");
//     return true;
// }

// bool Robot::initPositionControl(void)
// {
//     char *returnMessage;
//     char SDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 1 start",
//         "[1] 2 start",
//         "[1] 3 start",
//         "[1] 4 start",
//         "[1] 2 write 0x6060 0 i8 1",
//         "[1] 1 write 0x6060 0 i8 1",
//         "[1] 3 write 0x6060 0 i8 1",
//         "[1] 4 write 0x6060 0 i8 1",
//         "[1] 2 write 0x6081 0 i32 4000000",
//         "[1] 1 write 0x6081 0 i32 4000000",
//         "[1] 3 write 0x6081 0 i32 4000000",
//         "[1] 4 write 0x6081 0 i32 4000000",
//         "[1] 2 write 0x6083 0 i32 240000",
//         "[1] 1 write 0x6083 0 i32 240000",
//         "[1] 3 write 0x6083 0 i32 240000",
//         "[1] 4 write 0x6083 0 i32 240000",
//         "[1] 2 write 0x6084 0 i32 240000",
//         "[1] 1 write 0x6084 0 i32 240000",
//         "[1] 3 write 0x6084 0 i32 240000",
//         "[1] 4 write 0x6084 0 i32 240000"};
//     if (!positionControlConfigured)
//     {
//         int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
//         for (int i = 0; i < num_of_Messages; ++i)
//         {
//             cancomm_socketFree(SDO_MessageList[i], returnMessage);
//         }
//         positionControlConfigured = true;
//         printf("Motors configured for position control\n");
//         return true;
//     }
//     else
//     {
//         printf("WARNING:::: Position Control already configured\n");
//         return false;
//     }
// }
// bool Robot::initPositionControlAnkles(void)
// {
//     char *returnMessage;
//     char SDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 5 start",
//         "[1] 6 start",
//         "[1] 5 write 0x6060 0 i8 1",
//         "[1] 6 write 0x6060 0 i8 1",
//         "[1] 5 write 0x6081 0 i32 300000",
//         "[1] 6 write 0x6081 0 i32 300000",
//         "[1] 5 write 0x6083 0 i32 10000000",
//         "[1] 6 write 0x6083 0 i32 10000000",
//         "[1] 5 write 0x6084 0 i32 10000000",
//         "[1] 6 write 0x6084 0 i32 10000000",
//         "[1] 5 write 0x6040 0 i16 6",
//         "[1] 5 write 0x6040 0 i16 15",
//         "[1] 6 write 0x6040 0 i16 6",
//         "[1] 6 write 0x6040 0 i16 15",
//     };
//     int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);

//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         cancomm_socketFree(SDO_MessageList[i], returnMessage);
//     }
//     printf("Motors configured for position control\n");
//     return true;
// }

// bool Robot::remapPDO(void)
// {
//     char *returnMessage;
//     char PDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 1 write 0x1801 1 u32 0x80000281",
//         "[1] 2 write 0x1801 1 u32 0x80000282",
//         "[1] 3 write 0x1801 1 u32 0x80000283",
//         "[1] 4 write 0x1801 1 u32 0x80000284",
//         "[1] 1 write 0x1A01 0 u8 0",
//         "[1] 1 write 0x1801 2 u8 1",
//         "[1] 1 write 0x1A01 1 u32 0x60640020",
//         "[1] 1 write 0x1A01 2 u32 0x606C0020",
//         "[1] 1 write 0x1A01 0 u8 2",
//         "[1] 2 write 0x1A01 0 u8 0",
//         "[1] 2 write 0x1801 2 u8 1",
//         "[1] 2 write 0x1A01 1 u32 0x60640020",
//         "[1] 2 write 0x1A01 2 u32 0x606C0020",
//         "[1] 2 write 0x1A01 0 u8 2",
//         "[1] 3 write 0x1A01 0 u8 0",
//         "[1] 3 write 0x1801 2 u8 1",
//         "[1] 3 write 0x1A01 1 u32 0x60640020",
//         "[1] 3 write 0x1A01 2 u32 0x606C0020",
//         "[1] 3 write 0x1A01 0 u8 2",
//         "[1] 4 write 0x1A01 0 u8 0",
//         "[1] 4 write 0x1801 2 u8 1",
//         "[1] 4 write 0x1A01 1 u32 0x60640020",
//         "[1] 4 write 0x1A01 2 u32 0x606C0020",
//         "[1] 4 write 0x1A01 0 u8 2",
//         "[1] 1 write 0x1801 1 u32 0x281",
//         "[1] 2 write 0x1801 1 u32 0x282",
//         "[1] 3 write 0x1801 1 u32 0x283",
//         "[1] 4 write 0x1801 1 u32 0x284",
//         "[1] 1 write 0x1800 1 u32 0x80000181",
//         "[1] 2 write 0x1800 1 u32 0x80000182",
//         "[1] 3 write 0x1800 1 u32 0x80000183",
//         "[1] 4 write 0x1800 1 u32 0x80000184",
//         "[1] 1 write 0x1A00 0 u8 0",
//         "[1] 1 write 0x1800 2 u8 0xFF",
//         "[1] 1 write 0x1A00 1 u32 0x60410010",
//         "[1] 1 write 0x1A00 0 u8 1",
//         "[1] 2 write 0x1A00 0 u8 0",
//         "[1] 2 write 0x1800 2 u8 0xFF",
//         "[1] 2 write 0x1A00 1 u32 0x60410010",
//         "[1] 2 write 0x1A00 0 u8 1",
//         "[1] 3 write 0x1A00 0 u8 0",
//         "[1] 3 write 0x1800 2 u8 0xFF",
//         "[1] 3 write 0x1A00 1 u32 0x60410010",
//         "[1] 3 write 0x1A00 0 u8 1",
//         "[1] 4 write 0x1A00 0 u8 0",
//         "[1] 4 write 0x1800 2 u8 0xFF",
//         "[1] 4 write 0x1A00 1 u32 0x60410010",
//         "[1] 4 write 0x1A00 0 u8 1",
//         "[1] 1 write 0x1800 1 u32 0x181",
//         "[1] 2 write 0x1800 1 u32 0x182",
//         "[1] 3 write 0x1800 1 u32 0x183",
//         "[1] 4 write 0x1800 1 u32 0x184",
//         "[1] 1 write 0x1802 1 u32 0x80000381",
//         "[1] 2 write 0x1802 1 u32 0x80000382",
//         "[1] 3 write 0x1802 1 u32 0x80000383",
//         "[1] 4 write 0x1802 1 u32 0x80000384",
//         "[1] 1 write 0x1A02 0 u8 0",
//         "[1] 1 write 0x1802 2 u8 0x01",
//         "[1] 1 write 0x1A02 1 u32 0x60770010",
//         "[1] 1 write 0x1A02 0 u8 1",
//         "[1] 2 write 0x1A02 0 u8 0",
//         "[1] 2 write 0x1802 2 u8 0x01",
//         "[1] 2 write 0x1A02 1 u32 0x60770010",
//         "[1] 2 write 0x1A02 0 u8 1",
//         "[1] 3 write 0x1A02 0 u8 0",
//         "[1] 3 write 0x1802 2 u8 0x01",
//         "[1] 3 write 0x1A02 1 u32 0x60770010",
//         "[1] 3 write 0x1A02 0 u8 1",
//         "[1] 4 write 0x1A02 0 u8 0",
//         "[1] 4 write 0x1802 2 u8 0x01",
//         "[1] 4 write 0x1A02 1 u32 0x60770010",
//         "[1] 4 write 0x1A02 0 u8 1",
//         "[1] 1 write 0x1802 1 u32 0x381",
//         "[1] 2 write 0x1802 1 u32 0x382",
//         "[1] 3 write 0x1802 1 u32 0x383",
//         "[1] 4 write 0x1802 1 u32 0x384",
//         "[1] 1 write 0x1401 1 u32 0x80000301",
//         "[1] 2 write 0x1401 1 u32 0x80000302",
//         "[1] 3 write 0x1401 1 u32 0x80000303",
//         "[1] 4 write 0x1401 1 u32 0x80000304",
//         "[1] 1 write 0x1601 0 u8 0",
//         "[1] 1 write 0x1401 2 u8 0xFF",
//         "[1] 1 write 0x1601 1 u32 0x607A0020",
//         "[1] 1 write 0x1601 0 u8 1",
//         "[1] 2 write 0x1601 0 u8 0",
//         "[1] 2 write 0x1401 2 u8 0xFF",
//         "[1] 2 write 0x1601 1 u32 0x607A0020",
//         "[1] 2 write 0x1601 0 u8 1",
//         "[1] 3 write 0x1601 0 u8 0",
//         "[1] 3 write 0x1401 2 u8 0xFF",
//         "[1] 3 write 0x1601 1 u32 0x607A0020",
//         "[1] 3 write 0x1601 0 u8 1",
//         "[1] 4 write 0x1601 0 u8 0",
//         "[1] 4 write 0x1401 2 u8 0xFF",
//         "[1] 4 write 0x1601 1 u32 0x607A0020",
//         "[1] 4 write 0x1601 0 u8 1",
//         "[1] 1 write 0x1401 1 u32 0x301",
//         "[1] 2 write 0x1401 1 u32 0x302",
//         "[1] 3 write 0x1401 1 u32 0x303",
//         "[1] 4 write 0x1401 1 u32 0x304",
//         "[1] 1 write 0x1402 1 u32 0x80000401",
//         "[1] 2 write 0x1402 1 u32 0x80000402",
//         "[1] 3 write 0x1402 1 u32 0x80000403",
//         "[1] 4 write 0x1402 1 u32 0x80000404",
//         "[1] 1 write 0x1602 0 u8 0",
//         "[1] 1 write 0x1402 2 u8 0xFF",
//         "[1] 1 write 0x1602 1 u32 0x60FF0020",
//         "[1] 1 write 0x1602 0 u8 1",
//         "[1] 2 write 0x1602 0 u8 0",
//         "[1] 2 write 0x1402 2 u8 0xFF",
//         "[1] 2 write 0x1602 1 u32 0x60FF0020",
//         "[1] 2 write 0x1602 0 u8 1",
//         "[1] 3 write 0x1602 0 u8 0",
//         "[1] 3 write 0x1402 2 u8 0xFF",
//         "[1] 3 write 0x1602 1 u32 0x60FF0020",
//         "[1] 3 write 0x1602 0 u8 1",
//         "[1] 4 write 0x1602 0 u8 0",
//         "[1] 4 write 0x1402 2 u8 0xFF",
//         "[1] 4 write 0x1602 1 u32 0x60FF0020",
//         "[1] 4 write 0x1602 0 u8 1",
//         "[1] 1 write 0x1402 1 u32 0x401",
//         "[1] 2 write 0x1402 1 u32 0x402",
//         "[1] 3 write 0x1402 1 u32 0x403",
//         "[1] 4 write 0x1402 1 u32 0x404",
//         "[1] 1 start",
//         "[1] 2 start",
//         "[1] 3 start",
//         "[1] 4 start",
//         "[1] 1 write 0x6040 0 i16 0",
//         "[1] 2 write 0x6040 0 i16 0",
//         "[1] 3 write 0x6040 0 i16 0",
//         "[1] 4 write 0x6040 0 i16 0"};
//     int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         cancomm_socketFree(PDO_MessageList[i], returnMessage);
//     }
//     return true;
// }

// bool Robot::remapPDOAnkles(void)
// {
//     char *returnMessage;
//     char PDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 5 write 0x1801 1 u32 0x80000285",
//         "[1] 5 write 0x1A01 0 u8 0",
//         "[1] 5 write 0x1801 2 u8 1",
//         "[1] 5 write 0x1A01 1 u32 0x60640020",
//         "[1] 5 write 0x1A01 2 u32 0x606C0020",
//         "[1] 5 write 0x1A01 0 u8 2",
//         "[1] 5 write 0x1801 1 u32 0x285",
//         "[1] 5 write 0x1800 1 u32 0x80000185",
//         "[1] 5 write 0x1A00 0 u8 0",
//         "[1] 5 write 0x1800 2 u8 0xFF",
//         "[1] 5 write 0x1A00 1 u32 0x60410010",
//         "[1] 5 write 0x1A00 0 u8 1",
//         "[1] 5 write 0x1800 1 u32 0x185",
//         "[1] 5 write 0x1401 1 u32 0x80000305",
//         "[1] 5 write 0x1601 0 u8 0",
//         "[1] 5 write 0x1401 2 u8 0xFF",
//         "[1] 5 write 0x1601 1 u32 0x607A0020",
//         "[1] 5 write 0x1601 0 u8 1",
//         "[1] 5 write 0x1401 1 u32 0x305",
//         "[1] 5 write 0x1402 1 u32 0x80000405",
//         "[1] 5 write 0x1602 0 u8 0",
//         "[1] 5 write 0x1402 2 u8 0xFF",
//         "[1] 5 write 0x1602 1 u32 0x60FF0020",
//         "[1] 5 write 0x1602 0 u8 1",
//         "[1] 5 write 0x1402 1 u32 0x405",
//         "[1] 5 start",
//         "[1] 6 write 0x1801 1 u32 0x80000286",
//         "[1] 6 write 0x1A01 0 u8 0",
//         "[1] 6 write 0x1801 2 u8 1",
//         "[1] 6 write 0x1A01 1 u32 0x60640020",
//         "[1] 6 write 0x1A01 2 u32 0x606C0020",
//         "[1] 6 write 0x1A01 0 u8 2",
//         "[1] 6 write 0x1801 1 u32 0x286",
//         "[1] 6 write 0x1800 1 u32 0x80000186",
//         "[1] 6 write 0x1A00 0 u8 0",
//         "[1] 6 write 0x1800 2 u8 0xFF",
//         "[1] 6 write 0x1A00 1 u32 0x60410010",
//         "[1] 6 write 0x1A00 0 u8 1",
//         "[1] 6 write 0x1800 1 u32 0x186",
//         "[1] 6 write 0x1401 1 u32 0x80000306",
//         "[1] 6 write 0x1601 0 u8 0",
//         "[1] 6 write 0x1401 2 u8 0xFF",
//         "[1] 6 write 0x1601 1 u32 0x607A0020",
//         "[1] 6 write 0x1601 0 u8 1",
//         "[1] 6 write 0x1401 1 u32 0x306",
//         "[1] 6 write 0x1402 1 u32 0x80000406",
//         "[1] 6 write 0x1602 0 u8 0",
//         "[1] 6 write 0x1402 2 u8 0xFF",
//         "[1] 6 write 0x1602 1 u32 0x60FF0020",
//         "[1] 6 write 0x1602 0 u8 1",
//         "[1] 6 write 0x1402 1 u32 0x406",
//         "[1] 6 start"};
//     int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         //printf("%s     ", PDO_MessageList[i]);
//         cancomm_socketFree(PDO_MessageList[i], returnMessage);
//     }
//     return true;
// }

// bool Robot::preop(void)
// {
//     char *returnMessage;
//     char PDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 1 preop",
//         "[1] 2 preop",
//         "[1] 3 preop",
//         "[1] 4 preop",
//         "[1] 5 preop",
//         "[1] 6 preop"};
//     int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
//     //    printf("Num of messages: %d\n", num_of_Messages);
//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         cancomm_socketFree(PDO_MessageList[i], returnMessage);
//     }
//     return true;
// }

// bool Robot::resetTrackingError(void)
// {
//     char *returnMessage;
//     char PDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 1 write 0x2183 0 i32 512",
//         "[1] 2 write 0x2183 0 i32 512",
//         "[1] 3 write 0x2183 0 i32 512",
//         "[1] 4 write 0x2183 0 i32 512"};
//     int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
//     //    printf("Num of messages: %d\n", num_of_Messages);
//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         cancomm_socketFree(PDO_MessageList[i], returnMessage);
//     }
//     return true;
// }
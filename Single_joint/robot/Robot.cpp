//
// Created by William Campbell on 2019-07-23.
//

#include "Robot.h"
#include "CO_command.h"
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#define CANMESSAGELENGTH (100)

Robot::Robot()
{
    positionControl = 0;
    cout << "Setting Robot joint initial conditions...\n";
    // Set joint Intial positions.
    joints[0].applyPos(0);
    joints[1].applyPos(0);
    joints[2].applyPos(0);
    joints[3].applyPos(0);
    // Set joint IDs
    joints[0].setId(1);
    joints[1].setId(2);
    joints[2].setId(3);
    joints[3].setId(4);
};
void Robot::printInfo()
{
    cout << "This is an X2 robot with: \n";
    for (auto i = 0; i < 4; i++)
    {
        joints[i].printInfo();
    }
}
void Robot::jointIncrement()
{
    int current;
    for (auto i = 0; i < 4; i++)
    {
        current = joints[i].getPos();
        current = current + 1;
        joints[i].applyPos(current);
    }
}
// Update all of this robots software joint positions from object dictionary
void Robot::updateJoints()
{
    for (auto i = 0; i < 4; i++)
    {
        joints[i].updateJoint();
    }
}
bool Robot::sdoMSG(void)
{
    char *returnMessage;
    char SDO_Message[CANMESSAGELENGTH];
    strcpy(SDO_Message, "[1] 100 read 0x1017 0 i16");
    cancomm_socketFree(SDO_Message, returnMessage);
    printf("HEart beat read!\n");
    return true;
}
bool Robot::homeCalibration(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 start",
        "[1] 2 start",
        "[1] 3 start",
        "[1] 4 start",
        "[1] 2 write 0x6060 0 i8 1",
        "[1] 1 write 0x6060 0 i8 1",
        "[1] 3 write 0x6060 0 i8 1",
        "[1] 4 write 0x6060 0 i8 1",
        "[1] 2 write 0x6081 0 i32 200000",
        "[1] 1 write 0x6081 0 i32 200000",
        "[1] 3 write 0x6081 0 i32 200000",
        "[1] 4 write 0x6081 0 i32 200000",
        "[1] 2 write 0x6083 0 i32 30000",
        "[1] 1 write 0x6083 0 i32 30000",
        "[1] 3 write 0x6083 0 i32 30000",
        "[1] 4 write 0x6083 0 i32 30000",
        "[1] 2 write 0x6084 0 i32 30000",
        "[1] 1 write 0x6084 0 i32 30000",
        "[1] 3 write 0x6084 0 i32 30000",
        "[1] 4 write 0x6084 0 i32 30000",
        "[1] 1 read 0x6063 0 i32",
        "[1] 2 read 0x6063 0 i32",
        "[1] 3 read 0x6063 0 i32",
        "[1] 4 read 0x6063 0 i32",
        "[1] 2 write 0x607A 0 i32 -280000",
        "[1] 1 write 0x607A 0 i32 115000",
        "[1] 4 write 0x607A 0 i32 -280000",
        "[1] 3 write 0x607A 0 i32 115000",
        "[1] 2 write 0x6040 0 i16 47",
        "[1] 2 write 0x6040 0 i16 63",
        "[1] 2 write 0x6040 0 i16 47",
        "[1] 1 write 0x6040 0 i16 47",
        "[1] 1 write 0x6040 0 i16 63",
        "[1] 1 write 0x6040 0 i16 47",
        "[1] 4 write 0x6040 0 i16 47",
        "[1] 4 write 0x6040 0 i16 63",
        "[1] 4 write 0x6040 0 i16 47",
        "[1] 3 write 0x6040 0 i16 47",
        "[1] 3 write 0x6040 0 i16 63",
        "[1] 3 write 0x6040 0 i16 47"};

    int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    sleep(10);
    // TODO: Change sleep to check that we reached home
    printf("Home motion complete\n");
    char *returnMessageB;
    char SDO_MessageListB[][CANMESSAGELENGTH] = {
        "[1] 1 read 0x6063 0 i32",
        "[1] 2 read 0x6063 0 i32",
        "[1] 3 read 0x6063 0 i32",
        "[1] 4 read 0x6063 0 i32",
        "[1] 2 write 0x6060 0 i8 6",
        "[1] 1 write 0x6060 0 i8 6",
        "[1] 3 write 0x6060 0 i8 6",
        "[1] 4 write 0x6060 0 i8 6 ",
        "[1] 2 write 0x6098 0 i8 0",
        "[1] 1 write 0x6098 0 i8 0",
        "[1] 3 write 0x6098 0 i8 0",
        "[1] 4 write 0x6098 0 i8 0",
        "[1] 2 write 0x607C 0 i32 0",
        "[1] 1 write 0x607C 0 i32 0",
        "[1] 3 write 0x607C 0 i32 0",
        "[1] 4 write 0x607C 0 i32 0",
        "[1] 1 write 0x607D 1 i32 - 110000",
        "[1] 1 write 0x607D 2 i32 310000",
        "[1] 2 write 0x607D 1 i32 2000",
        "[1] 2 write 0x607D 2 i32 280000",
        "[1] 3 write 0x607D 1 i32 -110000",
        "[1] 3 write 0x607D 2 i32 310000",
        "[1] 4 write 0x607D 1 i32 2000",
        "[1] 4 write 0x607D 2 i32 280000",
        "[1] 2 write 0x6040 0 i16 15",
        "[1] 2 write 0x6040 0 i16 31",
        "[1] 2 write 0x6040 0 i16 15",
        "[1] 4 write 0x6040 0 i16 15",
        "[1] 4 write 0x6040 0 i16 31",
        "[1] 4 write 0x6040 0 i16 15",
        "[1] 3 write 0x6040 0 i16 15",
        "[1] 3 write 0x6040 0 i16 31",
        "[1] 3 write 0x6040 0 i16 15",
        "[1] 1 write 0x6040 0 i16 15",
        "[1] 1 write 0x6040 0 i16 31",
        "[1] 1 write 0x6040 0 i16 15"};
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageListB[i], returnMessageB);
    }
    printf("Zeroing drives complete\n");
    return true;
}
bool Robot::initPositionControl(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 start",
        "[1] 2 start",
        "[1] 3 start",
        "[1] 4 start",
        "[1] 2 write 0x6060 0 i8 1",
        "[1] 1 write 0x6060 0 i8 1",
        "[1] 3 write 0x6060 0 i8 1",
        "[1] 4 write 0x6060 0 i8 1",
        "[1] 2 write 0x6081 0 i32 800000",
        "[1] 1 write 0x6081 0 i32 800000",
        "[1] 3 write 0x6081 0 i32 800000",
        "[1] 4 write 0x6081 0 i32 800000",
        "[1] 2 write 0x6083 0 i32 60000",
        "[1] 1 write 0x6083 0 i32 60000",
        "[1] 3 write 0x6083 0 i32 60000",
        "[1] 4 write 0x6083 0 i32 60000",
        "[1] 2 write 0x6084 0 i32 60000",
        "[1] 1 write 0x6084 0 i32 60000",
        "[1] 3 write 0x6084 0 i32 60000",
        "[1] 4 write 0x6084 0 i32 60000"};
    int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    printf("Motors configured for position control\n");
    return true;
}
bool Robot::initVelocityControl(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 start",
        "[1] 2 start",
        "[1] 2 write 0x6060 0 i8 3",
        "[1] 1 write 0x6060 0 i8 3",
        "[1] 2 write 0x6083 0 i32 30000",
        "[1] 1 write 0x6083 0 i32 30000",
        "[1] 2 write 0x6084 0 i32 30000",
        "[1] 1 write 0x6084 0 i32 30000"};

    int num_of_Messages = sizeof(SDO_MessageList)/sizeof(SDO_MessageList[0]);
    for(int i = 0; i < num_of_Messages; i++){
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    printf("initVelocity Control complete!\n");
    return true;
    

}

bool Robot::remapPDO(void){
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
            "[1] 1 write 0x1801 1 u32 0x80000281",
            "[1] 2 write 0x1801 1 u32 0x80000282",
            "[1] 3 write 0x1801 1 u32 0x80000283",
            "[1] 4 write 0x1801 1 u32 0x80000284",
            "[1] 1 write 0x1A01 0 u8 0",
            "[1] 1 write 0x1801 2 u8 1",
            "[1] 1 write 0x1A01 1 u32 0x60640020",
            "[1] 1 write 0x1A01 2 u32 0x606C0020",
            "[1] 1 write 0x1A01 0 u8 2",
            "[1] 2 write 0x1A01 0 u8 0",
            "[1] 2 write 0x1801 2 u8 1",
            "[1] 2 write 0x1A01 1 u32 0x60640020",
            "[1] 2 write 0x1A01 2 u32 0x606C0020",
            "[1] 2 write 0x1A01 0 u8 2",
            "[1] 3 write 0x1A01 0 u8 0",
            "[1] 3 write 0x1801 2 u8 1",
            "[1] 3 write 0x1A01 1 u32 0x60640020",
            "[1] 3 write 0x1A01 2 u32 0x606C0020",
            "[1] 3 write 0x1A01 0 u8 2",
            "[1] 4 write 0x1A01 0 u8 0",
            "[1] 4 write 0x1801 2 u8 1",
            "[1] 4 write 0x1A01 1 u32 0x60640020",
            "[1] 4 write 0x1A01 2 u32 0x606C0020",
            "[1] 4 write 0x1A01 0 u8 2",
            "[1] 1 write 0x1801 1 u32 0x281",
            "[1] 2 write 0x1801 1 u32 0x282",
            "[1] 3 write 0x1801 1 u32 0x283",
            "[1] 4 write 0x1801 1 u32 0x284",
            "[1] 1 write 0x1800 1 u32 0x80000181",
            "[1] 2 write 0x1800 1 u32 0x80000182",
            "[1] 3 write 0x1800 1 u32 0x80000183",
            "[1] 4 write 0x1800 1 u32 0x80000184",
            "[1] 1 write 0x1A00 0 u8 0",
            "[1] 1 write 0x1800 2 u8 0xFF",
            "[1] 1 write 0x1A00 1 u32 0x60410010",
            "[1] 1 write 0x1A00 0 u8 1",
            "[1] 2 write 0x1A00 0 u8 0",
            "[1] 2 write 0x1800 2 u8 0xFF",
            "[1] 2 write 0x1A00 1 u32 0x60410010",
            "[1] 2 write 0x1A00 0 u8 1",
            "[1] 3 write 0x1A00 0 u8 0",
            "[1] 3 write 0x1800 2 u8 0xFF",
            "[1] 3 write 0x1A00 1 u32 0x60410010",
            "[1] 3 write 0x1A00 0 u8 1",
            "[1] 4 write 0x1A00 0 u8 0",
            "[1] 4 write 0x1800 2 u8 0xFF",
            "[1] 4 write 0x1A00 1 u32 0x60410010",
            "[1] 4 write 0x1A00 0 u8 1",
            "[1] 1 write 0x1800 1 u32 0x181",
            "[1] 2 write 0x1800 1 u32 0x182",
            "[1] 3 write 0x1800 1 u32 0x183",
            "[1] 4 write 0x1800 1 u32 0x184",
            "[1] 1 write 0x1800 1 u32 0x80000381",
            "[1] 2 write 0x1800 1 u32 0x80000382",
            "[1] 3 write 0x1800 1 u32 0x80000383",
            "[1] 4 write 0x1800 1 u32 0x80000384",
            "[1] 1 write 0x1A00 0 u8 0",
            "[1] 1 write 0x1800 2 u8 0x01",
            "[1] 1 write 0x1A00 1 u32 0x60770010",
            "[1] 1 write 0x1A00 0 u8 1",
            "[1] 2 write 0x1A00 0 u8 0",
            "[1] 2 write 0x1800 2 u8 0x01",
            "[1] 2 write 0x1A00 1 u32 0x60770010",
            "[1] 2 write 0x1A00 0 u8 1",
            "[1] 3 write 0x1A00 0 u8 0",
            "[1] 3 write 0x1800 2 u8 0x01",
            "[1] 3 write 0x1A00 1 u32 0x60770010",
            "[1] 3 write 0x1A00 0 u8 1",
            "[1] 4 write 0x1A00 0 u8 0",
            "[1] 4 write 0x1800 2 u8 0x01",
            "[1] 4 write 0x1A00 1 u32 0x60770010",
            "[1] 4 write 0x1A00 0 u8 1",
            "[1] 1 write 0x1800 1 u32 0x381",
            "[1] 2 write 0x1800 1 u32 0x382",
            "[1] 3 write 0x1800 1 u32 0x383",
            "[1] 4 write 0x1800 1 u32 0x384",
            "[1] 1 write 0x1401 1 u32 0x80000301",
            "[1] 2 write 0x1401 1 u32 0x80000302",
            "[1] 3 write 0x1401 1 u32 0x80000303",
            "[1] 4 write 0x1401 1 u32 0x80000304",
            "[1] 1 write 0x1601 0 u8 0",
            "[1] 1 write 0x1401 2 u8 0xFF",
            "[1] 1 write 0x1601 1 u32 0x607A0020",
            "[1] 1 write 0x1601 0 u8 1",
            "[1] 2 write 0x1601 0 u8 0",
            "[1] 2 write 0x1401 2 u8 0xFF",
            "[1] 2 write 0x1601 1 u32 0x607A0020",
            "[1] 2 write 0x1601 0 u8 1",
            "[1] 3 write 0x1601 0 u8 0",
            "[1] 3 write 0x1401 2 u8 0xFF",
            "[1] 3 write 0x1601 1 u32 0x607A0020",
            "[1] 3 write 0x1601 0 u8 1",
            "[1] 4 write 0x1601 0 u8 0",
            "[1] 4 write 0x1401 2 u8 0xFF",
            "[1] 4 write 0x1601 1 u32 0x607A0020",
            "[1] 4 write 0x1601 0 u8 1",
            "[1] 1 write 0x1401 1 u32 0x301",
            "[1] 2 write 0x1401 1 u32 0x302",
            "[1] 3 write 0x1401 1 u32 0x303",
            "[1] 4 write 0x1401 1 u32 0x304",
            "[1] 1 write 0x1402 1 u32 0x80000401",
            "[1] 2 write 0x1402 1 u32 0x80000402",
            "[1] 3 write 0x1402 1 u32 0x80000403",
            "[1] 4 write 0x1402 1 u32 0x80000404",
            "[1] 1 write 0x1602 0 u8 0",
            "[1] 1 write 0x1402 2 u8 0xFF",
            "[1] 1 write 0x1602 1 u32 0x60FF0020",
            "[1] 1 write 0x1602 0 u8 1",
            "[1] 2 write 0x1602 0 u8 0",
            "[1] 2 write 0x1402 2 u8 0xFF",
            "[1] 2 write 0x1602 1 u32 0x60FF0020",
            "[1] 2 write 0x1602 0 u8 1",
            "[1] 3 write 0x1602 0 u8 0",
            "[1] 3 write 0x1402 2 u8 0xFF",
            "[1] 3 write 0x1602 1 u32 0x60FF0020",
            "[1] 3 write 0x1602 0 u8 1",
            "[1] 4 write 0x1602 0 u8 0",
            "[1] 4 write 0x1402 2 u8 0xFF",
            "[1] 4 write 0x1602 1 u32 0x60FF0020",
            "[1] 4 write 0x1602 0 u8 1",
            "[1] 1 write 0x1402 1 u32 0x401",
            "[1] 2 write 0x1402 1 u32 0x402",
            "[1] 3 write 0x1402 1 u32 0x403",
            "[1] 4 write 0x1402 1 u32 0x404",
            "[1] 1 start",
            "[1] 2 start",
            "[1] 3 start",
            "[1] 4 start",
            "[1] 1 write 0x6040 0 i16 0",
            "[1] 2 write 0x6040 0 i16 0",
            "[1] 3 write 0x6040 0 i16 0",
            "[1] 4 write 0x6040 0 i16 0"
    };
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
//    printf("Num of messages: %d\n", num_of_Messages);
    for (int i = 0; i < num_of_Messages; ++i){
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;

}
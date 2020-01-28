//
// Created by William Campbell on 2019-07-23.
//

#include "Robot.h"
#include "CO_command.h"
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <cmath>

#define CANMESSAGELENGTH (100)
#define NOFLIP (100)

Robot::Robot()
{
    positionControlConfigured = false;
    cout << "Setting Robot joint initial conditions...\n";
    // Set joint Intial positions.

    // // Set joint Intial positions to 0, Set joint IDs, Populate joint Trajectories
    for (auto i = 0; i < 6; i++)
    {
        joints[i].applyPos(0);
        joints[i].setId(i + 1);
    }
}
void Robot::printInfo()
{
    cout << "This is an X2 robot with: \n";
    for (auto i = 0; i < 6; i++)
    {
        joints[i].printInfo();
    }
}

// Update all of this robots software joint positions from object dictionary
void Robot::updateJoints()
{
    for (auto i = 0; i < 6; i++)
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
    printf("Heart beat read!\n");
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

    sleep(5);
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
        "[1] 2 write 0x6081 0 i32 2000000",
        "[1] 1 write 0x6081 0 i32 2000000",
        "[1] 3 write 0x6081 0 i32 2000000",
        "[1] 4 write 0x6081 0 i32 2000000",
        "[1] 2 write 0x6083 0 i32 100000",
        "[1] 1 write 0x6083 0 i32 100000",
        "[1] 3 write 0x6083 0 i32 100000",
        "[1] 4 write 0x6083 0 i32 100000",
        "[1] 2 write 0x6084 0 i32 100000",
        "[1] 1 write 0x6084 0 i32 100000",
        "[1] 3 write 0x6084 0 i32 100000",
        "[1] 4 write 0x6084 0 i32 100000"};
    if (!positionControlConfigured)
    {
        int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
        for (int i = 0; i < num_of_Messages; ++i)
        {
            cancomm_socketFree(SDO_MessageList[i], returnMessage);
        }
        positionControlConfigured = true;
        printf("Motors configured for position control\n");
        return true;
    }
    else
    {
        printf("WARNING:::: Position Control already configured\n");
        return false;
    }
}
bool Robot::initPositionControlAnkles(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 5 start",
        "[1] 6 start",
        "[1] 5 write 0x6060 0 i8 1",
        "[1] 6 write 0x6060 0 i8 1",
        "[1] 5 write 0x6081 0 i32 300000",
        "[1] 6 write 0x6081 0 i32 300000",
        "[1] 5 write 0x6083 0 i32 10000000",
        "[1] 6 write 0x6083 0 i32 10000000",
        "[1] 5 write 0x6084 0 i32 10000000",
        "[1] 6 write 0x6084 0 i32 10000000",
        "[1] 5 write 0x6040 0 i16 6",
        "[1] 5 write 0x6040 0 i16 15",
        "[1] 6 write 0x6040 0 i16 6",
        "[1] 6 write 0x6040 0 i16 15",
    };
    int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    printf("Motors configured for position control\n");
    return true;
}

bool Robot::remapPDO(void)
{
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
        "[1] 4 write 0x6040 0 i16 0"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::remapPDOAnkles(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 5 write 0x1801 1 u32 0x80000285",
        "[1] 5 write 0x1A01 0 u8 0",
        "[1] 5 write 0x1801 2 u8 1",
        "[1] 5 write 0x1A01 1 u32 0x60640020",
        "[1] 5 write 0x1A01 2 u32 0x606C0020",
        "[1] 5 write 0x1A01 0 u8 2",
        "[1] 5 write 0x1801 1 u32 0x285",
        "[1] 5 write 0x1800 1 u32 0x80000185",
        "[1] 5 write 0x1A00 0 u8 0",
        "[1] 5 write 0x1800 2 u8 0xFF",
        "[1] 5 write 0x1A00 1 u32 0x60410010",
        "[1] 5 write 0x1A00 0 u8 1",
        "[1] 5 write 0x1800 1 u32 0x185",
        "[1] 5 write 0x1401 1 u32 0x80000305",
        "[1] 5 write 0x1601 0 u8 0",
        "[1] 5 write 0x1401 2 u8 0xFF",
        "[1] 5 write 0x1601 1 u32 0x607A0020",
        "[1] 5 write 0x1601 0 u8 1",
        "[1] 5 write 0x1401 1 u32 0x305",
        "[1] 5 write 0x1402 1 u32 0x80000405",
        "[1] 5 write 0x1602 0 u8 0",
        "[1] 5 write 0x1402 2 u8 0xFF",
        "[1] 5 write 0x1602 1 u32 0x60FF0020",
        "[1] 5 write 0x1602 0 u8 1",
        "[1] 5 write 0x1402 1 u32 0x405",
        "[1] 5 start",
        "[1] 6 write 0x1801 1 u32 0x80000286",
        "[1] 6 write 0x1A01 0 u8 0",
        "[1] 6 write 0x1801 2 u8 1",
        "[1] 6 write 0x1A01 1 u32 0x60640020",
        "[1] 6 write 0x1A01 2 u32 0x606C0020",
        "[1] 6 write 0x1A01 0 u8 2",
        "[1] 6 write 0x1801 1 u32 0x286",
        "[1] 6 write 0x1800 1 u32 0x80000186",
        "[1] 6 write 0x1A00 0 u8 0",
        "[1] 6 write 0x1800 2 u8 0xFF",
        "[1] 6 write 0x1A00 1 u32 0x60410010",
        "[1] 6 write 0x1A00 0 u8 1",
        "[1] 6 write 0x1800 1 u32 0x186",
        "[1] 6 write 0x1401 1 u32 0x80000306",
        "[1] 6 write 0x1601 0 u8 0",
        "[1] 6 write 0x1401 2 u8 0xFF",
        "[1] 6 write 0x1601 1 u32 0x607A0020",
        "[1] 6 write 0x1601 0 u8 1",
        "[1] 6 write 0x1401 1 u32 0x306",
        "[1] 6 write 0x1402 1 u32 0x80000406",
        "[1] 6 write 0x1602 0 u8 0",
        "[1] 6 write 0x1402 2 u8 0xFF",
        "[1] 6 write 0x1602 1 u32 0x60FF0020",
        "[1] 6 write 0x1602 0 u8 1",
        "[1] 6 write 0x1402 1 u32 0x406",
        "[1] 6 start"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        //printf("%s     ", PDO_MessageList[i]);
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::preop(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 preop",
        "[1] 2 preop",
        "[1] 3 preop",
        "[1] 4 preop",
        "[1] 5 preop",
        "[1] 6 preop"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    //    printf("Num of messages: %d\n", num_of_Messages);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::resetTrackingError(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 write 0x2183 0 i32 512",
        "[1] 2 write 0x2183 0 i32 512",
        "[1] 3 write 0x2183 0 i32 512",
        "[1] 4 write 0x2183 0 i32 512"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    //    printf("Num of messages: %d\n", num_of_Messages);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

void Robot::startNewTraj()
{
    // Reset the time
    timerclear(&moving_tv);
    timerclear(&stationary_tv);
    gettimeofday(&start_traj, NULL);
    last_tv = start_traj;

    // Set the bit flip state to zero
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        joints[i].setBitFlipState(NOFLIP);
    }

    // Index Resetting
    desiredIndex = 0;
    fracTrajProgress = 0;

    printf("Start New Traj \n");
}

void Robot::moveThroughTraj(double (*trajFunction)(int, double))
{
    //long lastTarget = 0;
    struct timeval tv;
    struct timeval tv_diff;
    struct timeval tv_changed;
    gettimeofday(&tv, NULL);
    timersub(&tv, &last_tv, &tv_diff);
    last_tv = tv;

    //uint32_t difftime =  tv_diff.tv_sec*1000000+tv_diff.tv_usec;
    long movingMicro = moving_tv.tv_sec * 1000000 + moving_tv.tv_usec;

    double trajTimeUS = trajTime * 1000000;
    fracTrajProgress = movingMicro / trajTimeUS;
    /*If gButton -> else commented out until button code integrated as object*/
    /*if Green Button is pressed, move through trajetory. Otherwise stay where you are*/
    int gButton = 0;
        if (!gButton)
        {
            timeradd(&moving_tv, &tv_diff, &tv_changed);
            moving_tv = tv_changed;

            printf("Time: %3f \n", fracTrajProgress);

    #ifndef _NOACTUATION
            for (int i = 0; i < NUM_JOINTS; i++)
            {
                if (joints[i].getBitFlipState() == NOFLIP)
                {
                    // Send a new trajectory point
                    // Get Trajectory point for this joint based on current time
                    double desiredPos = (*trajFunction)(i, fracTrajProgress);
                    //printf("%d, %3f \n", i, desiredPos );
                    joints[i].applyPosDeg(desiredPos);

                    // set state machine bitFlip to LOW state.
                    joints[i].bitflipLow();
                }
                else
                {
                    joints[i].bitflipHigh();
                }
            }
    #endif
        }
        else
        {
            timeradd(&stationary_tv, &tv_diff, &tv_changed);
            stationary_tv = tv_changed;
        }
}

// Trajectory functions
// From input array of points, getInterpolatedPoints outputs an interpolated point
// @ the given time instance from the array.

double Robot::getInterpolatedPoint(std::array<double, TRAJ_LENGTH> points, double scaledTime)
{
    int length = points.size();
    double fractInd = scaledTime * (length - 1);
    int down = floor(fractInd);

    if (scaledTime >= 1)
    {
        return points[length - 1];
    }
    else if (scaledTime <= 0)
    {
        return points[0];
    }
    else
    {
        return points[down] + (fractInd - down) * (points[down + 1] - points[down]);
    }
}
double Robot::sittingTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(stationarySittingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(stationarySittingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(stationarySittingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(stationarySittingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(stationarySittingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(stationarySittingAnkleTraj, scaledTime);
    }

    return desPos;
}

double Robot::standUpTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(standingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(standingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(standingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(standingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(standingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(standingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::sitDownTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(sittingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(sittingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(sittingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(sittingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(sittingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(sittingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingFirstLeftTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(firstSwingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(firstStanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(firstSwingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(firstStanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(firstSwingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(firstStanceAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingRightTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(stanceKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(swingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(stanceHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(swingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(stanceAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(swingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLeftTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(stanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(swingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(stanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(swingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(stanceAnkleTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(swingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLastRightTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(lastSwingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(lastStanceKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(lastSwingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(lastStanceHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastSwingAnkleTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastStanceAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLastLeftTrajFunc(int jointInd, double scaledTime)
{
    int jointID = joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(lastSwingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(lastStanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(lastSwingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(lastStanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastSwingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastStanceAnkleTraj, scaledTime);
    }
    return desPos;
}
double Robot::getSteptime()
{
    return steptime;
}
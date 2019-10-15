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
        "[1] 4 write 0x6084 0 i32 30000"};
    int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    printf("Motors configured for position control\n");
    return true;
}


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
// bool Robot::initPositionControl(void)
// {
//     char *returnMessage;
//     char SDO_MessageList[][CANMESSAGELENGTH] = {
//         "[1] 1 start",
//         "[1] 2 start",
//         "[1] 2 write 0x6060 0 i8 1",
//         "[1] 1 write 0x6060 0 i8 1",
//         "[1] 2 write 0x6081 0 i32 200000",
//         "[1] 1 write 0x6081 0 i32 200000",
//         "[1] 2 write 0x6083 0 i32 30000",
//         "[1] 1 write 0x6083 0 i32 30000",
//         "[1] 2 write 0x6084 0 i32 30000",
//         "[1] 1 write 0x6084 0 i32 30000"};

//     int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
//     for (int i = 0; i < num_of_Messages; ++i)
//     {
//         cancomm_socketFree(SDO_MessageList[i], returnMessage);
//     }
//     printf("initPosition Control complete!\n");
//     return true;
// }
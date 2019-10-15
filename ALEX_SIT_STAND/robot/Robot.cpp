//
// Created by William Campbell on 2019-07-23.
//

#include "Robot.h"
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>

Robot::Robot(){
    cout<<"Setting Robot joint initial conditions...\n";
    // Set joint Intial positions.
    joints[0].applyPos(30);
    joints[1].applyPos(60);
    joints[2].applyPos(30);
    joints[3].applyPos(60);
    // Set joint IDs
    joints[0].setId(1);
    joints[1].setId(2);
    joints[2].setId(3);
    joints[3].setId(4);
};
void Robot::printInfo() {
    cout<<"This is an X2 robot with: \n";
    for (auto i=0; i<4 ;i++) {
        joints[i].printInfo();
    }
}
void Robot::jointIncrement() {
    int current;
    for (auto i=0; i<4 ;i++) {
        current = joints[i].getPos();
        current = current +1;
        joints[i].applyPos(current);
    }
}
// Creates a socket connection to canopend using a pointer to int socket
// void Robot::canFeastUp(int *canSocket)
// {
//     char *socketPath = ((char *)"/tmp/CO_command_socket"); /* Name of the local domain socket, configurable by arguments. */
//     struct sockaddr_un addr;

//     *canSocket = socket(AF_UNIX, SOCK_STREAM, 0);
//     if (*canSocket == -1)
//     {
//         perror("Socket creation failed");
//         exit(EXIT_FAILURE);
//     }
//     memset(&addr, 0, sizeof(struct sockaddr_un));
//     addr.sun_family = AF_UNIX;
//     strncpy(addr.sun_path, socketPath, sizeof(addr.sun_path) - 1);
//     // Try to make a connection to the local UNIT AF_UNIX SOCKET, quit if unavailable
//     if (connect(*canSocket, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
//     {
//         perror("Socket connection failed");
//         exit(EXIT_FAILURE);
//     }
// }
// void Robot::canFeastDown(int *canSocket)
// {
//     printf("closing socket...\n");
//     //close socket
//     close(*canSocket);
//     printf("socket close\n");
// }
// void Robot::canFeast(int *canSocket, char *command, char *canReturnMessage)
// {
//     int commandLength = strlen(command);
//     size_t n;
//     char buf[BUF_SIZE];

//     if (write(*canSocket, command, commandLength) != commandLength)
//     {
//         perror("Socket write failed");
//         exit(EXIT_FAILURE);
//     }

//     n = read(*canSocket, buf, sizeof(buf));
//     if (n == -1)
//     {
//         perror("Socket read failed");
//         close(*canSocket);
//         exit(EXIT_FAILURE);
//     }
//     //printf("%s", buf);
//     strcpy(canReturnMessage, buf);
// }
// Error handling -> reset socket and try again when sockets fail.
//void canFeastErrorHandler(int *canSocket, char *command, char *canReturnMessage)
//{
//    int commandLength = strlen(command);
//    int recconects;
//    size_t n;
//    char buf[BUF_SIZE];
//
//    if (write(*canSocket, command, commandLength) != commandLength)
//    {
//        perror("Socket write failed, attempting again");
//        canFeast(canSocket, command, canReturnMessage);
//    }
//    while ((write(*canSocket, command, commandLength) != commandLength) && recconects != MAX_RECONNECTS)
//    {
//        perror("Socket write failed, attempting again");
//        //shut down socket
//        canFeastDown(canSocket);
//        //recreate socket
//        canFeastUp(canSocket);
//        recconects++;
//        // try to send again
//    }
//
//    n = read(*canSocket, buf, sizeof(buf));
//    if (n == -1)
//    {
//        perror("Socket read failed, attempting to send command again");
//        //shut down socket
//        canFeastDown(canSocket);
//        //recreate socket
//        canFeastUp(canSocket);
//        // try to send again
//        canFeast(canSocket, command, canReturnMessage);
//        exit(EXIT_FAILURE);
//    }
//    printf("%s", buf);
//    strcpy(canReturnMessage, buf);
//}

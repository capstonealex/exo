///
//// Created by William Campbell on 2019-07-01.
//// ALEX EXOSKELETON MULTITHREAD ROBOTIC MAIN
////
#include "Robot.h"

/* Helper functions */
void initexo(Robot& robot);
const int NUM_JOINTS = 4;
//const int STRING_LENGTH =50;
const int NUM_POLLS = 30;
int main() {
    Robot X2;
    initexo(X2);
    X2.printInfo();
    //Start sockets with canopend
    //Used to store the canReturnMessage. Not used currently, hence called junk.
    //Should pass this to calling function for possible error handling.
    int n = 0;
    std::string currentPos;
    while(n<NUM_POLLS) {
        for (auto i=0; i<4 ;i++) {
            currentPos = X2.joints[i].getPos();
            std::cout << "current motor pos:" << currentPos;
        }
    }
    return 0;
}


void initexo(Robot& X2){
    // Initialize canOpenBBB node through canOpend, bind socket w/ parser callback.
//    const int NUM_JOINTS = 4;
    ////    Initialize robot
/*   X2.printInfo();*/
    ////    initialize all joints to Current read position (STATE) or homing sequence?
    float position = 90.0;
    std:: cout<<"----------Reading actual joint pos and internalizing----------\n";
    for (auto x=0;x< NUM_JOINTS;x++){
        X2.joints[x].applyPos(position);
        position+=15.0;
    }
}

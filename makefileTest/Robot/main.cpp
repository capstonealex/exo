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
//
//    int n = 0;
//    float currentPos;
//    while(n<NUM_POLLS) {
//        for (auto i=0; i<4 ;i++) {
//            X2.joints[i].printInfo();
////            std::cout << "current motor pos:" << currentPos<< "\n";
//        }
//    }
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

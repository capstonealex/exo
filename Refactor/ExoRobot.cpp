#include "ExoRobot.h"

ExoRobot::ExoRobot() {
    // Creates all the joints based
    if (initialise()) {
        cout << "ExoRobot object created" << endl;
        trajectoryGenerator.setPilotParameter(exoParams);
        trajectoryGenerator.setTrajectoryParameter(movementTrajMap[INITIAL]);
    } else {
        cout << "ExoRobot failed to initialise" << endl;
    }
}
ExoRobot::~ExoRobot() {
    std::cout << "Delete exoRobot object begins" << std::endl;
    for (auto p : joints) {
        std::cout << "Delete Joint ID: " << p->getId();
        delete p;
    }
    joints.clear();
    for (auto p : copleyDrives) {
        std::cout << "Delete Drive Node: " << p->getNodeID();
        delete p;
    }
    copleyDrives.clear();
    cout << "ExoRobot deleted" << endl;
};

bool ExoRobot::initPositionControl() {
    std::cout << "Initialising Position Control on all joints " << std::endl;
    bool returnValue = true;
    for (auto p : joints) {
        if (((ActuatedJoint *)p)->setMode(POSITION_CONTROL) != POSITION_CONTROL) {
            // Something bad happened
            returnValue = false;
        }
    }
    return returnValue;
}

void ExoRobot::startNewTraj() {
    printf("Start New Traj \n");
}
bool ExoRobot::moveThroughTraj() {
    bool returnValue = true;
    for (auto p : joints) {
        setMovementReturnCode_t setPosCode = ((ActuatedJoint *)p)->setPosition(100);
        if (setPosCode == INCORRECT_MODE) {
            std::cout << "Joint " << p->getId() << ": is not in Position Control " << std::endl;
            returnValue = false;
        } else if (setPosCode != SUCCESS) {
            // Something bad happened
            std::cout << "Joint " << p->getId() << ": Unknown Error " << std::endl;
            returnValue = false;
        }
    }
    return returnValue;
}

void ExoRobot::setTrajectory() {
    std::cout << ">>>> Set Trajectory" << std::endl;
    //TODO: LOAD FROM CURRENTMOTION variable or from OD access?
    int currentMotion = NORMALWALK;
    trajectoryGenerator.setTrajectoryParameter(movementTrajMap[currentMotion]);
}
void ExoRobot::printTrajectoryParam() {
    std::cout << "Step height:" << trajectoryGenerator.trajectoryParameter.step_height << std::endl;
    std::cout << "Slop_angle: " << trajectoryGenerator.trajectoryParameter.slope_angle << std::endl;
}
bool ExoRobot::initialiseJoints() {
    for (int id = 0; id < NUM_JOINTS; id++) {
        copleyDrives.push_back(new CopleyDrive(id + 1));
        joints.push_back(new DummyActJoint(id, jointMinMap[id], jointMaxMap[id], copleyDrives[id]));
    }
    return true;
}

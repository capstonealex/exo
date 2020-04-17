#include "ExoRobot.h"
#include "DebugMacro.h"


ExoRobot::ExoRobot() {
    // Creates all the joints based
    if (initialise()) {
        DEBUG_OUT("ExoRobot object created")
        trajectoryGenerator.setPilotParameter(exoParams);
        trajectoryGenerator.setTrajectoryParameter(movementTrajMap[INITIAL]);
    } else {
        cout << "ExoRobot failed to initialise" << endl;
    }
}
ExoRobot::~ExoRobot() {
    DEBUG_OUT("Delete ExoRobot object begins")
    freeMemory();
    joints.clear();
    copleyDrives.clear();
    DEBUG_OUT("ExoRobot deleted")
};

bool ExoRobot::initPositionControl() {
    DEBUG_OUT( "Initialising Position Control on all joints " )
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
    DEBUG_OUT("Start New Traj");
}
bool ExoRobot::moveThroughTraj() {
    bool returnValue = true;
    for (auto p : joints) {
        // Calculate the position for each of these joints
        double jointPos = 100 + p->getId(); 
        setMovementReturnCode_t setPosCode = ((ActuatedJoint *)p)->setPosition(jointPos);
        if (setPosCode == INCORRECT_MODE) {
            std::cout << "Joint ID " << p->getId() << ": is not in Position Control " << std::endl;
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
    DEBUG_OUT("Set Trajectory")
    //TODO: LOAD FROM CURRENTMOTION variable or from OD access?
    int currentMotion = NORMALWALK;
    trajectoryGenerator.setTrajectoryParameter(movementTrajMap[currentMotion]);
}
void ExoRobot::printTrajectoryParam() {
    std::cout << "Step height:" << trajectoryGenerator.trajectoryParameter.step_height << std::endl;
    std::cout << "Slope angle: " << trajectoryGenerator.trajectoryParameter.slope_angle << std::endl;
}
bool ExoRobot::initialiseJoints() {
    for (int id = 0; id < NUM_JOINTS; id++) {
        copleyDrives.push_back(new CopleyDrive(id + 1));
        joints.push_back(new DummyActJoint(id, jointMinMap[id], jointMaxMap[id], copleyDrives[id]));

    }
    return true;
}
bool ExoRobot::initialiseNetwork() {
    bool status;
    for (auto joint : joints) {
        status = joint->initNetwork();
        if (!status)
            return false;
    }
    return true;
}
void ExoRobot::freeMemory() {
    /*for (vector<Joint *>::iterator pObj = joints.begin();
         pObj != joints.end(); ++pObj) {
        delete *pObj;  // Note that this is deleting what pObj points to,
                       // which is a pointer
    }
    for (vector<CopleyDrive *>::iterator pObj = copleyDrives.begin();
         pObj != copleyDrives.end(); ++pObj) {
        delete *pObj;  // Note that this is deleting what pObj points to,
                       // which is a pointer
    }*/

    for (auto p : joints) {
        DEBUG_OUT("Delete Joint ID: " << p->getId())
        delete p;
    }
    for (auto p : copleyDrives) {
        DEBUG_OUT("Delete Drive Node: " << p->getNodeID())
        delete p;
    }
}

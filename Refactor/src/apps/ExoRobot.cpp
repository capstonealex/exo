#include "ExoRobot.h"

#include "DebugMacro.h"

ExoRobot::ExoRobot() {
    // Constructs the Trajectory Generator
    trajectoryGenerator = new ALEXTrajectoryGenerator();

    // Creates all the joints
    if (initialise()) {
        DEBUG_OUT("ExoRobot object created")
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setPilotParameter(exoParams);
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameter(movementTrajMap[INITIAL]);
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
    DEBUG_OUT("Initialising Position Control on all joints ")
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
    setTrajectory();
    /*
    // Index Resetting
    fracTrajProgress = 0;
    TrajectoryGenerator::jointspace_state startNewTrajJointspace;

    double robotJointspace[NUM_JOINTS];
    int j = 0;
    for (auto joint : joints) {
        robotJointspace[j] = deg2rad(joint.getQ);
        j++;
    }

    cout << "joints position at start traj" << endl;
    printInfo();
    startNewTrajJointspace = {.q = {robotJointspace[0],
                                    robotJointspace[1],
                                    robotJointspace[2],
                                    robotJointspace[3],
                                    deg2rad(85),   //robotJointspace[4],
                                    deg2rad(85)},  //robotJointspace[5]},
                              .time = 0};

    trajectoryGenerator.generateAndSaveSpline(startNewTrajJointspace);

    trajectoryGenerator.startTrajectory();*/
}

bool ExoRobot::moveThroughTraj() {
    bool returnValue = true;
    for (auto p : joints) {
        // Calculate the position for each of these joints
        double jointPos = rand() % 100;
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
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameter(movementTrajMap[STNDUP]);
}
void ExoRobot::setSpecificTrajectory(int traj) {
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameter(movementTrajMap[traj]);
}
void ExoRobot::printTrajectoryParam() {
    std::cout << "Step height:" << ((ALEXTrajectoryGenerator *)trajectoryGenerator)->trajectoryParameter.step_height << std::endl;
    std::cout << "Slope angle: " << ((ALEXTrajectoryGenerator *)trajectoryGenerator)->trajectoryParameter.slope_angle << std::endl;
}

bool ExoRobot::initialiseJoints() {
    for (int id = 0; id < NUM_JOINTS; id++) {
        copleyDrives.push_back(new CopleyDrive(id + 1));
        joints.push_back(new DummyActJoint(id, jointMinMap[id], jointMaxMap[id], copleyDrives[id]));
    }
    return true;
}

bool ExoRobot::initialiseNetwork() {
    DEBUG_OUT("ExoRobot::initialiseNetwork()")
    bool status;
    for (auto joint : joints) {
        status = joint->initNetwork();
        if (!status)
            return false;
    }
    return true;
}
bool ExoRobot::initialiseInputs() {
    inputs.push_back(new Keyboard());
    return true;
}
void ExoRobot::freeMemory() {
    keyboard.~Keyboard();
    for (auto p : joints) {
        DEBUG_OUT("Delete Joint ID: " << p->getId())
        delete p;
    }
    for (auto p : copleyDrives) {
        DEBUG_OUT("Delete Drive Node: " << p->getNodeID())
        delete p;
    }
}
void ExoRobot::updateRobot() {
    Robot::updateRobot();
    keyboard.updateInput();
}
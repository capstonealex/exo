#include "ExoRobot.h"

#include "DebugMacro.h"

ExoRobot::ExoRobot() {
    // Constructs the Trajectory Generator
    trajectoryGenerator = new ALEXTrajectoryGenerator();

    // Creates all the joints
    if (initialise()) {
        DEBUG_OUT("ExoRobot object created")
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setPilotParameters(exoParams);
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameters(movementTrajMap[RobotMode::INITIAL]);
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

    jointspace_state initialPose;
    for (int i = 0; i < NUM_JOINTS; i++)
        initialPose.q[i] = 0;
    initialPose.time = 0;

    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->initialiseTrajectory(RobotMode::STNDUP, initialPose);

    // Index Resetting
    currTrajProgress = 0;
    clock_gettime(CLOCK_MONOTONIC, &prevTime);
}

bool ExoRobot::moveThroughTraj() {
    bool returnValue = true;
    timespec currTime;
    clock_gettime(CLOCK_MONOTONIC, &currTime);
    long elapsedns = (currTime.tv_sec - prevTime.tv_sec) * 1000000000 + currTime.tv_nsec - prevTime.tv_nsec;
    prevTime = currTime;

    // Pretend trajectories take 10 seconds
    time_tt fracProgress = elapsedns / (double)10000000000;
    currTrajProgress += fracProgress;
    DEBUG_OUT("Elapsed Time: " << currTrajProgress)

    double positions[NUM_JOINTS];
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->calcPosition(currTrajProgress, positions);

    DEBUG_OUT("After function call")

    for (auto p : joints) {
        // Calculate the position for each of these joints

        double jointPos = positions[p->getId()];

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
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameters(movementTrajMap[RobotMode::STNDUP]);
}

void ExoRobot::setSpecificTrajectory(RobotMode mode) {
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameters(movementTrajMap[mode]);
}
void ExoRobot::printTrajectoryParam() {
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->printTrajectoryParameters();
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
#include "ExoRobot.h"

#include "DebugMacro.h"

ExoRobot::ExoRobot() {
    // Constructs the Trajectory Generator
    trajectoryGenerator = new ALEXTrajectoryGenerator();
}
ExoRobot::~ExoRobot() {
    DEBUG_OUT("Delete ExoRobot object begins")
    freeMemory();
    joints.clear();
    copleyDrives.clear();
    DEBUG_OUT("ExoRobot deleted")
};

void ExoRobot::start() {
    if (initialise()) {
        DEBUG_OUT("ExoRobot object created")
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setPilotParameters(exoParams);
        ((ALEXTrajectoryGenerator *)trajectoryGenerator)->setTrajectoryParameters(movementTrajMap[RobotMode::INITIAL]);
    } else {
        cout << "ExoRobot failed to initialise" << endl;
    }
};
bool ExoRobot::initPositionControl() {
    DEBUG_OUT("Initialising Position Control on all joints ")
    bool returnValue = true;
    for (auto p : joints) {
        if (((ActuatedJoint *)p)->setMode(POSITION_CONTROL, posControlMotorProfile) != POSITION_CONTROL) {
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
#ifndef NOROBOT
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->initialiseTrajectory(RobotMode::STNDUP, initialPose);
#endif
    // Index Resetting
    currTrajProgress = 0;
    clock_gettime(CLOCK_MONOTONIC, &prevTime);
}

bool ExoRobot::moveThroughTraj() {
    bool returnValue = false;
    // Only progress through trajectory if user presses A
    timespec currTime;
    clock_gettime(CLOCK_MONOTONIC, &currTime);

    double elapsedSec = currTime.tv_sec - prevTime.tv_sec + (currTime.tv_nsec - prevTime.tv_nsec) / 1e9;
    prevTime = currTime;

    // Pretend trajectories take 10 seconds
    time_tt fracProgress = elapsedSec / 10;
    currTrajProgress += fracProgress;
    DEBUG_OUT("Elapsed Time: " << currTrajProgress)
#ifdef NOROBOT
    // testing w/o robot and use of calcPosition to create test virtual positions
    // positions @ any point in time = elapsedSec*10
    double testPos = elapsedSec;
    double positions[NUM_JOINTS];
    for (int i = 0; i < NUM_JOINTS; i++) {
        positions[i] = testPos + i;
    }
    if (currTrajProgress >= 10)
        returnValue = true;
#endif
#ifndef NOROBOT
    ((ALEXTrajectoryGenerator *)trajectoryGenerator)->calcPosition(currTrajProgress, positions);
#endif
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
    DEBUG_OUT("ExoRobot::initialiseNetwork()");
#ifndef NOROBOT
    bool status;
    for (auto joint : joints) {
        status = joint->initNetwork();
        if (!status)
            return false;
    }
#endif
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
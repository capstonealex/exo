//
// Created by William Campbell on 2019-07-30.
//

#ifndef CANOPENBEAGLE_ROBOT_H
#define CANOPENBEAGLE_ROBOT_H
#include "Joint.h"
#include <array>
// Trajectory constants
#define TRAJ_LENGTH 6
#define SITSTANDTIME 2
#define STEPTIME 2
#define NUM_JOINTS 4

#define STANCE_END_KNEE 8
#define SWING_END_KNEE 20

#define STANCE_END_HIP 180
#define SWING_END_HIP 150

#define STANCE_END_ANKLE 80
#define SWING_END_ANKLE 100

#define SIT_KNEE_ANGLE 80
#define SIT_HIP_ANGLE 105
#define SIT_ANKLE_ANGLE 100

#define STAND_KNEE_ANGLE 8
#define STAND_HIP_ANGLE 170
#define STAND_ANKLE_ANGLE 95

class Robot
{
private:
    bool positionControlConfigured;
    int desiredIndex = 0;
    double steptime = STEPTIME;
    //Stationary Sitting Traj
    std::array<double, TRAJ_LENGTH> stationarySittingKneeTraj = {
        SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE};
    std::array<double, TRAJ_LENGTH> stationarySittingHipTraj = {
        SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE};
    std::array<double, TRAJ_LENGTH> stationarySittingAnkleTraj = {
        SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE};

    // Trajectories for Sitting
    std::array<double, TRAJ_LENGTH> sittingKneeTraj = {
        STAND_KNEE_ANGLE,
        15,
        30,
        54,
        72,
        SIT_KNEE_ANGLE};
    std::array<double, TRAJ_LENGTH> sittingHipTraj = {
        STAND_HIP_ANGLE,
        165,
        150,
        125,
        110,
        SIT_HIP_ANGLE};
    std::array<double, TRAJ_LENGTH> sittingAnkleTraj = {
        STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE,
        SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE};

    // Trajectories for Standing
    std::array<double, TRAJ_LENGTH> standingKneeTraj = {
        SIT_KNEE_ANGLE,
        72,
        54,
        30,
        15,
        STAND_KNEE_ANGLE};
    std::array<double, TRAJ_LENGTH> standingHipTraj = {
        SIT_HIP_ANGLE,
        110,
        125,
        150,
        165,
        STAND_HIP_ANGLE};
    std::array<double, TRAJ_LENGTH> standingAnkleTraj = {
        SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE,
        STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE};

    //Trajectories for First Step
    std::array<double, TRAJ_LENGTH> firstSwingKneeTraj = {
        STAND_KNEE_ANGLE,
        50,
        80,
        80,
        41,
        SWING_END_KNEE};
    std::array<double, TRAJ_LENGTH> firstSwingHipTraj = {
        STAND_HIP_ANGLE,
        140,
        130,
        120,
        120,
        SWING_END_HIP};
    std::array<double, TRAJ_LENGTH> firstSwingAnkleTraj = {
        STAND_ANKLE_ANGLE,
        90,
        90,
        90,
        90,
        SWING_END_ANKLE};

    std::array<double, TRAJ_LENGTH> firstStanceKneeTraj = {
        STAND_KNEE_ANGLE,
        8,
        8,
        8,
        8,
        STANCE_END_KNEE};
    std::array<double, TRAJ_LENGTH> firstStanceHipTraj = {
        STAND_HIP_ANGLE,
        170,
        170,
        170,
        175,
        STANCE_END_HIP};
    std::array<double, TRAJ_LENGTH> firstStanceAnkleTraj = {
        STAND_ANKLE_ANGLE,
        90,
        90,
        90,
        STANCE_END_ANKLE,
        STANCE_END_ANKLE};

    //Trajectories for Step
    std::array<double, TRAJ_LENGTH> stanceKneeTraj = {
        SWING_END_KNEE,
        8,
        8,
        8,
        8,
        STANCE_END_KNEE};
    std::array<double, TRAJ_LENGTH> stanceHipTraj = {
        SWING_END_HIP,
        155,
        160,
        170,
        175,
        STANCE_END_HIP};
    std::array<double, TRAJ_LENGTH> stanceAnkleTraj = {
        SWING_END_ANKLE,
        90,
        90,
        90,
        STANCE_END_ANKLE,
        STANCE_END_ANKLE};

    std::array<double, TRAJ_LENGTH> swingKneeTraj = {
        STANCE_END_KNEE,
        2,
        20,
        80,
        70,
        SWING_END_KNEE};
    std::array<double, TRAJ_LENGTH> swingHipTraj = {
        STANCE_END_HIP,
        180,
        180,
        140,
        110,
        SWING_END_HIP};
    std::array<double, TRAJ_LENGTH> swingAnkleTraj = {
        STANCE_END_ANKLE,
        110,
        100,
        90,
        90,
        SWING_END_ANKLE};

    //Trajectories for Last Step
    std::array<double, TRAJ_LENGTH> lastStanceKneeTraj = {
        SWING_END_KNEE,
        8,
        8,
        8,
        8,
        STAND_KNEE_ANGLE};
    std::array<double, TRAJ_LENGTH> lastStanceHipTraj = {
        SWING_END_HIP,
        170,
        170,
        170,
        170,
        STAND_HIP_ANGLE};
    std::array<double, TRAJ_LENGTH> lastStanceAnkleTraj = {
        SWING_END_ANKLE,
        90,
        90,
        90,
        90,
        STAND_ANKLE_ANGLE};
    std::array<double, TRAJ_LENGTH> lastSwingKneeTraj = {
        STANCE_END_KNEE,
        8,
        40,
        80,
        40,
        STAND_KNEE_ANGLE};
    std::array<double, TRAJ_LENGTH> lastSwingHipTraj = {
        STANCE_END_HIP,
        185,
        170,
        130,
        130,
        STAND_HIP_ANGLE};
    std::array<double, TRAJ_LENGTH> lastSwingAnkleTraj = {
        STANCE_END_ANKLE,
        90,
        90,
        90,
        90,
        STAND_ANKLE_ANGLE};

public:
    Robot();
    Joint joints[NUM_JOINTS];
    double fracTrajProgress = 0;
    void printInfo();
    //void jointIncrement();
    void updateJoints();
    bool positionControl;
    bool initPositionControl(void);
    bool initPositionControlAnkles(void);
    bool homeCalibration(void);
    bool sdoMSG(void);
    bool remapPDO(void);
    bool remapPDOAnkles(void);
    bool preop(void);
    bool resetTrackingError(void);
    // void printTrajectories();

    //canFeasat constants
    unsigned int MAX_RECONNECTS = 10;
    unsigned int DECIMAL = 10;
    // Exo user buttons
    unsigned int BUTTON_ONE = 1;
    unsigned int BUTTON_TWO = 2;
    unsigned int BUTTON_THREE = 3;
    unsigned int BUTTON_FOUR = 4;
    //Node ID for the 4 joints
    // Variable for moving through trajectories
    struct timeval moving_tv;
    struct timeval stationary_tv;
    struct timeval start_traj;
    struct timeval last_tv;
    // Trajectory functions - should move to trajectory object
    void startNewTraj();
    void moveThroughTraj(double (*trajFunction)(int, double), double trajTime);
    double getSteptime();
    double getInterpolatedPoint(std::array<double, TRAJ_LENGTH> points, double scaledTime);
    double sittingTrajFunc(int jointInd, double scaledTime);
    double standUpTrajFunc(int jointInd, double scaledTime);
    double sitDownTrajFunc(int jointInd, double scaledTime);
    double steppingFirstLeftTrajFunc(int jointInd, double scaledTime);
    double steppingRightTrajFunc(int jointInd, double scaledTime);
    double steppingLeftTrajFunc(int jointInd, double scaledTime);
    double steppingLastRightTrajFunc(int jointInd, double scaledTime);
    double steppingLastLeftTrajFunc(int jointInd, double scaledTime);
};

#endif //CAPSTONE_ROBOT_H

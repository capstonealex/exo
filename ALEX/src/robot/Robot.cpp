//
// Created by William Campbell on 2019-07-23.
//

#include "Robot.h"
#include "CO_command.h"
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <cmath>

#define CANMESSAGELENGTH (100)
#define NOFLIP (100)

//Stationary Sitting Traj
static constexpr std::array<double, TRAJ_LENGTH> stationarySittingKneeTraj = {
    SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE, SIT_KNEE_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> stationarySittingHipTraj = {
    SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE, SIT_HIP_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> stationarySittingAnkleTraj = {
    SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE};
// Trajectories for Sitting
static constexpr std::array<double, TRAJ_LENGTH> sittingKneeTraj = {
    STAND_KNEE_ANGLE,
    15,
    30,
    54,
    72,
    SIT_KNEE_ANGLE};
//test
static constexpr std::array<double, TRAJ_LENGTH> sittingHipTraj = {
    STAND_HIP_ANGLE,
    165,
    150,
    125,
    110,
    SIT_HIP_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> sittingAnkleTraj = {
    STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE,
    SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE};
// Trajectories for Standing
static constexpr std::array<double, TRAJ_LENGTH> standingKneeTraj = {
    SIT_KNEE_ANGLE,
    72,
    54,
    30,
    15,
    STAND_KNEE_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> standingHipTraj = {
    SIT_HIP_ANGLE,
    110,
    125,
    150,
    165,
    STAND_HIP_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> standingAnkleTraj = {
    SIT_ANKLE_ANGLE, SIT_ANKLE_ANGLE,
    STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE, STAND_ANKLE_ANGLE};

//Trajectories for First Step
static constexpr std::array<double, TRAJ_LENGTH> firstSwingKneeTraj = {
    STAND_KNEE_ANGLE,
    50,
    80,
    80,
    41,
    SWING_END_KNEE};
static constexpr std::array<double, TRAJ_LENGTH> firstSwingHipTraj = {
    STAND_HIP_ANGLE,
    140,
    130,
    120,
    120,
    SWING_END_HIP};
static constexpr std::array<double, TRAJ_LENGTH> firstSwingAnkleTraj = {
    STAND_ANKLE_ANGLE,
    90,
    90,
    90,
    90,
    SWING_END_ANKLE};

static constexpr std::array<double, TRAJ_LENGTH> firstStanceKneeTraj = {
    STAND_KNEE_ANGLE,
    8,
    8,
    8,
    8,
    STANCE_END_KNEE};
static constexpr std::array<double, TRAJ_LENGTH> firstStanceHipTraj = {
    STAND_HIP_ANGLE,
    170,
    170,
    170,
    175,
    STANCE_END_HIP};
static constexpr std::array<double, TRAJ_LENGTH> firstStanceAnkleTraj = {
    STAND_ANKLE_ANGLE,
    90,
    90,
    90,
    STANCE_END_ANKLE,
    STANCE_END_ANKLE};

//Trajectories for Step
static constexpr std::array<double, TRAJ_LENGTH> stanceKneeTraj = {
    SWING_END_KNEE,
    8,
    8,
    8,
    8,
    STANCE_END_KNEE};
static constexpr std::array<double, TRAJ_LENGTH> stanceHipTraj = {
    SWING_END_HIP,
    155,
    160,
    170,
    175,
    STANCE_END_HIP};
static constexpr std::array<double, TRAJ_LENGTH> stanceAnkleTraj = {
    SWING_END_ANKLE,
    90,
    90,
    90,
    STANCE_END_ANKLE,
    STANCE_END_ANKLE};

static constexpr std::array<double, TRAJ_LENGTH> swingKneeTraj = {
    STANCE_END_KNEE,
    2,
    20,
    80,
    70,
    SWING_END_KNEE};
static constexpr std::array<double, TRAJ_LENGTH> swingHipTraj = {
    STANCE_END_HIP,
    180,
    180,
    140,
    110,
    SWING_END_HIP};
static constexpr std::array<double, TRAJ_LENGTH> swingAnkleTraj = {
    STANCE_END_ANKLE,
    110,
    100,
    90,
    90,
    SWING_END_ANKLE};

//Trajectories for Last Step
static constexpr std::array<double, TRAJ_LENGTH> lastStanceKneeTraj = {
    SWING_END_KNEE,
    8,
    8,
    8,
    8,
    STAND_KNEE_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> lastStanceHipTraj = {
    SWING_END_HIP,
    170,
    170,
    170,
    170,
    STAND_HIP_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> lastStanceAnkleTraj = {
    SWING_END_ANKLE,
    90,
    90,
    90,
    90,
    STAND_ANKLE_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> lastSwingKneeTraj = {
    STANCE_END_KNEE,
    8,
    40,
    80,
    40,
    STAND_KNEE_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> lastSwingHipTraj = {
    STANCE_END_HIP,
    185,
    170,
    130,
    130,
    STAND_HIP_ANGLE};
static constexpr std::array<double, TRAJ_LENGTH> lastSwingAnkleTraj = {
    STANCE_END_ANKLE,
    90,
    90,
    90,
    90,
    STAND_ANKLE_ANGLE};

Robot::Robot()
{
    positionControlConfigured = false;
    cout << "Setting Robot joint initial conditions...\n";
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        joints[i].applyPos(0);
        joints[i].setId(i + 1);
    }
    Trajectory::trajectory_parameters initial_trajectory_parameters = {
        .step_duration = 1,
        .step_height = 0.2,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Sitting,
        .seat_height = 0.45,    // sit-stand
        .step_end_height = 0.0, // stairs
        .slope_angle = 0.0,     // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    Trajectory::pilot_parameters lenny_parameters = {
        .lowerleg_length = 0.43,
        .upperleg_length = 0.46,
        .ankle_height = 0.12,
        .foot_length = 0.30,
        .hip_width = 0.43,
        .torso_length = 0.4,
        .buttocks_height = 0.05};
    trajectoryObj.setPilotParameter(lenny_parameters);
    trajectoryObj.setTrajectoryParameter(initial_trajectory_parameters);
}
void Robot::printInfo()
{
    cout << "This is an X2 robot with: \n";
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        // std::cout << "Joint address:" << &joints[i] << endl;
        this->joints[i].printInfo();
    }
}

// Update all of this robots software joint positions from object dictionary
void Robot::updateJoints()
{
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        //joints[i].updateJoint();
    }
}
bool Robot::sdoMSG(void)
{
    char *returnMessage;
    char SDO_Message[CANMESSAGELENGTH];
    strcpy(SDO_Message, "[1] 100 read 0x1017 0 i16");
    cancomm_socketFree(SDO_Message, returnMessage);
    printf("Heart beat read!\n");
    return true;
}

bool Robot::initPositionControl(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 start",
        "[1] 2 start",
        "[1] 3 start",
        "[1] 4 start",
        "[1] 2 write 0x6060 0 i8 1",
        "[1] 1 write 0x6060 0 i8 1",
        "[1] 3 write 0x6060 0 i8 1",
        "[1] 4 write 0x6060 0 i8 1",
        "[1] 2 write 0x6081 0 i32 2000000",
        "[1] 1 write 0x6081 0 i32 2000000",
        "[1] 3 write 0x6081 0 i32 2000000",
        "[1] 4 write 0x6081 0 i32 2000000",
        "[1] 2 write 0x6083 0 i32 100000",
        "[1] 1 write 0x6083 0 i32 100000",
        "[1] 3 write 0x6083 0 i32 100000",
        "[1] 4 write 0x6083 0 i32 100000",
        "[1] 2 write 0x6084 0 i32 100000",
        "[1] 1 write 0x6084 0 i32 100000",
        "[1] 3 write 0x6084 0 i32 100000",
        "[1] 4 write 0x6084 0 i32 100000"};
    if (!positionControlConfigured)
    {
        int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
        for (int i = 0; i < num_of_Messages; ++i)
        {
            cancomm_socketFree(SDO_MessageList[i], returnMessage);
        }
        positionControlConfigured = true;
        printf("Motors configured for position control\n");
        return true;
    }
    else
    {
        printf("WARNING:::: Position Control already configured\n");
        return false;
    }
}
bool Robot::initPositionControlAnkles(void)
{
    char *returnMessage;
    char SDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 5 start",
        "[1] 6 start",
        "[1] 5 write 0x6060 0 i8 1",
        "[1] 6 write 0x6060 0 i8 1",
        "[1] 5 write 0x6081 0 i32 300000",
        "[1] 6 write 0x6081 0 i32 300000",
        "[1] 5 write 0x6083 0 i32 10000000",
        "[1] 6 write 0x6083 0 i32 10000000",
        "[1] 5 write 0x6084 0 i32 10000000",
        "[1] 6 write 0x6084 0 i32 10000000",
        "[1] 5 write 0x6040 0 i16 6",
        "[1] 5 write 0x6040 0 i16 15",
        "[1] 6 write 0x6040 0 i16 6",
        "[1] 6 write 0x6040 0 i16 15",
    };
    int num_of_Messages = sizeof(SDO_MessageList) / sizeof(SDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(SDO_MessageList[i], returnMessage);
    }
    printf("Motors configured for position control\n");
    return true;
}

bool Robot::remapPDO(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 write 0x1801 1 u32 0x80000281",
        "[1] 2 write 0x1801 1 u32 0x80000282",
        "[1] 3 write 0x1801 1 u32 0x80000283",
        "[1] 4 write 0x1801 1 u32 0x80000284",
        "[1] 1 write 0x1A01 0 u8 0",
        "[1] 1 write 0x1801 2 u8 1",
        "[1] 1 write 0x1A01 1 u32 0x60640020",
        "[1] 1 write 0x1A01 2 u32 0x606C0020",
        "[1] 1 write 0x1A01 0 u8 2",
        "[1] 2 write 0x1A01 0 u8 0",
        "[1] 2 write 0x1801 2 u8 1",
        "[1] 2 write 0x1A01 1 u32 0x60640020",
        "[1] 2 write 0x1A01 2 u32 0x606C0020",
        "[1] 2 write 0x1A01 0 u8 2",
        "[1] 3 write 0x1A01 0 u8 0",
        "[1] 3 write 0x1801 2 u8 1",
        "[1] 3 write 0x1A01 1 u32 0x60640020",
        "[1] 3 write 0x1A01 2 u32 0x606C0020",
        "[1] 3 write 0x1A01 0 u8 2",
        "[1] 4 write 0x1A01 0 u8 0",
        "[1] 4 write 0x1801 2 u8 1",
        "[1] 4 write 0x1A01 1 u32 0x60640020",
        "[1] 4 write 0x1A01 2 u32 0x606C0020",
        "[1] 4 write 0x1A01 0 u8 2",
        "[1] 1 write 0x1801 1 u32 0x281",
        "[1] 2 write 0x1801 1 u32 0x282",
        "[1] 3 write 0x1801 1 u32 0x283",
        "[1] 4 write 0x1801 1 u32 0x284",
        "[1] 1 write 0x1800 1 u32 0x80000181",
        "[1] 2 write 0x1800 1 u32 0x80000182",
        "[1] 3 write 0x1800 1 u32 0x80000183",
        "[1] 4 write 0x1800 1 u32 0x80000184",
        "[1] 1 write 0x1A00 0 u8 0",
        "[1] 1 write 0x1800 2 u8 0xFF",
        "[1] 1 write 0x1A00 1 u32 0x60410010",
        "[1] 1 write 0x1A00 0 u8 1",
        "[1] 2 write 0x1A00 0 u8 0",
        "[1] 2 write 0x1800 2 u8 0xFF",
        "[1] 2 write 0x1A00 1 u32 0x60410010",
        "[1] 2 write 0x1A00 0 u8 1",
        "[1] 3 write 0x1A00 0 u8 0",
        "[1] 3 write 0x1800 2 u8 0xFF",
        "[1] 3 write 0x1A00 1 u32 0x60410010",
        "[1] 3 write 0x1A00 0 u8 1",
        "[1] 4 write 0x1A00 0 u8 0",
        "[1] 4 write 0x1800 2 u8 0xFF",
        "[1] 4 write 0x1A00 1 u32 0x60410010",
        "[1] 4 write 0x1A00 0 u8 1",
        "[1] 1 write 0x1800 1 u32 0x181",
        "[1] 2 write 0x1800 1 u32 0x182",
        "[1] 3 write 0x1800 1 u32 0x183",
        "[1] 4 write 0x1800 1 u32 0x184",
        "[1] 1 write 0x1800 1 u32 0x80000381",
        "[1] 2 write 0x1800 1 u32 0x80000382",
        "[1] 3 write 0x1800 1 u32 0x80000383",
        "[1] 4 write 0x1800 1 u32 0x80000384",
        "[1] 1 write 0x1A00 0 u8 0",
        "[1] 1 write 0x1800 2 u8 0x01",
        "[1] 1 write 0x1A00 1 u32 0x60770010",
        "[1] 1 write 0x1A00 0 u8 1",
        "[1] 2 write 0x1A00 0 u8 0",
        "[1] 2 write 0x1800 2 u8 0x01",
        "[1] 2 write 0x1A00 1 u32 0x60770010",
        "[1] 2 write 0x1A00 0 u8 1",
        "[1] 3 write 0x1A00 0 u8 0",
        "[1] 3 write 0x1800 2 u8 0x01",
        "[1] 3 write 0x1A00 1 u32 0x60770010",
        "[1] 3 write 0x1A00 0 u8 1",
        "[1] 4 write 0x1A00 0 u8 0",
        "[1] 4 write 0x1800 2 u8 0x01",
        "[1] 4 write 0x1A00 1 u32 0x60770010",
        "[1] 4 write 0x1A00 0 u8 1",
        "[1] 1 write 0x1800 1 u32 0x381",
        "[1] 2 write 0x1800 1 u32 0x382",
        "[1] 3 write 0x1800 1 u32 0x383",
        "[1] 4 write 0x1800 1 u32 0x384",
        "[1] 1 write 0x1401 1 u32 0x80000301",
        "[1] 2 write 0x1401 1 u32 0x80000302",
        "[1] 3 write 0x1401 1 u32 0x80000303",
        "[1] 4 write 0x1401 1 u32 0x80000304",
        "[1] 1 write 0x1601 0 u8 0",
        "[1] 1 write 0x1401 2 u8 0xFF",
        "[1] 1 write 0x1601 1 u32 0x607A0020",
        "[1] 1 write 0x1601 0 u8 1",
        "[1] 2 write 0x1601 0 u8 0",
        "[1] 2 write 0x1401 2 u8 0xFF",
        "[1] 2 write 0x1601 1 u32 0x607A0020",
        "[1] 2 write 0x1601 0 u8 1",
        "[1] 3 write 0x1601 0 u8 0",
        "[1] 3 write 0x1401 2 u8 0xFF",
        "[1] 3 write 0x1601 1 u32 0x607A0020",
        "[1] 3 write 0x1601 0 u8 1",
        "[1] 4 write 0x1601 0 u8 0",
        "[1] 4 write 0x1401 2 u8 0xFF",
        "[1] 4 write 0x1601 1 u32 0x607A0020",
        "[1] 4 write 0x1601 0 u8 1",
        "[1] 1 write 0x1401 1 u32 0x301",
        "[1] 2 write 0x1401 1 u32 0x302",
        "[1] 3 write 0x1401 1 u32 0x303",
        "[1] 4 write 0x1401 1 u32 0x304",
        "[1] 1 write 0x1402 1 u32 0x80000401",
        "[1] 2 write 0x1402 1 u32 0x80000402",
        "[1] 3 write 0x1402 1 u32 0x80000403",
        "[1] 4 write 0x1402 1 u32 0x80000404",
        "[1] 1 write 0x1602 0 u8 0",
        "[1] 1 write 0x1402 2 u8 0xFF",
        "[1] 1 write 0x1602 1 u32 0x60FF0020",
        "[1] 1 write 0x1602 0 u8 1",
        "[1] 2 write 0x1602 0 u8 0",
        "[1] 2 write 0x1402 2 u8 0xFF",
        "[1] 2 write 0x1602 1 u32 0x60FF0020",
        "[1] 2 write 0x1602 0 u8 1",
        "[1] 3 write 0x1602 0 u8 0",
        "[1] 3 write 0x1402 2 u8 0xFF",
        "[1] 3 write 0x1602 1 u32 0x60FF0020",
        "[1] 3 write 0x1602 0 u8 1",
        "[1] 4 write 0x1602 0 u8 0",
        "[1] 4 write 0x1402 2 u8 0xFF",
        "[1] 4 write 0x1602 1 u32 0x60FF0020",
        "[1] 4 write 0x1602 0 u8 1",
        "[1] 1 write 0x1402 1 u32 0x401",
        "[1] 2 write 0x1402 1 u32 0x402",
        "[1] 3 write 0x1402 1 u32 0x403",
        "[1] 4 write 0x1402 1 u32 0x404",
        "[1] 1 start",
        "[1] 2 start",
        "[1] 3 start",
        "[1] 4 start",
        "[1] 1 write 0x6040 0 i16 0",
        "[1] 2 write 0x6040 0 i16 0",
        "[1] 3 write 0x6040 0 i16 0",
        "[1] 4 write 0x6040 0 i16 0"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::remapPDOAnkles(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 5 write 0x1801 1 u32 0x80000285",
        "[1] 5 write 0x1A01 0 u8 0",
        "[1] 5 write 0x1801 2 u8 1",
        "[1] 5 write 0x1A01 1 u32 0x60640020",
        "[1] 5 write 0x1A01 2 u32 0x606C0020",
        "[1] 5 write 0x1A01 0 u8 2",
        "[1] 5 write 0x1801 1 u32 0x285",
        "[1] 5 write 0x1800 1 u32 0x80000185",
        "[1] 5 write 0x1A00 0 u8 0",
        "[1] 5 write 0x1800 2 u8 0xFF",
        "[1] 5 write 0x1A00 1 u32 0x60410010",
        "[1] 5 write 0x1A00 0 u8 1",
        "[1] 5 write 0x1800 1 u32 0x185",
        "[1] 5 write 0x1401 1 u32 0x80000305",
        "[1] 5 write 0x1601 0 u8 0",
        "[1] 5 write 0x1401 2 u8 0xFF",
        "[1] 5 write 0x1601 1 u32 0x607A0020",
        "[1] 5 write 0x1601 0 u8 1",
        "[1] 5 write 0x1401 1 u32 0x305",
        "[1] 5 write 0x1402 1 u32 0x80000405",
        "[1] 5 write 0x1602 0 u8 0",
        "[1] 5 write 0x1402 2 u8 0xFF",
        "[1] 5 write 0x1602 1 u32 0x60FF0020",
        "[1] 5 write 0x1602 0 u8 1",
        "[1] 5 write 0x1402 1 u32 0x405",
        "[1] 5 start",
        "[1] 6 write 0x1801 1 u32 0x80000286",
        "[1] 6 write 0x1A01 0 u8 0",
        "[1] 6 write 0x1801 2 u8 1",
        "[1] 6 write 0x1A01 1 u32 0x60640020",
        "[1] 6 write 0x1A01 2 u32 0x606C0020",
        "[1] 6 write 0x1A01 0 u8 2",
        "[1] 6 write 0x1801 1 u32 0x286",
        "[1] 6 write 0x1800 1 u32 0x80000186",
        "[1] 6 write 0x1A00 0 u8 0",
        "[1] 6 write 0x1800 2 u8 0xFF",
        "[1] 6 write 0x1A00 1 u32 0x60410010",
        "[1] 6 write 0x1A00 0 u8 1",
        "[1] 6 write 0x1800 1 u32 0x186",
        "[1] 6 write 0x1401 1 u32 0x80000306",
        "[1] 6 write 0x1601 0 u8 0",
        "[1] 6 write 0x1401 2 u8 0xFF",
        "[1] 6 write 0x1601 1 u32 0x607A0020",
        "[1] 6 write 0x1601 0 u8 1",
        "[1] 6 write 0x1401 1 u32 0x306",
        "[1] 6 write 0x1402 1 u32 0x80000406",
        "[1] 6 write 0x1602 0 u8 0",
        "[1] 6 write 0x1402 2 u8 0xFF",
        "[1] 6 write 0x1602 1 u32 0x60FF0020",
        "[1] 6 write 0x1602 0 u8 1",
        "[1] 6 write 0x1402 1 u32 0x406",
        "[1] 6 start"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        //printf("%s     ", PDO_MessageList[i]);
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::preop(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 preop",
        "[1] 2 preop",
        "[1] 3 preop",
        "[1] 4 preop",
        "[1] 5 preop",
        "[1] 6 preop"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    //    printf("Num of messages: %d\n", num_of_Messages);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}

bool Robot::resetTrackingError(void)
{
    char *returnMessage;
    char PDO_MessageList[][CANMESSAGELENGTH] = {
        "[1] 1 write 0x2183 0 i32 512",
        "[1] 2 write 0x2183 0 i32 512",
        "[1] 3 write 0x2183 0 i32 512",
        "[1] 4 write 0x2183 0 i32 512"};
    int num_of_Messages = sizeof(PDO_MessageList) / sizeof(PDO_MessageList[0]);
    //    printf("Num of messages: %d\n", num_of_Messages);
    for (int i = 0; i < num_of_Messages; ++i)
    {
        cancomm_socketFree(PDO_MessageList[i], returnMessage);
    }
    return true;
}
void Robot::startNewTraj()
{
    // Set the bit flip state to zero
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        joints[i].setBitFlipState(NOFLIP);
    }

    // Index Resetting
    desiredIndex = 0;
    fracTrajProgress = 0;
    Trajectory::jointspace_state startNewTrajJointspace;
    double robotJointspace[NUM_JOINTS];
    int i;
    for (i = 0; i < NUM_JOINTS; i++)
    {
        int j = joints[i].getId();
        robotJointspace[j - 1] = deg2rad(joints[i].getPosDeg());
    }
    cout << "joints position at start traj" << endl;
    printInfo();
    startNewTrajJointspace = {.q = {robotJointspace[0],
                                    robotJointspace[1],
                                    robotJointspace[2],
                                    robotJointspace[3],
                                    robotJointspace[4],
                                    robotJointspace[5]},
                              .time = 0};

    trajectoryObj.generateAndSaveSpline(startNewTrajJointspace);

    // Reset the time
    timerclear(&moving_tv);
    timerclear(&stationary_tv);
    gettimeofday(&start_traj, NULL);
    last_tv = start_traj;

    printf("Start New Traj \n");
}

void Robot::moveThroughTraj()
{
    //long lastTarget = 0;
    struct timeval tv;
    struct timeval tv_diff;
    struct timeval tv_changed;
    gettimeofday(&tv, NULL);
    timersub(&tv, &last_tv, &tv_diff);
    last_tv = tv;

    //uint32_t difftime =  tv_diff.tv_sec*1000000+tv_diff.tv_usec;
    long movingMicro = moving_tv.tv_sec * 1000000 + moving_tv.tv_usec;

    double trajTimeUS = trajectoryObj.trajectoryParameter.step_duration * 1000000;
    fracTrajProgress = movingMicro / trajTimeUS;

    // if Green Button is pressed, move through trajetory. Otherwise stay where you are
    if (!buttons.getGButtonState())
    {
        timeradd(&moving_tv, &tv_diff, &tv_changed);
        moving_tv = tv_changed;
        //array for position and velocity profile
        double positionArray[NUM_JOINTS];
        // printInfo();

#ifndef _NOACTUATION
        // Send a new trajectory point
        // Get Trajectory point for this joint based on current time
        trajectoryObj.calcPosition(fracTrajProgress, positionArray);

        for (int i = 0; i < NUM_JOINTS; i++)
        {
            if (joints[i].getBitFlipState() == NOFLIP)
            {
                int j = joints[i].getId();
                cout << " applied position on joint " << joints[i].getId() << " is " << rad2deg(positionArray[j - 1]) << endl;
                joints[i].applyPosDeg(rad2deg(positionArray[j - 1]));

                // set state machine bitFlip to LOW state.
                joints[i].bitflipLow();
            }
            else
            {
                joints[i].bitflipHigh();
            }
        }
#endif
    }
    else
    {
        timeradd(&stationary_tv, &tv_diff, &tv_changed);
        stationary_tv = tv_changed;
    }
}

// OLD Trajectory functions
// From input array of points, getInterpolatedPoints outputs an interpolated point
// @ the given time instance from the array.

double Robot::getInterpolatedPoint(std::array<double, TRAJ_LENGTH> points, double scaledTime)
{
    int length = points.size();
    double fractInd = scaledTime * (length - 1);
    int down = floor(fractInd);

    if (scaledTime >= 1)
    {
        return points[length - 1];
    }
    else if (scaledTime <= 0)
    {
        return points[0];
    }
    else
    {
        return points[down] + (fractInd - down) * (points[down + 1] - points[down]);
    }
}
double Robot::sittingTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(stationarySittingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(stationarySittingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(stationarySittingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(stationarySittingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(stationarySittingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(stationarySittingAnkleTraj, scaledTime);
    }

    return desPos;
}

double Robot::standUpTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(standingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(standingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(standingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(standingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(standingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(standingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::sitDownTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(sittingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(sittingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(sittingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(sittingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(sittingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(sittingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingFirstLeftTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(firstSwingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(firstStanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(firstSwingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(firstStanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(firstSwingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(firstStanceAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingRightTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(stanceKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(swingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(stanceHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(swingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(stanceAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(swingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLeftTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(stanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(swingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(stanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(swingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(stanceAnkleTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(swingAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLastRightTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(lastSwingKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(lastStanceKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(lastSwingHipTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(lastStanceHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastSwingAnkleTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastStanceAnkleTraj, scaledTime);
    }
    return desPos;
}

double Robot::steppingLastLeftTrajFunc(int jointID, double scaledTime)
{
    double desPos = 0;

    if (jointID == LEFT_KNEE)
    {
        desPos = getInterpolatedPoint(lastSwingKneeTraj, scaledTime);
    }
    else if (jointID == RIGHT_KNEE)
    {
        desPos = getInterpolatedPoint(lastStanceKneeTraj, scaledTime);
    }
    else if (jointID == LEFT_HIP)
    {
        desPos = getInterpolatedPoint(lastSwingHipTraj, scaledTime);
    }
    else if (jointID == RIGHT_HIP)
    {
        desPos = getInterpolatedPoint(lastStanceHipTraj, scaledTime);
    }
    else if (jointID == LEFT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastSwingAnkleTraj, scaledTime);
    }
    else if (jointID == RIGHT_ANKLE)
    {
        desPos = getInterpolatedPoint(lastStanceAnkleTraj, scaledTime);
    }
    return desPos;
}
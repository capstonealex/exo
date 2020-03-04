//hi
/**
 *
 * Created for ALEX exoskeleton on 2019-10-02.
 *
 * State Machine: Sit Stand task
 *
 *              isPressed        isCal              isPressed
 *  uncalibrated +--> calibrating  +--> idle(standing)  +--> sitingDown
 *       ^---------------+                 ^                   +
 *             calFail          isStanding |                   | isSitting
 *                                         |                   |
 *                                         standingUp<--+ sitting
 *                                                     isPressed
 * ALL states can also leave to xferror state as well, which holds the current pos
 * unitl another button is pressed and then goes to uncalibrated (LIMP)
 *
 */
#include "exoStateMachine.h"
#include "CO_command.h"
#include <sys/time.h>
#include <cmath>
#include <array>

// For logging
#include <iostream>
#include <fstream>
#include <time.h> /* time_t, struct tm, time, localtime, strftime */
#include <string>

int running = 0;

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE
#define _VIRTUALROBOT
/////////////////////////////////////////////////////////

#define OWNER ((exoStateMachine *)owner)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

// Logging
char filename[80] = "DefaultFilename.csv";
ofstream logfile;

/////////////////////////////////////////////////////////
// State Machine exoStateMachine methods ----------------------------------------------------------
/////////////////////////////////////////////////////////

exoStateMachine::exoStateMachine(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isYPressed = new IsYPressed(this);
    isBPressed = new IsBPressed(this);
    isRPressed = new IsRPressed(this);
    isGPressed = new IsGPressed(this);
    endTraj = new EndTraj(this);
    startButtonsPressed = new StartButtonsPressed(this);
    resetButtonsPressed = new ResetButtonsPressed(this);
    startWalk = new StartWalk(this);
    // startSit = new StartSit(this);
    // startStand = new StartStand(this);
    // startBackStep = new StartBackStep(this);
    // feetTogether = new FeetTogether(this);

    // StateMachine states
    initState = new InitState(this);
    standing = new Standing(this);
    sitting = new Sitting(this);
    standingUp = new StandingUp(this);
    sittingDwn = new SittingDwn(this);
    steppingFirstLeft = new SteppingFirstLeft(this);
    leftForward = new LeftForward(this);
    steppingRight = new SteppingRight(this);
    rightForward = new RightForward(this);
    steppingLeft = new SteppingLeft(this);
    steppingLastRight = new SteppingLastRight(this);
    steppingLastLeft = new SteppingLastLeft(this);
    errorState = new ErrorState(this);

    // Trajectory Transitions
    NewTransition(sittingDwn, endTraj, sitting);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(steppingRight, endTraj, rightForward);
    NewTransition(steppingFirstLeft, endTraj, leftForward);
    NewTransition(steppingLeft, endTraj, leftForward);
    NewTransition(steppingLastRight, endTraj, standing);
    NewTransition(steppingLastLeft, endTraj, standing);
    // Sit Stand Transitions
    NewTransition(initState, startButtonsPressed, sitting);
    NewTransition(standing, isYPressed, sittingDwn);
    NewTransition(sitting, isYPressed, standingUp);
    // Walking Transitions
    // NewTransition(standing, isBPressed, steppingFirstLeft);
    NewTransition(leftForward, isGPressed, steppingRight);
    NewTransition(rightForward, isGPressed, steppingLeft);
    NewTransition(leftForward, isYPressed, steppingLastRight);
    NewTransition(rightForward, isYPressed, steppingLastLeft);
    // TRANSITION USING NEWMOTION OD EVENTS
    NewTransition(standing, startWalk, steppingFirstLeft);
    // NewTransition(leftForward, startWalk, steppingRight);
    // NewTransition(rightForward, startWalk, steppingLeft);
    // NewTransition(leftForward, feetTogether, steppingLastRight);
    // NewTransition(rightForward, feetTogether, steppingLastLeft);

    // Error State Transitions
    NewTransition(errorState, resetButtonsPressed, initState);
    NewTransition(sitting, isRPressed, errorState);
    NewTransition(standing, isRPressed, errorState);
    NewTransition(standingUp, isRPressed, errorState);
    NewTransition(sittingDwn, isRPressed, errorState);
    NewTransition(steppingFirstLeft, isRPressed, errorState);
    NewTransition(leftForward, isRPressed, errorState);
    NewTransition(steppingRight, isRPressed, errorState);
    NewTransition(rightForward, isRPressed, errorState);
    NewTransition(steppingLeft, isRPressed, errorState);
    NewTransition(steppingLastRight, isRPressed, errorState);
    NewTransition(steppingLastLeft, isRPressed, errorState);

    // Initialize the state machine with first state
    StateMachine::initialize(initState);
    robot = NULL;
    bitFlipState = NOFLIP;
    running = 0;
}

void exoStateMachine::init(void)
{
    mark = 1;
    calibrated = 0;
    StateMachine::init();
    populateDictionary();
#ifndef _VIRTUALROBOT
    printf("Remapping PDOs \n");
    if (calibrated == 0)
    {
        if (robot->remapPDO())
        {
            printf("Motors PDO messages configured\n");
            calibrated = 1;
        }
    }
    else
    {
        printf("Motors already calibrated for motion\n");
    }
    printf("Initialising Position Control \n");
    if (!robot->initPositionControl())
    {
        printf("*****WARNING: LOGIC ERROR*******\n");
    }
#endif

#ifndef _NOANKLES
    robot->remapPDOAnkles();
    robot->initPositionControlAnkles();
#endif

    /// Move to an initial sitting state at the start
    bitFlipState = NOFLIP;
    running = 1;
}
void exoStateMachine::activate(void)
{
    StateMachine::activate();
}
void exoStateMachine::deactivate(void)
{
    StateMachine::deactivate();
}
void exoStateMachine::update(void)
{
    StateMachine::update();
}

////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool exoStateMachine::EndTraj::check(void)
{
    //int reached = 0;
    if (OWNER->robot->fracTrajProgress > 1.15 && OWNER->robot->buttons.getGButtonState() == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//////////// BUTTON PRESS CHECKS //////////////
bool exoStateMachine::IsYPressed::check(void)
{
    if (OWNER->robot->buttons.getYButtonState() == 0)
    {
        return true;
    }
    return false;
}

bool exoStateMachine::IsBPressed::check(void)
{
    if (OWNER->robot->buttons.getBButtonState() == 0)
    {
        return true;
    }
    return false;
}

bool exoStateMachine::IsRPressed::check(void)
{
    if (OWNER->robot->buttons.getRButtonState() == 0)
    {
        return true;
    }
    return false;
}
bool exoStateMachine::IsGPressed::check(void)
{
    if (OWNER->robot->buttons.getGButtonState() == 0)
    {
        printf("G button pressed\n");
        return true;
    }
    return false;
}
bool exoStateMachine::StartButtonsPressed::check(void)
{
    if (OWNER->robot->buttons.getBButtonState() == 0 && OWNER->robot->buttons.getRButtonState() != 0 && OWNER->robot->buttons.getYButtonState() == 0 && OWNER->robot->buttons.getGButtonState() != 0)
    {
        return true;
    }
    return false;
}
bool exoStateMachine::ResetButtonsPressed::check(void)
{
    if (OWNER->robot->buttons.getBButtonState() != 0 && OWNER->robot->buttons.getRButtonState() == 0 && OWNER->robot->buttons.getYButtonState() != 0 && OWNER->robot->buttons.getGButtonState() == 0)
    {
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////
//Crutch new Motion Paramater Events ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
bool exoStateMachine::StartWalk::check(void)
{
    // OD_NM = CO_OD_RAM.nextMovement;
    int OD_NM = CO_OD_RAM.nextMovement;
    //TODO: CHANGE getGBUTTON TO LOOK IN OD NOT FOR BUTTON PRESS
    if ((OD_NM > 0 && OD_NM < 6) && OWNER->robot->buttons.getGButtonState() == 0)
    {
        std::cout << "START WALK EVENT HAPPEND YEWW" << endl;
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[OD_NM]);
        // RESET OD_NM for safety
        CO_OD_RAM.nextMovement = 0;
        CO_OD_RAM.currentMovement = OD_NM;
        return true;
    }
    return false;
}
// bool exoStateMachine::FeetTogether::check(void)
// {
//     // OD_NM = CO_OD_RAM.nextMovement;
//     //TODO: CHANGE getGBUTTON TO LOOK IN OD NOT FOR BUTTON PRESS
//     if (OD_NM == 6 && OWNER->robot->buttons.getGButtonState() == 0)
//     {
//         // Set trajOBJECT paramaters to selected nexMOVEMENT
//         OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[OD_NM]);
//         // RESET OD_NM for safety
//         CO_OD_RAM.nextMovement = 0;
//         return true;
//     }
//     return false;
// }
// bool exoStateMachine::startSit::check(void)
// {
//     // OD_NM = CO_OD_RAM.nextMovement;
//     //TODO: CHANGE getGBUTTON TO LOOK IN OD NOT FOR BUTTON PRESS
//     if ((OD_NM == 8 ) && OWNER->robot->buttons.getGButtonState() == 0)
//     {
//         // Set trajOBJECT paramaters to selected nexMOVEMENT
//         OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[OD_NM]);
//         // RESET OD_NM for safety
//         CO_OD_RAM.nextMovement= 0;
//         return true;
//     }
//     return false;
// }
// bool exoStateMachine::startStand::check(void)
// {
//    // OD_NM = CO_OD_RAM.nextMovement;
// //TODO: CHANGE getGBUTTON TO LOOK IN OD NOT FOR BUTTON PRESS
// if ((OD_NM == 8) && OWNER->robot->buttons.getGButtonState() == 0)
// {
//     // Set trajOBJECT paramaters to selected nexMOVEMENT
//     OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[OD_NM]);
//     // RESET OD_NM for safety
//     CO_OD_RAM.nextMovement= 0;
//     return true;
// }
// return false;
// }
// bool exoStateMachine::startBackstep::check(void)
// {
//     // OD_NM = CO_OD_RAM.nextMovement;
//     //TODO: CHANGE getGBUTTON TO LOOK IN OD NOT FOR BUTTON PRESS
//     if ((OD_NM == 7) && OWNER->robot->buttons.getGButtonState() == 0)
//     {
//         // Set trajOBJECT paramaters to selected nexMOVEMENT
//         OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[OD_NM]);
//         // RESET OD_NM for safety
//         CO_OD_RAM.nextMovement = 0;
//         return true;
//     }
//     return false;
// }

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
void exoStateMachine::initRobot(Robot *rb)
{
    if (robot != NULL)
    {
        printf("Robot object already selected");
    }
    robot = rb;
    robot->buttons.initButtons();
    // robot->printInfo();
};

// Update button state, loop counter (mark) and joints
void exoStateMachine::hwStateUpdate(void)
{
    robot->buttons.setButtonStates();
    //if blue button pressed change actualMotorV to 1 use as sudo change from crutch
    // if (robot->buttons.getBButtonState() == 0)
    // {
    //     CO_OD_RAM.actualMotorVelocities.motor1 = 1;
    //     std::cout << "CHANGE NM FLAG!" << endl;
    // }
    mark = mark + 1;
    robot->updateJoints();
    // LOG TO FILE
    if (mark % 10 == 1)
    {
        //printf("%d, %d \n", robot->joints[2].getStatus(),   robot->joints[2].getActualTorque() );
        struct timeval tv;
        gettimeofday(&tv, NULL);
        double currtime = tv.tv_sec + ((double)tv.tv_usec) / 1000000;
        logfile << std::to_string(currtime);

        for (auto i = 0; i < NUM_JOINTS; i++)
        {
            logfile << "," + std::to_string(robot->joints[i].getPosDeg()) + "," + std::to_string(robot->joints[i].getDesPosDeg()) + "," + std::to_string(robot->joints[i].getActualTorque());
            //printf("%3f, %3f,", robot->joints[i].getPosDeg(), robot->joints[i].getDesPosDeg());
        }
        //printf("\n");
        logfile << "\n";
    }
}
void exoStateMachine::populateDictionary(void)
{
    // nm and cm OD maps
    mvmntToIntODMap["normal"] = 1;
    mvmntToIntODMap["backstep"] = 2;
    mvmntToIntODMap["feet together"] = 3;
    mvmntToIntODMap["up stairs"] = 4;
    mvmntToIntODMap["down stairs"] = 5;
    mvmntToIntODMap["up slope"] = 6;
    mvmntToIntODMap["down slope"] = 7;
    mvmntToIntODMap["uneven"] = 8;
    mvmntToIntODMap["Sit Down"] = 9;
    mvmntToIntODMap["Stand Up"] = 10;
    intToMvmntODMap[1] = "normal";
    intToMvmntODMap[2] = "backstep";
    intToMvmntODMap[3] = "feet together";
    intToMvmntODMap[4] = "up stairs";
    intToMvmntODMap[5] = "down stairs";
    intToMvmntODMap[6] = "up slope";
    intToMvmntODMap[7] = "down slope";
    intToMvmntODMap[8] = "uneven";
    intToMvmntODMap[9] = "Sit Down";
    intToMvmntODMap[10] = "Stand Up";
    // state to OD maps
    // TODO:change to less generic if we want: After testing
    stateToIntODMap["Error"] = 1;
    stateToIntODMap["Init"] = 2;
    stateToIntODMap["Moving"] = 3;
    stateToIntODMap["Standing"] = 4;
    stateToIntODMap["Sitting"] = 4;

    intToStateODMap[1] = "Error";
    intToStateODMap[2] = "Init";
    intToStateODMap[3] = "Moving";
    intToStateODMap[4] = "Standing";
    intToStateODMap[5] = "Sitting";

    std::cout << "Dictionary populated" << std::endl;
}
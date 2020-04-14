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
    startExo = new StartExo(this);
    startSit = new StartSit(this);
    startStand = new StartStand(this);
    // startBackStep = new StartBackStep(this);
    feetTogether = new FeetTogether(this);

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
    //TEST STATE
    testState = new TestState(this);

    // Trajectory Transitions
    NewTransition(sittingDwn, endTraj, sitting);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(steppingRight, endTraj, rightForward);
    NewTransition(steppingFirstLeft, endTraj, leftForward);
    NewTransition(steppingLeft, endTraj, leftForward);
    NewTransition(steppingLastRight, endTraj, standing);
    NewTransition(steppingLastLeft, endTraj, standing);
    // TRANSITION USING OD.NM Triggered EVENTS
    NewTransition(initState, startExo, sitting);
    NewTransition(standing, startWalk, steppingFirstLeft);
    NewTransition(standing, startSit, sittingDwn);
    NewTransition(sitting, startStand, standingUp);
    NewTransition(leftForward, startWalk, steppingRight);
    NewTransition(rightForward, startWalk, steppingLeft);
    NewTransition(leftForward, feetTogether, steppingLastRight);
    NewTransition(rightForward, feetTogether, steppingLastLeft);

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
    // StateMachine::initialize(initState);
    // TESTING
    StateMachine::initialize(testState);
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

    // Set up the logging file
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(filename, 80, "ALEXLOG_%Y%m%e_%H%M.csv", timeinfo);
    std::cout << "Type the file name for the log + .csv" << endl;
    std::cin >> filename;
    printf("File Created: %s\n", filename);

    logfile.open(filename);
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
    if (OWNER->robot->fracTrajProgress > 1.05 && OWNER->robot->buttons.getGButtonState() == 0)
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
bool exoStateMachine::StartExo::check(void)
{
    if ((CO_OD_RAM.currentMovement == 11) && OWNER->robot->buttons.getGButtonState() == 0)
    {
        std::cout << "LEAVING INIT and entering Sitting" << endl;
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        // OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[OD_NM]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}
bool exoStateMachine::StartStand::check(void)
{
    if ((CO_OD_RAM.currentMovement == STNDUP) && OWNER->robot->buttons.getGButtonState() == 1)
    {
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[STNDUP]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}
bool exoStateMachine::StartWalk::check(void)
{
    if ((CO_OD_RAM.currentMovement >= NORMALWALK && CO_OD_RAM.currentMovement <= TILTDWN) && OWNER->robot->buttons.getGButtonState() == 1)
    {
        std::cout << "Motion Type:" << OWNER->intToMvmntODMap[CO_OD_RAM.currentMovement];
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[CO_OD_RAM.currentMovement]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}
bool exoStateMachine::FeetTogether::check(void)
{
    if (CO_OD_RAM.currentMovement == FTTG && OWNER->robot->buttons.getGButtonState() == 1)
    {
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[FTTG]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}
bool exoStateMachine::StartSit::check(void)
{
    if (CO_OD_RAM.currentMovement == SITDWN && OWNER->robot->buttons.getGButtonState() == 1)
    {
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[SITDWN]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
void exoStateMachine::initRobot(ExoRobot *rb)
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
    //cout << "looping" << endl;
    robot->buttons.setButtonStates();
    // Check for commands from Crutch, when new nm sent send back that cm has been changed
    // Proper event now checks for that cm index and the next gButton press to transition
    CO_OD_RAM.currentMovement = CO_OD_RAM.nextMovement;
    if (cm != CO_OD_RAM.currentMovement)
    {
        cm = CO_OD_RAM.currentMovement;
        std::cout << "NEXT MOTION: " << cm << std::endl;
    }
    mark = mark + 1;
    robot->updateRobot();
    // LOG TO FILE
    // if (mark % 10 == 1)
    // {
    //     //printf("%d, %d \n", robot->joints[2].getStatus(),   robot->joints[2].getActualTorque() );
    //     struct timeval tv;
    //     gettimeofday(&tv, NULL);
    //     double currtime = tv.tv_sec + ((double)tv.tv_usec) / 1000000;
    //     logfile << std::to_string(currtime);

    //     for (auto i = 0; i < NUM_JOINTS; i++)
    //     {
    //         logfile << "," + std::to_string(robot->joints[i].getPosDeg()) + "," + std::to_string(robot->joints[i].getDesPosDeg()) + "," + std::to_string(robot->joints[i].getActualTorque());
    //         //printf("%3f, %3f,", robot->joints[i].getPosDeg(), robot->joints[i].getDesPosDeg());
    //     }
    //     //printf("\n");
    //     logfile << "\n";
    // }
}
void exoStateMachine::populateDictionary(void)
{
    // next Movement maps
    mvmntToIntODMap["normal"] = 1;
    mvmntToIntODMap["up stairs"] = 2;
    mvmntToIntODMap["down stairs"] = 3;
    mvmntToIntODMap["up slope"] = 4;
    mvmntToIntODMap["down slope"] = 5;
    mvmntToIntODMap["feet together"] = 6;
    mvmntToIntODMap["backstep"] = 7;
    mvmntToIntODMap["sit Down"] = 8;
    mvmntToIntODMap["stand Up"] = 9;

    intToMvmntODMap[1] = "normal";
    intToMvmntODMap[2] = "up stairs";
    intToMvmntODMap[3] = "down stairs";
    intToMvmntODMap[4] = "up slope";
    intToMvmntODMap[5] = "down slope";
    intToMvmntODMap[6] = "feet together";
    intToMvmntODMap[7] = "backstep";
    intToMvmntODMap[8] = "sit Down";
    intToMvmntODMap[9] = "stand Up";
    // State maps
    stateToIntODMap["Error"] = 1;
    stateToIntODMap["Init"] = 2;
    stateToIntODMap["Left Forward"] = 3;
    stateToIntODMap["Right Forward"] = 4;
    stateToIntODMap["Standing"] = 5;
    stateToIntODMap["Sitting"] = 6;
    stateToIntODMap["Sitting Down"] = 7;
    stateToIntODMap["Standing Up"] = 8;
    stateToIntODMap["Step 1st L"] = 9;
    stateToIntODMap["Step 1st R"] = 10;
    stateToIntODMap["Step last L"] = 11;
    stateToIntODMap["Step last R"] = 12;
    stateToIntODMap["Step L"] = 13;
    stateToIntODMap["Step R"] = 14;

    intToStateODMap[1] = "Error";
    intToStateODMap[2] = "Init";
    intToStateODMap[3] = "Left Forward";
    intToStateODMap[4] = "Right Forward";
    intToStateODMap[5] = "Standing";
    intToStateODMap[6] = "Sitting";
    intToStateODMap[7] = "Sitting Down";
    intToStateODMap[8] = "Standing Up";
    intToStateODMap[9] = "Step 1st L";
    intToStateODMap[10] = "Step 1st R";
    intToStateODMap[11] = "Step last L";
    intToStateODMap[12] = "Step last R";
    intToStateODMap[13] = "Step L";
    intToStateODMap[14] = "Step R";

    std::cout << "Dictionary populated" << std::endl;
}
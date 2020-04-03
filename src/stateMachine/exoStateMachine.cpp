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
//#define _VIRTUALROBOT
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

    // Create Trasitions between states and events which trigger them
    NewTransition(initState, startButtonsPressed, sitting);
    NewTransition(standing, isYPressed, sittingDwn);
    NewTransition(sittingDwn, endTraj, sitting);
    NewTransition(sitting, isYPressed, standingUp);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(steppingFirstLeft, endTraj, leftForward);
    NewTransition(leftForward, isGPressed, steppingRight);
    NewTransition(steppingRight, endTraj, rightForward);
    NewTransition(rightForward, isGPressed, steppingLeft);
    NewTransition(steppingLeft, endTraj, leftForward);
    NewTransition(leftForward, isYPressed, steppingLastRight);
    NewTransition(rightForward, isYPressed, steppingLastLeft);
    NewTransition(steppingLastRight, endTraj, standing);
    NewTransition(steppingLastLeft, endTraj, standing);
    NewTransition(errorState, resetButtonsPressed, initState);

    // Transitions to Error State
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
    //int reached = 0;
    if (OWNER->robot->fracTrajProgress > 1.05 && OWNER->robot->buttons.getGButtonState() == 1)
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
    //cout << "looping" << endl;
    robot->buttons.setButtonStates();
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

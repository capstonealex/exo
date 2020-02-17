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
#include "sitStand.h"
#include "CO_command.h"
#include <sys/time.h>
#include <cmath>
#include <array>

// For logging
#include <iostream>
#include <fstream>
#include <time.h> /* time_t, struct tm, time, localtime, strftime */
#include <string>

#include "Joint.h"

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE

/////////////////////////////////////////////////////////

#define OWNER ((sitStand *)owner)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

// For remote
static char *BUTTONRED = "P8_10";
static char *BUTTONBLUE = "P8_9";
static char *BUTTONGREEN = "P8_7";
static char *BUTTONYELLOW = "P8_8";
GPIO::GPIOManager *gp;
int redPin;
int yellowPin;
int greenPin;
int bluePin;

// Logging
char filename[80] = "DefaultFilename.csv";
ofstream logfile;

/////////////////////////////////////////////////////////
// State Machine sitStand methods ----------------------------------------------------------
/////////////////////////////////////////////////////////

sitStand::sitStand(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isYPressed = new IsYPressed(this);
    isBPressed = new IsBPressed(this);
    isRPressed = new IsRPressed(this);
    endTraj = new EndTraj(this);
    startButtonsPressed = new StartButtonsPressed(this);
    resetButtonsPressed = new ResetButtonsPressed(this);

    // TRANSITION FOR TESTING
    dummyTrue = new DummyTrue(this);

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
    NewTransition(standing, isBPressed, steppingFirstLeft);
    NewTransition(steppingFirstLeft, endTraj, leftForward);
    NewTransition(leftForward, isBPressed, steppingRight);
    NewTransition(steppingRight, endTraj, rightForward);
    NewTransition(rightForward, isBPressed, steppingLeft);
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

void sitStand::init(void)
{
    mark = 1;
    calibrated = 0;
    std::cout << "Welcome to The ALEX STATE MACHINE"
              << "\n";
    StateMachine::init();

    // Set up the buttons
    gp = GPIO::GPIOManager::getInstance();
    redPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONRED);
    bluePin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONBLUE);
    greenPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONGREEN);
    yellowPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONYELLOW);
    gp->setDirection(redPin, GPIO::INPUT);
    gp->setDirection(bluePin, GPIO::INPUT);
    gp->setDirection(greenPin, GPIO::INPUT);
    gp->setDirection(yellowPin, GPIO::INPUT);

    // Configure the drives
    calibrated = 1;
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
    // comment out for Virtual robot
    // printf("Initialising Position Control \n");
    // if (!robot->initPositionControl())
    // {
    //     printf("*****WARNING: LOGIC ERROR*******\n");
    // }

#ifndef _NOANKLES
    robot->remapPDOAnkles();
    robot->initPositionControlAnkles();
#endif

    /// Move to an initial sitting state at the start
    bitFlipState = NOFLIP;
    running = 1;
    printf("END INIT\n");
}
void sitStand::activate(void)
{
    StateMachine::activate();
}
void sitStand::deactivate(void)
{
    StateMachine::deactivate();
}
void sitStand::update(void)
{
    cout << "!!!!!! WITHIN UPDATE FUNCTION in SIT STAND" << endl;
    std::cout << "this State machine: " << this << endl;
    std::cout << "Robot object" << robot << endl;

    StateMachine::update();
}

////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool sitStand::EndTraj::check(void)
{
    //int reached = 0;
    if (OWNER->robot->fracTrajProgress > 1.25)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//////////// BUTTON PRESS CHECKS //////////////
bool sitStand::IsYPressed::check(void)
{
    if (OWNER->yButton == 0)
    {
        return true;
    }
    return false;
}

bool sitStand::IsBPressed::check(void)
{
    if (OWNER->bButton == 0)
    {
        return true;
    }
    return false;
}

bool sitStand::IsRPressed::check(void)
{
    if (OWNER->rButton == 0)
    {
        return true;
    }
    return false;
}
bool sitStand::StartButtonsPressed::check(void)
{
    if (OWNER->bButton == 0 && OWNER->rButton != 0 && OWNER->yButton == 0 && OWNER->gButton != 0)
    {
        return true;
    }
    return false;
}
bool sitStand::ResetButtonsPressed::check(void)
{
    if (OWNER->bButton != 0 && OWNER->rButton == 0 && OWNER->yButton != 0 && OWNER->gButton == 0)
    {
        return true;
    }
    return false;
}

bool sitStand::DummyTrue::check(void)
{
    return true;
}

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
void sitStand::initRobot(Robot *rb)
{

    cout << "initRobot function entered" << endl;
    if (robot != NULL)
    {
        printf("Robot object already selected");
    }
    robot = rb;
    // Perform proper initialization
    robot->printInfo();
    std::cout << "Robot object address: " << robot << endl;
    // Initialize all States with same robot pointer
    initState->initRobot(rb);
    // standing
    //     sitting
    //         standingUp
    //             sittingDwn
    //                 steppingFirstLeft
    //                     leftForward
    //                         steppingRight = new SteppingRight(this);
    // rightForward = new RightForward(this);
    // steppingLeft = new SteppingLeft(this);
    // steppingLastRight = new SteppingLastRight(this);
    // steppingLastLeft = new SteppingLastLeft(this);
};

// Update button state, loop counter (mark) and joints
void sitStand::hwStateUpdate(void)
{

    /*BUTON CODE*/
    //Read all 4 BUTTONs  and print to screen
    int redbtn = gp->getValue(redPin);
    int bluebtn = gp->getValue(bluePin);
    int greenbtn = gp->getValue(greenPin);
    int yellowbtn = gp->getValue(yellowPin);

    // Send buttons to statemachine variables
    yButton = yellowbtn;
    gButton = greenbtn;
    bButton = bluebtn;
    rButton = redbtn;

    if (!yButton)
    {
        printf("Yellow \n");
    }
    if (!gButton)
    {
        printf("Green \n");
    }
    if (!bButton)
    {
        printf("Blue \n");
    }
    if (!rButton)
    {
        printf("Red \n");
    }
    std::cout << "CURRENT State  HW State Update:" << getCurState() << endl;

    // Update loop time counter
    mark = mark + 1;
    robot->updateJoints();
    std::cout << "CURRENT State : HW State Update:" << getCurState() << endl;

    // Log to file
    //if (mark%%==1){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double currtime = tv.tv_sec + ((double)tv.tv_usec) / 1000000;
    logfile << std::to_string(currtime);
    std::cout << "State machine name: HW State Update:" << getCurState() << endl;

    for (auto i = 3; i < NUM_JOINTS; i++)
    {
        logfile << "," + std::to_string(robot->joints[i].getPosDeg()) + "," + std::to_string(robot->joints[i].getDesPosDeg()) + "," + std::to_string(robot->joints[i].getActualTorque());
    }
    //printf("\n");
    logfile << "\n";

    // }
}

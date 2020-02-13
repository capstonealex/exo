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
 * ALL states can also leave to error state as well, which holds the current pos
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

//////////////// For testing  ///////////////////////////
#define _NOANKLES

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE

/////////////////////////////////////////////////////////

#define OWNER ((sitStand *)owner)
#define POSCLEARANCE (8000)
#define POSCLEARANCEDEG (2.0)
#define FINALPOSCLEARANCE (5000)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)
#define TRAJ_LENGTH 6

#ifndef _NOANKLES
#define NUM_JOINTS 6
#else
#define NUM_JOINTS 4
#endif
// For remote
static char *BUTTONRED = "P8_9";
static char *BUTTONGREEN = "P8_8";
static char *BUTTONBLUE = "P8_7";
static char *BUTTONYELLOW = "P8_10";

GPIO::GPIOManager *gp;
int redPin;
int yellowPin;
int greenPin;
int bluePin;

// Logging stuff
char filename[80] = "DefaultFilename.csv";
ofstream logfile;

// Variable for moving through trajectories
struct timeval moving_tv;
struct timeval stationary_tv;
struct timeval start_traj;
struct timeval last_tv;

double fracTrajProgress = 0;
int desiredIndex = 0;
int running = 0;

#define SITSTANDTIME 2
#define STEPTIME 2
#define STEPLENGTH 0.33
#define STEPHEIGHT 0.5
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
    isGPressed = new IsGPressed(this);
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
    //Moonwalking back steps
    walkSelectConfirm = new WalkSelectConfirm(this);
    walkSelect = new WalkSelect(this);
    steppingLeftBack = new SteppingLeftBack(this);
    errorState = new ErrorState(this);
    // Transitions
    NewTransition(initState, startButtonsPressed, sitting);
    //Sit stand*/
    NewTransition(sitting, isYPressed, standingUp);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(sittingDwn, endTraj, sitting);
    NewTransition(standing, isYPressed, sittingDwn);
    NewTransition(standing, isBPressed, walkSelect);
    /*Transition to forward or back steps*/
    NewTransition(walkSelect, isGPressed, steppingFirstLeft);
    NewTransition(walkSelect, isYPressed, steppingLeftBack);
    /*Forward Stepping*/
    NewTransition(steppingFirstLeft, endTraj, leftForward);
    NewTransition(leftForward, isGPressed, steppingRight);
    NewTransition(steppingRight, endTraj, rightForward);
    NewTransition(rightForward, isGPressed, steppingLeft);
    NewTransition(steppingLeft, endTraj, leftForward);
    NewTransition(leftForward, isYPressed, steppingLastRight);
    NewTransition(rightForward, isYPressed, steppingLastLeft);
    NewTransition(steppingLastLeft, endTraj, standing);
    NewTransition(steppingLastRight, endTraj, standing);
    // Moonwalking transitions
    // NewTransition(walkSelectConfirm, isGPressed, walkSelect); Testing w/o
    NewTransition(steppingLeftBack, endTraj, rightForward);
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
    NewTransition(walkSelect, isRPressed, errorState);
    // NewTransition(walkSelectConfirm, isRPressed, errorState);
    NewTransition(steppingLeftBack, isRPressed, errorState);
    /*Transition out fo error state*/
    NewTransition(errorState, resetButtonsPressed, initState);

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

//////////////////////////////////////////////
// State Classes ----------------------------------------------------------
// Moving states
// Positive bending control machine
////////////////////////////////////////////

void sitStand::InitState::entry(void)
{
    printf("Initialise State Entered at Time %d\n", OWNER->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE + YELLOW  TO START PROGRAM\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    OWNER->robot->resetTrackingError();
    // Set up the logging file
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(filename, 80, "ALEXLOG_%Y%m%e_%H%M.csv", timeinfo);
    printf("File Created: %s\n", filename);

    logfile.open(filename);
}
void sitStand::InitState::during(void)
{
    // Do nothing in this state
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].readyToSwitchOn();
    }
}
void sitStand::InitState::exit(void)
{

    printf("Initialise State Exited at Time %d\n", OWNER->mark);
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].enable();
    }
}

void sitStand::SittingDwn::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting Down State Entered at Time %d\n", OWNER->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN SITTING DOWN\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = SITSTANDTIME,
        .step_height = 0.0,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Sit,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};

    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}
void sitStand::SittingDwn::during(void)
{
    // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}
void sitStand::SittingDwn::exit(void)
{
    printf("Sitting Down State Exited at Time %d\n", OWNER->mark);
}

// Negative bending control machine
void sitStand::StandingUp::entry(void)
{
    printf("Standing Up State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = SITSTANDTIME,
        .step_height = 0.0,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Stand,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    OWNER->moveThroughTraj();
}
void sitStand::StandingUp::exit(void)
{
    printf("Standing up motion State Exited at Time %d\n", OWNER->mark);
}

////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void sitStand::Sitting::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("Forcing to Sitting State\n");

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = SITSTANDTIME,
        .step_height = 0.0,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Sitting,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}
void sitStand::Sitting::during(void)
{
    OWNER->moveThroughTraj();
}
void sitStand::Sitting::exit(void)
{
    printf("Sitting State Exited at Time %d\n", OWNER->mark);
}

////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void sitStand::Standing::entry(void)
{
    printf("Standing State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START Sitting DOWN\n");
    printf("Press BLUE BUTTON TO ENTER WALKING SELECT STATE\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::Standing::during(void)
{
    // Press yellow button to leave state
}
void sitStand::Standing::exit(void)
{
    printf("Standing State Exited at Time %d\n", OWNER->mark);
}

////////// STATE ////////////////////
// Stepping First Left
///////////////////////////////////////////////
void sitStand::SteppingFirstLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingFirstLeft State Entered at Time %d\n", OWNER->mark);

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingFirstLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingFirstLeft::exit(void)
{
    printf("SteppingFirstLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

//////////////////////////////////////////
// LEFT FORWARD
//////////////////////////////////////////
void sitStand::LeftForward::entry(void)
{
    //READ TIME OF MAIN
    printf("LeftForward State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO KEEP STEPPING\n");
    printf("PRESS YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::LeftForward::during(void)
{
}
void sitStand::LeftForward::exit(void)
{
    printf("LeftForward State Exited at Time %d\n", OWNER->mark);
}

////////// STATE ////////////////////
// Stepping Right
///////////////////////////////////////////////
void sitStand::SteppingRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingRight State Entered at Time %d\n", OWNER->mark);

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Left,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};

    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingRight::exit(void)
{
    printf("SteppingRight State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
void sitStand::RightForward::entry(void)
{
    //READ TIME OF MAIN
    printf("RightForward State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO KEEP STEPPING \n");
    printf("YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::RightForward::during(void)
{
}
void sitStand::RightForward::exit(void)
{

    printf("RightForward State Exited at Time %d\n", OWNER->mark);
}

////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void sitStand::SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLeft State Entered at Time %d\n", OWNER->mark);
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = STEPHEIGHT,
        .step_length = STEPLENGTH,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingLeft::exit(void)
{
    printf("SteppingLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

////////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void sitStand::SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastRight State Entered at Time %d\n", OWNER->mark);
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = 0.2,
        .step_length = 0.0,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Left,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingLastRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingLastRight::exit(void)
{
    printf("SteppingLastRight State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void sitStand::SteppingLastLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastLeft State Entered at Time %d\n", OWNER->mark);
    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = 0.2,
        .step_length = 0.0,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Walk,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingLastLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingLastLeft::exit(void)
{
    printf("SteppingLastLeft State Exited at Time %d\n", OWNER->mark);
    // do nothing
}

void sitStand::ErrorState::entry(void)
{
    //READ TIME OF MAIN
    printf("Error State Entered at Time %d\n", OWNER->mark);
    logfile.close();
    printf("File Closed \n");

    printf("Reset with Red + Green \n");

    // Set Drives to Disabled mode
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].disable();
    }
}

void sitStand::ErrorState::during(void)
{
}

void sitStand::ErrorState::exit(void)
{
    printf("Error State Exited");
}
////////////////////////////////////////////////////////////////
// BACK STEP STATES ------------------------------------------------------------
// Stepping First Left Back
///////////////////////////////////////////////
void sitStand::SteppingLeftBack::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLeftBack State Entered at Time %d\n", OWNER->mark);

    Trajectory::trajectory_parameters movement_trajectory_parameters = {
        .step_duration = STEPTIME,
        .step_height = 0.2,
        .step_length = 0.3,
        .hip_height_slack = 0.0001,        // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
        .torso_forward_angle = deg2rad(5), // TODO: make this a vector/array?
        .swing_ankle_down_angle = 0,
        .stance_foot = Trajectory::Foot::Right,
        .movement = Trajectory::Movement::Back,
        .seat_height = 0.42, // sit-stand
        .stair_height = 0.0, // stairs
        .slope_angle = 0.0,  // tilted path
        .left_foot_on_tilt = false,
        .right_foot_on_tilt = false};
    OWNER->robot->trajectoryObj.setTrajectoryParameter(movement_trajectory_parameters);

    OWNER->startNewTraj();
}

void sitStand::SteppingLeftBack::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj();
}

void sitStand::SteppingLeftBack::exit(void)
{
    printf("SteppingLeftBack State Exited at Time %d\n", OWNER->mark);
    // do nothing
}
///////// STATE ////////////////////
// Walk select
// *Select to begin forward stepping
// or take a left back step *
///////////////////////////////////////////////
void sitStand::WalkSelect::entry(void)
{
    printf("Walk Select State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO STEP LEFT LEG BACK\n");
    printf("PRESS GREEN BUTTON TO STEP LEFT LEG FORWARD\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::WalkSelect::during(void)
{
    // Press yellow button to leave state
}
void sitStand::WalkSelect::exit(void)
{
    printf("Walk select State Exited at Time %d\n", OWNER->mark);
}

///////// STATE ////////////////////
// walk Select confirm
// * Confirm you want to enter walk selct state
// Used to account for no debounce in Y and B *
///////////////////////////////////////////////

void sitStand::WalkSelectConfirm::entry(void)
{
    printf("Walk Select Confirm State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PAUSE FOR A MOMENT\n");
    printf("RELEASE BLUE AND YELLOW BUTTONS\n");
    printf("TAP GREEN TO ENTER WALK SELECTION STATE\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::WalkSelectConfirm::during(void)
{
    // Press green button to leave state
}
void sitStand::WalkSelectConfirm::exit(void)
{
    printf("Walk select Confirm Exited at Time %d\n", OWNER->mark);
}
////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool sitStand::EndTraj::check(void)
{
    //int reached = 0;
    if (fracTrajProgress > 1.25 && OWNER->gButton == 1)
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
bool sitStand::IsGPressed::check(void)
{
    if (OWNER->gButton == 0)
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

    if (robot != NULL)
    {
        printf("Robot object already selected");
    }
    robot = rb;
    // Perform proper initialization
    robot->printInfo();
};

// Update button state, loop counter (mark) and joints from
void sitStand::hwStateUpdate(void)
{
    /*BUTON CODE*/
    //Read all 4 BUTTONs  and print to screen
    int redbtn = gp->getValue(redPin);
    int bluebtn = gp->getValue(bluePin);
    int greenbtn = gp->getValue(greenPin);
    int yellowbtn = gp->getValue(yellowPin);

    // Send buttons to statemachine variables
    this->yButton = yellowbtn;
    this->gButton = greenbtn;
    this->bButton = bluebtn;
    this->rButton = redbtn;

    //printf("%d, %d, %d, %d \n", yButton, gButton, bButton, rButton);

    // if (!yButton)
    // {
    // 	printf("Yellow \n");
    // }
    // if (!gButton)
    // {
    // 	printf("Green \n");
    // }
    // if (!bButton)
    // {
    // 	printf("Blue \n");
    // }
    // if (!rButton)
    // {
    // 	printf("Red \n");
    // }

    // Update loop time counter
    mark = mark + 1;
    robot->updateJoints();
    // robot->printInfo();
    // robot->printTrajectories();

    //printf("%d, %3f \n", robot->joints[2].getStatus(),   robot->joints[2].getActualTorque() );
    //printf(std::to_string(robot->joints[2].getActualTorque()));
    // Log to file
    //if (mark%%==1){
    // struct timeval tv;
    // gettimeofday(&tv, NULL);
    // double currtime = tv.tv_sec + ((double)tv.tv_usec) / 1000000;
    // logfile << std::to_string(currtime);

    // for (auto i = 0; i < NUM_JOINTS; i++)
    // {
    // 	logfile << "," + std::to_string(robot->joints[i].getPosDeg()) + "," + std::to_string(robot->joints[i].getDesPosDeg()) + "," + std::to_string(robot->joints[i].getActualTorque());
    // 	//printf("%3f, %3f,", robot->joints[i].getPosDeg(), robot->joints[i].getDesPosDeg());
    // }
    // //printf("\n");
    // logfile << "\n";
    // }
}

void sitStand::startNewTraj()
{
    // Set the bit flip state to zero
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        robot->joints[i].setBitFlipState(NOFLIP);
    }

    // Index Resetting
    desiredIndex = 0;
    fracTrajProgress = 0;
    Trajectory::jointspace_state startNewTrajJointspace;
    double robotJointspace[NUM_JOINTS];
    int i;
    for (i = 0; i < NUM_JOINTS; i++)
    {
        int j = robot->joints[i].getId();
        robotJointspace[j - 1] = deg2rad(robot->joints[i].getPosDeg());
    }
    startNewTrajJointspace = {.q = {robotJointspace[0],
                                    robotJointspace[1],
                                    robotJointspace[2],
                                    robotJointspace[3],
                                    M_PI_2,
                                    M_PI_2},
                              .time = 0};

    robot->trajectoryObj.generateAndSaveSpline(startNewTrajJointspace);

    // Reset the time
    timerclear(&moving_tv);
    timerclear(&stationary_tv);
    gettimeofday(&start_traj, NULL);
    last_tv = start_traj;

    printf("Start New Traj \n");
}

void sitStand::moveThroughTraj()
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

    double trajTimeUS = robot->trajectoryObj.trajectoryParameter.step_duration * 1000000;
    fracTrajProgress = movingMicro / trajTimeUS;

    // if Green Button is pressed, move through trajetory. Otherwise stay where you are
    if (!gButton)
    {
        timeradd(&moving_tv, &tv_diff, &tv_changed);
        moving_tv = tv_changed;
        //array for position and velocity profile
        double positionArray[NUM_JOINTS];
        // robot->printInfo();

#ifndef _NOACTUATION
        // Send a new trajectory point
        // Get Trajectory point for this joint based on current time
        robot->trajectoryObj.calcPosition(fracTrajProgress, positionArray);

        for (int i = 0; i < NUM_JOINTS; i++)
        {
            if (robot->joints[i].getBitFlipState() == NOFLIP)
            {
                int j = robot->joints[i].getId();
                robot->joints[i].applyPosDeg(rad2deg(positionArray[j - 1]));
                // set state machine bitFlip to LOW state.
                robot->joints[i].bitflipLow();
            }
            else
            {
                robot->joints[i].bitflipHigh();
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

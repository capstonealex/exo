
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
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */
#include <string>



#define OWNER ((sitStand *)owner)
#define POSCLEARANCE (8000)
#define POSCLEARANCEDEG (2.0)
#define FINALPOSCLEARANCE (5000)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)
#define TRAJ_LENGTH 6
#define NUM_JOINTS 4

#define LEFT_HIP (1)
#define LEFT_KNEE (2)
#define RIGHT_HIP (3)
#define RIGHT_KNEE (4)

// For testing
//#define KNEE_MOTOR_POS1 250880
//#define KNEE_MOTOR_POS2 0

static char *BUTTONRED = "P8_7";
static char *BUTTONBLUE = "P8_8";
static char *BUTTONGREEN = "P8_9";
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


#define SITSTANDTIME 1.5
#define STEPTIME 2

//Stationary Sitting Traj
std::array<double, TRAJ_LENGTH> stationarySittingKneeTraj = {
         80, 
         80,
         80,
         80,
        80,
        80};
std::array<double, TRAJ_LENGTH>  stationarySittingHipTraj = {
        105,
        105,
        105,
        105,
        105,
        105};

// Trajectories for Sitting
std::array<double, TRAJ_LENGTH>  sittingKneeTraj = {
         8,
         15,
         30,
         54,
         72,
        80};
std::array<double, TRAJ_LENGTH>  sittingHipTraj = {
        170,
        165,
        150,
        125,
        110,
        105};

// Trajectories for Standing
std::array<double, TRAJ_LENGTH>  standingKneeTraj = {
        80,
        72,
        54,
        30,
        15,
        8};
std::array<double, TRAJ_LENGTH>  standingHipTraj = {
        105,
        110,
        125,
        150,
        165,
        170};     

//Trajectories for First Step        
std::array<double, TRAJ_LENGTH> firstSwingKneeTraj = {
         8,
        50,
        80,
        80,
        41,
        40};
std::array<double, TRAJ_LENGTH>  firstSwingHipTraj = {
        170,
        140,
        130,
        120,
        120,
        140};
std::array<double, TRAJ_LENGTH>  firstStanceKneeTraj = {
        8,
        8,
        8,
        8,
        8,
        8};
std::array<double, TRAJ_LENGTH>  firstStanceHipTraj = {
        170, 
        170,
        170,
        170,
        175,
        180};  

//Trajectories for Step        
std::array<double, TRAJ_LENGTH> stanceKneeTraj = {
         40,
         8,
         8,
         8,
         8,
         20
         };
std::array<double, TRAJ_LENGTH> stanceHipTraj = {
        140,
        160,
        170,
        170,
        180,
        180};
std::array<double, TRAJ_LENGTH> swingKneeTraj = {
        8,
        2,
        40,
        80,
        90,
        40};
std::array<double, TRAJ_LENGTH> swingHipTraj = {
        180,
        180,
        180,
        140,
        120,
        140};  
        
/*
std::array<double, TRAJ_LENGTH> firstSwingKneeTraj = {
         8,
        20,
        75,
        75,
        30,
        20};
std::array<double, TRAJ_LENGTH>  firstSwingHipTraj = {
        170,
        170,
        160,
        140,
        130,
        160};
std::array<double, TRAJ_LENGTH>  firstStanceKneeTraj = {
        8,
        8,
        8,
        8,
        8,
        8};
std::array<double, TRAJ_LENGTH>  firstStanceHipTraj = {
        170, 
        170,
        177,
        170,
        170,
        175};  

std::array<double, TRAJ_LENGTH> stanceKneeTraj = {
         20,
         8,
         8,
         8,
         8,
         8};
std::array<double, TRAJ_LENGTH> stanceHipTraj = {
        160,
        165,
        170,
        170,
        170,
        175};
std::array<double, TRAJ_LENGTH> swingKneeTraj = {
        8,
        2,
        75,
        75,
        30,
        20};
std::array<double, TRAJ_LENGTH> swingHipTraj = {
        175,
        175,
        170,
        140,
        130,
        160};  */
//Trajectories for Last Step        
std::array<double, TRAJ_LENGTH> lastStanceKneeTraj = {
         40,
         8,
         8,
         8,
         8,
         8};
std::array<double, TRAJ_LENGTH> lastStanceHipTraj = {
        140,
        170,
        170,
        170,
        170,
        170};
std::array<double, TRAJ_LENGTH> lastSwingKneeTraj = {
        8,
        8,
        40,
        80,
        40,
        8};
std::array<double, TRAJ_LENGTH> lastSwingHipTraj = {
        180,
        185,
        170,
        130,
        130,
        170};  

double getInterpolatedPoint(std::array<double, TRAJ_LENGTH> points, double scaledTime){
    int length = points.size();
    double fractInd = scaledTime*(length-1);
    int down = floor(fractInd);
    
    if (scaledTime >= 1){
        return points[length-1];
    } else if (scaledTime <= 0){
        return points[0];
    }    
    else{
        return points[down] + (fractInd - down)*(points[down+1]-points[down]);
    }
}

double sittingTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;
    
    if (jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(stationarySittingKneeTraj,scaledTime);}
    else if (jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(stationarySittingKneeTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(stationarySittingHipTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(stationarySittingHipTraj, scaledTime); }
    return desPos;
}

double standUpTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;
    
    if (jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(standingKneeTraj, scaledTime);}
    else if(jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(standingKneeTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(standingHipTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(standingHipTraj, scaledTime);}
    return desPos;
}

double sitDownTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(sittingKneeTraj, scaledTime);}
    else if(jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(sittingKneeTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(sittingHipTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(sittingHipTraj, scaledTime);}
    return desPos;
}

double steppingFirstLeftTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(firstSwingKneeTraj, scaledTime);}
    else if(jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(firstStanceKneeTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(firstSwingHipTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(firstStanceHipTraj, scaledTime);}
    return desPos;
}

double steppingRightTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;

    if (jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(stanceKneeTraj, scaledTime);}
    else if(jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(swingKneeTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(stanceHipTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(swingHipTraj, scaledTime);}
    return desPos;
}
 
double steppingLeftTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;

    if (jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(stanceKneeTraj, scaledTime);}
    else if(jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(swingKneeTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(stanceHipTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(swingHipTraj, scaledTime);}
    return desPos;
} 

double steppingLastRightTrajFunc(int jointInd, double scaledTime, Robot *rob)
{ 
    int jointID = rob->joints[jointInd].getId();
    double desPos = 0;

    if (jointID == RIGHT_KNEE) {desPos= getInterpolatedPoint(lastSwingKneeTraj, scaledTime);}
    else if(jointID == LEFT_KNEE) {desPos= getInterpolatedPoint(lastStanceKneeTraj, scaledTime);}
    else if (jointID == RIGHT_HIP) {desPos= getInterpolatedPoint(lastSwingHipTraj, scaledTime);}
    else if (jointID == LEFT_HIP) {desPos= getInterpolatedPoint(lastStanceHipTraj, scaledTime);}
    return desPos;
} 
 
 
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
    
    
    // DUMMY TRANSITION FOR TESTING ONLY
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
    NewTransition(steppingLastRight, endTraj, standing);
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


    // Initialize the state machine with first state
    StateMachine::initialize(initState);
    robot = NULL;
    bitFlipState = NOFLIP;
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
    if (calibrated == 0)
    {
        /*if (robot->remapPDO())
        {
            printf("Motors PDO messages configured\n");
            calibrated = 1;
        }*/
    }
    else{
        printf("Motors already calibrated for motion\n");
    }
        
    // Set up the logging file
      time_t rawtime;
      struct tm * timeinfo;

      time (&rawtime);
      timeinfo = localtime (&rawtime);

      strftime (filename,80,"ALEXLOG_%Y%m%e_%H%M.csv",timeinfo);
      printf("File Created: %s\n", filename);
      
      logfile.open (filename);

    /// Move to an initial sitting state at the start 
    bitFlipState = NOFLIP;
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
// State Methods ----------------------------------------------------------
// Moving states
// Positive bending control machine
////////////////////////////////////////////

void sitStand::InitState::entry(void)
{
    printf("Initialise State Entered at Time %f\n", OWNER->mark);
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE + YELLOW  TO START PROGRAM\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    
    //OWNER->robot->resetTrackingError();
}
void sitStand::InitState::during(void)
{
    // Do nothing in this state
}
void sitStand::InitState::exit(void)
{
    if (OWNER->robot->positionControl == 0)
    {
      /*  if (OWNER->robot->initPositionControl())
        {
            printf("drives finished position control configuration\n");
            OWNER->robot->positionControl = 1;
        }*/
    }
    printf("Initialise State Exited at Time %f\n", OWNER->mark);
}



void sitStand::SittingDwn::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting Down State Entered at Time %f\n", OWNER->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN SITTING DOWN\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    OWNER->startNewTraj();
    
    
}
void sitStand::SittingDwn::during(void)
{
   // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj(sitDownTrajFunc, SITSTANDTIME);
}
void sitStand::SittingDwn::exit(void)
{
    printf("Sitting Down State Exited at Time %f\n", OWNER->mark);
}

// Negative bending control machine
void sitStand::StandingUp::entry(void)
{
    printf("Standing Up State Entered at Time %f\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    OWNER->startNewTraj();
}

void sitStand::StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    OWNER->moveThroughTraj(standUpTrajFunc, SITSTANDTIME);
}
void sitStand::StandingUp::exit(void)
{
    printf("Standing up motion State Exited at Time %f\n", OWNER->mark);
}


////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void sitStand::Sitting::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting State Entered at Time %f\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    printf("Forcing to Sitting State\n");
    OWNER->startNewTraj();
}
void sitStand::Sitting::during(void)
{
    OWNER->moveThroughTraj(sittingTrajFunc, 10);
}
void sitStand::Sitting::exit(void)
{
    printf("Sitting State Exited at Time %f\n", OWNER->mark);
}



////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void sitStand::Standing::entry(void)
{
    printf("Standing State Entered at Time %f\n", OWNER->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START Sitting DOWN\n");
    printf("PRESS BLUE BUTTON TO STEP LEFT LEG FORWARD\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::Standing::during(void)
{
    // Press yellow button to leave state
}
void sitStand::Standing::exit(void)
{
    printf("Standing State Exited at Time %f\n", OWNER->mark);
}


////////// STATE ////////////////////
// Stepping First Left
///////////////////////////////////////////////
void sitStand::SteppingFirstLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingFirstLeft State Entered at Time %f\n", OWNER->mark);

    OWNER->startNewTraj();
}

void sitStand::SteppingFirstLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj(steppingFirstLeftTrajFunc, STEPTIME); 
}

void sitStand::SteppingFirstLeft::exit(void)
{
    printf("SteppingFirstLeft State Exited at Time %f\n", OWNER->mark);
    // do nothing
}

//////////////////////////////////////////
// LEFT FORWARD
//////////////////////////////////////////
void sitStand::LeftForward::entry(void)
{
    //READ TIME OF MAIN
    printf("LeftForward State Entered at Time %f\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING\n");
    printf("PRESS YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::LeftForward::during(void)
{
}
void sitStand::LeftForward::exit(void)
{
    printf("LeftForward State Exited at Time %f\n", OWNER->mark);
}


////////// STATE ////////////////////
// Stepping Right
///////////////////////////////////////////////
void sitStand::SteppingRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingRight State Entered at Time %f\n", OWNER->mark);

    OWNER->startNewTraj();
}

void sitStand::SteppingRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj(steppingRightTrajFunc, STEPTIME); 
}

void sitStand::SteppingRight::exit(void)
{
    printf("SteppingRight State Exited at Time %f\n", OWNER->mark);
    // do nothing
}

//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
void sitStand::RightForward::entry(void)
{
    //READ TIME OF MAIN
    printf("RightForward State Entered at Time %f\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::RightForward::during(void)
{
}
void sitStand::RightForward::exit(void)
{

    printf("RightForward State Exited at Time %f\n", OWNER->mark);
}


////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void sitStand::SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLeft State Entered at Time %f\n", OWNER->mark);

    OWNER->startNewTraj();
}

void sitStand::SteppingLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj(steppingLeftTrajFunc, STEPTIME); 
}

void sitStand::SteppingLeft::exit(void)
{
    printf("SteppingLeft State Exited at Time %f\n", OWNER->mark);
    // do nothing
}


////////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void sitStand::SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastRight State Entered at Time %f\n", OWNER->mark);

    OWNER->startNewTraj();
}

void sitStand::SteppingLastRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->moveThroughTraj(steppingLastRightTrajFunc, STEPTIME); 
}

void sitStand::SteppingLastRight::exit(void)
{
    printf("SteppingLastRight State Exited at Time %f\n", OWNER->mark);
    // do nothing
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
}


void sitStand::ErrorState::entry(void)
{
    //READ TIME OF MAIN
    printf("Error State Entered at Time %f\n", OWNER->mark);
    logfile.close();
    printf("File Closed \n");
    
    printf("Reset with Red + Green \n");

   // Load New Trajectory
    OWNER->robot->preop();
    OWNER->robot->positionControl = 0;
}

void sitStand::ErrorState::during(void)
{
}

void sitStand::ErrorState::exit(void)
{
    printf("Error State Exited");
}


////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool sitStand::EndTraj::check(void)
{
    //int reached = 0;
    if (fracTrajProgress > 1.25)
    {
        return true;
    } else
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
    if(OWNER->bButton == 0 && OWNER->rButton!=0 && OWNER->yButton==0 && OWNER->gButton!=0){
        return true;
    }
    return false;
}
bool sitStand::ResetButtonsPressed::check(void)
{
    if(OWNER->bButton != 0 && OWNER->rButton==0 && OWNER->yButton!=0 && OWNER->gButton==0){
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
    
    // Update loop time counter
    mark = mark + 1;
    robot->updateJoints();
    // robot->printInfo();
    // robot->printTrajectories();
    
    // Log to file
    struct timeval tv;
    gettimeofday(&tv,NULL);
    double currtime =  tv.tv_sec+((double)tv.tv_usec)/1000000;
    logfile << std::to_string(currtime);
    
    for (auto i = 0; i< NUM_JOINTS; i++){
        logfile << "," +std::to_string(robot->joints[i].getPosDeg()) + "," + std::to_string(robot->joints[i].getDesPosDeg());
    }
    logfile << "\n";

}

void sitStand::startNewTraj()
{
    // Reset the time
    timerclear(&moving_tv);
    timerclear(&stationary_tv);
    gettimeofday(&start_traj, NULL);
    last_tv = start_traj;
    
    // Set the bit flip state to zero
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        robot->joints[i].setBitFlipState(NOFLIP);
    }
    
    // Index Resetting
    desiredIndex = 0;
    fracTrajProgress = 0;
    
    printf("Start New Traj \n");
}


void sitStand::moveThroughTraj(double (*trajFunction)(int, double, Robot*), double trajTime)
{
    //long lastTarget = 0;
    
    struct timeval tv;
    struct timeval tv_diff;
    struct timeval tv_changed;
    gettimeofday(&tv,NULL);
    timersub(&tv, &last_tv, &tv_diff);
    last_tv = tv;
    
    //uint32_t difftime =  tv_diff.tv_sec*1000000+tv_diff.tv_usec;
    
    long movingMicro = moving_tv.tv_sec*1000000+moving_tv.tv_usec;

    double trajTimeUS = trajTime*1000000;
    fracTrajProgress = movingMicro/trajTimeUS;
    
    // if Green Button is pressed, move through trajetory. Otherwise stay where you are 
   // if (!gButton){
       if(true){
        timeradd(&moving_tv, &tv_diff, &tv_changed);
        moving_tv = tv_changed;

        //printf("Time: %3f \n", fracTrajProgress);
        for (auto i = 0; i < NUM_JOINTS; i++){
                if(robot->joints[i].getBitFlipState() == NOFLIP){
                // Send a new trajectory point
                // Get Trajectory point for this joint based on current time
                    // Get position to send to joint based on current arrayIndex, send off and increment index
                    // desired Position in motor command units
                    //double desiredPos = getDegPos(i, desiredIndex);
                    double desiredPos = trajFunction(i, fracTrajProgress, robot);
                           
                    robot->joints[i].applyPosDeg(desiredPos);
                    
                    // set state machine bitFlip to LOW state.
                    robot->joints[i].bitflipLow();
                }
                else{
                    robot->joints[i].bitflipHigh();
                }
            }
    } else{
        timeradd(&stationary_tv, &tv_diff, &tv_changed);
        stationary_tv = tv_changed;
    }
    
    //printf("Stationary Time: %d, Moving Time: %d \n", stationary_tv.tv_sec*1000000+stationary_tv.tv_usec, moving_tv.tv_sec*1000000+moving_tv.tv_usec);
}



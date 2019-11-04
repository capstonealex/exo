
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
#define OWNER ((sitStand *)owner)
#define POSCLEARANCE (8000)
#define FINALPOSCLEARANCE (5000)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

#define LEFT_HIP (1)
#define LEFT_KNEE (2)
#define RIGHT_HIP (3)
#define RIGHT_KNEE (4)

// For testing
//#define KNEE_MOTOR_POS1 250880
//#define KNEE_MOTOR_POS2 0

static const int LENGTH_TRAJ  = 4;
static char *BUTTONRED = "P8_7";
static char *BUTTONBLUE = "P8_8";
static char *BUTTONGREEN = "P8_9";
static char *BUTTONYELLOW = "P8_10";

GPIO::GPIOManager *gp;
int redPin;
int yellowPin;
int greenPin;
int bluePin;

//Stationary Sitting Traj
double stationarySittingKneeTraj[LENGTH_TRAJ] = {
         73,
         73,
         73,
        73};
double stationarySittingHipTraj[LENGTH_TRAJ] = {
        104.69,
        104.69,
        104.69,
        104.69};

// Trajectories for Sitting
double sittingKneeTraj[LENGTH_TRAJ] = {
         8.08,
         30,
         50,
        73.36};
double sittingHipTraj[LENGTH_TRAJ] = {
        170.08,
        150,
        130,
        104.69};

// Trajectories for Standing
double standingKneeTraj[LENGTH_TRAJ] = {
        73.36,
        50,
        30,
        8};
double standingHipTraj[LENGTH_TRAJ] = {
        105, 
        130,
        150,
        170};     

//Trajectories for First Left Step        
double firstSwingKneeTraj[LENGTH_TRAJ] = {
         8.08,
         70,
         70,
         25};
double firstSwingHipTraj[LENGTH_TRAJ] = {
        170.08,
        120,
        120,
        130};
double firstStanceKneeTraj[LENGTH_TRAJ] = {
        8,
        8,
        8,
        8};
double firstStanceHipTraj[LENGTH_TRAJ] = {
        170, 
        170,
        170,
        170};  

//Trajectories for Step        
double stanceKneeTraj[LENGTH_TRAJ] = {
         25,
         8,
         8,
         8};
double stanceHipTraj[LENGTH_TRAJ] = {
        130,
        160,
        160,
        170};
double steppingKneeTraj[LENGTH_TRAJ] = {
        8,
        70,
        70,
        25};
double steppingHipTraj[LENGTH_TRAJ] = {
        170, 
        170,
        130,
        130};  

//Trajectories for Last Step        
double lastStanceKneeTraj[LENGTH_TRAJ] = {
         20,
         8,
         8,
         8};
double lastStanceHipTraj[LENGTH_TRAJ] = {
        180,
        170,
        170,
        170};
double lastSteppingKneeTraj[LENGTH_TRAJ] = {
        8,
        70,
        70,
        8};
double lastSteppingHipTraj[LENGTH_TRAJ] = {
        150, 
        150,
        1,
        170};  

// State Machine sitStand methods ----------------------------------------------------------
sitStand::sitStand(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isYPressed = new IsYPressed(this);
    isBPressed = new IsBPressed(this);
    isRPressed = new IsRPressed(this);
    endTraj = new EndTraj(this);

    // StateMache states
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
    errorState = new ErrorState(this);

    // Create Trasitions between states and events which trigger them
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
    StateMachine::initialize(sitting);
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
    if (robot->positionControl == 0)
    {
        if (robot->initPositionControl())
        {
            printf("drives finished position control configuration\n");
            robot->positionControl = 1;
        }
    }
    if (calibrated == 0)
    {
        if (robot->remapPDO())
        {
            printf("Motors PDO messages configured\n");
            calibrated = 1;
        }
    }
    else{
        printf("Motors already calibrated for motion\n");
    }
    
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
void sitStand::SittingDwn::entry(void)
{
    
    //READ TIME OF MAIN
    printf("Bending Positive State  Entered at Time %f\n", OWNER->mark);
    //load the trajectories
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(sittingHipTraj, sittingHipTraj, sittingKneeTraj, sittingKneeTraj, LENGTH_TRAJ);
    }
    printf("SitStandTrjectories Loaded\n");
    
    OWNER->bitFlipState = NOFLIP;
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
    OWNER->robot->printTrajectories();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN SITTING DOWN\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::SittingDwn::during(void)
{
   // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        OWNER->moveThroughTraj();
    }
}
void sitStand::SittingDwn::exit(void)
{
    printf("Sitting Down State Exited at Time %f\n", OWNER->mark);
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
}

// Negative bending control machine
void sitStand::StandingUp::entry(void)
{
    //load the trajectories
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(standingHipTraj, standingHipTraj, standingKneeTraj, standingKneeTraj, LENGTH_TRAJ);
    }
    printf("SitStandTrjectories Loaded\n");
    //READ TIME OF MAIN
    printf("Standing Up State Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}

void sitStand::StandingUp::during(void)
{
   // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        OWNER->moveThroughTraj();
    }
}
void sitStand::StandingUp::exit(void)
{

    printf("Standing up motion State Exited at Time %f\n", OWNER->mark);
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
    //OWNER->robot->joints[1].zeroIndex();
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
    
    printf("Forcing to Sitting State");
        
    //load the trajectories
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(stationarySittingHipTraj, stationarySittingHipTraj, stationarySittingKneeTraj, stationarySittingKneeTraj, LENGTH_TRAJ);
    }
    printf("SitStandTrjectories Loaded\n");
    

    OWNER->bitFlipState = NOFLIP;
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
    OWNER->robot->printTrajectories();

}
void sitStand::Sitting::during(void)
{
    OWNER->moveThroughTraj();
}
void sitStand::Sitting::exit(void)
{

    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
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

   // Load New Trajectory
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(firstSwingHipTraj, firstStanceHipTraj, firstSwingKneeTraj, firstStanceKneeTraj, LENGTH_TRAJ);
    }
    printf("FirstLeftTrajectories Loaded\n");
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}

void sitStand::SteppingFirstLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        // do nothing for now
        OWNER->moveThroughTraj(); 
    }
}

void sitStand::SteppingFirstLeft::exit(void)
{
    printf("SteppingFirstLeft State Exited at Time %f\n", OWNER->mark);
    // do nothing
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
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

   // Load New Trajectory
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(stanceHipTraj, steppingHipTraj, stanceKneeTraj, steppingKneeTraj, LENGTH_TRAJ);
    }
    printf("Stepping Right Trajectories Loaded\n");
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}

void sitStand::SteppingRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        // do nothing for now
        OWNER->moveThroughTraj(); 
    }
}

void sitStand::SteppingRight::exit(void)
{
    printf("SteppingRight State Exited at Time %f\n", OWNER->mark);
    // do nothing
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
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

   // Load New Trajectory
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(steppingHipTraj, stanceHipTraj, steppingKneeTraj, stanceKneeTraj, LENGTH_TRAJ);
    }
    printf("SteppingLeft Trajectories Loaded\n");
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}

void sitStand::SteppingLeft::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        // do nothing for now
        OWNER->moveThroughTraj(); 
    }
}

void sitStand::SteppingLeft::exit(void)
{
    printf("SteppingLeft State Exited at Time %f\n", OWNER->mark);
    // do nothing
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
}


////////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void sitStand::SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    printf("SteppingLastRight State Entered at Time %f\n", OWNER->mark);

   // Load New Trajectory
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].setTrajectories(lastStanceHipTraj, lastSteppingHipTraj, lastStanceKneeTraj, lastSteppingKneeTraj, LENGTH_TRAJ);
    }
    printf("FirstLeftTrajectories Loaded\n");
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}

void sitStand::SteppingLastRight::during(void)
{
    //long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        // do nothing for now
        OWNER->moveThroughTraj(); 
    }
}

void sitStand::SteppingLastRight::exit(void)
{
    printf("SteppingLastRight State Exited at Time %f\n", OWNER->mark);
    // do nothing
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
}


void sitStand::ErrorState::entry(void)
{
    //READ TIME OF MAIN
    printf("Error State Entered at Time %f\n", OWNER->mark);

   // Load New Trajectory
    OWNER->robot->preop();
}

void sitStand::ErrorState::during(void)
{
    printf("You should be here forever \n");
}

void sitStand::ErrorState::exit(void)
{
    printf("This should never happen");
}


////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool sitStand::EndTraj::check(void)
{
    int reached = 0;
    for (auto i = 0; i < 4; i++)
    {
        int finalPos = OWNER->robot->joints[i].trajectories[LENGTH_TRAJ - 1];
        if (OWNER->robot->joints[i].getPos() > (finalPos - FINALPOSCLEARANCE) && OWNER->robot->joints[i].getPos() < (finalPos + FINALPOSCLEARANCE))
        {
            reached++;
            printf("Joint %d final position reached", OWNER->robot->joints[i].getId());
        }
    }
    if (reached > 0)
    {
        printf("\n");
    }

    if (reached == 4)
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
}


void sitStand::moveThroughTraj()
{
    long lastTarget = 0;
    for (auto i = 0; i < 4; i++){
            if(robot->joints[i].getBitFlipState() == NOFLIP){
                int desiredIndex = robot->joints[i].getIndex();
                // Make sure not to move array index past last member of array
                if (desiredIndex != (LENGTH_TRAJ)){
                    // Get position to send to joint based on current arrayIndex, send off and increment index
                    // desired Position in motor command units
                    long desiredPos = robot->joints[i].trajectories[desiredIndex];
                    lastTarget = robot->joints[i].trajectories[desiredIndex - 1];
                    //SINGLE JOINT FUNCTIONALITY TEST
                    //first member of array
                    if (desiredIndex == 0){
                        printf("Joint %d Bending to pos %ld\n",  robot->joints[i].getId(), desiredPos);
                        robot->joints[i].applyPos(desiredPos);
                        // set state machine bitFlip to LOW state.
                        robot->joints[i].incrementIndex();
                        robot->joints[i].bitflipLow();
                        // THIS SHOULD OCCUR AUTOMATICALLY THROUGH THE LAST FUNCTION
                        //robot->joints[i].setBitFlipState(BITHIGH);
                    }
                    // check if last last position reached -> go to next position
                    //THE BELOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units
                    else if ((desiredIndex > 0) && robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        robot->joints[i].applyPos(desiredPos);
                        // bring control word to low and setState to High for next round of program.
                        robot->joints[i].bitflipLow();
                        //robot->joints[i].setBitFlipState(BITHIGH);
                        printf("Joint %d Bending to pos %ld\n",  robot->joints[i].getId(), desiredPos);
                        robot->joints[i].incrementIndex();
                    }
                }
                else{
                    // print out for testing
                    lastTarget = robot->joints[i].trajectories[desiredIndex - 1];
                    if (robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        // printf("Final position of joint %d reached\n", robot->joints[i].getId());
                    }
                    else{
                        printf("Joint %d Still going to final position\n", robot->joints[i].getId());
                        // robot->printInfo();
                    }
                }
            }
            else{
                robot->joints[i].bitflipHigh();
            }
        }
}
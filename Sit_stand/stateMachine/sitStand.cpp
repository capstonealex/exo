

//
// Created by William Campbell on 2019-09-30.
//

#include "sitStand.h"
#include "CO_command.h"
#define OWNER ((sitStand *)owner)
#define POSCLEARANCE (10000)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)
// For testing
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_POS2 (0)

// State Machine sitStand methods ----------------------------------------------------------
sitStand::sitStand(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isYPressed = new IsYPressed(this);
    isSitting = new IsSitting(this);
    isStanding = new IsStanding(this);
    // StateMache states
    standing = new Standing(this);
    sitting = new Sitting(this);
    standingUp = new StandingUp(this);
    sittingDwn = new SittingDwn(this);

    // Create Trasitions between states and events which trigger them
    NewTransition(standing, isYPressed, sittingDwn);
    NewTransition(sittingDwn, isSitting, sitting);
    NewTransition(sitting, isYPressed, standingUp);
    NewTransition(standingUp, isStanding, standing);

    // Initialize the state machine with first state
    StateMachine::initialize(standing);
    robot = NULL;
    bitFlipState = NOFLIP;
}

void sitStand::init(void)
{
    mark = 1;
    calibrated = 0;
    std::cout << "Welcome to The single joint bend STATE MACHINE"
              << "\n";
    StateMachine::init();
    // Dont start robot unless drives have been configured for position control.
    if (robot->homeCalibration())
    {
        std::cout << "position control initialized"
                  << "\n";
    }
    else
    {
        std::cout << "Error initializing position control, SDO message timeout"
                  << "\n";
    }
}
void sitStand::activate(void)
{
    StateMachine::activate();
}
void sitStand::deactivate(void)
{
    StateMachine::deactivate();
}
// State Methods ----------------------------------------------------------
// Moving states
// Positive bending control machine
void sitStand::SittingDwn::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Positive State  Entered at Time %f\n", OWNER->mark);
    if (OWNER->robot->positionControl == 0)
    {
        if (OWNER->robot->initPositionControl())
        {
            printf("drives finished position control configuration\n");
            OWNER->robot->positionControl = 1;
        }
    }
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
    long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        for (auto i = 0; i < 4; i++){
            if(OWNER->robot->joints[i].getBitFlipState() == NOFLIP){
                int desiredIndex = OWNER->robot->joints[i].getIndex();
                // Make sure not to move array index past last member of array
                if (desiredIndex != (OWNER->robot->joints[i].NUM_TRAJ_POINTS)){
                    // Get position to send to joint based on current arrayIndex, send off and increment index
                    // desired Position in motor command units
                    long desiredPos = OWNER->robot->joints[i].posTrajectories[desiredIndex];
                    lastTarget = OWNER->robot->joints[i].posTrajectories[desiredIndex - 1];
                    /*SINGLE JOINT FUNCTIONALITY TEST*/
                    //first member of array
                    if (desiredIndex == 0){
                        printf("Joint %d Bending to pos %ld\n",  OWNER->robot->joints[i].getId(), desiredPos);
                        OWNER->robot->joints[i].applyPos(desiredPos);
                        // set state machine bitFlip to LOW state.
                        OWNER->robot->joints[i].incrementIndex();
                        OWNER->robot->joints[i].bitflipLow();
                        OWNER->robot->joints[i].setBitFlipState(BITHIGH);
                    }
                    // check if last last position reached -> go to next position
                    /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
                    else if ((desiredIndex > 0) && OWNER->robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        OWNER->robot->joints[i].applyPos(desiredPos);
                        // bring control word to low and setState to High for next round of program.
                        OWNER->robot->joints[i].bitflipLow();
                        OWNER->robot->joints[i].setBitFlipState(BITHIGH);
                        printf("Joint %d Bending to pos %ld\n",  OWNER->robot->joints[i].getId(), desiredPos);
                        OWNER->robot->joints[i].incrementIndex();
                    }
                }
                else{
                    // print out for testing
                    lastTarget = OWNER->robot->joints[i].posTrajectories[desiredIndex - 1];
                    if (OWNER->robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        // printf("Final position of joint %d reached\n", OWNER->robot->joints[i].getId());
                    }
                    else{
                        printf("Joint %d Still going to final position\n", OWNER->robot->joints[i].getId());
                        // robot->printInfo();
                    }
                }
            }
            else{
                OWNER->robot->joints[i].bitflipHigh();
            }
        }
    }
}
void sitStand::SittingDwn::exit(void)
{

    printf("Bending Positive State Exited at Time %f\n", OWNER->mark);
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
    }
}
// Negative bending control machine
void sitStand::StandingUp::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Negative State  Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    for (auto i = 0; i < 4; i++)
    {
        OWNER->robot->joints[i].zeroIndex();
        OWNER->robot->joints[i].setBitFlipState(NOFLIP);
    }
}
void sitStand::StandingUp::during(void)
{
    long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->gButton){
        for (auto i = 0; i < 4; i++){
            if(OWNER->robot->joints[i].getBitFlipState() == NOFLIP){
                int desiredIndex = OWNER->robot->joints[i].getIndex();
                // Make sure not to move array index past last member of array
                if (desiredIndex != (OWNER->robot->joints[i].NUM_TRAJ_POINTS)){
                    // Get position to send to joint based on current arrayIndex, send off and increment index
                    // desired Position in motor command units
                    long desiredPos = OWNER->robot->joints[i].negTrajectories[desiredIndex];
                    lastTarget = OWNER->robot->joints[i].negTrajectories[desiredIndex - 1];
                    /*SINGLE JOINT FUNCTIONALITY TEST*/
                    //first member of array
                    if (desiredIndex == 0){
                       printf("Joint %d Bending to pos %ld\n",  OWNER->robot->joints[i].getId(), desiredPos);
                        OWNER->robot->joints[i].applyPos(desiredPos);
                        // set state machine bitFlip to LOW state.
                        OWNER->robot->joints[i].incrementIndex();
                        OWNER->robot->joints[i].bitflipLow();
                        OWNER->robot->joints[i].setBitFlipState(BITHIGH);
                    }
                    // check if last last position reached -> go to next position
                    /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
                    else if ((desiredIndex > 0) && OWNER->robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        OWNER->robot->joints[i].applyPos(desiredPos);
                        // bring control word to low and setState to High for next round of program.
                        OWNER->robot->joints[i].bitflipLow();
                        OWNER->robot->joints[i].setBitFlipState(BITHIGH);
                        printf("Joint %d Bending to pos %ld\n",  OWNER->robot->joints[i].getId(), desiredPos);
                        OWNER->robot->joints[i].incrementIndex();
                    }
                }
                else{
                    lastTarget = OWNER->robot->joints[i].negTrajectories[desiredIndex - 1];
                    if (OWNER->robot->joints[i].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (lastTarget + POSCLEARANCE)){
                        //printf("Final position of joint %d reached\n,", OWNER->robot->joints[i].getId());
                    }
                    else{
                        //printf("Joint %d Still going to final position\n", OWNER->robot->joints[i].getId());
                        // robot->printInfo();
                    }
                }
            }
            else{
                OWNER->robot->joints[i].bitflipHigh();
            }
        }
    }
}
void sitStand::StandingUp::exit(void)
{

    printf("Standing up motion State Exited at Time %f\n", OWNER->mark);

    OWNER->robot->joints[1].zeroIndex();
}
void sitStand::Sitting::entry(void)
{
    //READ TIME OF MAIN
    printf("Sitting State Entered at Time %f\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void sitStand::Sitting::during(void)
{
}
void sitStand::Sitting::exit(void)
{

    printf("Sitting State Exited at Time %f\n", OWNER->mark);
}
void sitStand::Standing::entry(void)
{
    printf("Standing State Entered at Time %f\n", OWNER->mark);
    if (OWNER->calibrated == 0)
    {
        if (OWNER->robot->remapPDO())
        {
            printf("Motors PDO messages configured\n");
            OWNER->calibrated = 1;
        }
    }
    else{
        printf("Motors already calibrated for motion\n");
    }

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START Sitting DOWN\n");
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
// Events ------------------------------------------------------------
bool sitStand::IsSitting::check(void)
{
    int reached = 0;
    for (auto i = 0; i < 4; i++)
    {
        int finalPos = OWNER->robot->joints[i].posTrajectories[OWNER->robot->joints[i].NUM_TRAJ_POINTS - 1];
        if (OWNER->robot->joints[i].getPos() > (finalPos - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (finalPos + POSCLEARANCE))
        {
            reached++;
            printf("Joint %d final position reached\n", OWNER->robot->joints[i].getId());
        }
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
bool sitStand::IsStanding::check(void)
{
    int reached = 0;
    for (auto i = 0; i < 4; i++)
    {
        int finalPos = OWNER->robot->joints[i].negTrajectories[OWNER->robot->joints[i].NUM_TRAJ_POINTS - 1];
        if (OWNER->robot->joints[i].getPos() > (finalPos - POSCLEARANCE) && OWNER->robot->joints[i].getPos() < (finalPos + POSCLEARANCE))
        {
            reached++;
            printf("Joint %d final position reached\n", OWNER->robot->joints[i].getId());
        }
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
bool sitStand::IsYPressed::check(void)
{
    if (OWNER->yButton == 0)
    {
        return true;
    }
    return false;
}

// Robot interface methods ----------------------------------------------------------
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
    // TODO: Once working Turn button into its own class and object: call button.getState() return 0 or 1, Statemachines have a button or an event could even

    //Read all 4 BUTTONs  and print to screen
    static char *BUTTONRED = "P8_7";
    static char *BUTTONBLUE = "P8_8";
    static char *BUTTONGREEN = "P8_9";
    static char *BUTTONYELLOW = "P8_10";
    int redbtn;
    int bluebtn;
    int greenbtn;
    int yellowbtn;
    GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
    int red = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONRED);
    int blue = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONBLUE);
    int green = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONGREEN);
    int yellow = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONYELLOW);
    gp->setDirection(red, GPIO::INPUT);
    gp->setDirection(blue, GPIO::INPUT);
    gp->setDirection(green, GPIO::INPUT);
    gp->setDirection(yellow, GPIO::INPUT);
    redbtn = gp->getValue(red);
    bluebtn = gp->getValue(blue);
    greenbtn = gp->getValue(green);
    yellowbtn = gp->getValue(yellow);
    // Send buttons to statemachine variables
    this->yButton = yellowbtn;
    this->gButton = greenbtn;
    this->bButton = bluebtn;
    this->rButton = redbtn;
    gp->~GPIOManager();
    // Update loop time counter
    mark = mark + 1;
    robot->updateJoints();
    // robot->printInfo();s
    // robot->printTrajectories();
}

/*
 * bitFlip returns true if the second bit flip has occured, signalling a movement, else returns flase
 * 
 * 
 * 
*/
bool sitStand::bitFlip(int i)
{
    int bit = bitFlipState;
    /*switch statement replacement*/
    switch (bit)
    {
    case (BITLOW):
        //do first bit flip
        if (!robot->joints[i].bitflipLow())
        {
            printf("Error in changing object dictionary entry");
            return false;
        }

        // success, change bit flip state to high
        bitFlipState = BITHIGH;
        return false;
        break;

    case (BITHIGH):
        //do second bit flip
        if (!robot->joints[i].bitflipHigh())
        {
            printf("Error in changing object dictionary entry");
            return false;
        }
        // bitflipHigh successful, change bitFlip state to unengaged and retrun true
        bitFlipState = NOFLIP;
        printf("Bit has been flipped for motor %d should move\n", robot->joints[i].getId());
        return true;
        break;
    default:
        //do nothing
        // printf("No motion triggered\n");
        break;
    }
}

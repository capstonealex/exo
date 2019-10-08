
//
// Created by William Campbell on 2019-09-30.
//

#include "bendTest.h"
#define OWNER ((bendTest *)owner)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)
// For testing
#define KNEE_MOTOR_POS1 (250880)

// State Machine bendTest methods ----------------------------------------------------------
bendTest::bendTest(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isPressed = new IsPressed(this);
    isBentP = new IsBentP(this);
    isBentN = new IsBentN(this);
    // StateMache states
    idle = new Idle(this);
    bent = new Bent(this);
    bendingN = new BendingN(this);
    bendingP = new BendingP(this);

    // Create Trasitions between states and events which trigger them
    NewTransition(idle, isPressed, bendingP);
    NewTransition(bendingP, isBentP, bent);
    NewTransition(bent, isPressed, bendingN);
    NewTransition(bendingN, isBentN, idle);

    // Initialize the state machine with first state
    StateMachine::initialize(idle);
    robot = NULL;
    bitFlipState = NOFLIP;

    // Convert hardcoded trajectories to actual motor commands
    // Test for LKNE
    // motorPosArrayConverter(posTrajectoriesDeg, posTrajectories, LKNEE);
    // motorPosArrayConverter(negTrajectoriesDeg, negTrajectories, LKNEE);
}

void bendTest::init(void)
{
    mark = 1;
    std::cout << "Welcome to The single joint bend STATE MACHINE"
              << "\n";
    StateMachine::init();
}
void bendTest::activate(void)
{
    StateMachine::activate();
}
void bendTest::deactivate(void)
{
    StateMachine::deactivate();
}
// State Methods ----------------------------------------------------------
// Moving states
// Positive bending control machine
void bendTest::BendingP::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Positive State  Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    OWNER->robot->joints[1].zeroIndex();
    printf("array index set to zero\n");
}
void bendTest::BendingP::during(void)
{

    //// DO FOR EACH JOINT
    ///for (auto i = 0; i < 4; i++) {
    int desiredIndex = OWNER->robot->joints[1].getIndex();
    // Make sure not to move array index past last member of array
    if (desiredIndex != (OWNER->robot->joints[1].NUM_TRAJ_POINTS))
    {
        // Get position to send to joint based on current arrayIndex, send off and increment index
        // desired Position in motor command units
        long desiredPos = OWNER->robot->joints[1].posTrajectories[desiredIndex];
        /*SINGLE JOINT FUNCTIONALITY TEST*/
        //first member of array
        if (desiredIndex == 0)
        {
            printf("Bending to motor command %f\n", desiredPos);
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            OWNER->robot->joints[1].incrementIndex();
        }
        // check if last last position reached -> go to next position
        // long last = OWNER->posTrajectories[OWNER->arrayIndex - 1]
        // long current =OWNER->robot->joints[1].getPos()
        // More conservative: else if (current>(last-30) current>(last+30))
        /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
        else if (OWNER->robot->joints[1].getPos() == OWNER->robot->joints[1].posTrajectories[desiredIndex - 1])
        {
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            printf("Bending to pos %ld\n", desiredPos);
            OWNER->robot->joints[1].incrementIndex();
        }
        /*ALL JOINT MOTION*/
        // check if last last position reached -> go to next position
        //        for (auto i = 0; i < 4; i++) {
        //            //// TODO: CHANGE arrayIndex and Trajectories to be owned by each joint for easier, indexing and addressing
        //            if (OWNER->robot->joints[i].getPos() == OWNER->posTrajectories[OWNER->arrayIndex - 1]) {
        //                OWNER->robot->joints[i].applyPos(desiredPos);
        //                // set state machine bitFlip to LOW state.
        //                OWNER->bitFlipState = BITLOW;
        //                printf("Bending to pos %f\n", desiredPos);
        //                OWNER->arrayIndex++;
        //                // Do first bit flip
        //                // change stateMachine bit flip value to first one
        //            }
        //        }
    }
    else
    {
        // change 1 to i after single joint works
        if (OWNER->robot->joints[1].getPos() == OWNER->robot->joints[1].posTrajectories[desiredIndex - 1])
        {
            printf("Final position of joint %d reached\n,", OWNER->robot->joints[1].getId());
        }
        else
        {
            printf("Joint %d Still going to final position\n", OWNER->robot->joints[1].getId());
        }
    }
    // BITFLIP FUNCTION to trigger low and high bit flip needed for motor motion
    OWNER->bitFlip();
}

void bendTest::BendingP::exit(void)
{

    printf("Bending Positive State Exited at Time %f\n", OWNER->mark);
    OWNER->robot->joints[1].zeroIndex();
}
// Negative bending control machine
void bendTest::BendingN::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Negative State  Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    OWNER->robot->joints[1].zeroIndex();
}
void bendTest::BendingN::during(void)
{
    //// DO FOR EACH JOINT
    ///for (auto i = 0; i < 4; i++) {
    int desiredIndex = OWNER->robot->joints[1].getIndex();
    // Make sure not to move array index past last member of array
    if (desiredIndex != (OWNER->robot->joints[1].NUM_TRAJ_POINTS + 1))
    {
        // Get position to send to joint based on current arrayIndex, send off and increment index
        // desired Position in motor command units
        float desiredPos = OWNER->robot->joints[1].negTrajectories[desiredIndex];
        /*SINGLE JOINT FUNCTIONALITY TEST*/
        //first member of array
        if (desiredIndex == 0)
        {
            printf("Bending to motor command %f\n", desiredPos);
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            OWNER->robot->joints[1].incrementIndex();
        }
        // check if last last position reached -> go to next position
        // long last = OWNER->posTrajectories[OWNER->arrayIndex - 1]
        // long current =OWNER->robot->joints[1].getPos()
        // More conservative: else if (current>(last-30) current>(last+30))
        /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
        else if (OWNER->robot->joints[1].getPos() == OWNER->robot->joints[1].negTrajectories[desiredIndex - 1])
        {
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            printf("Bending to pos %f\n", desiredPos);
            OWNER->robot->joints[1].incrementIndex();
        }
        /*ALL JOINT MOTION*/
        // check if last last position reached -> go to next position
        //        for (auto i = 0; i < 4; i++) {
        //            //// TODO: CHANGE arrayIndex and Trajectories to be owned by each joint for easier, indexing and addressing
        //            if (OWNER->robot->joints[i].getPos() == OWNER->posTrajectories[OWNER->arrayIndex - 1]) {
        //                OWNER->robot->joints[i].applyPos(desiredPos);
        //                // set state machine bitFlip to LOW state.
        //                OWNER->bitFlipState = BITLOW;
        //                printf("Bending to pos %f\n", desiredPos);
        //                OWNER->arrayIndex++;
        //                // Do first bit flip
        //                // change stateMachine bit flip value to first one
        //            }
        //        }
    }
    else
    {
        // change 1 to i after single joint works
        if (OWNER->robot->joints[1].getPos() == OWNER->robot->joints[1].negTrajectories[desiredIndex - 1])
        {
            printf("Final position of joint %d reached\n,", OWNER->robot->joints[1].getId());
        }
        else
        {
            printf("Joint %d Still going to final position\n", OWNER->robot->joints[1].getId());
        }
    }
    // BITFLIP FUNCTION to trigger low and high bit flip needed for motor motion
    OWNER->bitFlip();
}
void bendTest::BendingN::exit(void)
{

    printf("Bending Negative State Exited at Time %f\n", OWNER->mark);
    OWNER->robot->joints[1].zeroIndex();
}
// Bent(90deg)
void bendTest::Bent::entry(void)
{
    //READ TIME OF MAIN
    printf("Bent State Entered at Time %f\n", OWNER->mark);
}
void bendTest::Bent::during(void)
{
}
void bendTest::Bent::exit(void)
{

    printf("Bent State Exited at Time %f\n", OWNER->mark);
}
// Idle (0 deg) and ready to move
void bendTest::Idle::entry(void)
{
    //READ TIME OF MAIN
    printf("Idle State Entered at Time %f\n", OWNER->mark);
}
void bendTest::Idle::during(void)
{
    // printf("BUTTON IS: %d", OWNER->button);
}
void bendTest::Idle::exit(void)
{

    printf("Idle State Exited at Time %f\n", OWNER->mark);
}
// Events ------------------------------------------------------------
bool bendTest::IsBentP::check(void)
{
    if (OWNER->robot->joints[1].getPos() >= KNEE_MOTOR_POS1)
    {
        return true;
    }
    return false;
}
bool bendTest::IsBentN::check(void)
{
    if (OWNER->robot->joints[1].getPos() <= 0)
    {
        return true;
    }
    return false;
}
bool bendTest::IsPressed::check(void)
{
    if (OWNER->button == 0)
    {
        return true;
    }
    return false;
}

// Robot interface methods ----------------------------------------------------------
void bendTest::initRobot(Robot *rb)
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
void bendTest::hwStateUpdate(void)
{
    /*BUTON CODE*/
    // Once working Turn button into its own class and object: call button.getState() return 0 or 1, Statemachines have a button or an event could even

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
    this->button = greenbtn;
    gp->~GPIOManager();
    // printf("%d %d %d %d\n", redbtn, bluebtn, yellowbtn, greenbtn);

    // Update loop time counter
    mark = mark + 1;
    // Update Joint angle from register
    robot->joints[1].updateJoint();
    // Update all the robots joint values.
    robot->updateJoints();
    // robot->printInfo();
}

/*
 * bitFlip returns true if the second bit flip has occured, signalling a movement, else returns flase
 * 
 * 
 * 
*/
bool bendTest::bitFlip(void)
{
    int bit = bitFlipState;
    /*switch statement replacement*/
    switch (bit)
    {
    case (BITLOW):
        //do first bit flip
        if (!robot->joints[1].bitflipLow())
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
        if (!robot->joints[1].bitflipHigh())
        {
            printf("Error in changing object dictionary entry");
            return false;
        }
        // bitflipHigh successful, change bitFlip state to unengaged and retrun true
        bitFlipState = NOFLIP;
        printf("Last sent command to motor %d sent\n", robot->joints[1].getId());
        return true;
        break;
    default:
        //do nothing
        printf("No motion triggered\n");
        break;
    }
}

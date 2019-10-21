

//
// Created by William Campbell on 2019-09-30.
//

#include "bendTest.h"
#include "CO_command.h"
#define OWNER ((bendTest *)owner)
#define POSCLEARANCE (10000)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)
// For testing
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_POS2 (0)
struct timeval timeMark;
struct timeval loopTime;
double markTime;
double timeLoop;
double velocityTime;

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

// void bendTest::init(void)
// {
//     mark = 1;
//     std::cout << "Welcome to The single joint bend STATE MACHINE"
//               << "\n";
//     StateMachine::init();
// }
//// FOR TESTING
void bendTest::init(void)
{
    mark = 1;
    calibrated = 0;
    std::cout << "Welcome to The single joint bend STATE MACHINE"
              << "\n";
    StateMachine::init();
    // Do'nt start robot unless drives have been configured for position control.
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
    if(OWNER->robot->velocityControl == 0){
    if (OWNER->robot->initVelocityControl()){
        printf("drives finished velocity control configuration\n");
        OWNER->robot->velocityControl = 1;

    }
    }
    char SDO_MessageListB[][100] = {
        "[1] 2 write 0x6060 0 i8 3",
        "[1] 2 write 0x6040 0 i16 15",
        "[1] 2 write 0x6040 0 i16 31"
    };
    char *returnMessage;
    cancomm_socketFree(SDO_MessageListB[0], returnMessage);
    cancomm_socketFree(SDO_MessageListB[1], returnMessage);
    cancomm_socketFree(SDO_MessageListB[2], returnMessage);


    gettimeofday(&timeMark, NULL);
    markTime = timeMark.tv_sec*1000 +timeMark.tv_usec/1000;
    printf("mark time init: %lf\n",markTime);
    OWNER->startPos = OWNER->robot->joints[1].getPos();
    printf("joint 1 pos: %d\n",OWNER->startPos);
    // OWNER->robot->joints[1].bitflipLow;
    // OWNER->robot->joints[1].bitflipHigh;
    // Set arrayIndex to zero
    // OWNER->robot->joints[1].zeroIndex();
    // printf("array index set to zero\n");
}
void bendTest::BendingP::during(void)
{
    long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    // if (!OWNER->greenButton)
    // {
        gettimeofday(&loopTime, NULL);
        timeLoop = loopTime.tv_sec*1000 +loopTime.tv_usec/1000;
        printf("time loop time init: %lf\n",timeLoop);

        velocityTime = timeLoop - markTime;
        printf("vel time init: %lf\n",velocityTime);

        //Hardcooded fixed velocity PDO test
        /* if(velocityTime<=10000){
            OWNER->robot->joints[1].setVel(100000);
        }else
        {
            OWNER->robot->joints[1].setVel(0);
        } */

        //Velocity control loop for lknee that goes moves 70 degrees in 3 seconds
        if(velocityTime<=3000){
            OWNER->ePos = OWNER->getDesPos(velocityTime, 200000, 3000, OWNER->startPos) - OWNER->robot->joints[1].getPos();
            OWNER->eVel = OWNER->getDesVel(velocityTime, 200000, 3000) - OWNER->robot->joints[1].getVel(); 
            printf("pos is %d\n",OWNER->robot->joints[1].getPos());
            OWNER->qdotnew = OWNER->getDesVel(velocityTime, 200000, 3000) + 0.1*OWNER->ePos;
            printf("new velocity is %ld\n", OWNER->qdotnew);
            OWNER->robot->joints[1].setVel(OWNER->qdotnew);
        }
        else
        {
            OWNER->robot->joints[1].setVel(0);
        }
        // printf("CURRENT JOINT position: %d \n,", OWNER->robot->joints[1].getPos());
        // //// DO FOR EACH JOINT
        // ///for (auto i = 0; i < 4; i++) {
        // int desiredIndex = OWNER->robot->joints[1].getIndex();
        // // Make sure not to move array index past last member of array
        // if (desiredIndex != (OWNER->robot->joints[1].NUM_TRAJ_POINTS))
        // {
        //     // Get position to send to joint based on current arrayIndex, send off and increment index
        //     // desired Position in motor command units
        //     long desiredPos = OWNER->robot->joints[1].posTrajectories[desiredIndex];
        //     lastTarget = OWNER->robot->joints[1].posTrajectories[desiredIndex - 1];
        //     /*SINGLE JOINT FUNCTIONALITY TEST*/
        //     //first member of array
        //     if (desiredIndex == 0)
        //     {
        //         printf("Bending to motor command %f\n", desiredPos);
        //         OWNER->robot->joints[1].applyPos(desiredPos);
        //         // set state machine bitFlip to LOW state.
        //         OWNER->robot->joints[1].incrementIndex();
        //         OWNER->bitFlipState = BITLOW;
        //     }
        //     // check if last last position reached -> go to next position
        //     /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
        //     else if ((desiredIndex > 0) && OWNER->robot->joints[1].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[1].getPos() < (lastTarget + POSCLEARANCE))
        //     {
        //         OWNER->robot->joints[1].applyPos(desiredPos);
        //         // set state machine bitFlip to LOW state.
        //         OWNER->bitFlipState = BITLOW;
        //         printf("Bending to pos %ld\n", desiredPos);
        //         OWNER->robot->joints[1].incrementIndex();
        //     }
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
        // }
    //     else
    //     {
    //         // change 1 to i after single joint works
    //         if (OWNER->robot->joints[1].getPos() == OWNER->robot->joints[1].posTrajectories[desiredIndex - 1])
    //         {
    //             printf("Final position of joint %d reached\n,", OWNER->robot->joints[1].getId());
    //         }
    //         else
    //         {
    //             printf("Joint %d Still going to final position\n", OWNER->robot->joints[1].getId());
    //         }
    //     }
    //     // BITFLIP FUNCTION to trigger low and high bit flip needed for motor motion
    //     OWNER->bitFlip();
    // }
    // else
    // {
    // }
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
    printf("Entered during state\n");
    long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    if (!OWNER->greenButton)
    {
        printf("CURRENT JOINT position: %d \n,", OWNER->robot->joints[1].getPos());
        //// DO FOR EACH JOINT
        ///for (auto i = 0; i < 4; i++) {
        int desiredIndex = OWNER->robot->joints[1].getIndex();
        // Make sure not to move array index past last member of array
        if (desiredIndex != (OWNER->robot->joints[1].NUM_TRAJ_POINTS))
        {
            // Get position to send to joint based on current arrayIndex, send off and increment index
            // desired Position in motor command units
            long desiredPos = OWNER->robot->joints[1].negTrajectories[desiredIndex];
            lastTarget = OWNER->robot->joints[1].negTrajectories[desiredIndex - 1];
            /*SINGLE JOINT FUNCTIONALITY TEST*/
            //first member of array
            if (desiredIndex == 0)
            {
                printf("Bending to motor command %ld\n", desiredPos);
                OWNER->robot->joints[1].applyPos(desiredPos);
                // set state machine bitFlip to LOW state.
                OWNER->robot->joints[1].incrementIndex();
                OWNER->bitFlipState = BITLOW;
            }
            // check if last last position reached -> go to next position
            /*THE BELLOW CONDITION MUST BOTH BE IN THE SAME UNITS, either deg or motorCOMMAND units*/
            else if ((desiredIndex > 0) && OWNER->robot->joints[1].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[1].getPos() < (lastTarget + POSCLEARANCE))
            {
                OWNER->robot->joints[1].applyPos(desiredPos);
                // set state machine bitFlip to LOW state.
                OWNER->bitFlipState = BITLOW;
                printf("Bending to motor command %ld\n", desiredPos);
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
            lastTarget = OWNER->robot->joints[1].negTrajectories[desiredIndex - 1];
            // change 1 to i after single joint works
            if (OWNER->robot->joints[1].getPos() > (lastTarget - POSCLEARANCE) && OWNER->robot->joints[1].getPos() < (lastTarget + POSCLEARANCE))
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
    else
    {
    }
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
void bendTest::Idle::entry(void)
{
    if(OWNER->calibrated == 0){
        if(OWNER->robot->remapPDO()){
            printf("Motors PDO messages configured\n");
            OWNER->calibrated = 1;
        }
    }

    printf("Calibration State Entered at Time %f\n", OWNER->mark);
}
void bendTest::Idle::during(void)
{
    printf("Entered idle state\n");
  // Press yellow button to leave state
}
void bendTest::Idle::exit(void)
{
    printf("Calibration State Exited at Time %f\n", OWNER->mark);
}
// Events ------------------------------------------------------------
bool bendTest::IsBentP::check(void)
{
    if (OWNER->robot->joints[1].getPos() > (KNEE_MOTOR_POS1 - POSCLEARANCE) && OWNER->robot->joints[1].getPos() < (KNEE_MOTOR_POS1 + POSCLEARANCE))
    {
        return true;
    }
    return false;
}
bool bendTest::IsBentN::check(void)
{
    if(OWNER->robot->joints[1].getPos() > (KNEE_MOTOR_POS2 - POSCLEARANCE) && OWNER->robot->joints[1].getPos() < (KNEE_MOTOR_POS2 + POSCLEARANCE))
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
    this->button = yellowbtn;
    this->greenButton = greenbtn;
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
        printf("Bit has been flipped for motor %d should move\n", robot->joints[1].getId());
        return true;
        break;
    default:
        //do nothing
        printf("No motion triggered\n");
        break;
    }
}

double bendTest::getDesPos(double time, double posDelta, double endTime, double initPos) {
    double pos =
            pow(time, 3) * (-2 * posDelta / (pow(endTime, 3))) + pow(time, 2) * (3 * posDelta / (pow(endTime, 2))) +
            initPos;
    return pos;
}
double bendTest::getDesVel(double time, double posDelta, double endTime){
    double vel = 3*pow(time,2)*(-2*posDelta/(pow(endTime,3))) + 2*time*(3*posDelta/(pow(endTime,2)));
    return vel*10000;
}
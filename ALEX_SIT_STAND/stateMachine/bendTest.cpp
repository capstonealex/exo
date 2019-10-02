
//
// Created by William Campbell on 2019-09-30.
//

#include "bendTest.h"
#define OWNER ((bendTest *)owner)
#define NOFLIP (100) 
#define BITHIGH (1)
#define BITLOW (0)

//Node ID for the 4 joints
#define LHIP (1)
#define LKNEE (2)
#define RHIP (3)
#define RKNEE (4)
//Knee motor reading and corresponding angle. Used for mapping between degree and motor values.
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_DEG1 (90)
#define KNEE_MOTOR_POS2 (0)
#define KNEE_MOTOR_DEG2 (0)
//Hip motor reading and corresponding angle. Used for mapping between degree and motor values.
#define HIP_MOTOR_POS1 (250880)
#define HIP_MOTOR_DEG1 (90)
#define HIP_MOTOR_POS2 (0)
#define HIP_MOTOR_DEG2 (180)

// State Machine Constructors ----------------------------------------------------------
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
    motorPosArrayConverter(posTrajectoriesDeg,posTrajectories, LKNEE);
    motorPosArrayConverter(negTrajectoriesDeg,negTrajectories, LKNEE);

}

/*Helper functions for motor deg to command conversion*/
// TODO -> don't use this and only use trajectory function
//Used to convert position array from degrees to motors counts as used in CANopen
void motorPosArrayConverter(std::vector<double>  origArr,std::vector<long> newArr, int nodeid)
{
    double A = 0;
    double B = 0;

    if (nodeid == 1 || nodeid == 3)
        calcAB(HIP_MOTOR_POS1, HIP_MOTOR_DEG1, HIP_MOTOR_POS2, HIP_MOTOR_DEG2, &A, &B);

    if (nodeid == 2 || nodeid == 4)
        calcAB(KNEE_MOTOR_POS1, KNEE_MOTOR_DEG1, KNEE_MOTOR_POS2, KNEE_MOTOR_DEG2, &A, &B);

    for (int i : origArr)
    {
        newArr.push_back((long)(A * origArr[i] + B));
    }
}

//calculate A and B in the formula y=Ax+B. Use by motorPosArrayConverter()
void calcAB(long y1, long x1, long y2, long x2, double *A, double *B)
{
    *A = 1.0 * (y2 - y1) / (x2 - x1);
    //printf("A is %f\n", *A);
    *B = 1.0 * (y1 * x2 - y2 * x1) / (x2 - x1);
    //printf("B is %f\n", *B);
}
// State Machine bendTest methods ----------------------------------------------------------
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
    OWNER->arrayIndex = 0;


}
void bendTest::BendingP::during(void) {
    //// DO FOR EACH JOINT
    ///for (auto i = 0; i < 4; i++) {
    // Make sure not to move array index past last member of array
    if (OWNER->arrayIndex != OWNER->posTrajectories.size()) {
        // Get position to send to joint based on current arrayIndex, send off and increment index
        float desiredPos = OWNER->posTrajectories[OWNER->arrayIndex];
        /*SINGLE JOINT FUNCTIONALITY TEST*/
        // check if last last position reached -> go to next position
        if (OWNER->robot->joints[1].getPos() == OWNER->posTrajectories[OWNER->arrayIndex - 1]) {
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            printf("Bending to pos %f\n", desiredPos);
            OWNER->arrayIndex++;
            // Do first bit flip
            // change stateMachine bit flip value to first one
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
    else{
        // change 1 to i after single joint works
        if(OWNER->robot->joints[1].getPos() == OWNER->posTrajectories[OWNER->arrayIndex-1]) {
            printf("Final position of joint %d reached\n,",OWNER->robot->joints[1].getID())
        }
        else{
            printf("Joint %d Still going to final position\n",OWNER->robot->joints[1].getID() );
        }
    }
    // BITFLIP FUNCTION to trigger low and high bit flip needed for motor motion
    OWNER.bitflip();
    
}
void bendTest::BendingP::exit(void)
{

    printf("Bending Positive State Exited at Time %f\n", OWNER->mark);
}
// Negative bending control machine
void bendTest::BendingN::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Positive State  Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    OWNER->arrayIndex = 0;
}
void bendTest::BendingN::during(void) {
    printf("Current joint position %f\n", OWNER->robot->joints[1].getPos());
    if (OWNER->arrayIndex != OWNER->negTrajectories.size()){
        float desiredPos = OWNER->negTrajectories[OWNER->arrayIndex];
        //BIT FLIP FUNCTION
        OWNER->robot->joints[1].applyPos(desiredPos);
        printf("Bending to pos %f\n", desiredPos);
        OWNER->arrayIndex ++;
    }
    else{
        printf("Final position reached\n");
    }
}
void bendTest::BendingN::exit(void)
{

    printf("Bending Positive State Exited at Time %f\n", OWNER->mark);
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
}
void bendTest::Idle::exit(void)
{

    printf("Idle State Exited at Time %f\n", OWNER->mark);
}
// Events ------------------------------------------------------------
bool bendTest::IsBentP::check(void)
{
    if (OWNER->robot->joints[1].getPos()>=90)
    {
        return true;
    }
    return false;
}
bool bendTest::IsBentN::check(void)
{
    if (OWNER->robot->joints[1].getPos()<=0)
    {
        return true;
    }
    return false;
}
bool bendTest::IsPressed::check(void)
{
    if (OWNER->button == 1)
    {
        return true;
    }
    return false;
}

// Robot interface methods ----------------------------------------------------------
void bendTest::initRobot( Robot *rb ) {

    if ( robot != NULL ) {
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
    static char *BUTTON1 = "P9_23";
    int holder;
    GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
    int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
    gp->setDirection(pin, GPIO::INPUT);
    holder = gp->getValue(pin);
    this->button = holder;
    gp->~GPIOManager();

    // Update loop time counter
    mark = mark + 1;
    // Update Joint angle from register
//    robot->joints[1].updateJoint();
    // Update all the robots joint values.
    robot.updateJoints();

}

/*
 * bitFlip returns true if the second bit flip has occured, signalling a movement, else returns flase
 * 
 * 
 * 
*/
bool bendTest::bitFlip(void){
    // DO BIT FLIPS FOR EACH joiny
    // for loop for all joints and bitFipState[0] to 3 for each joint
    if(bitFlipState == BITLOW){
        // Do first bit flip
        // print error if bit not flipped
        if(!robot->joints[1].bitflipLow;){
            printf("Error in changing object dictionary entry");
            return false;
        }
        else{
            // success, change bit flip state to high
            bitFlipState = BITHIGH;
            return false;
        }

    }
    else if(bitFlipState == BITHIGH){
        // Do second bit flip
        if(!robot->joints[1].bitflipHigh;){
        printf("Error in changing object dictionary entry");
        return false;
        }
        else{
            // bitflipHigh successful, change bitFlip state to unengaged and retrun true
            bitFlipState = NOFLIP;
            printf("Last sent command to motor %d sent\n",robot->joints[1]->id);
            return true;
        }

    }
    else {
        // Do nothing
    }

}
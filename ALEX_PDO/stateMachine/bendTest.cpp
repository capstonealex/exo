
//
// Created by William Campbell on 2019-09-30.
//

#include "bendTest.h"
#define OWNER ((bendTest *)owner)

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
    OWNER->arrayIndex = 0;


}
void bendTest::BendingP::during(void) {
    // Get position to send to joint based on current arrayIndex, send off and increment index
    float desiredPos =OWNER->posTrajectories[OWNER->arrayIndex];
    // Make sure not to move array index past last member of array
    if (OWNER->arrayIndex != OWNER->posTrajectories.size()){
        //BIT FLIP FUNCTION
        OWNER->robot->joints[1].applyPos(desiredPos);
        
        printf("Bending to pos %f\n", desiredPos);
        OWNER->arrayIndex ++;
    }
    else{
        printf("Final position reached\n");
    }
    
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

// Loop counter test method
void bendTest::toyUpdate(void)
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
    robot->joints[1].updateJoint();
    float ya = robot->joints[1].getPos();
    printf("Robot joint is at: %f\n", ya);


}
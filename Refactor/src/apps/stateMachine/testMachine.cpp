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
#include "testMachine.h"

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE
/////////////////////////////////////////////////////////

#define OWNER ((exoStateMachine *)owner)

/////////////////////////////////////////////////////////
// State Machine exoStateMachine methods ----------------------------------------------------------
/////////////////////////////////////////////////////////

exoStateMachine::exoStateMachine(void) {
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isGPressed = new IsGPressed(this);
    endTraj = new EndTraj(this);
    startButtonsPressed = new StartButtonsPressed(this);
    startExo = new StartExo(this);
    startSit = new StartSit(this);
    startStand = new StartStand(this);
    standing = new Standing(this);
    sitting = new Sitting(this);
    standingUp = new StandingUp(this);
    sittingDwn = new SittingDwn(this);

    // Trajectory Transitions
    NewTransition(initState, startExo, sitting);
    NewTransition(sitting, startStand, standingUp);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(standing, startSit, sittingDwn);
    NewTransition(sittingDwn, endTraj, sitting);
    // Initialize the state machine with first state
    StateMachine::initialize(initState);
    robot = NULL;
}

void exoStateMachine::init(void) {
    StateMachine::init();
}
void exoStateMachine::activate(void) {
    StateMachine::activate();
}
void exoStateMachine::deactivate(void) {
    StateMachine::deactivate();
}
void exoStateMachine::update(void) {
    StateMachine::update();
}

////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool exoStateMachine::EndTraj::check(void) {
    //implement with movethroughztraj
    return true;
}
///KEYBOARD AS BUTTON///
////TODO: IMPLEMENT once compilining
//////////// BUTTON PRESS CHECKS //////////////
bool exoStateMachine::IsGPressed::check(void) {
    if (OWNER->robot->buttons.getGButtonState() == 0) {
        return true;
    }
    return false;
}
bool exoStateMachine::StartButtonsPressed::check(void) {
    if (OWNER->robot->buttons.getBButtonState() == 0 && OWNER->robot->buttons.getRButtonState() != 0 && OWNER->robot->buttons.getYButtonState() == 0 && OWNER->robot->buttons.getGButtonState() != 0) {
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////
//Crutch new Motion Paramater Events ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
/// TODO: CHANGE TO KEYBOARD INPUT
bool exoStateMachine::StartExo::check(void) {
    if ((CO_OD_RAM.currentMovement == 11) && OWNER->robot->buttons.getGButtonState() == 0) {
        std::cout << "LEAVING INIT and entering Sitting" << endl;
        return true;
    }
    return false;
}
bool exoStateMachine::StartStand::check(void) {
    if ((CO_OD_RAM.currentMovement == STNDUP) && OWNER->robot->buttons.getGButtonState() == 1) {
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[STNDUP]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}

bool exoStateMachine::StartSit::check(void) {
    if (CO_OD_RAM.currentMovement == SITDWN && OWNER->robot->buttons.getGButtonState() == 1) {
        // Set trajOBJECT paramaters to selected nexMOVEMENT
        OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[SITDWN]);
        // RESET OD_NM for safety
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
void exoStateMachine::initRobot(ExoRobot *rb) {
    if (robot != NULL) {
        printf("Robot object already selected");
    }
    robot = rb;
    robot->buttons.initButtons();
    // robot->printInfo();
};

// Update button state, loop counter (mark) and joints
void exoStateMachine::hwStateUpdate(void) {
    //cout << "looping" << endl;
    robot->buttons.setButtonStates();
    // Check for commands from Crutch, when new nm sent send back that cm has been changed
    // Proper event now checks for that cm index and the next gButton press to transition
    CO_OD_RAM.currentMovement = CO_OD_RAM.nextMovement;
    if (cm != CO_OD_RAM.currentMovement) {
        cm = CO_OD_RAM.currentMovement;
        std::cout << "NEXT MOTION: " << cm << std::endl;
    }
    mark = mark + 1;
    robot->updateRobot();
}

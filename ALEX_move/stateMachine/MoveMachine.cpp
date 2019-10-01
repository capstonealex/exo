//
// Created by William Campbell on 2019-09-24.
//

#include "../../ALEX/stateMachine/ToyMachine.h"
#define OWNER ( ( ToyMachine * ) owner )

// Events ------------------------------------------------------------
bool ToyMachine::EventOne::check ( void ) {
    // check function is if 1001 counts has occured
    return bool( count > OWNER->mark + 1.0 );

}

// States ------------------------------------------------------------
void ToyMachine::StateOne::entry ( void) {
    //READ TIME OF MAIN
    OWNER->mark ;
    printf ( "State One Entered at Time %f\n", OWNER->mark );

}
void ToyMachine::StateOne::during ( void ) {}
void ToyMachine::StateOne::exit ( void ) {

    printf ( "State One Exited at Time %f\n", OWNER->mark );

}

void ToyMachine::StateTwo::entry ( void ) {

    printf ( "State Two Entered at Time %f\n", OWNER->mark );

}
void ToyMachine::StateTwo::during ( void ) {}
void ToyMachine::StateTwo::exit ( void ) {}

ToyMachine::ToyMachine ( void ) {

    // allocate events : provide pointer to this state machine as owner
    eventOne = new EventOne ( this );
    eventOne.count = 1000;
    // allocate states: provide pointer to this state machine as owner
    stateOne = new StateOne ( this );
    stateTwo = new StateTwo ( this );

    // transitions  -> TURN INTO A MACRO
    stateOne->addArc( new Transition ( stateTwo, eventOne ) )
    // set initial State to state ONe
    initialize ( stateOne );

}

ToyMachine::~ToyMachine ( void ) {

    if ( eventOne ) delete ( eventOne );
    if ( stateOne ) delete ( stateOne );
    if ( stateTwo ) delete ( stateTwo );

}

void ToyMachine::init ( void ) {
    printf ("Welcome to THE TOY STATE MACHINE \n");
    StateMachine::init();

}

void ToyMachine::activate ( void ) {

    StateMachine::activate();

}

void ToyMachine::deactivate ( void ) {
    printf ("Toy machine deactivated \n");
    StateMachine::deactivate();

}
//// FOR TESTING -> NEED TO GIVE STATE MACHINE TIMING ACCESS

void ToyMachine::increaseCount ( int count ) {

    mark = count;

}

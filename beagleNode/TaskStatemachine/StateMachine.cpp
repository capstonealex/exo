//
// Created by William Campbell on 2019-09-24.
//
#include <stdio.h>
#include "StateMachine.h"
//State machine constructors
StateMachine::StateMachine(void ){
    initialState = NULL;
};
// Set initial state to input of constructor
StateMachine::StateMachine( State *i ){
    initialState = i;
};
// Set the pointer of the initial state
void StateMachine::initialize ( State * i ) {
    initialState = i;
};
State* StateMachine::getCurState( void ) {
    return currentState;
}

// methods
void StateMachine::init ( void ) {
    currentState = initialState;
}
void StateMachine::activate ( void ) {
    currentState = initialState;
    currentState->entry();
};

void StateMachine::update( void ) {

    Transition * t = currentState->getActiveArc();

    if ( t != NULL ) {

        currentState->exit();
        currentState = t->target;
        currentState->entry();

    }

    currentState->during();

}


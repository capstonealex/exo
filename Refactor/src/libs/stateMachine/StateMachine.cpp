//
// Created by William Campbell on 2019-09-24.
//
#include "StateMachine.h"

#include <stdio.h>

#include <iostream>

#include "DebugMacro.h"
//State machine constructors
StateMachine::StateMachine(void) {
    currentState = NULL;
};
// Set initial state to input of constructor
StateMachine::StateMachine(State *i){};
// Set the pointer of the initial state
void StateMachine::initialize(State *i) {
    currentState = i;
    DEBUG_OUT("StateMachine::initialize()")
}
State *StateMachine::getCurState(void) {
    //printf("getCurState:  %p\n", this);
    return currentState;
}
void StateMachine::init(void) {
}

void StateMachine::activate(void) {
    DEBUG_OUT("StateMachine::Activate")
    currentState->entry();
}
void StateMachine::deactivate(void) {
}
void StateMachine::update(void) {
    Transition *t = currentState->getActiveArc();
    if (t != NULL) {
        currentState->exit();
        this->currentState = t->target;
        currentState->entry();
    }
    currentState->during();
    // printf("Value:  %p\n", this);
}

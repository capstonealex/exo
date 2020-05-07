//
// Created by William Campbell on 2019-09-24.
//
#include "StateMachine.h"

#include <stdio.h>

#include <iostream>
//State machine constructors
StateMachine::StateMachine(void) {
    currentState = NULL;
};
// Set initial state to input of constructor
StateMachine::StateMachine(State *i){};
// Set the pointer of the initial state
void StateMachine::initialize(State *i) {
    currentState = i;
}
State *StateMachine::getCurState(void) {
    return currentState;
}
void StateMachine::init(void) {
}

void StateMachine::activate(void) {
    currentState->entry();
}
void StateMachine::deactivate(void) {
}
void StateMachine::update(void) {
    Transition *t = currentState->getActiveArc();
    if (t != NULL) {
        currentState->exit();
        currentState = t->target;
        currentState->entry();
    }
    currentState->during();
}

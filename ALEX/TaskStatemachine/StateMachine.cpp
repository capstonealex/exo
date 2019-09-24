//
// Created by William Campbell on 2019-09-24.
//
#include <stdio.h>
#include "StateMachine.h"


void StateMachine::activate ( void ) {
    currentState = initialState;
    currentState->entry();
};

void StateMachine::update( void ) {

    Arc * a = currentState->getActiveArc();

    if ( a != NULL ) {

        currentState->exit();
        currentState = a->target;
        currentState->entry();

    }

    currentState->during();

}


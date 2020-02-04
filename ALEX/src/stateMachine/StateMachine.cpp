//
// Created by William Campbell on 2019-09-24.
//
#include <stdio.h>
#include <iostream>
#include "StateMachine.h"
//State machine constructors
StateMachine::StateMachine(void)
{
    initialState = NULL;
};
// Set initial state to input of constructor
StateMachine::StateMachine(State *i)
{
    initialState = i;
};
// Set the pointer of the initial state
void StateMachine::initialize(State *i)
{
    initialState = i;
    std::cout << "Initial state set\n";
    std::cout << "Current Active State name: "<< initialState << endl;
};
State *StateMachine::getCurState(void)
{
    return currentState;
}

// methods
void StateMachine::init(void)
{
    currentState = initialState;
}
void StateMachine::uninit(void)
{
}

void StateMachine::activate(void)
{
    printf("State entered\n");
    currentState = initialState;
    std::cout << "Current Active State name: "<< getCurState() <<endl;
    currentState->entry();
}
void StateMachine::deactivate(void)
{
}
void StateMachine::update(void)
{
    printf("UPDATE FUNCTION Entered\n");
    std::cout << "Current Active State name: "<< getCurState() <<endl;
    Transition *t = currentState->getActiveArc();
    if (t != NULL)
    {
        currentState->exit();
        currentState = t->target;
        currentState->entry();
    }
    printf("durring function called\n");
    currentState->during();
    printf("durring function finished calling\n");

}

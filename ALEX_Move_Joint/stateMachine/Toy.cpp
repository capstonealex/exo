//
// Created by William Campbell on 2019-09-26.
// The Toy state machine demonstates the basic structure of creating an event based
// state machine using the provided classes: statemachine, state, transition and events.
// The state machine is designed to do as follows:
// BEGIN -> STATE1 (STAY HERE FOR 10 seconds) -----> STATE2 (print: I'm in state 2)
//

#include "Toy.h"
#include <iostream>
#define OWNER ((Toy *)owner)
// State Methods ----------------------------------------------------------
void Toy::StateOne::entry(void)
{
    //READ TIME OF MAIN
    OWNER->mark;
    printf("State One Entered at Time %f\n", OWNER->mark);
}
void Toy::StateOne::during(void) {}
void Toy::StateOne::exit(void)
{

    printf("State One Exited at Time %f\n", OWNER->mark);
}
// State Two
void Toy::StateTwo::entry(void)
{
    //READ TIME OF MAIN
    printf("State Two Entered at Time %f\n", OWNER->mark);
}
void Toy::StateTwo::during(void)
{
}
void Toy::StateTwo::exit(void)
{

    printf("State Two Exited at Time %f\n", OWNER->mark);
}
// Events ------------------------------------------------------------
bool Toy::EventOne::check(void)
{
    if (OWNER->mark > 10)
    {
        return true;
    }
    return false;
}
// Toy methods ----------------------------------------------------------
Toy::Toy(void)
{
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    eventOne = new EventOne(this);

    // StateMache states
    stateOne = new StateOne(this);
    stateTwo = new StateTwo(this);

    // Create Trasitions between states and events which trigger them
    NewTransition(stateOne, eventOne, stateTwo);

    std::cout << "TOY OBJECT CREATED\n";
    // Initialize the state machine with first state
    StateMachine::initialize(stateOne);
}
void Toy::init(void)
{
    mark = 1;
    std::cout << "Welcome to THE TOY STATE MACHINE"
              << "\n";
    StateMachine::init();
}
void Toy::activate(void)
{
    StateMachine::activate();
}
void Toy::deactivate(void)
{
    StateMachine::deactivate();
}
void Toy::toyUpdate(void)
{
    mark = mark + 1;
};
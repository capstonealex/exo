//
// Created by William Campbell on 2019-09-26.
//

#include "Toy.h"
#include <iostream>
void Toy::StateOne::entry ( void) {
    //READ TIME OF MAIN
    OWNER->mark ;
    printf ( "State One Entered at Time %f\n", OWNER->mark );

}
void Toy::StateOne::during ( void ) {}
void Toy::StateOne::exit ( void ) {

    printf ( "State One Exited at Time %f\n", OWNER->mark );

}


// Toy methods ----------------------------------------------------------
Toy::Toy(void)
{
    stateOne = new StateOne ( this );
    initialize ( stateOne );
}
void Toy::init(void)
{
    mark = 1;
    std::cout << "Welcome to THE TOY STATE MACHINE"<< "\n";
    StateMachine::init();
}
void Toy::activate(void)
{
}
void Toy::deactivate(void)
{
}
void Toy::toyUpdate(void)
{
    mark = mark + 1;
    std::cout << "State machine counter at: " << mark<<"\n";
};

//
// Created by William Campbell on 2019-09-24.
//

#include "State.h"

/* Cyclicly check the status of this states arc list, if any return true, return that arch object*/
Transition * State::getActiveArc( void ) {
    int i=0;
    while ( i<numarcs ) {
        if ( arclist[i]->ev->check() ) return arclist[i];
        i++;
    }
    return NULL;
}
/* Add an arc to the arc list -> done at initialization (specific for each statemachine)*/
bool State::addArc ( Transition * t ) {
    if ( numarcs < MAXARCS ) {
        arclist[numarcs++] = t;
        return true;
    } else return false;
};

const char * State::getName( void ) {
    return name;
};
//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_STATEMACHINE_H
#define EXO_STATEMACHINE_H
#include "State.h"

class StateMachine {
public:
    /* State machine constructors*/
    // No input arguments.
    StateMachine( ){
        initialState = NULL;
    };
    // Set initial state to input of constructor
    StateMachine( State *i ){
        initialState = i;
    };
    // Set the pointer of the initial state
    void initialize ( State * i ) {
        initialState = i;
    };
    State *getCurState( void ) {
        return currentState;
    };

    // methods
    void init ( void ) {
        currentState = initialState;
    }
    void uninit ( void ) {};
    void activate ( void ) ;
    void deactivate (void ) {};
    void update ( void );

private:

    // pointers to the initial state and the current state
    State * initialState;
    State * currentState;

};
#endif //EXO_STATEMACHINE_H

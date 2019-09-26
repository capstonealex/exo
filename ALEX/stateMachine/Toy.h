//
// Created by William Campbell on 2019-09-26.
//

#ifndef EXO_TOY_H
#define EXO_TOY_H


#include "StateMachine.h"

class Toy : public StateMachine {

public:

    Toy ( void );
    void init ( void );
    void activate ( void );
    void deactivate ( void );
    void toyUpdate(void);

private:

    // events
//    EventObject ( EventOne ) * eventOne;
//
//    // states
//    StateObject ( StateOne ) * stateOne;
//    StateObject ( StateTwo ) * stateTwo;

    // data
    double mark;

};




#endif //EXO_TOY_H

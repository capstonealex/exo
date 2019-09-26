//
// Created by William Campbell on 2019-09-26.
//

#ifndef EXO_TOY_H
#define EXO_TOY_H


#include "StateMachine.h"

// State one
class StateOne : public State {
    friend class ToyMachine ;
public:

    StateOne ( StateMachine *m const char *name = NULL ) : State ( m, name ) {};
    void entry ( void );
    void during ( void );
    void exit ( void );

}StateOne;

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
    stateOne SateOne;
//    StateObject ( StateTwo ) * stateTwo;

    // data
    double mark;

};




#endif //EXO_TOY_H

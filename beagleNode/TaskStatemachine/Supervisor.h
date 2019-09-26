//
// Created by William Campbell on 2019-09-24.
//

#include "StateMachine.hh"
#include "Event.h"
class Supervisor: public StateMachine {
public:

    Supervisor ( void );
    void init ( void );
    void activate ( void );
    void deactivate ( void );
private:

    // events
    Event TestEvent();
    EventObject ( StartCommand ) * startCommand;


    // states
    StateObject ( UnCalibrated ) * unCalibrated;


    // data
    StandMachine     * standMachine;
    WalkMachine       * walkMachine;
    CalibMachine     * calibMachine[6];
    Hardware         * hw;
    Input           * rc;
    ExtProfiler      accelProfile;
    double           mark;
    int              direction;
};


#endif //EXO_SUPERVISOR_H

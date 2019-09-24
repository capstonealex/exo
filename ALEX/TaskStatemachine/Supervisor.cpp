//
// Created by William Campbell on 2019-09-24.
//

#include "Supervisor.h"

Supervisor::Supervisor() {
    /*Create events*/
    testEvent = new testEvent (this, "testEvent");
    startCommand = new StartCommand ( this, "StartCommand" );
    calFail = new CalFail ( this, "CalFail" );
    calSuccess = new CalSuccess ( this, "CalSuccess" );
    /*Create state object*/
    testState = new testSate(this,"testState");
    testState2 = new testSate(this,"testState2");
    unCalibrated = new UnCalibrated ( this, "unCalibrated" );
    calibrating = new Calibrating ( this, "calibrating" );

    /*Create transitions*/


    /* Set the stateMAchines initial state */
    initialize ( unCalibrated );
     * /

}
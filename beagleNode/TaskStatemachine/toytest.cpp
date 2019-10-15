//
// Created by William Campbell on 2019-09-26.
//

// System includes
#include <stdio.h>
#include "sysutil.hh"

// Local includes
#include "StateMachine.h"
#include "ToyMachine.h"


int main( void ) {

    ToyMachine tm;

    tm.init();


    // in mainline thread run update()
    // increae count based on number of loops(testing) -> change to time -> then chagne to happen inside toymachine
    tm.increaseCount();
    tm.update();

    // delete toy machine

//    Shutdown();

    return 0;

}

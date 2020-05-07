// Init State Class publically inheriting State
#ifndef SITTING_H_INCLUDED
#define SITTING_H_INCLUDED

#include <time.h>

#include "ExoTestState.h"

class Sitting : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    Sitting(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
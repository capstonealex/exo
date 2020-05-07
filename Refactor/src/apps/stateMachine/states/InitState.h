// Init State Class publically inheriting State
#ifndef INITSTATE_H_INCLUDED
#define INITSTATE_H_INCLUDED

#include "ExoTestState.h"

class InitState : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    InitState(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
#ifndef SITTINGDWN_H_INCLUDED
#define SITTINGDWN_H_INCLUDED
#include "ExoTestState.h"

// forward declaration
class SittingDwn : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    SittingDwn(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
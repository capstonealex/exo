#ifndef STANDING_H_INCLUDED
#define STANDING_H_INCLUDED

#include "ExoTestState.h"

// forward declaration
class Standing : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    Standing(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
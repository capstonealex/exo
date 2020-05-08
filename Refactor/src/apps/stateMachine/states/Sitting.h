// Init State Class publically inheriting State
#ifndef SITTING_H_INCLUDED
#define SITTING_H_INCLUDED

#include <time.h>

#include "ExoTestState.h"

/**
 * @brief Sitting (stationary) State for the ExoTestMachine (implementing ExoTestState)
 * 
 * State machines enters this state when the sitting down trajectory is finished, and waits here for input
 */
class Sitting : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    Sitting(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
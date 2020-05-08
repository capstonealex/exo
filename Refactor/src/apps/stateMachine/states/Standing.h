#ifndef STANDING_H_INCLUDED
#define STANDING_H_INCLUDED

#include "ExoTestState.h"

/**
 * @brief Standing (stationary) State for the ExoTestMachine (implementing ExoTestState)
 * 
 * State machines enters this state when the standing up trajectory is finished, and waits here for input
 */
class Standing : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    Standing(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
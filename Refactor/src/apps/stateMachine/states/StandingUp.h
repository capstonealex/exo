#ifndef STANDINGUP_H_INCLUDED
#define STANDINGUP_H_INCLUDED

#include "ExoTestState.h"

/**
 * @brief Standing up (moving) state for the ExoTestMachine (implementing ExoTestState)
 * 
 * Starts the Standing Up trajectory on entry, executes in during, and exits when trajectory is complete
 */
class StandingUp : public ExoTestState {
   public:
    void entry(void);
    void during(void);
    void exit(void);
    StandingUp(StateMachine *m, ExoRobot *exo, DummyTrajectoryGenerator *tg, const char *name = NULL) : ExoTestState(m, exo, tg, name){};
};

#endif
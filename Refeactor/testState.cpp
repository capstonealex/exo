#include "exoStateMachine.h"

void InitState::entry(void)
{
    std::cout
        << "TEST STATE" << endl

                               // CO_OD_RAM.currentState = intToStateODMap[this.getName()]
                               CO_OD_RAM.currentState = OWNER->stateToIntODMap["Init"];
    std::cout << "current movement:" << CO_OD_RAM.currentMovement << std::endl;
}
void InitState::during(void)
{
    CO_OD_RAM.currentMovement = CO_OD_RAM.nextMovement;
}
void InitState::exit(void)
{
}

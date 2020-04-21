/**
 * The <code>Input</code> class is a abstract class which represents an input device.
 * The device has generic states which maintain the current values of the input device. 
 * For example if a button us being pressed or not.
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

#ifndef INPUT_H_INCLUDED
#define INPUT_DEVICE

#include <curses.h>

#include "Bitmask.h"
#include "DebugMacro.h"
#include "Input.h"
typedef struct keys {
    bool a;
    bool s;
    bool d;
    bool w;
    bool x;
    bool q;
} key_states;
class Keyboard : public Input {
   private:
    key_states lastKeyStates;
    key_states currentKeyStates;

   public:
    Keyboard();
    key_states getStates();
    // storing current keyboard input
    int ch;
    void setStates();
    void clearCurrentStates();
    void printPressed();
    // Returns true if the key is pressed.
    bool getA();
    bool getS();
    bool getD();
    bool getW();
    bool getX();
    bool getQ();
};
#endif
/**
 * The <code>Input</code> class is a abstract class which represents an input device.
 * The device has generic states which maintain the current values of the input device. 
 * For example if a button us being pressed or not.
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

#include <unistd.h>

#include "InputDevice.h"
#include "termios.h"
#define NB_DISABLE 0
#define NB_ENABLE 1
typedef struct keys {
    bool a;
    bool s;
    bool d;
    bool w;
    bool x;
    bool q;
} key_states;
class Keyboard : public InputDevice {
   private:
    key_states lastKeyStates;
    key_states currentKeyStates;
    int keyboardActive;

   public:
    Keyboard();
    ~Keyboard();
    key_states getStates();
    //termios structs for turning on and off terminal echo
    struct termios original, noecho;
    // storing current keyboard input
    char ch;
    // Check if keyboard has been hit - is stdin active
    int kbhit();
    // variable for storing output of kbhit
    // int keyboardActive;
    int getKeyboardActive();
    void setKeyboardActive(int value);
    void setKeys();
    void Update();
    // Turn on or off terminal canonical mode
    // Canonical mode (default): user must hit enter to confirm input.
    void nonblock(int state);

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
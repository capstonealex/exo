/**
 * The <code>Button</code> class represents an array of I/O buttons
 * This class can be implemented to any I/O hardware needed.
 * 
 * 
 * Version 0.1
 * Date: 07/04/2020
 *
 */
#ifndef BUTTONS_H
#define BUTTONS_H
#include <iostream>

typedef struct button_states {
    int gButton;
    int yButton;
    int bButton;
    int rButton;
} button_states;
class Buttons {
   private:
    button_states state;

   public:
    Buttons();
    bool isKeyPressed(int state);
    bool isKeyDown(int state);
    bool isKeyUp(int state);
    button_states getStates();
    void setStates();
};
#endif
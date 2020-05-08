/**
 * The <code>Button</code> class represents an array of I/O buttons
 * This class can be implemented to any I/O hardware needed.
 * 
 * 
 * Version 0.1
 * Date: 07/04/2020
 *
 */
#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED
#include <iostream>

/**
 * @brief Describes the state of a set of buttons which include a Green, Yellow, Blue and Red. Used within the Buttons class. - Not currently used
 * 
 * \todo Complete implementation
 * 
 */
struct button_states {
    int gButton;
    int yButton;
    int bButton;
    int rButton;
};

/**
 * @brief Buttons class, which represents a set of buttons. - Not currently used
 * 
 * \todo Complete implementation, make it extend the InputDevices class
 * 
 */
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
/**
 * The <code>Input</code> class is a abstract class which represents an input device.
 * The Update function is called in a main program to query the devices output and 
 * update any memory representation of the device implemented.
 * For example the keyboard implementation checks for key presses and fills key memory 
 * with a boolean value when pressed. See <code>Keyboard</code> for further detail.
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

#ifndef InputDevice_H_INCLUDED
#define InputDevice_H_INCLUDED
#include <iostream>
class InputDevice {
   private:
   public:
    InputDevice();
    virtual void updateInput() = 0;
};
#endif
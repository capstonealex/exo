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
#include <iostream>
class Input {
   private:
   public:
    Input();
    virtual void setStates() = 0;
    void Update();
};
#endif
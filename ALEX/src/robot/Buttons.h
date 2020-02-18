#include "GPIOManager.h"
#include "GPIOConst.h"
#include <iostream>
class Buttons
{
private:
    int gButton;
    int yButton;
    int bButton;
    int rButton;
// button 

public:
    Buttons();
    void initButtons(void);
    int getYButtonState();
    int getGButtonState();
    int getBButtonState();
    int getRButtonState();
    void setButtonStates();
    void printButtonStates();
    void printPressedButtons();
};
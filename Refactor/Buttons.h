#include "GPIO/GPIOManager.h"
#include "GPIO/GPIOConst.h"
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
    GPIO::GPIOManager *gp;
    int redPin, yellowPin, greenPin, bluePin;
    static char *BUTTONRED = "P8_9";
    static char *BUTTONBLUE = "P8_7";
    static char *BUTTONGREEN = "P8_8";
    static char *BUTTONYELLOW = "P8_10";
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
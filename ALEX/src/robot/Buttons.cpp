#include "Buttons.h"

// Crutch button BBB pins GPIO object and value holders
static char *BUTTONRED = "P8_10";
static char *BUTTONBLUE = "P8_9";
static char *BUTTONGREEN = "P8_7";
static char *BUTTONYELLOW = "P8_8";

GPIO::GPIOManager *gp;
int redPin;
int yellowPin;
int greenPin;
int bluePin;

Buttons::Buttons()
{
    std::cout << "Button object created";
}
//set up buttons using GPIO manager
void Buttons::initButtons(void)
{
    gp = GPIO::GPIOManager::getInstance();
    redPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONRED);
    bluePin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONBLUE);
    greenPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONGREEN);
    yellowPin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTONYELLOW);
    gp->setDirection(redPin, GPIO::INPUT);
    gp->setDirection(bluePin, GPIO::INPUT);
    gp->setDirection(greenPin, GPIO::INPUT);
    gp->setDirection(yellowPin, GPIO::INPUT);
    //for testing
    // std::cout << "buttons initialized\n";
}
// get functions for each individual button and all buttons as an array

int Buttons::getYButtonState()
{
    return yButton;
}
int Buttons::getGButtonState()
{
    return gButton;
}
int Buttons::getBButtonState()
{
    return bButton;
}
int Buttons::getRButtonState()
{
    return rButton;
}
// int getButtonStates(){
//     return
// }
void Buttons::setButtonStates()
{
    //Read all 4 BUTTONs  and print to screen
    int redbtn = gp->getValue(redPin);
    int bluebtn = gp->getValue(bluePin);
    int greenbtn = gp->getValue(greenPin);
    int yellowbtn = gp->getValue(yellowPin);

    // Send buttons to variables
    this->yButton = yellowbtn;
    this->gButton = greenbtn;
    this->bButton = bluebtn;
    this->rButton = redbtn;
}
void Buttons::printButtonStates()
{
    std::cout << "Red Button: " << rButton << "\n";
    std::cout << "Green Button: " << gButton << "\n";
    std::cout << "Blue Button: " << bButton << "\n";
    std::cout << "Yellow Button: " << yButton << "\n";
}
void Buttons::printPressedButtons()
{
    if (!yButton)
    {
        printf("Yellow \n");
    }
    if (!gButton)
    {
        printf("Green \n");
    }
    if (!bButton)
    {
        printf("Blue \n");
    }
    if (!rButton)
    {
        printf("Red \n");
    }
}
#include "Buttons.h"

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
}

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
    // this->gButton = greenbtn;
    this->bButton = bluebtn;
    this->rButton = redbtn;
    this->gButton = CO_OD_RAM.goButton;
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
    if (gButton)
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
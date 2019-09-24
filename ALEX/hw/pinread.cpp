//
//
//
#include <iostream>
#include "GPIO/GPIOManager.h"
#include "GPIO/GPIOConst.h"
#include <unistd.h>//for sleep
stati char *BUTTON1 = "P9_23";

void Read() {
    GPIO::GPIOManager* gp = GPIO::GPIOManager::getInstance();
    int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);

    gp->setDirection(pin, GPIO::INPUT);

    while(true){
        printf("Pin 9.23 value: %d\n",gp->getValue(pin));
        sleep(1);
    }

    gp->~GPIOManager();

    return 0;
}
#include "Buttons.h"

Buttons::Buttons() {
    std::cout << "Button object created";
}
//set up buttons using GPIO manager

// get functions for each individual button and all buttons as an array

button_states Buttons::getStates() {
    button_states current_state = {this->state.gButton, this->state.yButton, this->state.bButton, this->state.rButton};
    return current_state;
};
void Buttons::setStates() {
    //Read all 4 BUTTONs  from i/o device
    int redbtn = 0;
    int bluebtn = 0;
    int greenbtn = 0;
    int yellowbtn = 0;

    // Send buttons to variables
    this->state.yButton = yellowbtn;
    // this->gButton = greenbtn;
    this->state.bButton = bluebtn;
    this->state.rButton = redbtn;
    this->state.gButton = greenbtn;
}

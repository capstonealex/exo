
#include "Keyboard.h"

void Keyboard::setStates() {
    /// set last Key states
    /// Clear current states
    clearCurrentStates();
    ch = getch();

    /* Set States, limited to one key Press at a time*/

    switch (ch) {
        case ERR:
            //do nothing, just capture and keep runnin
            printf("No input from keyboard\n");
        case 'a':
        case 'A':
            currentKeyStates.a = true;
            break;
        case 's':
        case 'S':
            currentKeyStates.s = true;
            break;
        case 'd':
        case 'D':
            currentKeyStates.d = true;
            break;
        case 'w':
        case 'W':
            currentKeyStates.w = true;
            break;
        case 'x':
        case 'X':
            currentKeyStates.x = true;
            break;
        case 'q':
        case 'Q':
            currentKeyStates.q = true;
            break;
    }
}
key_states Keyboard::getStates() {
    key_states current_state = {this->currentKeyStates.a, this->currentKeyStates.s,
                                this->currentKeyStates.d, this->currentKeyStates.w, this->currentKeyStates.x};
    return current_state;
};
void Keyboard::printPressed() {
    if (getA()) {
        std::cout << "A ";
    }
    if (getS()) {
        std::cout << "S ";
    }
    if (getD()) {
        std::cout << "D ";
    }
    if (getW()) {
        std::cout << "W ";
    }
    if (getX()) {
        std::cout << "X ";
    }
    std::cout << std::endl;
}
void Keyboard::clearCurrentStates() {
    currentKeyStates.a = false;
    currentKeyStates.s = false;
    currentKeyStates.d = false;
    currentKeyStates.w = false;
    currentKeyStates.x = false;
}
bool Keyboard::getA() {
    return currentKeyStates.a;
};

bool Keyboard::getS() {
    return currentKeyStates.s;
};
bool Keyboard::getD() {
    return currentKeyStates.d;
};
bool Keyboard::getW() {
    return currentKeyStates.w;
};
bool Keyboard::getX() {
    return currentKeyStates.x;
};
bool Keyboard::getQ() {
    return currentKeyStates.q;
};
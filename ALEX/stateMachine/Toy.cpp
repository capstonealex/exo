//
// Created by William Campbell on 2019-09-26.
//

#include "Toy.h"
#include <iostream>

Toy::Toy(void)
{
}
void Toy::init(void)
{
    mark = 1;
    std::cout << "Welcome to THE TOY STATE MACHINE"
              << "\n";
}
void Toy::activate(void)
{
}
void Toy::deactivate(void)
{
}
void Toy::toyUpdate(void)
{
    mark = mark + 1;
    std::cout << "State machine counter at: " << mark;
};
//
// Created by William Campbell on 2019-09-17.
//

#include "add.h"
#include <iostream>

void add::setA(int num){
       a = num;

}
void add::setB(int num){
        c = num;

}
void  add::adding(){
    int C = a+c;
    std::cout<< "A plus B is " << C << "\n";
}
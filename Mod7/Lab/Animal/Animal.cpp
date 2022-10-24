/* Animal.cpp - Function definitions for parent class
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 * Description:  Function definitions for parent class - constructor,
 *     getters, setters, nap, makeNoise, and showInfo
 */
#include <iostream>
#include "Animal.h"
using namespace std ;

//Constructor
Animal::Animal(string name) {
    setName(name);
    cout << "The Animal " << name << " has been created." << endl;
}

//Getter
const string &Animal::getName() const {
    return Animal::name;
}

//Setter
void Animal::setName(const string &name) {
    Animal::name = name;
}

//Member functions
void Animal::nap() {
    cout << "The Animal " << getName() << " is napping." << endl;
}

void Animal::makeNoise() {
    cout << "The Animal " << getName() << " is making a noise" << endl;
}

void Animal::showInfo() {
    cout << "The Animal " << getName() << endl;
}


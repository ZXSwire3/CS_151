/* Owl.cpp - Definition of functions for the Owl subclass to Animal
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 */
#include <iostream>
#include "Owl.h"

using namespace std ;

//Constructor
Owl::Owl(string name, string breed) : Animal(name) {
    Owl::breed = breed;
    cout << "A Owl " << getName() << " of breed " << getBreed() << " has been created." << endl;
}

//Getter
const string &Owl::getBreed() const {
    return breed;
}

//Setter
void Owl::setBreed(const string &breed) {
    Owl::breed = breed;
}

//Override makeNoise
void Owl::makeNoise() {
    cout << "The Owl " << getName() << " is hooting." << endl;
}

//Override showInfo
void Owl::showInfo() {
    cout << "The Owl " << getName() << " of breed " << getBreed() << endl;
}

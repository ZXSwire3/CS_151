/* Fox.cpp - Definition of functions for the Fox subclass to Animal
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 */
#include <iostream>
#include "Fox.h"

using namespace std ;

//Constructor
Fox::Fox(string name) : Animal(name) {
    cout << "A Fox " << getName() << " has been created." << endl;
}

//Override makeNoise
void Fox::makeNoise() {
    cout << "The Fox " << getName() << " is yelping." << endl;
}

//Override showInfo
void Fox::showInfo() {
    cout << "The Fox " << getName() << endl;
}

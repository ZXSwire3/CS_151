/* AnimalTester.cpp - Create objects of subclasses to Animal class
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 * Problem statement:  Create a parent class Animal with subclass for
 *    Owl, and Fox.
 *
 * Algorithm:
 *   1.  Create an animal object for Oscar
 *   2.  Create an owl object for Errol
 *   3.  Create a fox object for Foxy
 *   4.  Use showInfo function on all 3 objects
 *   5.  Use makeNoise function on all 3 objects
 *   6.  Use nap function on all 3 objects
 *
 * Questions:
 *   1. The base class is 'Animal'
 *   2. The derived classes are 'Owl' and 'Fox'
 *   3. Animal does not have a parent class
 *   4. The showInfo and makeNoise functions are overridden but nap is not
 *   5. If the instance member 'name' in the Animal class were made protected
 *          we would not need to use a getter to access it.
 *   6. If the instance members were left private but the base access modifiers
 *          to the 'Animal' class in both child classes were made protected we
 *          would still need to use the getters in the showInfo function
 */
#include "Animal.h"
#include "Fox.h"
#include "Owl.h"
#include <iostream>
using namespace std ;

int main() {
    //Create objects
    cout << "Animal Construction: " << endl;
    Animal Oscar("Oscar");
    Owl Errol("Errol", "Great Grey");
    Fox Foxy("Foxy");
    cout << endl;

    //Show info of objects
    cout << "Animal Info: " << endl;
    Oscar.showInfo();
    Errol.showInfo();
    Foxy.showInfo();
    cout << endl;


    //Make objects make noise
    cout << "Animal Noise: " << endl;
    Oscar.makeNoise();
    Errol.makeNoise();
    Foxy.makeNoise();
    cout << endl;

    //Make objects take a nap
    cout << "Animal Nap: " << endl;
    Oscar.nap();
    Errol.nap();
    Foxy.nap();
}
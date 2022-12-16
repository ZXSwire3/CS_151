/* Elephant.h - Child class to Animal
 * Author:     Ben Foltz
 * Project:    Final Project
 * Description:
 *
 *    Instance variables:
 *       (string) breed - the specific breed of elephant
 *       (string) color - the color of the elephant
 *
 *    Functions:
 *       Constructor
 *       Destructor
 *       getter and setter for instance variable
 *       showInfo       - function that displays info about the elephant
 *       poop           - function that displays how the elephant poops
 *       createChildren - function that displays how the elephant makes children
 */
#ifndef ELEPHANT_H
#define ELEPHANT_H
#include "Animal.h"
using namespace std;

//Inheritance
class Elephant : public Animal{
    private:
        string breed;
        string color;
    public:
        //Constructor
        Elephant(string name, int age, int lifespan, bool isExotic, string breed, string color) : Animal(name, age, lifespan, isExotic), breed(breed), color(color) {};

        //Destructor
        ~Elephant() {};

        //Getters
        const string &getBreed() const {
            return breed;
        }
        const string &getColor() const {
            return color;
        }

        //Setters
        void setBreed(const string &breed) {
            Elephant::breed = breed;
        }
        void setColor(const string &color) {
            Elephant::color = color;
        }

        //Overridden Polymorphism
        //Member functions
        void showInfo() override {
            cout << getName() << " is a " << getAge() << " year(s) old elephant that is a " << getBreed() << " elephant it's color is " << getColor() << endl;
        }
        void poop() override {
            cout << getName() << " pooped, you grab a shovel and pick it up" << endl;
        }
        void createChildren() override {
            cout << getName() << " made a calf with another elephant and they turned out to be " << getColor() << " just like " << getName() << endl;
        }
};

#endif //ELEPHANT_H

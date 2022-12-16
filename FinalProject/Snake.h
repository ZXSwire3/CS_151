/* Snake.h - Child class to Animal
 * Author:     Ben Foltz
 * Project:    Final Project
 * Description:
 *
 *    Instance variables:
 *       (bool) isVenomous - if the snake is venomous or not
 *
 *    Functions:
 *       Constructor
 *       Destructor
 *       getter and setter for instance variable
 *       showInfo       - function that displays info about the snake
 *       poop           - function that displays how the snake poops
 *       createChildren - function that displays how the snake makes children
 */
#ifndef SNAKE_H
#define SNAKE_H

#include "Animal.h"
using namespace std;

//Inheritance
class Snake : public Animal{
private:
    bool isVenomous;
public:
    //Constructor
    Snake(string name, int age, int lifespan, bool isExotic, bool isVenomous) : Animal(name, age, lifespan, isExotic), isVenomous(isVenomous) {};

    //Destructor
    ~Snake() {};

    //Getters
    const bool &getVenomous() const {
        return isVenomous;
    }

    //Setters
    void setIsVenomous(bool isVenomous) {
        Snake::isVenomous = isVenomous;
    }

    //Overridden Polymorphism
    //Member functions
    void showInfo() override {
        cout << getName() << " is a " << getAge() << " year(s) old snake that is ";
        // Check if snake is venomous, and print proper value
        if (getVenomous()) {
            cout << "venomous" << endl;
        } else {
            cout << "not venomous" << endl;
        }
    }
    void poop() override {
        cout << getName() << " left little poop pellets, you go to into the grass to pick it up" << endl;
    }
    void createChildren() override {
        cout << getName() << " made a snakelet with another snake and they turned out to be ";
        // Check if snake is venomous, and print proper value
        if (getVenomous()) {
            cout << "venomous ";
        } else {
            cout << "not venomous ";
        }
        cout << "just like " << getName() << endl;
    }
};

#endif //SNAKE_H

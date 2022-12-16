/* Koala.h - Child class to Animal
 * Author:     Ben Foltz
 * Project:    Final Project
 * Description:
 *
 *    Instance variables:
 *       (string) earSize - the ear size of the koala
 *
 *    Functions:
 *       Constructor
 *       Destructor
 *       getter and setter for instance variable
 *       showInfo       - function that displays info about the koala
 *       poop           - function that displays how the koala poops
 *       createChildren - function that displays how the koala makes children
 */
#ifndef KOALA_H
#define KOALA_H
#include "Animal.h"
using namespace std;

class Koala : public Animal{
    private:
        string earSize;
    public:
        //Constructor
        Koala(string name, int age, int lifespan, bool isExotic, string earSize) : Animal(name, age, lifespan, isExotic), earSize(earSize) {};

        //Destructor
        ~Koala() {};

        //Getters
        const string &getEarSize() const {
            return earSize;
        }

        //Setters
        void setBreed(const string &earSize) {
            Koala::earSize = earSize;
        }

        //Member functions
        void showInfo() override {
            cout << getName() << " is a " << getAge() << " year(s) old koala that has " << getEarSize() << " sized ears" << endl;
        }
        void poop() override {
            cout << getName() << " pooped from a tree, you go to the base of the tree to pick it up" << endl;
        }
        void createChildren() override {
            cout << getName() << " made a joey with another koala and they turned out to have " << getEarSize() << " just like " << getName() << endl;
        }
};

#endif //KOALA_H

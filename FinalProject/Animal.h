/* Animal.h - Abstract parent class to Elephant, Koala, and Snake
 * Author:     Ben Foltz
 * Project:    Final Project
 * Description:
 *
 *    Instance variables:
 *       (string) name     - name of the animal
 *       (int)    age      - age of the animal
 *       (int)    lifespan - lifespan of the animal
 *       (bool)   isExotic - true if this object is exotic
 *
 *    Functions:
 *       Constructor
 *       Pure virtual destructor
 *       getter and setter for instance variable
 *       showInfo       - virtual function for how the derived class will show info about the object
 *       poop           - virtual function for how the derived class will poop
 *       createChildren - virtual function for how the derived class will spawn children
 */
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

//Designed Abstract class
class Animal {
    private:
        string name;
        int age;
        int lifespan;
        bool isExotic;
    public:
        //Exception
        //Class exception if the animal is older than it's lifespan
        class olderThanLifespan {};

        //Constructor
        Animal(string name, int age, int lifespan, bool isExotic) : name(name), age(age), lifespan(lifespan), isExotic(isExotic) {
            if (age > lifespan) {
                throw olderThanLifespan();
            }
        };

        //Polymorphism
        //Pure virtual destructor
        virtual ~Animal() = 0;

        //Getters
        const string &getName() const {
            return name;
        }
        const int &getAge() const {
            return age;
        }
        const int &getLifespan() const {
            return lifespan;
        }
        const bool &getExotic() const {
            return isExotic;
        }

        //Setters
        void setName(const string &name) {
            Animal::name = name;
        }
        void setAge(int age) {
            Animal::age = age;
        }
        void setLifespan(int lifespan) {
            Animal::lifespan = lifespan;
        }
        void setIsExotic(bool isExotic) {
            Animal::isExotic;
        }

        //Polymorphism
        //Virtual member functions
        virtual void showInfo() = 0;
        virtual void poop() = 0;
        virtual void createChildren() = 0;

};

//Explicit destructor call
Animal::~Animal() {};

#endif //ANIMAL_H

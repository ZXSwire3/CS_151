/* Animal.h - Header for parent class of Fox and Owl
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 * Description:
 *
 *    Instance members
 *       name (string)
 *
 *    Functions
 *       default constructor
 *       full constructor
 *       all getters and setters
 *       nap
 *       makeNoise
 *       showinfo
 */
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std ;

class Animal {

    private:
        string name ;

    public :
        //Constructor
        Animal(string name);

        //Getter
        const string &getName() const;

        //Setter
        void setName(const string &name);

        //Member functions
        void nap();

        void makeNoise();

        void showInfo();
} ;

#endif //ANIMAL_H

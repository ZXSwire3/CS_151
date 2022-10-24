/* Owl.h - Header for an Owl, child of Animal
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 * Description:
 *
 *    Child of Animal
 *
 *    Instance members:
 *       breed (string)
 *
 *    Functions:
 *       full constructor
 *       getters and setters for all instance members
 *       makeNoise
 *       showInfo
 */
#ifndef OWL_H
#define OWL_H
#include "Animal.h"

using namespace std ;

class Owl: public Animal {
    private:
        string breed;

    public :
        //Constructor
        Owl(string, string);

        //Getter
        const string &getBreed() const;
        //Setter
        void setBreed(const string &breed);
        //makeNoise Override
        void makeNoise();
        //showInfo Override
        void showInfo();
};

#endif //OWL_H

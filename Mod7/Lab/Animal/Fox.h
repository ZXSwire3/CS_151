/* Fox.h - Header for a Fox, child of Animal
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 2
 * Description:
 *
 *    Child of Animal
 *
 *    Functions:
 *       full constructor
 *       makeNoise
 *       showInfo
 */
#ifndef FOX_H
#define FOX_H
#include "Animal.h"

using namespace std ;

class Fox: public Animal {

    public :
        //Constructor
        Fox(string);

        //makeNoise Override
        void makeNoise();

        //showInfo Override
        void showInfo();
};

#endif //FOX_H

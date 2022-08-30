/* Country.h - Header file for a country
 * Author: Ben Foltz
 * Module: 1
 * Project: Homework 1, project 1
 * Description: Header file for Country class (data members, function headings)
 *
 *     Data Member (instance) variables
 *         (string) name of the country
 *         (int) number of people that live in the country in thousands
 *         (int) number of sq ft in the country
 *
 *    Functions
 *       constructor(string, int, int)
 *       destructor
 *       all getters and setters
 */
#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <iomanip>

using namespace std;

class Country {
    private:
        string name;
        int population;
        int area;
    public:
        Country(string, int, int);
        ~Country();

        string getName() const;
        int getPopulation() const;
        int getArea() const;

        void setName(const string &);
        void setPopulation(int);
        void setArea(int);
};
#endif //COUNTRY_H

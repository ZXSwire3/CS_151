/* SortCountries - Sorts countries and inserts them into a vector
 * Author: Ben Foltz
 * Module: 1
 * Project: Homework 1, project 2
 * Problem Statement: This program generates creates countries and then sorts them from smallest to biggest area into a
 *                    vector.
 * Algorithm:
 * 1. Create countries vector
 * 2. Create countries and call countryInsert
 * 3. Print heading
 *    countryInsert(vector<Country> countries, Country country)
 * 4. Create iterator
 * 5. if vector is empty
 * 6. push country into vector
 * 7. else loop through the countries in the vector and exit the loop when the country's area in the vector is greater
 *      than the current one
 * 8. Insert country into vector
 */
#include "Country.h"

#include <iostream>
#include <vector>

void countryInsert(vector<struct Country> &countries, Country country);

using namespace std;

int main() {
    //Create vector for the countries
    vector<Country> countries;

    //Create countries and then insert into the countries vector
    Country argentina("Argentina", 45258, 1073234);
    countryInsert(countries, argentina);
    Country bolivia("Bolivia", 11696, 424052);
    countryInsert(countries, bolivia);
    Country brazil("Brazil", 212845, 3287086);
    countryInsert(countries, brazil);
    Country chile("Chile", 19206, 291855);
    countryInsert(countries, chile);
    Country columbia("Columbia", 51115, 440715);
    countryInsert(countries, columbia);
    Country ecuador("Ecuador", 17705, 106851);
    countryInsert(countries, ecuador);
    Country falkland("Falkland Islands", 3, 4700);
    countryInsert(countries, falkland);
    Country french("French Guiana", 290, 32253);
    countryInsert(countries, french);
    Country guyana("Guyana", 787, 82978);
    countryInsert(countries, guyana);
    Country paraguay("Paraguay", 7145, 157056);
    countryInsert(countries, paraguay);
    Country peru("Peru", 33108, 496093);
    countryInsert(countries, peru);
    Country suriname("Suriname", 586, 63252);
    countryInsert(countries, suriname);
    Country uruguay("Uruguay", 3475, 68037);
    countryInsert(countries, uruguay);
    Country venezuela("Venezuela", 28102, 353748);
    countryInsert(countries, venezuela);

    //Print out the countries
    cout << right << setw(12) << "Country" << left << setw(6) << "" << "Population" << left << setw(5) << "" << "Area" << endl;
    cout << left << setw(18) << "----------------" << left << setw(12) << "----------" << left << setw(12) << "----------" << endl;
    for (int i = 0; i < countries.size(); i++) {
        cout << left << setw(18) << countries[i].getName() << right << setw(10) << countries[i].getPopulation() << right << setw(12) << countries[i].getArea() << endl;
    }
}

void countryInsert(vector<Country> &countries, Country country) {
    vector<Country>::iterator iter;

    //Check if vector is empty
    if (countries.empty()) {
        //Add country if the vector is empty
        countries.push_back(country);
    } else {
        //Set index to last element in countries
        int index = countries.size();
        //Loop through vector
        for (int j = 0; j < countries.size(); j++) {
            //Check if countries in vector have bigger area than current country
            if (countries[j].getArea() > country.getArea()) {
                index = j;
                break;
            }
        }

        //Iterator starts at index
        iter = countries.begin() + index;
        //Insert current country at index
        countries.insert(iter, country);
    }
}
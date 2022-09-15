/* Country.cpp - Defines all functions for the Country class
 * Author: Ben Foltz
 * Module: 1
 * Project: Homework 1, project 1
 * Description: Implementation of functions for Country class
 *
 *   Constructor takes the country name, population, and area
 *
 *   Getters and setters
 */
#include "Country.h"
using namespace std;

Country::Country(string name, int population, int area) {
    setName(name);
    setPopulation(population);
    setArea(area);
}

Country::~Country(){};

string Country::getName() const {
    return name;
}

int Country::getPopulation() const {
    return population;
}

int Country::getArea() const {
    return area;
}

void Country::setName(const string &name) {
    Country::name = name;
}

void Country::setPopulation(int population) {
    Country::population = population;
}

void Country::setArea(int area) {
    Country::area = area;
}


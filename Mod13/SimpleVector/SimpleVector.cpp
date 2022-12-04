/* SimpleVector.cpp - Create a vector class and prompt user to fill it and then empty the vector
 * Author:     Ben Foltz
 * Module:     13
 * Project:    Homework 13, project 2
 * Problem statement: Create vector class, push and pop elements in vector
 *
 * Algorithm:
 *   1. int main()
 *       a. Infinite loop
 *           i. Create input int
 *          ii. Prompt user for int
 *         iii. try
 *               1. push elements on vector
 *               2. print elements in vector
 *          iv. catch ArrayFull
 *               1. print error
 *               2. exit loop
 *       b. try
 *           i. Loop through 0 to vector size + 1
 *               1. print elements in vector
 *               2. pop element off vector
 *       c. catch ArrayEmpty
 *           i. print error
 *       d. Infinite loop
 *           i. Create input string
 *          ii. Prompt user for string
 *         iii. try
 *               1. push elements on vector
 *               2. print elements in vector
 *          iv. catch ArrayFull
 *               1. print error
 *               2. exit loop
 *       b. try
 *           i. Loop through 0 to vector size + 1
 *               1. print elements in vector
 *               2. pop element off vector
 *       c. catch ArrayEmpty
 *           i. print error
 */
#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main() {
    string inputStr;
    int inputInt;

    SimpleVector<int> simpleIntVector(5);
    SimpleVector<string> simpleStringVector(5);

    do {
        //Prompt user for an int
        cout << "Enter an int: ";
        cin >> inputInt;

        //Try catch to see if vector is full
        try {
            //Push int to vector
            simpleIntVector.push_back(inputInt);
            //Print out elements in vector
            cout << "Vector: ";
            simpleIntVector.print();
        } catch (SimpleVector<int>::ArrayFull) {
            //Print error
            cout << "The vector is full" << endl << endl;
            break;
        }
    } while (true);

    //Try catch to see if vector is empty
    try {
        cout << "Popping off elements in the vector" << endl;
        for (int i = 0; i < 6; ++i) {
            //Print elements in vector
            cout << "Vector: ";
            simpleIntVector.print();
            //Pop int from vector
            simpleIntVector.pop_back();
        }
    } catch (SimpleVector<int>::ArrayEmpty) {
        //Print error
        cout << "The vector is empty" << endl << endl;
    }

    do {
        //Prompt user for string
        cout << "Enter a string: ";
        cin >> inputStr;

        //Try catch to see if vector is full
        try {
            //Push string to vector
            simpleStringVector.push_back(inputStr);
            //Print out elements in vector
            cout << "Vector: ";
            simpleStringVector.print();
        } catch (SimpleVector<string>::ArrayFull) {
            //Print error
            cout << "The vector is full" << endl << endl;
            break;
        }
    } while (true);

    //Try catch to see if vector is empty
    try {
        cout << "Popping off elements in the vector" << endl;
        for (int i = 0; i < 6; ++i) {
            //Print elements in vector
            cout << "Vector: ";
            simpleStringVector.print();
            //Pop string from vector
            simpleStringVector.pop_back();
        }
    } catch (SimpleVector<string>::ArrayEmpty) {
        //Print error
        cout << "The vector is empty";
    }
}

/* DriverBCheckString.cpp - Prompt user for a string and an int and returns the value at that position in the string.
 * Author:     Ben Foltz
 * Module:     13
 * Project:    Homework 13, project 1
 * Problem statement: Create a string and check if the position is valid.
 *
 * Algorithm:
 *   1. int main()
 *       a. Infinite loop
 *           i. Create input string, int position, and char letter
 *          ii. Prompt user for string
 *         iii. Create BCheckString object (bStr) from string input
 *          iv. Prompt user for int input (position)
 *           v. try
 *               1. letter = bStr[position - 1]
 *               2. print out letter and position
 *          vi. catch BoundsException
 *               1. print error
 */
#include <iostream>
#include "BCheckString.h"

using namespace std;

int main() {
    string inputStr;
    int position;
    char letter;

    do {
        //Prompt user for input string
        cout << "Enter a string: ";
        cin >> inputStr;
        //Create a new object from the input string
        BCheckString bStr(inputStr);

        //exit program
        if (inputStr == "quit") {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //Prompt user
        cout << "Enter the position you'd like to check: ";
        cin >> position;

        //Try catch to see if position is valid
        try {
            //Find char at position
            letter = bStr[position - 1];
            //Print out char and position
            cout << "The character at position " << position << " is " << letter << endl << endl;
        } catch (BCheckString::BoundsException) {
            //Print error
            cout << "That value is out of bounds." << endl << endl;
        }
    } while (true);
}

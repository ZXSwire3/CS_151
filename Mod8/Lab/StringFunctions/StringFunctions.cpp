// StringFunctions.cpp
// Author: Ben Foltz
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main () {

    while (true){
        //Prompt user for input
        cout << "Enter a non-negative whole number: ";
        int original = 0;
        cin >> original;

        //Exit the program if user input is negative
        if (original < 0) {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //Create string copy of user input and add " rah!" to the end of it
        string original_as_string = to_string(original) + " rah!";
        cout << "That number converted to a string: " << original_as_string << endl;

        //Create a new int from the string
        istringstream inpstr(original_as_string);
        int original_copy;
        inpstr >> original_copy;
        cout << left << setw(35) << "Converted back to a number: " << original_copy << endl;

        //Convert original_copy to binary
        char *binary = new char[33];
        *(binary + 32) = '\0';
        int index = 32;
        do {
            *(binary + (--index)) = (char) (original_copy % 2 + '0') ;
            original_copy /= 2;
        } while (original_copy > 0);
        cout << left << setw(35) << "That number in binary is: " << (binary + index) << endl;

        //Convert binary number back to a decimal form
        original_copy = stoi((binary + index), nullptr, 2);
        cout << left << setw(35) << "Back to decimal: " << original_copy << endl;

        //Convert original to hexadecimal form
        stringstream iostr;
        iostr << hex << original;
        cout << left << setw(35) << "Here's your number in hex: " << iostr.str() << endl;

        //Convert from hexadecimal form back to decimal form
        iostr >> hex >> original_copy;
        cout << left << setw(35) << "And back once more: " << original_copy << endl << endl;
    };
}
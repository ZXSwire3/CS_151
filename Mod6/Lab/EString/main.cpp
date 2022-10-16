// main.cpp
// Author: Ben Foltz
#include "EString.h"

int main() {
    //Create two EString variables
    EString estring1 = "Hello MiraCosta!", estring2;
    //Use overloaded assignment operator
    estring2 = estring1;

    //Print both EStrings
    cout << "First string: " << estring1 << endl
         << "Second string: " << estring2 << endl << endl;

    //Create new EString
    EString original = "New Year's Party at 8:30.";

    //Print out EStrings
    cout << "Original string:       " << original << endl;
    cout << "Using prefix operator: " << ++original << endl;
    cout << "After using prefix:    " << original++ << endl << endl;

    //User + overload
    cout << "Overloaded + operator: " << endl;
    EString all;
    all = estring1 + estring2 + original + ++original + original++;

    //Print result of overloaded +
    cout << all << endl << endl;

    //Print each letter of the EString
    cout << "Original: ";
    for (int i = 0; i < original.getSize(); ++i) {
        cout << original[i] << " ";
    }
    //Print each letter of the updated EString
    cout << endl << "Updated:  ";
    for (int i = 0; i < original.getSize(); ++i) {
        //User overloaded prefix to print other value at [i]
        cout << ++original[i] << " ";
    }
}
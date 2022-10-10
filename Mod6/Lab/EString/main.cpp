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

    //Create 3 new EStrings
    EString originalEString = "New Year's Party at 8:30.";
    //Use prefix overload
    EString prefix = ++originalEString;
    //Use postfix overload
    EString postfix = originalEString++;

    //Print out EStrings
    cout << "Original string:       " << originalEString << endl;
    cout << "Using prefix operator: " << prefix << endl;
    cout << "After using prefix:    " << postfix << endl << endl;

    //User + overload
    cout << "Overloaded + operator: " << endl;
    EString all;
    all = estring1 + estring2 + originalEString + prefix + postfix;

    //Print result of overloaded +
    cout << all << endl << endl;

    //Print each letter of the EString
    cout << "Original: ";
    for (int i = 0; i < originalEString.getSize(); ++i) {
        cout << originalEString[i] << " ";
    }
    //Print each letter of the updated EString
    cout << endl << "Updated:  ";
    for (int i = 0; i < originalEString.getSize(); ++i) {
        //User overloaded prefix to print other value at [i]
        cout << ++originalEString[i] << " ";
    }
}
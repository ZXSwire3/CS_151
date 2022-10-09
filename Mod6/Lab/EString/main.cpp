#include "EString.h"

int main() {
    EString estring1 = "Hello MiraCosta!", estring2;
    estring2 = estring1;

    cout << "First string: " << estring1 << endl
         << "Second string: " << estring2 << endl << endl;

    EString originalEString = "New Year's Party at 8:30.";
    EString prefix = ++originalEString;
    EString postfix = originalEString++;

    cout << "Original string:       " << originalEString << endl;
    cout << "Using prefix operator: " << prefix << endl;
    cout << "After using prefix:    " << postfix << endl << endl;

    cout << "Overloaded + operator: " << endl;
    EString all;
    all = estring1 + estring2 + originalEString + prefix + postfix;

    cout << all << endl << endl;

    cout << "Original: ";
    for (int i = 0; i < originalEString.getSize(); ++i) {
        cout << originalEString[i] << " ";
    }
    cout << endl << "Updated:  ";
    for (int i = 0; i < originalEString.getSize(); ++i) {
        cout << ++originalEString[i] << " ";
    }
}
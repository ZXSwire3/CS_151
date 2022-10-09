// CopyConstructor.cpp
// Author: Ben Foltz
#include <iostream>

#include "String.h"

using namespace std;

int main() {
    //Create Strings using a constructor and an assignment statement
    cout << "Create two strings, one using constructor, "
         << "another an assignment statement" << endl;
    EString str1("MiraCosta College");       //regular constructor
    EString str2 = str1;                                //copy constructor

    //Print out both EString objects
    str1.print();
    str2.print();

    cout << "\nAfter changing string 2 using change()" << endl;
    str2.change("Cal State San Marcos");

    //Print out both EString objects
    str1.print();
    str2.print();

    cout << "\nAfter changing string 1 using change()" << endl;
    str1.change("UCSD");

    //Print out both EString objects
    str1.print();
    str2.print();
}
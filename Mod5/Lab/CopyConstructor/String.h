// EString.h
// Author: Ben Foltz
#ifndef CS_151_STRING_H
#define CS_151_STRING_H

#include <cstring>
#include <iostream>

using namespace std;

class EString {
    private:
        char *string;
        int size;

    public:
        EString(const char *s = ""); //constructor
        ~EString();                  //destructor
        void print();               //print the string
        void change(const char *);  //reassign the string
        EString(const EString &);     //copy constructor
};

//Constructor
EString::EString(const char *original) {
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//Copy constructor which creates a new string
EString::EString(const EString &original) {
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

//Destructor
EString::~EString() {
    delete [] string;
    size = 0;
}

//Replace with another EString object
void EString::change(const char *original) {
    delete [] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

void EString::print() {
    cout << string << endl;
}


#endif //CS_151_STRING_H

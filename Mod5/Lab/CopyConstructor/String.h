// String.h
// Author: Ben Foltz
#ifndef CS_151_STRING_H
#define CS_151_STRING_H

#include <cstring>
#include <iostream>

using namespace std;

class String {
    private:
        char *string;
        int size;

    public:
        String(const char *s = ""); //constructor
        ~String();                  //destructor
        void print();               //print the string
        void change(const char *);  //reassign the string
        String(const String &);     //copy constructor
};

//Constructor
String::String(const char *original) {
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

//Copy constructor which creates a new string
String::String(const String &original) {
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

//Destructor
String::~String() {
    delete [] string;
    size = 0;
}

//Replace with another String object
void String::change(const char *original) {
    delete [] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

void String::print() {
    cout << string << endl;
}


#endif //CS_151_STRING_H

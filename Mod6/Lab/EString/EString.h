// EString.h
// Author: Ben Foltz
#ifndef CS_151_ESTRING_H
#define CS_151_ESTRING_H

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
        void print();                //print the string
        void change(const char *);   //reassign the string
        EString(const EString &);    //copy constructor
        int getSize();
        EString &operator=(const EString &); //Assignment overload
        friend ostream &operator<<(ostream &, const EString &); //stream extraction overload
        EString operator++();        //prefix overload
        EString operator++(int);     //postfix overload
        char &operator[](int);       //[] overload
        friend EString operator+(const EString &, const EString &); //+ overload
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

//Assignment operator
EString&EString::operator=(const EString &original) {
    delete [] string;
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
    return *this;
}

//Stream extraction operator
ostream &operator<<(ostream &out, const EString &output_EString) {
    out << output_EString.string;
    return out;
}

//Prefix Overload
EString EString::operator++() {
    for (int i = 0; i < size; ++i) {
        if (string[i] >= 97) {
            string[i] = toupper(string[i]);
        }
    }
    return *this;
}

//Postfix Overload
EString EString::operator++(int) {
    EString copy = *this;
    for (int i = 0; i < copy.size; ++i) {
        copy.string[i] = toupper(copy.string[i]);
    }
    return copy;
}

//[] Overload
char &EString::operator[](int index) {
    if (index < 0 || index > size) {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    return string[index];
}

//+ Overload
EString operator+(const EString &string1, const EString &string2) {
    char string3[string1.size + string2.size + 1];
    strcpy(string3, string1.string);
    strcpy(string3 + string1.size, string2.string);

    return EString(string3);
}

//Return size
int EString::getSize() {
    return size;
}

#endif //CS_151_ESTRING_H

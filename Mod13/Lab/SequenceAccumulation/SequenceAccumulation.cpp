//SequenceAccumulation.cpp
//Author: Ben Foltz
#include <iostream>
#include <vector>

using namespace std;

template <class T>
T accum(vector <T> v) {
    T sum = v[0];

    for (int i = 1; i < v.size(); ++i) {
        sum += v[i];
    }

    return sum;
}

int main() {
    vector<int> intVector;
    vector<double> doubleVector;
    vector<string> stringVector;
    int iInput;
    double dInput;
    string sInput;

    //Prompt user for 3 ints
    cout << "Enter 3 numbers, one at a time:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Number " << (i+1) << ": ";
        cin >> iInput;
        intVector.push_back(iInput);
    }
    //Print sum of vector
    cout << "The sum of the elements in the vector is " << accum(intVector) << endl << endl;

    //Prompt user for 3 doubles
    cout << "Enter 3 numbers with decimal values, one at a time:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Number " << (i+1) << ": ";
        cin >> dInput;
        doubleVector.push_back(dInput);
    }
    //Print sum of vector
    cout << "The sum of the elements in the vector is " << accum(doubleVector) << endl << endl;

    //Prompt user for 3 strings
    cout << "Enter 3 strings, one at a time:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "String " << (i+1) << ": ";
        cin >> sInput;
        stringVector.push_back(sInput);
    }

    //Print sum of vector
    cout << "The sum of the elements in the vector is " << accum(stringVector) << endl;
}


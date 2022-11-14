//BinaryFile.cpp
//Author: Ben Foltz
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Binary file name
const string BINARY_FILE = "array.dat";

int main() {
    //Open output stream to write binary file
    ofstream data_file(BINARY_FILE, ios::binary | ios::out);
    if (!data_file) {
        cout << "Can't create file";
        exit(EXIT_FAILURE);
    }

    //Write 1-10 ints to binary file
    cout << "Writing 1-10: " << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << i << " ";
        data_file.write(reinterpret_cast <char *>(&i), sizeof(int));
    }

    cout << endl
         << "and square root of 1-10:"
         << endl;
    //Write square root of 1-10 to binary file
    for (int i = 1; i <= 10; ++i) {
        double iSqrt = sqrt(i);
        cout << iSqrt << " ";
        data_file.write(reinterpret_cast <char *>(&iSqrt), sizeof(double));
    }
    //Close file
    data_file.close();

}
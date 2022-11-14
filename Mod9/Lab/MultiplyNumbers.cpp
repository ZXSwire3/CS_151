//MultiplyNumbers.cpp
//Author: Ben Foltz
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const string BINARY_FILE = "array.dat";

int main() {
    //Create file stream for both input and output
    fstream data_file(BINARY_FILE, ios::binary | ios::in | ios::out);
    if (!data_file) {
        cout << "Can't create file or open file";
        exit(EXIT_FAILURE);
    }

    //Prompt user for input
    double multiplier;
    cout << "Enter a multiplier: ";
    cin >> multiplier;

    //Read ints from data file, multiply, and store back in the file
    cout << "Reading and updating ints..." << endl;
    for (int i = 1; i <= 10; i++) {
        //read the next int in the file, saving read pointer position
        int data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast <char *>(&data), sizeof(int));

        //display on the screen and multiply
        cout << data << " -> ";
        data = round(data * multiplier);
        cout << data << endl;

        //set write pointer to read pointer's position, re-write on file
        data_file.seekg(position, ios::beg);
        data_file.write(reinterpret_cast <char *>(&data), sizeof(int));
    }

    //Read double from data file, multiply, and store back in the file
    cout << "Reading and updating ints..." << endl;
    for (int i = 1; i <= 10; i++) {
        //read the next double in the file, saving read pointer position
        double data;
        long long position = data_file.tellg();
        data_file.read(reinterpret_cast <char *>(&data), sizeof(double));

        //display on the screen and multiply
        cout << data << " -> ";
        data = data * multiplier;
        cout << data << "(root of " << pow(data, 2) << ")" << endl;

        //set write pointer to read pointer's position, re-write on file
        data_file.seekg(position, ios::beg);
        data_file.write(reinterpret_cast <char *>(&data), sizeof(double));
    }

    //Close file
    data_file.close();
}

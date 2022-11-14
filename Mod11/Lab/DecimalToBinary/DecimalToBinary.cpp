//DecimalToBinary.cpp
//Author: Ben Foltz
#include <iostream>

using namespace std;

string decimalToBinaryIterative(int decimal);

string decimalToBinaryRecursive(int decimal);

int main() {
    int decimal;
    do {
        //Prompt user for input
        cout << "Enter a decimal number: ";
        cin >> decimal;

        //Check if user wants to quit
        if (decimal == -1) {
            exit(EXIT_SUCCESS);
        }

        //Print out iterative results
        cout << "Iterative: " + decimalToBinaryIterative(decimal) << endl;
        //Print out recursive results
        cout << "Recursive: " + decimalToBinaryRecursive(decimal) << endl;
    } while (true);
}

string decimalToBinaryIterative(int decimal) {
    //Create binary string
    string binary;
    do {
        //append remainder from decimal
        binary.append(to_string(decimal % 2));
        //divide decimal by 2
        decimal /= 2;
    } while (decimal != 0);

    //Reverse the string
    string temp = binary;
    for (int i = binary.length() - 1, j = 0; i >= 0; i--, j++) {
        temp[j] = binary[i];
    }
    //return binary number
    binary = temp;
    return binary;
}

string decimalToBinaryRecursive(int decimal) {
    //Create binary string
    string binary;
    //Base case (stop when this happens)
    if (decimal / 2 == 0) {
        //if input is 0 then just return 0
        if (decimal == 0) {
            binary = "0";
        } else {
            //otherwise insert 1 at the beginning of string
            binary.insert(0,"1");
        }
        //return binary number
        return binary;
    } else {
        //call decimalToBinaryRecursive with smaller input
        return decimalToBinaryRecursive(decimal / 2) + to_string(decimal % 2);
    }
}

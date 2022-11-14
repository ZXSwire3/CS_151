//BinaryToDecimal.cpp
//Author: Ben Foltz
#include <iostream>

using namespace std;

string binaryToDecimalIterative(int binary);

string binaryToDecimalRecursive(int binary);

int main() {
    int binary;
    do {
        //Prompt user for input
        cout << "Enter a binary number: ";
        cin >> binary;

        //Check if user wants to exit program
        if (binary == -1) {
            exit(EXIT_SUCCESS);
        }

        //Print out iterative results
        cout << "Iterative: " + binaryToDecimalIterative(binary) << endl;
        //Print out recursive results
        cout << "Recursive: " + binaryToDecimalRecursive(binary) << endl;
    } while (true);
}

string binaryToDecimalIterative(int binary) {
    int decimal = 0;
    int base = 1;
    //loop until binary is 0 or less
    while (binary) {
        //find last digit of the number
        int lastDigit = binary % 10;
        //remove the last digit
        binary = binary / 10;
        //add last digit and base to number
        decimal += lastDigit * base;
        //multiply base by 2
        base *= 2;
    }

    //return decimal
    return to_string(decimal);
}


string binaryToDecimalRecursive(int binary) {
    //Base case
    if (binary == 0) {
        return "0";
    } else {
        //call binaryToDecimalRecursive with smaller number
        return to_string((binary % 10 + 2 * stoi(binaryToDecimalRecursive(binary / 10))));
    }
}
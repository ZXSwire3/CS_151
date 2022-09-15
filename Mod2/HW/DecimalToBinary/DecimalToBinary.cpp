/* SortNumbers - Sorts random numbers and inserts them into a vector
 * Author: Ben Foltz
 * Module: 1
 * Project: Homework 1, project 1
 * Problem Statement: This program generates random numbers and then sorts them from biggest to smallest into a vector.
 * Algorithm:
 * 1. Create numbers vector
 * 2. Create an iterator
 * 3. Create a for loop to loop through and generate 30 numbers
 * 4. If the vector is empty then push the first number generated
 * 5. Else loop through the numbers in the vector and exit the loop when the number in the vector is smaller than random
 * 6. Insert random number into vector
 * 7. Print out numbers in vector
 * 8. While loop until vector is empty
 * 9. Print number and pop vector
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int decimal;
    string binary;
    do {
        cout << "Enter a decimal number: ";
        cin >> decimal;

        if (decimal == -1) {
            exit(EXIT_SUCCESS);
        }

        //Convert to binary
        do {
            binary.append(to_string(decimal % 2));
//            cout << binary << endl << endl;
            decimal /= 2;
        } while (decimal != 0);

        //Reverse the string
        string temp = binary;
        for (int i = binary.length() - 1, j = 0; i >= 0; i--, j++) {
            temp[j] = binary[i];
//            cout << temp << endl;
        }
        binary = temp;

        //Print binary number
        cout << binary << endl;
        //Clear string for next loop
        binary = "";
    } while (true);
}

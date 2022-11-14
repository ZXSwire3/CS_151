/* IterativeFactorial.cpp - Prompt user for an integer and find the factorial of that integer.
 * Author:     Ben Foltz
 * Module:     11
 * Project:    Homework 11, project 1
 * Problem statement: Create a function that finds the factorial of an integer
 *
 * Algorithm:
 *   1. Create long long factorial(int number) function
 *       a. if number is 0
 *           1. return 0
 *       b. for loop from 1 to number
 *           1. multiply number by i
 *       c. return factorial
 *   2. int main()
 *       a. Infinite loop
 *           i. Create input string
 *          ii. Prompt user for input
 *         iii. Call factorial() with input from user
 */
#include <iostream>

using namespace std;

long long factorial(int number);

int main() {
    int input;
    do {
        //prompt user for input
        cout << "Enter a number: ";
        cin >> input;

        //exit program
        if (input == -1) {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //print factorial
        cout << "Factorial of " << input << ": " << factorial(input) << endl;

    } while (true);
}

long long factorial(int number) {
    if (number == 0) {
        return 0;
    }

    //find factorial by looping through each number from 1 to number given
    long long factorial = 1;
    for (int i = 1; i <= number ; ++i) {
        factorial *= i;
    }
    //return factorial
    return factorial;
}
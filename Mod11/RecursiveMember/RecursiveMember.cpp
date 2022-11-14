/* RecursiveMember.cpp - Prompt user for integers to put in an array and an integer to search in the array.
 * Author:     Ben Foltz
 * Module:     11
 * Project:    Homework 11, project 2
 * Problem statement: Create a function that finds the factorial of an integer
 *
 * Algorithm:
 *   1. Create bool isMember(int array[], int elements, int search) function
 *       a. decrement element
 *       b. if elements less than 0
 *           1. return false
 *       c. else if array at element equals search
 *           1. return true
 *       d. else
 *           1. return isMember(array, elements, search)
 *   2. int main()
 *       a. Instantiate variables for input, elements, array, and count
 *       b. Infinite loop
 *           i. Prompt user for input
 *          ii. Do while loop while count is less than elements
 *               1. Prompt user for number in the input
 *               2. Put user input in array
 *         iii. Prompt user for number to search in the array
 *          iv. if (isMember(array, elements, input)
 *               1. Print value found
 *           v. else
 *               1. Print value not found
 *       c. count = 0
 */
#include <iostream>

using namespace std;

bool isMember(int array[], int elements, int search);

int main() {
    int input;
    //number of elements in array
    int elements = 5;
    //create new array
    int array[elements];
    //count to know how many times to prompt user for int in array
    int count = 0;
    do {
        //Tell user to input numbers in an array
        cout << "Enter numbers into an array: " << endl;
        //Loop until there all elements are filled
        do {
            //Prompt user for int in array
            cout << "Number at element " << count + 1 << ": ";
            cin >> input;

            //Put input in array
            array[count++] = input;
        } while (count < elements);

        //Prompt user for int to search in the array
        cout << "Enter a number to search for: ";
        cin >> input;

        //exit the program
        if (input == -1) {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //If isMember
        if (isMember(array, elements, input)) {
            //print value found
            cout << "Value found!" << endl << endl;
        } else {
            //print value not found
            cout << "Value not found!" << endl << endl;
        }

        //reset count to 0
        count = 0;

    } while (true);
}

bool isMember(int array[], int elements, int search) {
    //Decrement elements
    elements--;

    if (elements < 0) { //base case
        return false;
    } else if (array[elements] == search) { //base case
        return true;
    } else { //recursive case
        return isMember(array, elements, search);
    }
}

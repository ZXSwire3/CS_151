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
    vector<int> numbers;
    //vector size
    int numSize = 30;

    unsigned int seed = time(0);
    srand(seed);
    //max value that random values can be
    int max = RAND_MAX;
    int min = 0;
    //random values
    int random;

    vector<int>::iterator iter;

    for (int i = 0; i < numSize; i++) {
        //generate random number from 0 to RAND_MAX
        random = (rand() % max) + min;
        //Convert number to a number between 1 and 10
        random = random % 11;

        //Check if vector is empty
        if (numbers.empty()) {
            //Add random number if the vector is empty
            numbers.push_back(random);
        } else {
            //Set index to last element in numbers
            int index = numbers.size();
            //Loop through vector
            for (int j = 0; j < numbers.size(); j++) {
                //Check if numbers in vector are smaller than random
                if (numbers[j] < random) {
                    index = j;
                    break;
                }
            }

            //Iterator starts at index
            iter = numbers.begin() + index;
            //Insert current number at index
            numbers.insert(iter, random);
        }
    }

    //Print vector from biggest to smallest
    cout << "big to small: ";
    for (int i = 0; i < numSize; i++) {
        if (i == numSize - 1) {
            cout << numbers.at(i) << endl;
        } else {
            cout << numbers.at(i) << ", ";
        }
    }

    int count = 0;
    //Print vector from smallest to biggest
    cout << "small to big: ";
    while (!numbers.empty()) {
        if (count == numSize - 1) {
            cout << numbers.back();
            numbers.pop_back();
        } else {
            cout << numbers.back() << ", ";
            numbers.pop_back();
        }
        count++;
    }

}

/* Pie - Dynamically allocates an array of ints and holds the number of pie slices eaten by 15 different people
 * Author: Ben Foltz
 * Module: 3
 * Project: Homework 3, project 2
 * Problem Statement: This program dynamically allocates an array of ints and holds the number of pie slices eaten by 15
 *                    different people.
 * Algorithm:
 * 1. void sort(int array[], int size)
 *    a. Instantiate int temp
 *    b. Use a for loop from 0 to size - 1
 *       i. Use a for loop from i + 1 to size
 *          1. if value at array[i] > value at array[j]
 *              a. temp = array[j]
 *              b. value at array[j] = array[i]
 *              c. set value at array[i] = temp
 * 2. getMode(int array[], int size)
 *    a. Instantiate int number = array[0]
 *    b. Instantiate int count = 0
 *    c. Instantiate int countMode = 0
 *    d. Instantiate int mode
 *    e. Use a for loop from 0 to size
 *       i. if array[i] == number
 *          1. Increment count
 *      ii. else
 *          1. if (count > countMode)
 *              a. countMode = count
 *              b. mode = number
 *          2. count = 0
 *          3. number = array[i]
 *    f. return average
 * 4. int main()
 *    a. Instantiate int *people = new int
 *    b. *people = 15
 *    c. Instantiate dynamically allocated array of ints with size people
 *    d. Use a for loop from 0 to *numberOfTests
 *       i. Prompt user for the number of pie slices they eat a year
 *      ii. while (numberOfPies[i] < 0)
 *          1. Print error
 *          2. Prompt user for number of pie slices they eat a year
 *    e. sort(numberOfPies, *people)
 *    f. Use a for loop from 0 to *people
 *       i. Print the number of pies
 *    g. Print mode of the data set
 *    h. delete dynamically allocated array
 */
#include <iostream>
#include <iomanip>

using namespace std;
void sort(int array[], int size);
int getMode(int array[], int size);

int main() {
    //Create a pointer to an int people
    int *people = new int;
    //Set the number of people asked to 15
    *people = 15;
    //Create a pointer to an array of ints with the size of people
    int *numberOfPies = new int[*people];

    //Prompt user for the number of pie slices they eat on a yearly basis
    for (int i = 0; i < *people; i++) {
        cout << "Enter the number of slices of pie you eat on a yearly basis: ";
        cin >> numberOfPies[i];
        //Check if input is valid
        while (numberOfPies[i] < 0) {
            cout << "Invalid number!" << endl
                 << "Enter the number of slices of pie you eat on a yearly basis: ";
            cin >> numberOfPies[i];
        }
    }

    //Sort the array in ascending order
    sort(numberOfPies, *people);

    //Print the number of pies in ascending order
    cout << "The number of pies that people eat in ascending order are: " << endl;
    for (int i = 0; i < *people; i++) {
        cout << numberOfPies[i] << endl;
    }

    //Print the mode
    cout << "The mode is : " << getMode(numberOfPies, *people);
    delete [] numberOfPies;
}

void sort(int array[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                //swapping with the smallest element of array.
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int getMode(int array[], int size) {
    int number = array[0];
    int count = 0;
    int countMode = 0;
    int mode;

    for (int i = 0; i <= size; i++) {
        if (array[i] == number) {
            //count occurrences of the current number
            count++;
        }
        else {
            // now this is a different number
            if (count > countMode)
            {
                // mode is the biggest occurrences
                countMode = count;
                mode = number;
            }
            // reset count for the new number
            count = 0;
            number = array[i];
        }
    }
    return mode;
}

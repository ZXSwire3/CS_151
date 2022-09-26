/* DynamicArray - Dynamically allocates an array of Students and holds the student's name and test score
 * Author: Ben Foltz
 * Module: 3
 * Project: Homework 3, project 1
 * Problem Statement: This program dynamically allocates an array of Students and holds the student's name and test score.
 * Algorithm:
 * 1. Class Student
 *    a. Instantiate string name
 *    b. Instantiate int score
 *    c. Create constructor and destructor
 *    d. Create getters and setters for name and score
 * 2. void sort(Student array[], int size)
 *    a. Instantiate string tempName
 *    b. Instantiate int tempScore
 *    c. Use a for loop from 0 to size - 1
 *       i. Use a for loop from i + 1 to size
 *          1. if score at array[i] > score at array[j]
 *              a. tempName = array[j].getName()
 *              b. tempScore = array[j].getScore()
 *              c. value at array[j] = array[i]
 *              d. set name at array[i] = tempName
 *              e. set score at array[i] = tempScore
 * 3. getAverage(Student array[], int size)
 *    a. Instantiate int sum = 0
 *    b. Instantiate double average
 *    c. Use a for loop from 0 to size
 *       i. add score at array[i] to sum
 *    d. Average = sum / size
 *    e. return average
 * 4. int main()
 *    a. Instantiate int *numberOfTest = new int
 *    b. Prompt user for number of test to be input
 *    c. Instantiate dynamically allocated array of Students with size numberOfTests
 *    d. Instantiate string *name
 *    e. Instantiate int *score
 *    f. Use a for loop from 0 to *numberOfTests
 *       i. Prompt user for student name
 *      ii. Prompt user for student score
 *     iii. while (*score < 0)
 *          1. Print error
 *          2. Prompt user for student score
 *      iv. Set name of the student
 *       v. Set score of the student
 *    g. sort(studentScores, *numberOfTests)
 *    h. Use a for loop from 0 to *numberOfTests
 *       i. Print student's name and score
 *    i. Print average score
 *    j. delete dynamically allocated array
 */
#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

struct Stone {
    char letter; //the letter of the stone occupying a slot in the display box (A - J)
    int attempts; //the number of attempts it took to find an available slot for this stone

    Stone (char letter, int attempts) {
        Stone::letter = letter;
        Stone::attempts = attempts;
    }
};
int main() {
    srand(time(NULL));
    unique_ptr<Stone> slots[10];

    int random;
    int max = 9;
    int min = 0;
    int attempts = 0;

    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J'};

    for (int i = 0; i < sizeof(slots); ++i) {
//        cout << "first loop" << endl;
        for (int j = 0; j < sizeof(slots); ++j) {
//            cout << "second loop" << endl;
            random = (rand() % (max - min + 1)) + min;
//            cout << random << endl;
            if (!slots[random]) {
                cout << attempts << endl;
                attempts++;
            } else {
                cout << "slot: " <<  random << " letter: " << letters[random] << " attempts: " << attempts << endl;
                unique_ptr<Stone> new_stone(new Stone(letters[random], attempts));
                slots[random] = std::move(new_stone);
                attempts = 0;
//                cout << "slot: " <<  random << " letter: " << slots[random]->letter << " attempts: " << slots[random]->attempts << endl;
            }
        }
    }

    cout << left << setw(6) << "Slot" << setw(7) << "Stone" << "Attempts" << endl
         << "----  -----  --------" << endl;

    for (int i = 0; i < sizeof(slots); i++) {
        cout << right << setw(4) << i << right << setw(5) << slots[i]->attempts << setw(6) << slots[i]->attempts;
    }
}
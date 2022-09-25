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

using namespace std;

class Student {
    private:
        string name; //student's name
        int score; //student's test score
    public:
        //Constructor
        Student(string name = "", int score = 0) {
            setName(name);
            setScore(score);
        }
        //Destructor
        ~Student() {}

        //Getters
        const string &getName() const {
            return name;
        }

        int getScore() const {
            return score;
        }

        //Setters
        void setName(string name) {
            Student::name = name;
        }

        void setScore(int score) {
            Student::score = score;
        }
};

void sort(Student array[], int size);
double getAverage(Student array[], int size);

int main() {
    //Create a pointer to an int of how many tests are going to be entered
    int *numberOfTests = new int;
    //Prompt user for number of tests
    cout << "Enter the number of test scores being entered: ";
    cin >> *numberOfTests;

    //Create a pointer to an array of Students with the size of numberOfTests
    Student *studentScores = new Student[*numberOfTests];

    //Create a pointer "name" to a string
    string *name = new string;
    //Create a pointer "score" to an int
    int *score = new int;
    //Prompt user for student name and score
    for (int i = 0; i < *numberOfTests; i++) {
        cout << "Enter student name: ";
        cin >> *name;
        cout << "Enter score " << ": ";
        cin >> *score;
        //Check if input is valid
        while (*score < 0) {
            cout << "Invalid score!" << endl
                    << "Enter score " << ": ";
            cin >> *score;
        }

        //Set the name of a student
        studentScores[i].setName(*name);
        //Set the score of a student
        studentScores[i].setScore(*score);
    }

    //Sort the array in ascending order
    sort(studentScores, *numberOfTests);

    //Print the scores in ascending order
    cout << "The test scores in ascending order are: " << endl;
    for (int i = 0; i < *numberOfTests; i++) {
        cout << left << "Name: " << left << setw(8) << studentScores[i].getName() << " Score: " << studentScores[i].getScore() << endl;
    }
    cout << "The average score is: " << getAverage(studentScores, *numberOfTests);
    delete [] studentScores;
}

//Selection sort function
void sort(Student array[], int size) {
    string tempName;
    int tempScore;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i].getScore() > array[j].getScore()) {
                //swapping with the smallest element of array.
                tempName = array[j].getName();
                tempScore = array[j].getScore();
                array[j] = array[i];
                array[i].setName(tempName);
                array[i].setScore(tempScore);
            }
        }
    }
}

//Calculate the average score
double getAverage(Student array[], int size) {
    int sum = 0;
    double average;

    //Loop through the entire array and add to the sum
    for (int i = 0; i < size; i++) {
        sum += array[i].getScore();
    }
    //Divide sum by size
    average = double(sum) / size;

    //return average
    return average;
}
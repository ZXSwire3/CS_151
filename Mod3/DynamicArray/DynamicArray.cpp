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
    double avg;

    //Loop through the entire array and add to the sum
    for (int i = 0; i < size; ++i) {
        sum += array[i].getScore();
    }
    //Divide sum by size
    avg = double(sum) / size;

    //return average
    return avg;
}
/* Numbers - Creates a Numbers class and prints the number in word form.
 * Author: Ben Foltz
 * Module: 5
 * Project: Homework 5, project 1
 * Problem Statement: This creates a Numbers class and prints the number in word form.
 * Algorithm:
 * 1. Class Student
 *    a. Instantiate int number
 *    b. Create constructor and destructor
 *    c. Create print function
 * 2. void print()
 *    a. Instantiate int numberChanging to Numbers::number
 *    b. if (numberChanging < 20)
 *       i. print lessThan20[numberChanging]
 *    c. else
 *       i. if (numberChanging >= 1000)
 *          1. if numberChanging has values greater than 0 after the first digit
 *              a. print lessThan[numberChanging / 1000] << " " << thousand << " "
 *              b. numberChanging = numberChanging % 1000
 *          2. else
 *              a. print lessThan[numberChanging / 1000] << " " << thousand << endl
 *              b. return
 *      ii. if (numberChanging >= 100)
 *          1. if numberChanging has values greater than 0 after the first digit
 *             a. print lessThan[numberChanging / 100] << " " << hundred << " "
 *             b. numberChanging = numberChanging % 100
 *          2. else
 *             a. print lessThan[numberChanging / 100] << " " << hundred << endl
 *             b. return
 *     iii. if (numberChanging >= 20)
 *          1. if numberChanging has values greater than 0 after the first digit
 *             a. print tens[(numberChanging / 10) - 1] << " "
 *             b. numberChanging = numberChanging % 10
 *          2. else
 *             a. print tens[(numberChanging / 10) - 1] << endl
 *             b. return
 *      iv. if (numberChanging < 20)
 *          1. print lessThan20[numberChanging] << endl
 * 3. int main()
 *    a. infinite loop
 *       i. Instantiate int number
 *      ii. Prompt user for input
 *     iii. Create new Numbers Object
 *      iv. use Number.print() function
 *       v. if (number == 0)
 *          1. exit(EXIT_SUCCESS)
 */
#include <iostream>

using namespace std;

class Numbers {
    private:
        int number; //number that will be converted to words
    public:
        const static string lessThan20[]; //contains numbers under 20 in word form
        const static string tens[];       //contains tens in word form
        const static string hundred;      //100 in word form
        const static string thousand;     //1000 in word form

        //Constructor
        Numbers(int);

        //Print number in word form
        void print();

};

const string Numbers::lessThan20[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const string Numbers::tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const string Numbers::hundred = "hundred";

const string Numbers::thousand = "thousand";

Numbers::Numbers(int number) {
    if (number < 0) {
        cout << "Invalid number!" << endl;
    } else {
        Numbers::number = number;
    }
}

void Numbers::print() {
    //value that will change
    int numberChanging = Numbers::number;

    if (Numbers::number < 20) { //if less than 20 return after printing value
        cout << lessThan20[numberChanging] << endl;
        return;
    } else { //otherwise check the other values
        //check if value is greater than or equal to 1000
        if (numberChanging >= 1000) {
            if (numberChanging % 1000 > 0) { //check if value has values greater than 0 in the hundreds place
                cout << lessThan20[numberChanging / 1000] << " " << thousand << " ";
                //remove first digit of number (in the thousands place)
                numberChanging = numberChanging % 1000;
            } else { //otherwise print a new line at the end
                cout << lessThan20[numberChanging / 1000] << " " << thousand << endl;
                return;
            }
        }

        //check if value is greater than or equal to 100
        if (numberChanging >= 100) {
            if (numberChanging % 100 > 0) { //check if value has values greater than 0 in the tens place
                cout << lessThan20[numberChanging / 100] << " " << hundred << " ";
                //remove first digit of number (in the hundreds place)
                numberChanging = numberChanging % 100;
            } else { //otherwise print a new line at the end
                cout << lessThan20[numberChanging / 100] << " " << hundred << endl;
                return;
            }
        }

        //check if value is greater than or equal to 20
        if (numberChanging >= 20) {
            if (numberChanging % 10 > 0) { //check if value has values greater than 0 in the ones place
                cout << tens[(numberChanging / 10) - 1] << " ";
                //remove first digit of number (in the tens place)
                numberChanging = numberChanging % 10;
            } else { //otherwise print a new line at the end
                cout << tens[(numberChanging / 10) - 1] << endl;
                return;
            }
        }

        //check if value is less than 20
        if (numberChanging < 20) {
            cout << lessThan20[numberChanging] << endl;
        }
    }
}

int main() {
    //Loop forever
    while (true) {
        int number;
        //Prompt user for input
        cout << "Please enter a number from 0-9999: ";
        cin >> number;

        //Create new Numbers object
        Numbers numberToWords = Numbers(number);
        //Print number in word form
        numberToWords.print();


        //exit loop when input is 0
        if (number == 0) {
            exit(EXIT_SUCCESS);
        }
    }
}
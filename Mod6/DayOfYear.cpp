/* DayOfYear - Creates a DayOfYear object and prints out what month and day of that month it is.
 * Author: Ben Foltz
 * Module: 6
 * Project: Homework 6, project 1
 * Problem Statement: This creates a DayOfYear object and prints out what month and day of that month it is.
 * Algorithm:
 * 1. Class DayOfYear
 *    a. Instantiate int day
 *    b. Create 2 constructors, DayOfYear(int day), DayOfYear(string month, int day)
 *    c. Create getter function
 *    d. Overload stream extraction function
 *    e. Overload prefix and postfix increment
 *    f. Overload prefix and postfix decrement
 * 2. Overloaded Stream Extraction
 *    a. Create string array with months of the year
 *    b. Create int array with the number of days in each month
 *    c. For loop from 0 to 12
 *       i. if (day <= 31)
 *          1. Create string object that prints out the month and the day of the month
 *          2. break
 *      ii. Decrement day by the number of days in each month
 *    d. put date in output stream
 *    e. return out
 * 3. DayOfYear(string month, int day)
 *    a. Create string array with months of the year
 *    b. Create int array with the number of days in each month
 *    c. Instantiate bool validMonth and bool validDay
 *    d. Instantiate int dayOfTheYear = 0
 *    e. For loop from 0 to 12
 *       i. if month == monthsOfTheYear[i]
 *          1. validMonth = true
 *          2. if dayOfTheMonth is less than or equal to daysOfTheMonths[i]
 *             a. validDay = true
 *             b. Increment dayOfTheYear by dayOfTheMonth
 *          3. exit loop
 *      ii. else
 *          1. increment dayOfTheYear by the number of days in each month
 *    f. if !validMonth
 *       i. print error
 *      ii. exit failure
 *    g. if !validDay
 *       i. print error
 *      ii. exit failure
 *    h. DayOfYear::day = dayOfTheYear
 * 4. int main()
 *    a. Instantiate 5 DayOfYear objects
 *    b. Print out 5 DayOfYear objects
 *    c. Instantiate 5 DayOfYear objects with month and day
 *    d. Print out 5 DayOfYear objects
 *    e. Print out DayOfYear object and manipulate it with prefix decrement
 *    f. Print out DayOfYear object and manipulate it with prefix increment
 *    g. Print out DayOfYear object and manipulate it with postfix decrement
 *    h. Print out DayOfYear object and manipulate it with postfix increment
 *    j. Create invalid DayOfYear object
 */
#include <iostream>

using namespace std;

class DayOfYear {
    private:
        int day;    //day of the year ex: 45
    public:
        //Constructors
        DayOfYear(int day) {
            DayOfYear::day = day;
        }

        DayOfYear(string month, int dayOfTheMonth) {
            //All the months in the year
            string monthsOfTheYear[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            //How many dayOfTheYear each month has
            int daysOfTheMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31 ,30 ,31};

            bool validMonth;
            bool validDay;

            //Day of the year
            int dayOfTheYear = 0;
            int count = 0;

            //Loop through all the months of the year
            for (int i = 0; i < 12; ++i) {
                //check if the month provided is a monthOfTheYear
                if (month == monthsOfTheYear[i]) {
                    //validMonth is true if month is a monthOfTheYear
                    validMonth = true;

                    //check if dayOfTheMonth is a valid day for that specific month
                    if (dayOfTheMonth <= daysOfTheMonths[i]) {
                        validDay = true;
                        //Increment dayOfTheYear by dayOfTheMonth
                        dayOfTheYear += dayOfTheMonth;
                    }

                    //exit loop if month is valid
                    break;
                } else {
                    //Increment dayOfTheYear by the number of days in each month
                    dayOfTheYear += daysOfTheMonths[i];
                }
                //Increment count to give specific error if day is not valid
                count++;
            }

            if (!validMonth) {
                cout << "Invalid Month!";
                exit(EXIT_FAILURE);
            }

            if (!validDay) {
                cout << "Invalid Day!" << endl
                     << "Must be 0-" << daysOfTheMonths[count] << " for " << monthsOfTheYear[count];
                exit(EXIT_FAILURE);
            }

            DayOfYear::day = dayOfTheYear;
        }


        //Getter
        int getDay();

        //Overloaded Functions
        friend ostream &operator<<(ostream &, const DayOfYear &); //stream extraction overload
        DayOfYear operator++(); //prefix increment overload
        DayOfYear operator++(int); //postfix increment overload
        DayOfYear operator--(); //prefix decrement overload
        DayOfYear operator--(int); //postfix decrement overload
};

//Stream extraction overload
ostream &operator<<(ostream &out, const DayOfYear &output_DayOfYear) {
    //All the months of the year
    string monthsOfTheYear[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    //How many days each month has
    int daysOfTheMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31 ,30 ,31};

    //Day of the year of the object
    int day = output_DayOfYear.day;
    //Date in month and day form. ex: January 1
    string date;

    //Loop through all months of the year
    for (int i = 0; i < 12; ++i) {
        //If the day is less than or equal to 31 then create the date string
        if (day <= 31) {
            date = monthsOfTheYear[i] + " " + to_string(day);
            break;
        }
        //Decrement day by the number of days in each month
        day -= daysOfTheMonths[i];
    }

    out << date;
    return out;
}

//Prefix increment overload
DayOfYear DayOfYear::operator++() {
    //Check if day is the last day of the year
    if (day + 1 > 365) {
        //Set day to the first day of the year
        day = 1;
    } else {
        //Increment day by one
        ++day;
    }
    //return object
    return *this;
}

//Postfix increment overload
DayOfYear DayOfYear::operator++(int) {
    //Create copy of the object
    DayOfYear copy = *this;
    //Check if day is the last day of the year
    if (copy.day + 1 > 365) {
        //Set day to the first day of the year
        day = 1;
    } else {
        //Increment day by one
        day++;
    }
    //return object
    return copy;
}

//Prefix decrement overload
DayOfYear DayOfYear::operator--() {
    //Check if day is the first day of the year
    if (day - 1 == 0) {
        //Set day to last day of the year
        day = 365;
    } else {
        //Decrement day by one
        --day;
    }
    //return object
    return *this;
}

//Postfix decrement overload
DayOfYear DayOfYear::operator--(int) {
    //Create copy of the object
    DayOfYear copy = *this;
    //Check if day is the last day of the year
    if (copy.day - 1 == 0) {
        //Set day to the first day of the year
        day = 365;
    } else {
        //Decrement day by one
        day--;
    }
    //return object
    return copy;
}

//Getter
int DayOfYear::getDay() {
    return day;
}

int main() {
    //Create DayOfYear objects with first constructor
    cout << "Day Constructor:" << endl;
    DayOfYear fifteen = DayOfYear(15);
    cout << fifteen << endl;
    DayOfYear thirtyOne = DayOfYear(31);
    cout << thirtyOne << endl;
    DayOfYear fiftyNine = DayOfYear(59);
    cout << fiftyNine << endl;
    DayOfYear oneEighty = DayOfYear(180);
    cout << oneEighty << endl;
    DayOfYear threeSixty = DayOfYear(360);
    cout << threeSixty << endl << endl;

    //Create DayOfYear objects with second constructor
    cout << "Day and Month Constructor:" << endl;
    DayOfYear janOne = DayOfYear("January", 1);
    cout << janOne << endl;
    DayOfYear marFour = DayOfYear("March", 4);
    cout << marFour << endl;
    DayOfYear julTwentyFifth = DayOfYear("July", 25);
    cout << julTwentyFifth << endl;
    DayOfYear decThirtyOne = DayOfYear("December", 31);
    cout << decThirtyOne << endl << endl;

    //Manipulate object with prefix decrement
    cout << "Using January 1 (day 1):" << endl;
    cout << "The original value: " << janOne << endl;
    cout << "Using prefix--    : " << --janOne << endl;
    cout << "After prefix--    : " << janOne << endl << endl;

    //Manipulate object with prefix increment
    cout << "Using March 4 (day 63):" << endl;
    cout << "The original value: " << marFour << endl;
    cout << "Using prefix++    : " << ++marFour << endl;
    cout << "After prefix++    : " << marFour << endl << endl;

    //Manipulate object with postfix decrement
    cout << "Using July 25 (day 206):" << endl;
    cout << "The original value: " << julTwentyFifth << endl;
    cout << "Using postfix--   : " << julTwentyFifth-- << endl;
    cout << "After postfix--   : " << julTwentyFifth << endl << endl;

    //Manipulate object with postfix increment
    cout << "Using January 1 (day 1):" << endl;
    cout << "The original value: " << janOne << endl;
    cout << "Using postfix++   : " << janOne++ << endl;
    cout << "After postfix++   : " << janOne << endl << endl;

    //Create invalid DayOfYear object
    cout << "Invalid Date:" << endl;
    DayOfYear febThirty = DayOfYear("February", 30);
    cout << febThirty;

    return 0;
}
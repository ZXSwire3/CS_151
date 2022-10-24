/* EncryptableString.cpp - Create objects of EncryptableString
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Homework 7, project 2
 * Problem statement:  Create a child class to the string class.
 *
 * Algorithm:
 *   1.  Create EncryptableString class which is a child of the string class
 *   2.  Create encrypt() function
 *       a. Loop through string
 *          i. if character at string[i] is a letter or a number
 *              1. if letter at string[i] is Z
 *                  a. letter at string[i] = 'A'
 *              2. else if letter at string[i] is z
 *                  a. letter at string[i] = 'a'
 *              3. else if character at string[i] is 9
 *                  a. character at string[i] = '0'
 *       c. print out encrypted phrase
 *   3.  Prompt user for input
 *   4.  Create EncryptableString object from input
 *   5.  Create 5 more EncryptableString objects
 */
#include <iostream>
using namespace std;

class EncryptableString : public string {
    public:
        //Constructor
        EncryptableString(string phrase) : string(phrase){
            encrypt();
        }

        //Member function
        void encrypt() {
            string phrase = &EncryptableString::at(0);

            for (int i = 0; i < phrase.length(); ++i) {
                //Check if character is a letter or a number
                if ((phrase[i] >= 64 && phrase[i] <= 90) || (phrase[i] >= 97 && phrase[i] <= 122) || (phrase[i] >= 48 && phrase[i] <= 57)) {
                    if (phrase[i] == 'Z') { //if character is Z
                        phrase[i] = 'A';
                    } else if (phrase[i] == 'z') { //if character is z
                        phrase[i] = 'a';
                    } else if (phrase[i] == '9') { //if character is 9
                        phrase[i] = '0';
                    } else { //otherwise increment value
                        phrase[i] = toascii(phrase[i] + 1);
                    }
                }
            }

            //print encrypted message
            cout << phrase << endl;
        }
};

int main () {
    string input;

    cout << "Enter a phrase: ";
    cin >> input;

    EncryptableString Einput(input);

    //Create PString objects
    EncryptableString exclamation("Holy Moly!");
    EncryptableString zoo("San Diego Zoo.");
    EncryptableString cost("The cost is $25.89.");
    EncryptableString taco("Go away – unless you have tacos.");
    EncryptableString consent("No one can make you feel inferior without your consent.");
}
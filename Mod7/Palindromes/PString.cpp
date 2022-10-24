/* PString.cpp - Create objects of PStrings
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Homework 7, project 1
 * Problem statement:  Create a child class to the string class.
 *
 * Algorithm:
 *   1.  Create PString class which is a child of the string class
 *   2.  Create isPalindrome() function
 *       a. Convert string to lowercase
 *       b. Loop through string and remove characters that are not numbers or lowercase letters
 *       c. Loop through string and check if values are equal forward and backward
 *   3.  Prompt user to input a string
 *   4.  Create PString object from input
 *   5.  Create 8 more PString objects
 */
#include <iostream>
using namespace std;

class PString : public string {
    public:
        //Constructor
        PString(string phrase) : string(phrase){
            string trueOrFalse;
            if (isPalindrome()) {
                trueOrFalse = "a";
            } else {
                trueOrFalse = "not a";
            }
            //Print out phrase and if it is a palindrome or not.
            cout << "\"" << phrase << "\"" << " is " << trueOrFalse << " palindrome." << endl;
        }

        //Member function
        bool isPalindrome() {
            string phrase = &PString::at(0);
            string lowercasePhrase = phrase;

            //Convert String to lower case
            for (int i = 0; i < phrase.size(); ++i) {
                lowercasePhrase[i] = tolower(phrase[i]);
            }

            for (int i = 0; i < lowercasePhrase.length(); ++i) {
                //Remove parts that are not lowercase letters or numbers
                for (int j = 0; j < lowercasePhrase.length(); ++j) {
                    if (!(lowercasePhrase[i] >= 97 && lowercasePhrase[i] <= 122) && !(lowercasePhrase[i] >= 48 && lowercasePhrase[i] <= 57) && lowercasePhrase[i] != 0) {
                        lowercasePhrase.erase(lowercasePhrase.begin()+i);
                    }
                }
            }

            for (int i = 0; i < lowercasePhrase.length() / 2; ++i) {
                // If string[i] is not equal to the string[string.length-i-1]
                if (lowercasePhrase[i] != lowercasePhrase[lowercasePhrase.length() - i - 1]) {
                    return false;
                }
            }
            return true;
        }
};

int main () {

    string input;

    cout << "Enter a phrase: ";
    cin >> input;

    PString Pinput(input);

    //Create PString objects
    PString Chic("Chic");
    PString Book("Book");
    PString Kayak("Kayak");
    PString numbersX("1x2x3x4x5");
    PString abc("25 ABC9 cba52");
    PString nod("Don't nod");
    PString notClose("Not even close!");
    PString aMan("A man, a plan, a canal -- Panama");
}
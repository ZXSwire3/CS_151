/* RecursivePalindrome.cpp - Prompt user for a word or phrase to check if it is a palindrome.
 * Author:     Ben Foltz
 * Module:     11
 * Project:    Homework 11, project 3
 * Problem statement: Create a recursive function to check if string is a palindrome
 *
 * Algorithm:
 *   1. Create bool isPalindrome(string str, int elements, int search) function
 *       a. if lower is 0
 *           i. str = toLowerCase(str)
 *          ii. str = onlyCharacters
 *         iii. upper = str length - 1
 *       b. if lower is equal to upper or if upper is equal to 0
 *           1. return true
 *       c. else if str[lower] does not equal str[upper]
 *           1. return false
 *       d. else
 *           1. return isPalindrome(str, lower + 1, upper - 1)
 *   2. Create string toLowerCase(string str)
 *       a. for each loop for each char in str
 *           i = tolower(i)
 *       b. return str
 *   3. Create string onlyCharacters(string str)
 *       a. for loop from 0 to length of str
 *           i. for loop from 0 to length of str
 *               1. if char at i in str isn't lowercase or a number
 *                   a. remove element
 *       b. return str
 *   4. int main()
 *       a. Infinite loop
 *           i. Prompt user for input
 *          ii. get line for input
 *         iii. if (isPalindrome(input, 0, input.length() - 1)
 *               1. Print string is a palindrome
 *           v. else
 *               1. Print string is not a palindrome
 */
#include <iostream>

using namespace std;

bool isPalindrome(string str, int lower, int upper);
string toLowerCase(string str);
string onlyCharacters(string str);

int main() {
    string input;

    do {
        cout << "Enter a string to check if it is a palindrome: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        if (isPalindrome(input, 0, input.length() - 1)) {
            cout << "String is a palindrome!" << endl << endl;
        } else {
            cout << "String is not a palindrome!" << endl << endl;
        }

    } while (true);
}

bool isPalindrome(string str, int lower, int upper) {
    if (lower == 0) {
        str = toLowerCase(str);
        str = onlyCharacters(str);
        upper = str.length() - 1;
    }

    if (lower == upper || upper == 0) {
        return true;
    } else if (str[lower] != str[upper]) {
        return false;
    } else {
        return isPalindrome(str, lower + 1, upper - 1);
    }
}

string toLowerCase(string str) {
    for (char & i : str) {
        i = tolower(i);
    }

    return str;
}

string onlyCharacters(string str) {
    for (int i = 0; i < str.length(); ++i) {
        //Remove parts that are not lowercase letters or numbers
        for (int j = 0; j < str.length(); ++j) {
            if (!(str[i] >= 97 && str[i] <= 122) && !(str[i] >= 48 && str[i] <= 57) && str[i] != 0) {
                str.erase(str.begin()+i);
            }
        }
    }

    return str;
}

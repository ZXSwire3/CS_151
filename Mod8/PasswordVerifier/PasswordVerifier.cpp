/* PasswordVerifier.cpp - Prompt user for password input and check if password is valid.
 * Author:     Ben Foltz
 * Module:     8
 * Project:    Homework 8, project 1
 * Problem statement: Create a function checks if the password provided meets the criteria
 *
 * Algorithm:
 *   1. Create bool passwordVerifier(string password) function
 *       a. Instantiate booleans for each criterion (isLongerThan6, hasUppercase, hasLowercase, hasDigit, hasSpace)
 *       b. if password.length() < 6
 *           1. isLongerThan6 = false
 *           2. Print reason why password is invalid
 *       c. Loop through c string
 *           i. if password[i] is uppercase
 *               1. hasUpperCase = true
 *          ii. if password[i] is lowercase
 *               1. hasLowercase = true
 *         iii. if password[i] is a digit
 *               1. hasDigit = true
 *          iv. if password[i] is a space
 *               1. hasSpace = true;
 *       d. if !hasUppercase
 *           1. Print reason why password is invalid
 *       e. if !hasLowercase
 *           1. Print reason why password is invalid
 *       f. if !hasDigit
 *           1. Print reason why password is invalid
 *       g. if hasSpace
 *           1. Print reason why password is invalid
 *       h. if (!isLongerThan6 || !hasUppercase || !hasLowercase || !hasDigit || hasSpace)
 *           1. return false
 *          else
 *           1. return true
 *   2. int main()
 *       a. Infinite loop
 *           i. Create input string
 *          ii. Prompt user for input
 *         iii. Get line and put in input
 *          iv. Call passwordVerifier() with input from user
 */
#include <iostream>
#include <algorithm>

using namespace std;

bool passwordVerifier(string password);

int main () {
    while (true) {
        //User input
        string input;

        //Prompt user for input
        cout << "Enter a password: ";
        getline(cin, input);

        //Copy user input
        string quit = input;
        //Convert copy of user input and convert to lowercase
        for (int i = 0; i < quit.length(); ++i) {
            quit[i] = tolower(quit[i]);
        }
        //Check if user input is "quit"
        if (quit == "quit") {
            //Exit program
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //Call function to check if password is valid
        passwordVerifier(input);
    };
}

bool passwordVerifier(string password) {
    //reason why the password isn't valid
    string notValid = "This password is not valid because";

    //Length (should be true)
    bool isLongerThan6 = true;
    //One uppercase (should be true)
    bool hasUppercase = false;
    //One lowercase (should be true)
    bool hasLowercase = false;
    //One digit (should be true)
    bool hasDigit = false;
    //Any space (should be false)
    bool hasSpace = false;

    //Must be longer than 6 characters long
    if (password.length() < 6) {
        notValid += " each password should be at least six characters long" ;
        isLongerThan6 = false;
    }

    //Loop through elements in C String
    for (int i = 0; i < password.length(); ++i) {
        //Check if there is an uppercase letter
        if (password[i] >= 65 && password[i] <= 90) {
            hasUppercase = true;
        }

        //Check if there is a lowercase letter
        if (password[i] >= 97 && password[i] <= 122) {
            hasLowercase = true;
        }

        //Check if there is a digit
        if (password[i] >= 48 && password[i] <= 57) {
            hasDigit = true;
        }

        //Check if there is a space
        if (password[i] == 32) {
            hasSpace = true;
        }
    }

    //Check if password does not have an uppercase
    if (!hasUppercase) {
        if (!isLongerThan6 && (!hasLowercase || !hasDigit || hasSpace)) { //Check if password isn't longer than 6 characters and if it doesn't have a lowercase, digit or a space
            //use comma and expect more reasons
            notValid += ", at least one uppercase letter";
        } else if (!isLongerThan6) { //Check if password is longer than 6 characters
            //use "and" because there are no additional reasons
            notValid += " and at least one uppercase letter";
        } else {
            //phrase reason like it's the only reason
            notValid += " each password should contain at least one uppercase letter";
        }
    }

    //Check if password does not have lowercase
    if (!hasLowercase) {
        if ((!isLongerThan6 || !hasUppercase) && (!hasDigit || hasSpace)) { //Check if password isn't longer than 6 characters or if it doesn't have an uppercase and if it doesn't have digit or a space
            //use comma and expect more reasons
            notValid += ", at least one lowercase letter";
        } else if (!isLongerThan6 || !hasUppercase) {
            //use "and" because there are no additional reasons
            notValid += " and at least one lowercase letter";
        } else {
            //phrase reason like it's the only reason
            notValid += " each password should contain at least one lowercase letter";
        }
    }

    //Check if password does not have a digit
    if (!hasDigit) {
        if ((!isLongerThan6 || !hasUppercase || !hasLowercase) && hasSpace) { //Check if password isn't longer than 6 characters or if it doesn't have an uppercase or lowercase and if it does have a space
            //use comma and expect more reasons
            notValid += ", at least one digit";
        } else if (!isLongerThan6 || !hasUppercase || !hasLowercase) {
            //use "and" because there are no additional reasons
            notValid += " and at least one digit";
        } else {
            //phrase reason like it's the only reason
            notValid += " each password should contain at least one digit";
        }
    }

    //Check if password has a space
    if (hasSpace) {
        if (!isLongerThan6 || !hasUppercase || !hasLowercase || !hasDigit) { //Check if password isn't longer than 6 characters or if it doesn't have an uppercase or lowercase or digit
            //use comma and "and" because there are no more reasons
            notValid += ", and no blanks";
        } else {
            //phrase reason like it's the only reasonS
            notValid += " each password cannot contain any blanks";
        }
    }

    //Check if there is any reason why the password is invalid
    if (!isLongerThan6 || !hasUppercase || !hasLowercase || !hasDigit || hasSpace) {
        //print reasons why it's invalid
        cout << notValid + "." << endl << endl;
        return false;
    } else {
        //print password is valid
        cout << "Valid password." << endl << endl;
        return true;
    }
}
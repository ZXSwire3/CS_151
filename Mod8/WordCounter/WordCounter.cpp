/* WordCounter.cpp - Prompt user for input and count the number of words that are in it.
 * Author:     Ben Foltz
 * Module:     8
 * Project:    Homework 8, project 1
 * Problem statement: Create a function that counts the number of words in a C String
 *
 * Algorithm:
 *   1. Create int wordCounter(char str[]) function
 *       a. Loop through c string
 *          i. if character at string[i] is a space
 *              1. increment word counter
 *       b. return word count
 *   2. int main()
 *       a. Infinite loop
 *           i. Create C String with max length
 *          ii. Prompt user for input
 *         iii. Get line and put in input C String
 *          iv. Use strcmp to compare input and "quit"
 *               1. exit program if they are the same
 *           v. Call word counter function to print out how many words are in the input.
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int wordCounter(char str[]);

int main () {
    while (true) {
        //Create C String with max length
        char input[INT16_MAX];

        //Prompt user for input
        cout << "Enter a sentence: ";
        //Get line from input and put it into C String
        cin.getline(input, sizeof(input), '\n');

        //exit program if input == quit
        char quit[] = "quit";
        if (strcmp(input, quit) == 0) {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //Print how many words there are
        wordCounter(input) == 1 ? cout << "There is " << wordCounter(input) << " word in the sentence." << endl << endl: cout << "There are " << wordCounter(input) << " words in the sentence." << endl << endl;
    };
}

int wordCounter(char str[]) {
    int words = 1;

    //Loop through elements in C String
    for (int i = 0; i < strlen(str); ++i) {
        //Check if element is a space
        if (str[i] == 32) {
            //increment words if a space is present
            words++;
        }
    }

    //return number of words
    return words;
}
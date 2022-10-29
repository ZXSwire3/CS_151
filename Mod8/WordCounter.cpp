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
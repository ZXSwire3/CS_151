// EncryptableString.cpp
// Author: Ben Foltz
#include <iostream>
#include <algorithm>

using namespace std;

void encrypt(char &c);

int main () {

    string input;

    while (true) {
        //Prompt user for input
        cout << "Enter a string to encode: ";
        getline(cin, input);
        string quit = input;

        //Copy convert quit string to lowercase
        for_each(quit.begin(), quit.end(), [](char &c) { c = tolower(c); });
        if (input == "quit") {
            cout << "Exiting program...";
            exit(EXIT_SUCCESS);
        }

        //Print input
        cout << "Input String: " << input << endl;
        //Convert each char in the string
        for_each(input.begin(), input.end(), [](char &c) { encrypt(c); });
        //Print encrypted string
        cout << "Encrypted String: " << input << endl << endl;
    };

}

void encrypt(char &character) {
    //Check if character is a letter or a number
    if ((character >= 64 && character <= 90) || (character >= 97 && character <= 122) || (character >= 48 && character <= 57)) {
        if (character == 'Z') { //if character is Z
            character = 'A';
        } else if (character == 'z') { //if character is z
            character = 'a';
        } else if (character == '9') { //if character is 9
            character = '0';
        } else { //otherwise increment value
            character = toascii(character + 1);
        }
    }
}
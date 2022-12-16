/* PlanetZoo.cpp - Prompt user to create 3 possible animals, elephant, koala, or snake
 * Author:     Ben Foltz
 * Project:    Final Project
 * Problem statement: Create animals to fill the zoo
 *
 * Algorithm:
 *   1. Create int choice for user input to choose which animal to make
 *   2. Create string name and int age for the generic animal values
 *   3. Create an elephant object with generic values
 *   4. Create elephant specific variables, ie. breed and color
 *   5. Create bool elephantMade to check if an elephant has already been made
 *   6. Create a koala object with generic values
 *   7. Create koala specific variables, ie. earSize
 *   8. Create bool koalaMade to check if a koala has already been made
 *   9. Create a snake object with generic values
 *  10. Create snake specific variables, ie. isVenomous
 *  11. Create bool snakeMade to check if a snake has already been made
 *  12. Print out Title screen
 *  13. do while loop until user types -1
 *       a. Prompt user for input on which animal to create
 *       b. switch (choice)
 *           i. case 1
 *               1. check if elephantMade
 *                   a. print error
 *                   b. break
 *               2. Prompt user for name
 *               3. Prompt user for age
 *               4. Prompt user for breed
 *               5. Prompt user for color
 *               6. try
 *                   a. set userMadeElephant to new values that are input from user
 *                   b. set elephantMade to true
 *               7. catch (Animal::olderThanLifeSpan)
 *                   a. Print error
 *                   b. break
 *               8. break
 *          ii. case 2
 *               1. check if koalaMade
 *                   a. print error
 *                   b. break
 *               2. Prompt user for name
 *               3. Prompt user for age
 *               4. Prompt user for earSize
 *               5. try
 *                   a. set userMadeKoala to new values that are input from user
 *                   b. set koalaMade to true
 *               6. catch (Animal::olderThanLifeSpan)
 *                   a. Print error
 *                   b. break
 *               7. break
 *         iii. case 3
 *               1. check if snakeMade
 *                   a. Print error
 *                   b. break
 *               2. Prompt user for name
 *               3. Prompt user for age
 *               4. Prompt user for venomousString
 *               5. Convert user input from venomousString to lowercase
 *               6. try
 *                   a. if venomousString == "true"
 *                       i. set isVenomous to true
 *                      ii. set userMadeSnake to new values
 *                   b. else
 *                       i. set isVenomous to false
 *                      ii. set userMadeSnake to new values
 *                   c. set snakeMade to true
 *               7. catch (Animal::olderThanLifeSpan)
 *                   a. print error
 *                   b. break
 *               8. break
 *          iv. case -1
 *               1. break
 *           v. default
 *               1. Print error
 *               2. break
 *  14. Print out animals in zoo
 *  15. check if elephantMade
 *       a. Print elephant name
 *       b. Print elephant ascii art
 *  16. check if koalaMade
 *       a. Print koala name
 *       b. Print koala ascii art
 *  17. check if snake made
 *       a. Print snake name
 *       b. Print snake ascii art
 *  18. Print out facts about animals
 *  19. check if elephantMade
 *       a. call elephant.showInfo()
 *  20. check if koalaMade
 *       a. call koala.showInfo()
 *  21. check if snake made
 *       a. call snake.showInfo()
 *  22. Print out animals pooping
 *  23. check if elephantMade
 *       a. call elephant.poop()
 *  24. check if koalaMade
 *       a. call koala.poop()
 *  25. check if snake made
 *       a. call snake.poop()
 *  26. Print out animals reproducing
 *  27. check if elephantMade
 *       a. call elephant.createChildren()
 *  28. check if koalaMade
 *       a. call koala.createChildren()
 *  29. check if snake made
 *       a. call snake.createChildren()
 *
 *  Items used:
 *   1. Inheritance             : Animal is parent class to elephant, koala and snake classes
 *   2. Polymorphism            : Animal class had 3 virtual functions that were overloaded by the child classes
 *   3. Exceptions              : Animal class created its own exception that is thrown if age > lifespan
 *   4. Designed Abstract class : Animal class is an abstract class of my own design
 */
#include <iostream>
#include "Animal.h"
#include "Elephant.h"
#include "Koala.h"
#include "Snake.h"

using namespace std;

int main() {

    //User input
    int choice;

    // Animal Values
    string name;
    int age;

    // Create Elephant with temp values
    Elephant userMadeElephant("", 0, 1, true, "", "");
    // Elephant values
    string breed, color;
    int elephantLifespan = 70;
    bool elephantMade = false;

    // Create Koala with temp values
    Koala userMadeKoala("", 0, 1, true, "");
    // Koala values
    string earSize;
    int koalaLifespan = 18;
    bool koalaMade = false;

    // Create Snake with temp values
    Snake userMadeSnake("", 0, 1, true, true);
    // Snake values
    bool isVenomous;
    string venomousString;
    bool snakeMade = false;
    int snakeLifespan = 30;


    // Print out planet ascii art
    cout << "     .-'''';''-."      << endl
         << "   ,'      <_,-.`."    << endl
         << "  /)      ,--,_>\\_\\" << endl
         << " |'      (,    \\_  |" << endl
         << " |_       `-.   /  |"  << endl
         << "  \\`-.      ;  _(`/"  << endl
         << "   `.(       \\/ ,'"   << endl
         << "     `-.......-'"      << endl;

    // Print welcoming title
    cout << "Welcome to planet zoo!" << endl
         << "Today we are going to be creating animals to place in our zoo!" << endl;

    // Loop until user types in -1
    do {
        // Prompt user for input
        cout << "\nAnimal Choices: " << endl
             << " 1. Elephant" << endl
             << " 2. Koala" << endl
             << " 3. Snake" << endl
             << "-1. Exit " << endl;
        cin >> choice;

        switch (choice) {
            // Create elephant
            case 1:
                // Check if elephant has been made
                if (elephantMade) {
                    // Print error
                    cout << "Elephant already made!" << endl;
                    // exit switch
                    break;
                }
                // Prompt user
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter breed: ";
                cin >> breed;
                cout << "Enter color: ";
                cin >> color;

                //Exception
                try { // Try to set elephant to new values
                    // Set userMadeElephant to new values
                    userMadeElephant = Elephant(name, age, elephantLifespan, true, breed, color);
                    // Set elephantMade to true
                    elephantMade = true;
                } catch (Animal::olderThanLifespan) { // Catch if elephant is older than lifespan
                    // Print error
                    cout << "\nEntered age is older than the normal life expectancy of elephants" << endl
                         << "Elephants normally live to a max of " << elephantLifespan << " years" << endl;
                    // exit switch
                    break;
                }
                // exit switch
                break;
            // Create Koala
            case 2:
                // Check if koala has been made
                if (koalaMade) {
                    // Print error
                    cout << "Koala already made!" << endl;
                    // exit switch
                    break;
                }
                // Prompt user
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter ear size: ";
                cin >> earSize;

                //Exception
                try { // Try to set koala to new values
                    // Set userMadeKoala to new values
                    userMadeKoala = Koala(name, age, koalaLifespan, true, earSize);
                    // Set koalaMade to true
                    koalaMade = true;
                } catch (Animal::olderThanLifespan) { // Catch if koala is older than lifespan
                    // Print error
                    cout << "\nEntered age is older than the normal life expectancy of koalas" << endl
                         << "Koalas normally live to a max of " << koalaLifespan << " years" << endl;
                    // exit switch
                    break;
                }
                // exit switch
                break;
            // Create snake
            case 3:
                // Check if snake has been made
                if (snakeMade) {
                    // Print error
                    cout << "Snake already made!" << endl;
                    // exit switch
                    break;
                }
                // Prompt user
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter true or false if venomous: ";
                cin >> venomousString;

                // Convert venomousString to lowercase
                for (char & i : venomousString) {
                    i = tolower(i);
                }

                //Exception
                try { // Try to set snake to new values
                    // Check value of user input
                    if (venomousString == "true") {
                        // Set isVenomous to true
                        isVenomous = true;
                        // Set userMadeSnake to new values
                        userMadeSnake = Snake(name, age, snakeLifespan, true, isVenomous);
                    } else {
                        // Set isVenomous to false
                        isVenomous = false;
                        userMadeSnake = Snake(name, age, snakeLifespan, false, isVenomous);
                    }
                    // Set snakeMade to true
                    snakeMade = true;
                } catch (Animal::olderThanLifespan) { // Catch if snake is older than lifespan
                    // Print error
                    cout << "\nEntered age is older than the normal life expectancy of snakes" << endl
                         << "Snakes normally live to a max of " << snakeLifespan << " years" << endl;
                    // exit switch
                    break;
                }
                // exit switch
                break;
            case -1:
                break;
            default:
                // Print error
                cout << "Not a valid input!" << endl
                     << "Choose one of the animals to create or type -1 to exit" << endl;
                // exit switch
                break;
        }
    } while (choice != -1);

    // Print out animals in the zoo
    cout << "\nAnimals in the zoo: " << endl;
    // Check if an elephant was made
    if (elephantMade) {
        // Print elephant's name
        cout << "  " << userMadeElephant.getName() << endl;

        // Print out ascii art of elephant
        cout << "  __      __"             << endl
             << " /  \\~~~~/  \\"          << endl
             << "(     ..     )----."      << endl
             << " \\__      __/      \\"   << endl
             << "   )|   /)         |\\"   << endl
             << "    |  /\\  /___\\  /  ^" << endl
             << "     ''-|__|   |__|"      << endl;

    }
    // Check if a koala was made
    if (koalaMade) {
        // Print out koala's name
        cout << "  " << userMadeKoala.getName() << endl;

        // Print out ascii art of koala
        cout << "       |   |##/#"  << endl
             << "       |   | //##" << endl
             << " \\'---'/   |//"   << endl
             << " '.^O^.'_   /"     << endl
             << " /    ___: |"      << endl
             << "(    :|_   |"      << endl
             << " \\__,___:  |"     << endl
             << "       |   |"      << endl;
    }
    // Check if a snake was made
    if (snakeMade) {
        // Print out snake's name
        cout << " " << userMadeSnake.getName() << endl;

        //Print out ascii art of snake
        cout << "   .--."         << endl
             << ">-'-') )"        << endl
             << "    / /   __"    << endl
             << "   ( (_.-'_ '."  << endl
             << "    '--'     ')" << endl
             << "         _.-'"   << endl;
    }

    // Print out facts about the animals
    cout << "\nFacts about the animals:" << endl;
    // Check if an elephant was made
    if (elephantMade) {
        userMadeElephant.showInfo();
    }
    // Check if a koala was made
    if (koalaMade) {
        userMadeKoala.showInfo();
    }
    // Check if a snake was made
    if (snakeMade) {
        userMadeSnake.showInfo();
    }
    cout << endl;

    // Print out every animal pooping
    cout << "Time to clean up the animal habitats!" << endl;
    // Check if an elephant was made
    if (elephantMade) {
        userMadeElephant.poop();
    }
    // Check if a koala was made
    if (koalaMade) {
        userMadeKoala.poop();
    }
    // Check if a snake was made
    if (snakeMade) {
        userMadeSnake.poop();
    }
    cout << endl;

    // Print out every animal reproducing
    cout << "WOW! The animals are giving birth!" << endl;
    // Check if an elephant was made
    if (elephantMade) {
        userMadeElephant.createChildren();
    }
    // Check if a koala was made
    if (koalaMade) {
        userMadeKoala.createChildren();
    }
    // Check if a snake was made
    if (snakeMade) {
        userMadeSnake.createChildren();
    }
    cout << endl;
}

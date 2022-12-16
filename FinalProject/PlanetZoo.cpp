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
             << "1. Elephant" << endl
             << "2. Koala" << endl
             << "3. Snake" << endl;
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
                //Prompt user
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter true or false if venomous: ";
                cin >> venomousString;


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

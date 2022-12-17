/* AbstractSeqTest.cpp - Test out AbstractSequence class and it's children
 * Author:     Ben Foltz
 * Module:     12
 * Project:    Homework 12, project 2
 * Problem statement: Create objects of the AbstractSequence class's children and print out their sequence and sums
 *
 * Algorithm:
 *   1. Create Odds object
 *   2. Print heading
 *   3. call printSeq(3, 12) on odds object
 *   4. Print sum of odds object from 7 to 9
 *   5. Create factorial object
 *   6. Print heading
 *   7. call printSeq(1, 10) on factorial object
 *   8. Print sum of factorial object from 4 to 6
 */
#include <iostream>
#include "SubSequence.h"
using namespace std;

int main() {

    //Create odds object
    Odds odds;

    //Print heading
    cout << "Odd numbers fun(3) to fun(12) are: " << endl;
    //Print out odds sequence from 3 to 12
    odds.printSeq(3, 12);
    //Print out sum from odds fun(7) to fun(9)
    cout << "The sum of fun(7) to fun(9) is " << odds.sumSeq(7, 9) << endl << endl;

    //Create factorial object
    Factorial factorial;

    //Print heading
    cout << "Factorial numbers fun(1) to fun(10) are: " << endl;
    //Print out factorial from 1 to 10
    factorial.printSeq(1, 10);
    //Print out sum from factorial fun(7) to fun(9)
    cout << "The sum of fun(4) to fun(6) is " << factorial.sumSeq(4, 6) << endl;

    return 0;
}
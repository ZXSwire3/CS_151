/* SetLinkedList.cpp - Tests a set in C++
 * Author:     Ben Foltz
 */

#include <iostream>
#include "SetLinkedList.h"

using namespace std;

template<typename T>
void runTests(Set<T> A, Set<T> B) {
    cout << "Set A: ";
    A.display();
    cout << "Set B: ";
    B.display();

    cout << "A n B: ";
    A.setIntersect(B).display();

    cout << "A u B: ";
    A.setUnion(B).display();

    cout << "A - B: ";
    A.minus(B).display();

    cout << "(A - B) U (A n B): ";
    A.minus(B).setUnion(A.setIntersect(B)).display();

    cout << "equal?: ";
    if (A.minus(B).setUnion(A.setIntersect(B)).equals(A)) {
        cout << "yes" << endl << endl;
    } else {
        cout << "no" << endl << endl;
    }
}

int main() {
    // Create two new string sets
    Set<string> setA;
    Set<string> setB;

    // Insert values in setA
    setA.insert("C");
    setA.insert("G");
    setA.insert("E");
    setA.insert("A");

    // Insert values in setB
    setB.insert("E");
    setB.insert("C");
    setB.insert("F");

    // Run tests on both sets
    runTests(setA, setB);

    // Clear both sets
    setA.clear();
    setB.clear();

    // Insert values in setA
    setA.insert("Carlos");
    setA.insert("John");
    setA.insert("Alice");

    // Insert values in setB
    setB.insert("John");
    setB.insert("Henry");
    setB.insert("Maria");

    // Run tests on both sets
    runTests(setA, setB);

    // Create two new int sets
    Set<int> intSetA;
    Set<int> intSetB;

    // Insert values in setA
    intSetA.insert(5);
    intSetA.insert(1);
    intSetA.insert(3);

    // Insert values in setB
    intSetB.insert(1);
    intSetB.insert(3);
    intSetB.insert(5);
    intSetB.insert(7);
    intSetB.insert(9);

    // Run tests on both sets
    runTests(intSetA, intSetB);

    // Clear both sets
    intSetA.clear();
    intSetB.clear();

    // Insert values in setA
    intSetA.insert(5);

    //Run tests on both sets
    runTests(intSetA, intSetB);
}
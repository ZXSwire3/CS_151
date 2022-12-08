//LinkedListTest.cpp
//Author: Ben Foltz
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> list;

    cout << "Display an empty linked list: " << endl;
    list.display();
    cout << endl;

    cout << "Remove an element from an empty linked list: " << list.remove(1) << endl << endl;

    cout << "Add elements to linked list: " << endl;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(1);
    list.addLast(7);
    list.addLast(9);
    list.addLast(2);
    list.addLast(1);
    list.display();
    cout << endl;

    cout << "Find the last index of the element \"1\": " << list.lastIndexOf(1) << endl;
    cout << "Find the last index of the element \"20\": " << list.lastIndexOf(10) << endl << endl;

    cout << "Remove element at index 1: " << endl;
    list.removeAt(1);
    list.display();
    cout << "Remove element at index 30: " << endl;
    try {
        list.removeAt(30);
    } catch (runtime_error) {
        cout << "Index out of range" << endl;
        list.display();
        cout << endl;
    }

    cout << "Remove element \"9\":" << endl;
    list.remove(9);
    list.display();
    cout << "Remove element \"10\":" << endl;
    list.remove(10);
    list.display();
    cout << endl;

    cout << "Check if linked list has an element \"10\": " << list.contains(10) << endl;
    cout << "Check if linked list has an element \"3\": " << list.contains(3) << endl << endl;

    cout << "Try to set value at node 3 to \"12345\", old value: " << list.set(3, 12345) << endl;
    list.display();
    cout << "Try to set value at node 12 to \"54321\", input value because node 12 does not exist: " << list.set(12, 54321) << endl;
    list.display();
}

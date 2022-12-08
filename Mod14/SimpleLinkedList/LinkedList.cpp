/* LinkedList.cpp - Define LinkedList functions
 * Author:     Ben Foltz
 * Module:     14
 * Project:    Homework 14, project 1
 * Problem statement: Define LinkedList functions and test them
 *
 * Algorithm:
 *   1. int main()
 *       a. Create linked list object
 *       b. add 3 elements using add()
 *       c. check if elements are members with isMember()
 *       d. create empty list
 *       e. print empty list
 *       f. print non-empty list
 *       g. reverse linked list with reverse()
 *       h. print list before and after reversing
 *       j. search location of element in linked list
 *       k. search location of element not in linked list
 *       l. insert element at beginning of linked list with insert()
 *       m. print linked list
 *       n. insert element in middle of linked list with insert()
 *       o. insert element at end of linked list with insert()
 */
#include <iostream>
#include <iomanip>
#include "LinkedList.h"

using namespace std;

//Constructor
LinkedList::LinkedList() {
    head = nullptr;
}

//Add node to beginning of the list
void LinkedList::add(double x) {
    if (head == nullptr) {
        head = new ListNode(x);
    } else {
        head = new ListNode(x, head);
    }
}

//Check if value is in linked list
bool LinkedList::isMember(double x) const {
    ListNode *ptr = head;
    while (ptr != nullptr) {    //loop through list
        if (ptr->value == x) {  //check if value is equal to x
            return true;
        }
        ptr = ptr->next;        //point to next node
    }
    return false;
}

//Print contents of linked list
void LinkedList::print() {
    ListNode *ptr = head;   //walk list
    cout << fixed << showpoint << setprecision(1);

    if (head == nullptr) {
        cout << "null" << endl;
    } else {
        while (ptr != nullptr) {
            cout << ptr->value << " ";  //print value
            ptr = ptr->next;            //point to next node
        }
        cout << endl;
    }
}

//Reverse order of linked list
void LinkedList::reverse() {
    ListNode *newHead = nullptr;    //new head

    while (head != nullptr) {           //loop through list
        ListNode *next = head->next;    //new next
        head->next = newHead;           //set node after head to new head
        newHead = head;                 //set new head to head
        head = next;                    //set head to next
    }

    head = newHead;                     //linked list is equal to new linked list
}

//Search linked list for value
int LinkedList::search(double x) {
    ListNode *ptr = head ;
    int count = 0;
    while (ptr != nullptr) {
        if (ptr->value == x)            // walk list to find value
            return count ;
        ptr = ptr->next ;               // point to next node
        count++;
    }
    return -1 ;
}

//Insert value at a certain point in the linked list
void LinkedList::insert(double x, int pos) {
    ListNode *ptr = head;
    ListNode *previous;
    int count = 0;

    ListNode *sizePtr = head;
    int size = 0;
    while (sizePtr != nullptr) {
        sizePtr = sizePtr->next;
        size++;
    }

    if (head == nullptr) {
        head = new ListNode(x);
    } else if (pos == 0) {
        ListNode *newNode = new ListNode(x) ;   // Create new node and ptr
        newNode->next = head ;                           // Assign value of head ptr to next ptr of new node
        head = newNode ;                                 // Set head to point at new node
    } else if (pos >= size) {
        ListNode *newNode = new ListNode(x);    // Create new node and ptr
        ListNode *tail = head;                           // Create tail ptr
        newNode->next = nullptr;                         // Point next node to nothing

        while (tail->next != nullptr) {                  // walk list
            tail = tail->next;                           // point to next node
        }

        tail->next = newNode;                            // point tail next to new node
    } else {
        while (ptr != nullptr && count != pos) {         // walk list until count equals pos
            previous = ptr;                              // set previous to current
            ptr = ptr->next;                             // set current to next
            count++;                                     // increment count
        }
        previous->next = new ListNode(x, ptr); // point next node of previous to new value
    }
}

int main () {
    LinkedList list;
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    cout << "isMember() Test" << endl;
    cout << "Is 9.0 a member? ";
    if (list.isMember(9.0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cout << "Is 7.0 a member? ";
    if (list.isMember(7.0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    cout << "Is 5.0 a member? ";
    if (list.isMember(5.0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    cout << endl;

    LinkedList empty;
    cout << "print() Test" << endl
         << "Empty List: ";
    list.print();
    cout << "Non-Empty List: ";
    empty.print();
    cout << endl;

    cout << "reverse() Test" << endl
         << "Original Order: ";
    list.print();
    cout << "Reverse Order: ";
    list.reverse();
    list.print();
    cout << endl;

    cout << "search() Test" << endl
         << "Position of 9.0: " << list.search(9.0) << endl
         << "Position of 1.0: " << list.search(1.0) << endl << endl;

    cout << "insert() Test" << endl
         << "Insert 2.0 at 0: ";
    list.insert(2.0, 0);
    list.print();
    cout << "Insert 5.0 at 4: ";
    list.insert(5.0, 4);
    list.print();
    cout << "Insert 1.0 at 70: ";
    list.insert(1.0, 70);
    list.print();
}
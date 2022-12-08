/* LinkedList.h - Linked list class
 * Author:     Ben Foltz
 * Module:     14
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {

    private:
        struct ListNode {
            double value;
            ListNode *next; //pointer to next node

            ListNode(double value1, ListNode *next1 = nullptr) { // Constructor
                value = value1;
                next = next1;
            }
        };
        ListNode *head;     //List head node

    public:

        // Prototypes of functions already present
        LinkedList();                           // constructor

        void add(double x);                     // add an element to the front list
        bool isMember(double x) const;          // check if value is in linked list
        void print();                           // print contents of linked list
        void reverse();                         // reverse contents of linked list
        int search(double x);                   // find the index of a value in linked list
        void insert(double x, int pos);         // insert value at certain position in linked list
} ;

#endif //LINKEDLIST_H

/* SetLinkedList.h - Emulates a set in C++
 * Author:     Ben Foltz
 * Module:     15
 * Project:    Lab
 * Problem statement:  Use a linked list to create a class template which
 *      performs the following set functions:
 *
 *    constructor - creates an empty set
 *    contains - returns true if an item is in the set (uses = operator)
 *    insert - adds an item (in sorted order) to the set (duplicates not allowed)
 *    display - shows the contents of the set on the screen
 *    toVector - returns a vector with the elements contained in the set
 *    setUnion - returns another set containing all items from two sets
 *    setIntersect - returns another set containing items only in both sets
 *
 *  Functions to be added in this lab:
 *      setMinus - returns another set containing all elements in calling set that
 *                 aren't in the parameter set
 *      equals - returns true if both sets contain the same elements
 *      clear - empties the contents of a set
 *
 */

#ifndef SET_LINKEDLIST_H
#define SET_LINKEDLIST_H

#include <vector>
#include <iostream>

using namespace std ;

// Node for each element in the set
template<typename T>
struct SetNode {

    T data ;
    SetNode *next ;

    SetNode(T new_data, SetNode *link) {     // full constructor
        data = new_data ;
        next = link ;
    }
} ;

template<class T>
class Set {

    private:
        SetNode<T> *head ;

    public:
        Set() ;                                // no-arg constructor
        bool contains(T search_item) const ;
        bool insert(T new_item) ;
        Set<T> setIntersect(Set<T> other_set) const ;
        Set<T> setUnion(Set<T> other_set) const ;
        void display() const ;
        vector<T> * toVector() const ;
        Set<T> minus(Set<T> other_set);
        bool equals(Set<T> other_set);
        void clear();
} ;

// No-argument constructor creates an empty set (linked list)
template<class T>
Set<T>::Set() {
    head = nullptr ;
}

// Returns true if the set contains a specified data element
template<typename T>
bool Set<T>::contains(T search_item) const {
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        if (ptr->data == search_item) {
            return true ;
        }
        ptr = ptr->next ;
    }
    return false ;
}

// Add a data element to a sorted list.
template<typename T>
bool Set<T>::insert(T new_item) {

    if (contains(new_item))
        return false ;                    // already in the list

    // Add to front of the list of if the list is empty or comes before first item.
    if (head == nullptr || (head->data > new_item)) {
        head = new SetNode<T>(new_item, head) ;
        return true ;                    // item was added
    }

    // Find the position to insert.  Keep pointers before and after insertion point.
    SetNode<T> *after = head ;               // will come after the new node
    SetNode<T> *before = nullptr ;           // node prior to the insertion point
    while (after != nullptr && after->data <= new_item) {
        before = after ;
        after = after->next ;
    }
    before->next = new SetNode<T>(new_item, after) ;
    return true ;
}

// Create a third set which is the intersection of two other sets.
// Intersection will contain only those elements in both sets.
template<typename T>
Set<T> Set<T>::setIntersect(Set<T> other_set) const {

    Set<T> common_set ;     // New set to return
    SetNode<T> *pos = head ;
    while (pos != nullptr) {
        if (other_set.contains(pos->data))
            common_set.insert(pos->data) ;
        pos = pos->next ;
    }
    return common_set ;
}

// Return the union of this set with another set.
template<typename T>
Set<T> Set<T>::setUnion(Set<T> other_set) const {

    Set<T> union_set ;     // new set to be returned

    // Add contents of calling object set to the new set
    SetNode<T> *pos = head ;
    while (pos != nullptr) {
        union_set.insert(pos->data) ;
        pos = pos->next ;
    }

    // Add the elements of the "other_set", avoid duplicates.
    pos = other_set.head ;
    while (pos != nullptr) {
        union_set.insert(pos->data) ;
        pos = pos->next ;
    }
    return union_set ;
}

// Display the contents of this set on the console.
template<typename T>
void Set<T>::display() const {
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        cout << ptr->data << " " ;
        ptr = ptr->next ;
    }
    cout << endl ;
}

// Return the contents of this set in a vector.
template<typename T>
vector<T> * Set<T>::toVector() const {
    vector<T> *items = new vector<T>() ;
    SetNode<T> *ptr = head ;
    while (ptr != nullptr) {
        items->push_back(ptr->data) ;
        ptr = ptr->next ;
    }
    return items ;
}

// Subtract one set from another set
template<typename T>
Set<T> Set<T>::minus(Set<T> other_set) {
    // Create a new set
    Set<T> newSet;
    // Create a pointer to traverse the set
    SetNode<T> *aptr = head;
    // Loop through set
    while (aptr != nullptr) {
        // Check if other_set has the value of data at the pointer
        if (!other_set.contains(aptr->data)) {
            // Insert data into newSet
            newSet.insert(aptr->data);
        }
        // Increment pointer
        aptr = aptr->next;
    }

    return newSet;
}
// Checks if one set is equal to another set
template<typename  T>
bool Set<T>::equals(Set<T> other_set) {
    // Create a pointer to traverse the set
    SetNode<T> *aptr = head;
    // Loop through set
    while (aptr != nullptr) {
        // Check if other_set has the value of data at the pointer
        if (!other_set.contains(aptr->data)) {
            return false;
        }
        // Increment pointer
        aptr = aptr->next;
    }
    return true;
}

// Clears the data in the set
template<typename  T>
void Set<T>::clear() {
    // Create pointer for current node
    SetNode<T> *current = head;
    // Create pointer for next node
    SetNode<T> *next;
    // Loop through set
    while (current != nullptr) {
        // Increment next
        next = current->next;
        // Delete current
        delete current;
        // Set current to next
        current = next;
    }
    // Set head to nullptr
    head = nullptr;
}

#endif

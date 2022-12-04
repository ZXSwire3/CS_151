/* SimpleVector.h - Simple Vector with added functionality
 * Author:     Ben Foltz
 * Module:     13
 * Project:    Homework #2
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
using namespace std ;

template <class T>
class SimpleVector {

    protected:
        T *aptr ;
        int position = 0 ;
        int size = 0 ;                        // number of elements in vector
        int capacity = 0 ;                    // size of underlying array

    public:
        SimpleVector(int = 0) ;               // Constructor
        SimpleVector(const SimpleVector &) ;  // Copy constructor
        ~SimpleVector() ;                     // Destructor

        class ArrayFull {};
        class ArrayEmpty {};

        int getCapacity()
            { return capacity ; }
        int getSize()
            { return size ; }
        void push_back(T);
        void pop_back();
        void print();
} ;

//*************************************************************
//         Constructor for EnhancedSimpleVector class         *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int new_capacity) {

    size = 0 ;
    capacity = new_capacity ;
    aptr = new T [capacity] ;

    // Empty the contents of the array
    for (int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = T() ;
    }
}

//**************************************************
//     Copy Constructor for SimpleVector class     *
//**************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    capacity = obj.capacity ;
    aptr = new T [capacity] ;
    for(int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = *(obj.aptr + count) ;
    }
}

//***********************************************
//     Destructor for SimpleVector class        *
//***********************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (capacity > 0) {
        delete [] aptr ;
    }
}

template<class T>
void SimpleVector<T>::push_back(T value) {
    if (size == capacity) {
        throw ArrayFull();
    } else {
        aptr[position++] = value;
        size++;
    }
}

template<class T>
void SimpleVector<T>::pop_back() {
    if (size == 0) {
        throw ArrayEmpty();
    } else {
        position--;
        size--;
    }
}

template<class T>
void SimpleVector<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout << aptr[i] << " ";
    }
    cout << endl;
}

#endif


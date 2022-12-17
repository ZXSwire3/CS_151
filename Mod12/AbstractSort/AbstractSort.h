//Author: Ben Foltz
#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H
#include <iostream>
using namespace std;

class AbstractSort {
    protected:
        int compares;	// Number of comparisons
    public:
        // Constructor
        AbstractSort() {
            compares = 0;
        }
        // pure virtual member function.
        virtual void sort(int arr[], int size) = 0;


        int compare(const int arr[], int k, int m) {
            compares++;

            if (arr[k] > arr[m]) {
                return -1;
            } else if (arr[k] == arr[m]) {
                return 0;
            } else if (arr[k] < arr[m]) {
                return 1;
            }
        }
        int getCompares() const {
            return compares;
        }
};

#endif  //ABSTRACTSORT_H
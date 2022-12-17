//Author: Ben Foltz
#ifndef SUBABSTRACTSORT_H
#define SUBABSTRACTSORT_H
#include <iostream>
#include "AbstractSort.h"
using namespace std;

class SubAbstractSort : public AbstractSort {
    public:
        // Constructor
        SubAbstractSort() {}

        // Overridden virtual function
        void sort(int arr[], int size) override {
            //Temp variable
            int temp;

            //sort array in ascending order with selection sort
            for (int i = 0; i < size - 1; i++) {
                for (int j = i + 1; j < size; j++) {
                    // Call to update comparisons
                    compare(arr, arr[i], arr[j]);
                    // can't figure out why comparison function doesn't result in function being properly sorted
                    if (arr[i] > arr[j]) {
                        //swapping with smallest element of array.
                        temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
        }
};
#endif  //SUBABSTRACTSORT_H
/* AbstractSortTest - Creates two arrays and sorts them using SubAbstractSort
 * Author: Ben Foltz
 * Module: 12
 * Project: Homework 12, project 1
 *
 * Problem Statement: Creates two arrays and sorts them using SubAbstractSort
 *
 * Algorithm:
 *   1. Create two arrays of ints
 *   2. Print out elements in first array
 *   3. Create SubAbstractSort object
 *   4. sort first array using sort function
 *   5. Print out elements in first array
 *   6. Print out comparisons or first sort call
 *   7. Print out elements in second array
 *   8. Initialize SubAbstractSort object again
 *   9. Print out elements in first array
 *  10. sort second array using sort function
 *  11. Print out comparisons of second sort call
 */
#include <iostream>
#include "AbstractSort.h"
#include "SubAbstractSort.h"
using namespace std;

int main()
{

    // Create array
    int arrayOne[] = {1,7,5,3,2};

    // Print out array before sorting
    cout << "Array before sort: ";
    for (int i : arrayOne) {
        cout << i << " ";
    }
    cout << endl;

    // Create SubAbstractSort
    SubAbstractSort sort;
    // sort array
    sort.sort(arrayOne,5);

    // Print out array after sorting
    cout << "Array after sort: ";
    for (int i : arrayOne) {
        cout << i << " ";
    }
    cout << endl;

    //Print out number of comparisons
    cout << "\nNumber of comparisons: " << sort.getCompares() << endl << endl;

    // Create array
    int arrayTwo[] = {0, 5, 3};

    // Print out array before sorting
    cout << "Array before sort: ";
    for (int i : arrayTwo) {
        cout << i << " ";
    }
    cout << endl;

    // Initialize SubAbstractSort again
    sort = SubAbstractSort();
    sort.sort(arrayTwo, 3);

    // Print out array after sorting
    cout << "Array after sort: ";
    for (int i : arrayTwo) {
        cout << i << " ";
    }
    cout << endl;

    //Print out number of comparisons
    cout << "\nNumber of comparisons: " << sort.getCompares() << endl;
    return 0;
}
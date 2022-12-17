/* AbstractSeq.h
 * Author: Ben Foltz
 */
#ifndef ABSTRACTSEQ_H
#define ABSTRACTSEQ_H

#include <iostream>
#include <iomanip>
using namespace std;

class AbstractSeq {
    public:
        // pure virtual member function.
        virtual int fun(int k) = 0;

    void printSeq(int k, int m);
    int sumSeq(int k, int m);
};

void AbstractSeq::printSeq(int k, int m) {
    if (k < m) {
        // Print out heading
        cout << right << setw(7) << "n" << setw(3) << "" << "fun(n)" << endl;
        cout << "------------------" << endl;
        for (int i = k; i <= m; ++i) {
            // Print out iteration number and the result of fun(i)
            cout << right << setw(7) << i << right << setw(9) << fun(i) << endl;
        }
        cout << endl;
    }
}

int AbstractSeq::sumSeq(int k, int m) {
    int sum = 0;
    // Check if k is smaller than m
    if (k < m) {
        // Loop from k to m
        for (int i = k; i <= m; ++i) {
            sum+= fun(i);
        }
    }
    return sum;
}
#endif //ABSTRACTSEQ_H

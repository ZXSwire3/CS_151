/* SubSequence.h
 * Author: Ben Foltz
 */
#ifndef CS_151_SUBSEQUENCE_H
#define CS_151_SUBSEQUENCE_H

#include <iostream>
#include "AbstractSeq.h"
using namespace std;

class Odds:public AbstractSeq {
    int fun(int k) override {
        return 2 * k + 1;
    }
};

class Factorial:public AbstractSeq {
    int fun(int k) override {
        int factorial = 1;
        for(int i = 1; i <= k; ++i) {
            factorial *= i;
        }
        return factorial;
    }
};

#endif //SUBSEQUENCE_H

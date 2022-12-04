//ArithmeticException.cpp
//Author: Ben Foltz
#include <iostream>
#include <cmath>

using namespace std;

int squareRoot(int);

class ImperfectSquare {};

int main() {
    //Result of square root
    int result;

    //Loop from 0 to 25
    for (int i = 0; i <= 25; ++i) {
        //Try catch to see if function throws an error
        try {
            //Put return value from function into result
            result = squareRoot(i);
            //Print out results
            cout << "The square root of " << i << " is " << result << endl;
        } catch (ImperfectSquare) {
            //Print out error
            cout << ("Error: Number is not a perfect square.") << endl;
        }
    }
}

int squareRoot(int n) {
    //Check if number is a perfect square
    if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
        //return square of input number
        return sqrt(n);
    } else {
        //throw exception
        throw ImperfectSquare();
    }
}
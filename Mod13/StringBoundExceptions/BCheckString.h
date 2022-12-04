#ifndef BCHECKSTRING_H
#define BCHECKSTRING_H

#include <iostream>
#include <iomanip>

using namespace std;

class BCheckString:public string {
    private:
        string str;
    public:

        BCheckString(string s) {
            str = s;
        }

        //Out of bounds class exception
        class BoundsException {};

        char operator [] (int k) {
                if (k < 0 || k >= str.length()) {
                    throw BoundsException();
                }
                return str[k];
            }
};

#endif //BCHECKSTRING_H

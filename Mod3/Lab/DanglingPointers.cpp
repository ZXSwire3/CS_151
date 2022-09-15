#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-stack-address"
#include <iostream>

using namespace std;

void first(int *ptr_to_intptr) {
    int a = 5;              //allocate space for 'a'
    ptr_to_intptr = &a;     //dangerous -- 'a' is deallocated
}

void second(int *&dummy) {
    int b = 99;             //overlays original memory for 'a'
    dummy = &b;             //follow first's code
}

int * third() {
    int x = 29;
    cout << "In third(), the value of x is " << x << endl;
    return &x;              //Can produce a compiler warning
}
int * fourth() {
    int y;                  //Don't Initialize this variable
    cout << "In fourth(), the value of y is " << y << endl;
    return &y;
}

int main() {
    int *intptr, *never_used; //pointers to ints

    //Call first() passing address of intptr. Upon return
    //intptr will point to de-allocated memory (dangling)!

    first(intptr);
    cout << "Part 1:" << endl
         << "   Return from first(), *intptr is "
         << *intptr << endl;

    //Call second() with a dummy parameter that is never used.
    //intptr is still dangling, as its contents are updated,
    //though it is never accessed directly by this function.
    second(never_used);
    cout << "   Return from second(), *intptr is "
         << *intptr << endl << endl;

    //Call third(), return pointer to a local variable from function
    intptr = third();
    cout << "Part 2:" << endl
         << "   Returned address " << *intptr << " from third()" << endl
         << "   Value in that address is " << *intptr << endl;

    //Call fourth() and see if the value of a local variable can
    //be set outside the function.
    cout << "   Setting memory at " << intptr << " to 109" << endl;
    *intptr = 109;
    fourth();

    return 0;
}
#pragma clang diagnostic pop
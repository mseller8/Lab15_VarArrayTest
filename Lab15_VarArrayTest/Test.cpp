// testing the implementation of class varArray
// Mikhail Nesterenko
// 4/01/2013

#include <iostream>
#include "vararray.hpp"

using std::cout; using std::endl;


void testfunc(varArray); // function to test pass-by-value for varArray

int main() {

    varArray a1;

    // testing regular member functions
    a1.addNumber(1.);
    a1.addNumber(2.);
    a1.addNumber(3.);
    a1.addNumber(3.); // trying to add duplicate, should not add it

    cout << "a1 size is after number addition is: " << a1.arraySize() << endl;

    if (a1.check(1.) != -1) // check() returns -1 if number not present
        cout << "1 is present in the array" << endl;

    if (a1.check(5.) != -1)
        cout << "5 is present in the array" << endl;

    cout << "a1 before removal of 2.0: "; a1.output();
    a1.removeNumber(2.);
    cout << "a1 after removal of 2.0: "; a1.output();

    // uncomment this when you debugged the first part
    /*
    testfunc(a1); // testing copy constructor

    cout << "a1 after testfunc call: ";
    a1.output(); // if destructor is implemented correctly
                 // this should print properly after testfunc completes

    varArray a2, a3;

    a3=a2=a1; // testing stackability of the overloaded assignment
    cout << "a3 after stackable assingment: ";
    a3.output();

    a3=a3; // testing protection against self-assingment
    cout << "a3 after self-assignment: ";
    a3.output();
    */
}


/*
// tests pass-by-value for object of class varArray
void testfunc(varArray va){ // copy constructor is invoked on "va"
    cout << "parameter va: ";
    va.output();
} // destructor is invoked when "va" goes out of scope
*/
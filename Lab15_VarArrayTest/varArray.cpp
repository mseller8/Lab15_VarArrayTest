#include "varArray.h"
#include <iostream>
using namespace std;

void output(double* arrayPtr, int size)
{
    for (int i = 0; i < size; i++) {
        cout << arrayPtr[i] << " ";
    }
    cout << endl;
}

int check(double* arrayPtr, double number, int size)
{
    for (int i = 0; i < size; i++) {
        if (arrayPtr[i] == number) {
            return i;
        }
    }
    return -1;
}

void addNumber(double*& arrayPtr, double number, int& size)
{
    int index = check(arrayPtr, number, size);
    if (index == -1) {
        double* arrayPtr2 = new double[++size];
        for (int i = 0; i < size; i++) {
            arrayPtr2[i] = arrayPtr[i];
        }
        *(arrayPtr2 + size - 1) = number;
        delete[] arrayPtr;
        arrayPtr = arrayPtr2;
    }
}

void removeNumber(double*& arrayPtr, double number, int& size)
{
    int index = check(arrayPtr, number, size);
    if (index >= 0 && index < size) {
        double* arrayPtr2 = new double[--size];
        //create a boolean variable "found", set it to to false
        bool found = false;
        //iterate over elements in the old array,
        for (int i = 0; i < size; i++) {
            // if old array element equals to the number to be removed then
            if ((arrayPtr[i]) == number) {
                //     set found to true
                found = true;
            }
            // if not found then
            if (!found) {
                // copy old array element to the new array element
                arrayPtr2[i] = arrayPtr[i];
            }
            // else // found 
            else {
                // copy old array element to the new array
                // element with index one less than old array's 
                // (move them to the left)
                arrayPtr2[i] = arrayPtr[i + 1];
            }
        }
        delete[] arrayPtr;
        arrayPtr = arrayPtr2;
    }
}

varArray::varArray()
{
    array_ = new double [0];
    size_ = 0;
}

int varArray::check(double number)
{
    for (int i = 0; i < size_; i++) {
        if (array_[i] == number) {
            return i;
        }
    }
    return -1;
}

void varArray::addNumber(double number)
{
    int index = check(number);
    if (index == -1) {
        double* array_2 = new double[++size_];
        for (int i = 0; i < size_; i++) {
            array_2[i] = array_[i];
        }
        *(array_2 + size_ - 1) = number;
        delete[] array_;
        array_ = array_2;
    }
}

void varArray::removeNumber(double number)
{
    int index = check(number);
    if (index >= 0 && index < size_) {
        double* array_2 = new double[--size_];
        //create a boolean variable "found", set it to to false
        bool found = false;
        //iterate over elements in the old array,
        for (int i = 0; i < size_; i++) {
            // if old array element equals to the number to be removed then
            if ((array_[i]) == number) {
                //     set found to true
                found = true;
            }
            // if not found then
            if (!found) {
                // copy old array element to the new array element
                array_2[i] = array_[i];
            }
            // else // found 
            else {
                // copy old array element to the new array
                // element with index one less than old array's 
                // (move them to the left)
                array_2[i] = array_[i + 1];
            }
        }
        delete[] array_;
        array_ = array_2;
    }
}

void varArray::output()
{
    for (int i = 0; i < size_; i++) {
        cout << array_[i] << " ";
    }
    cout << endl;
}

varArray::varArray(const varArray& arg)
{
    size_ = arg.size_;
    array_ = new double[size_];
    for (int i = 0; i < size_; i++) {
        array_[i] = arg.array_[i];
    }
}

varArray& varArray::operator=(const varArray& arg)
{
    // TODO: insert return statement here
}

varArray::~varArray()
{
    delete[] array_;
}

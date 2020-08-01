// variable size array class
// Mikhail Nesterenko
// 11/07/2019


#ifndef VARARRAY_HPP_
#define VARARRAY_HPP_

class varArray {
public:
	varArray(); // void constructor
	int arraySize() const { return size_; } // returns the size of the array

	int check(double number); // returns index of element containg "number" or -1 if none
	void addNumber(double);    // adds number to the array
	void removeNumber(double); // deletes the number from the array
	void output();      // prints the values of the array

	// big three
	varArray(const varArray&); // copy constructor
	varArray& operator=(const varArray&); // overloaded assignment
	~varArray(); // destructor

private:
	double* array_; // pointer to the dynamically allocated array
	int size_;   // array size
};

#endif /* VARARRAY_HPP_ */


#include <iostream>
#include "varArray.h"

using std::cout; using std::cin; using std::endl;



int main() {
	varArray arr;
	int size = 0;  // setting array size
	double* a = new double[size]; // allocating dynamic array
	double choiceNum;
	char choice;
	while (true) {
		cout << "enter operation[a / r / q] and number:\n";
		cin >> choice >> choiceNum;
		if (choice == 'a') {
			arr.addNumber(choiceNum);
			cout << "Your numbers: ";
			arr.output();
		}
		else if (choice == 'r') {
			arr.removeNumber(choiceNum);
			cout << "Your numbers: ";
			arr.output();
		}
		else
			break;
	}
	//enter operation[a / r / q] and number: a 5.0
	//your numbers : 5
	//enter operation[a / r / q] and number : a 8.0
	//your numbers : 5 8
	//enter operation[a / r / q] and number : a 8.0
	//your numbers : 5 8
	//enter operation[a / r / q] and number : r 8.0
	//your numbers : 5
	//enter operation[a / r / q] and number : a 3.3
	//your numbers : 5 3
	//enter operation[a / r / q] and number : a 12.2
	//your numbers : 5 3.3 12.2
	//enter operation[a / r / q] and number : q
}
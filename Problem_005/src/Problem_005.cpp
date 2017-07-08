// I solved this with pen and paper.
// You have to find the prime factorisation of the numbers
// in the range of interest (e.g. 1-10, or 1-20, etc.).
// Then, for each prime number in the range, choose the largest
// power in any one of the prime factorisations. Multiply
// these together and that is the smallest number evenly divisible
// by the numbers in the range

// See here for more info about algorith for finding the prime
// factorisation of a number (also useful for problem 3)
// http://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/


#include <iostream>
using namespace std;

int main() {
	cout << "Project Euler | Problem 5\n" << endl;

	const int MAX = 10;

	int product = 1;

	// smallest number is at least as big as all of the prime
	// numbers under MAX multiplied together... start counting
	// from here
	int must_be_as_big_as = 2*3*5*7*9;

	while(true) {

	}


	//
	cout << 8*5*7*9 << endl;

	double number = 20*19*17*13*11*9*8*7*5;
	// trial and error
	cout << number << endl;

	// brute force algorithm
	for(int i=1; i <= MAX; i++ ) {
		//cout << 1260/(double)i << endl;
	}

	//cout << 7560 / 2520 << endl;

	cout << product << endl;

	return 0;
}

//============================================================================
// Name        : Problem_002.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int NextFib(int previous_fib, int current_fib) {
	return previous_fib + current_fib;
}

int main() {
	cout << "Project Euler | Problem 2\n" << endl;

	const int MAX_NUM = 4000000;

	// Problem says to start sequence with 1 and 2
	int previous_fib = 1;
	int current_fib = 2;
	int next_fib = 0;

	int total = 2; // first even number is 2, which won't get seen in the for loop

	// Is is the right sequence?
//	cout << "Fibonacci Numbers below " << MAX_NUM << endl;
//
//	cout << previous_fib << endl;
//	cout << current_fib << endl;
//
//	for(int i = 2; i < MAX_NUM; i++) {
//		next_fib = NextFib(previous_fib, current_fib);
//		previous_fib = current_fib;
//		current_fib = next_fib;
//
//		cout << current_fib << endl;
//	}

	while(current_fib < MAX_NUM) {
		next_fib = NextFib(previous_fib, current_fib);
		previous_fib = current_fib;
		current_fib = next_fib;

		if((current_fib % 2) == 0) {
			total += current_fib;
		}
	}

	cout << "The sum of the even Fibonacci Numbers not exceeding " << MAX_NUM << " is: " << total << endl;
	cin;

	return 0;
}

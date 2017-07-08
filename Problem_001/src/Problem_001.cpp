//============================================================================
// Name        : Problem_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool IsDivisibleByThree(int number) {
	return (number % 3) == 0;
}

bool IsDivisibleByFive(int number) {
	return (number % 5) == 0;
}

int main() {
	cout << "Project Euler | Problem 1\n" << endl;

	const int NUM_MAX = 1000;

	int total = 0;

	for(int i = 0; i < NUM_MAX; i++) {
		if(IsDivisibleByThree(i) || IsDivisibleByFive(i)) {
			total += i;
		}
	}

	cout << "The sum of all number below " << NUM_MAX << " divisible by 3 and 5 is: " << total << endl;

	cin;

	return 0;
}


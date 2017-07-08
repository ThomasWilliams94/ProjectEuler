#include <iostream>
using namespace std;

// N should be a positive integer.
// Returns -1 if N <= 0. Otherwise, returns the number
// of divisors of N.
int findNumberOfDivisors(int N) {

	if(N <= 0) {
		return -1;
	}

	int num_divisors = 0;

	for(int i = 1; i <= N; ++i) {
		if(N % i == 0) {
			++num_divisors;
		}
	}

	return num_divisors;
}

int main() {
	cout << "Project Euler | Problem 12\n" << endl;

	const int NUM_DIVS = 500;
	int i = 1;
	long long int tri_num = 0;
	bool found = false;

	while(!found) {
		tri_num += i++;
		cout << i - 1 << " : " << tri_num << endl;
		if(findNumberOfDivisors(4978173871) > NUM_DIVS) {
			found = true;
		}
	}

	cout << "First triangle number with more than " << NUM_DIVS <<
			" divisors is: " << tri_num << endl;

	return 0;
}

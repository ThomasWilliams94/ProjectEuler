#include <iostream>
#include <map>
using namespace std;

// Returns -1 if n <= 1, else returns the sum of the
// proper divisors of n
int d_of_n(int n) {
	// for debugging
	cout << "Finding d_of_n for n = " << n << endl;
	if (n <= 1) {
		cout << "n must be greater than 1!\n=======\n" << endl;
		return -1;
	}

	long int sum = 1; // 1 is a divisor of all positive integers <= n, for n >= 2

	cout << "Proper divisors: 1, ";

	for (int i = 2; i < n; i++) {
		if (!(((float) n / i) - n / i > 0)) {
			cout << i << ", ";
			sum += i;
		}
	}

	cout << endl;

	cout << "d(" << n << ") = " << sum << endl;
	cout << "=======" << endl;
	return sum;
}


int main() {
	cout << "Project Euler | Problem 21\n" << endl;

	d_of_n(0);
	d_of_n(1);
	d_of_n(2);
	d_of_n(6);
	d_of_n(220);

	return 0;
}

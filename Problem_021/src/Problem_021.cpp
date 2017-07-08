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

bool is_amicable(int a) {
	int d_of_a = d_of_n(a);
	int d_of_b = d_of_n(d_of_a);
//	cout << "########" << endl;
//	cout << "d(a) with a=" << a << " is " << d_of_a << endl;
//	cout << "d(b) with b=" << d_of_a << " is " << d_of_b << endl;
//	cout << (a != d_of_a ? "true" : "false") << endl;
//	cout << "########" << endl;
	if( (a != d_of_a) && a == d_of_b ) {
		return true;
	} else {
		return false;
	}
}

int main() {
	cout << "Project Euler | Problem 21\n" << endl;

	d_of_n(0);
	d_of_n(1);
	d_of_n(2);
	d_of_n(6);
	d_of_n(220);

	cout << "Testing 1." << endl;
	d_of_n(d_of_n(220));

	cout << "Testing 2. Is amicable?" << endl;
	cout << (is_amicable(220) ? "true" : "false") << endl;
	cout << (is_amicable(284) ? "true" : "false") << endl;

	return 0;
}

#include <iostream>
#include <map>
using namespace std;

// Returns -1 if n <= 1, else returns the sum of the
// proper divisors of n
// set debug = true for helpful comments when debugging.
int d_of_n(int n, bool debug) {
	// for debugging
	if (debug)
		cout << "Finding d_of_n for n = " << n << endl;

	if (n <= 1) {
		cout << "n must be greater than 1!\n=======\n" << endl;
		return -1;
	}

	long int sum = 1; // 1 is a divisor of all positive integers <= n, for n >= 2

	if (debug)
		cout << "Proper divisors: 1 ";

	for (int i = 2; i < n; i++) {
		if (!(((float) n / i) - n / i > 0)) {
			if (debug)
				cout << ", " << i;
			sum += i;
		}
	}
	if (debug) {
		cout << endl;
		cout << "d(" << n << ") = " << sum << endl;
		cout << "=======" << endl;
	}

	return sum;
}

// Returns true if a is an amicable number, false otherwise.
// set debug = true for helpful comments when debugging.
bool is_amicable(int a, bool debug) {
	int d_of_a = d_of_n(a, debug);
	int d_of_b = d_of_n(d_of_a, debug);
	if (debug) {
		cout << "########" << endl;
		cout << "d(a) with a=" << a << " is " << d_of_a << endl;
		cout << "d(b) with b=" << d_of_a << " is " << d_of_b << endl;
		cout << "a not equal to b? : " << (a != d_of_a ? "true" : "false")
				<< endl;
		cout << "a = d(b) ==> " << a << " = " << d_of_b << " ? : "
				<< (a == d_of_b ? "true" : "false") << endl;
		cout << "########" << endl;
	}
	if ((a != d_of_a) && a == d_of_b) {
		return true;
	} else {
		return false;
	}
}

int main() {
	cout << "Project Euler | Problem 21\n" << endl;

	//*****************//
	//try __N__ for a small number that you can work out yourself manually.
//	int n = 220; // prime numbers, of course, only have d(n) = 1 which is why the n must be greater than 1! message keeps popping up.
//	d_of_n(n, 1);
//	d_of_n(d_of_n(n, 0), 1);
//	cout << (is_amicable(n, 1) ? "true" : "false") << endl;

	const int __N__ = 8000;
	long long int sum = 0; // sum of amicable numbers under 10000
	int count = 0;
	string nums = ""; // output the amicable numbers here.
	for (int i = 2; i < __N__; i++) {
		cout << "\nLooping for i = " <<  i << endl;
		if (is_amicable(i, 1)) {
			cout << "AMICABLE" << endl;
			count++;
			int d_i = d_of_n(i, 1);
			sum += d_i;

		}
	}
	cout << nums << endl;
	cout << count << endl;
	cout << "The sum of amicable numbers under " << __N__ << " is: " << sum
			<< endl;

	return 0;
}

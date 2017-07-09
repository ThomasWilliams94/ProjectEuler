// Returns -1 if n <= 1, else returns the sum of the
// proper divisors of n
// set debug = true for helpful comments when debugging.
int sum_of_proper_divisors(int n, bool debug = false) {
	// for debugging
	if (debug)
		cout << "Finding d_of_n for n = " << n << endl;

	if (n <= 1) {
		cout << "n must be greater than 1!\n=======\n" << endl;
		return -1;
	}

	long int sum = 1; // 1 is a divisor of all positive integers <= n, for n >= 2

	if (debug)
		cout << "Proper divisors: 1";

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
#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}

	if (n <= 3) {
		return true;
	}

	if ((n % 2 == 0) || (n % 3 == 0)) {
		return false;
	}

	int i = 5;

	while (i * i <= n) {
		if ((n % i == 0) || (n % (i + 2) == 0)) {
			return false;
		}
		i += 6;
	}

	return true;
}

int main() {
	cout << "Project Euler | Problem 10\n" << endl;

	const int SUM_BELOW = 2E6;
	long long int counter = 0;
	long long int sum = 0;

	cout << SUM_BELOW << endl;
	while(counter < SUM_BELOW) {
		if(isPrime(counter)) {
			sum+=counter;
		}

		++counter;
	}

	cout << sum << endl;

	return 0;
}

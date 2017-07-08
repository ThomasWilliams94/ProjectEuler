#include <iostream>
#include <map>
#include <string>
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

// N should be a positive integer.
// Returns -1 if N <= 0. Otherwise, returns the number
// of divisors of N.
int findNumberOfDivisors(int N) {

	if (N <= 0) {
		return -1;
	}

	if (N == 1) {
		cout << "N is 1" << endl << endl;
		return 1;
	}

	if (isPrime(N)) {
		cout << "N is prime: " << N << endl << endl;
		return 2;
	}

	cout << "N is: " << N << ". We find the number of divisors." << endl;
	// http://www.wikihow.com/Determine-the-Number-of-Divisors-of-an-Integer

	map<int, int> primes_and_exponents;

	int i = 2; // all numbers divisible by 1, so start with 2
	int n = N;
	int num_divisors = 0;

	while (i < N && n > 1) {
		//cout << "i is: " << i << " | N is: " << N << endl;
		//cout << "is " << i << " prime? ";
		if (isPrime(i)) {
			//cout << "i is prime " << endl;
			primes_and_exponents[i] = 0;
			while (n % i == 0) {
				++primes_and_exponents[i];
				n /= i;
				//cout << "Dividing n by i: " << n << endl;
			}
		} else {
			//cout << "i is not prime" << endl;
		}
		++i;
	}

	num_divisors = 1; // need to start with 1 for multiplying
	string mult_string = "";
	for (map<int, int>::iterator it = primes_and_exponents.begin();
			it != primes_and_exponents.end(); ++it) {
		num_divisors *= ((it->second) + 1);
		cout << it->first << " => " << it->second << endl;
	}
	cout << "Number of divisors: " << num_divisors << endl;
	cout << mult_string << endl;
//
//	for(int i = 1; i <= N; ++i) {
//		if(N % i == 0) {
//			++num_divisors;
//		}
//	}

	return num_divisors;
}

int main() {
	cout << "Project Euler | Problem 12\n" << endl;

	const int NUM_DIVS = 500;
	int i = 1;
	long long int tri_num = 0;
	bool found = false;

	while (!found) {
		tri_num += i++;
		//cout << i - 1 << " : " << tri_num << endl;
		if (findNumberOfDivisors(tri_num) > NUM_DIVS) {
			found = true;
		}
	}

//	cout << "About to start..." << endl;
//	findNumberOfDivisors(1);
//	findNumberOfDivisors(2);
//	findNumberOfDivisors(5);
//	findNumberOfDivisors(24);
//	findNumberOfDivisors(100);
//	cout << "Finished." << endl;

	cout << "First triangle number with more than " << NUM_DIVS
			<< " divisors is: " << tri_num << endl;

	return 0;
}

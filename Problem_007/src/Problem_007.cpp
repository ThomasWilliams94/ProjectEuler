#include <iostream>
using namespace std;

bool isPrime(int n) {
	if(n<=1) {
		return false;
	}

	if(n<=3) {
		return true;
	}

	if( (n%2 == 0) || (n%3 == 0) ) {
		return false;
	}

	int i = 5;

	while(i*i <= n) {
		if( (n%i == 0) || (n%(i+2) == 0) ) {
			return false;
		}
		i += 6;
	}

	return true;
}

int main() {
	cout << "Project Euler | Problem 7\n" << endl;

	int counter = 0;
	int current_prime = 0;
	int i = 0;

	while(counter < 10001 ) {
		if(isPrime(i)) {
			current_prime = i;
			++counter;
		}
		++i;
	}

	cout << "Prime number " << counter << " is " << current_prime << endl;
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	cout << "Project Euler | Problem X\n" << endl;

	const int MAX = 100;

	int sum = 0;
	int sum_of_squares = 0;

	for(int i=0; i<=MAX; i++) {
		sum += i;
		sum_of_squares += i*i;
	}

	int square_of_sum = sum*sum;

	int difference = square_of_sum - sum_of_squares;

	cout << difference << endl;

	return 0;
}

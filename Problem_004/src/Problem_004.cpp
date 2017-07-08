#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isPalindrome(int n) {
	// Change number to a string
	string number = to_string(n); //C++11 function.
	string number_reverse = number;

	reverse(number_reverse.begin(), number_reverse.end());

	char num[number.size() + 1];
	strcpy(num, number.c_str());

	char num_reverse[number.size() + 1];
	strcpy(num_reverse, number_reverse.c_str());

	if (strcmp(num, num_reverse) == 0) {
		return true;
	}

	return false;
}

int main() {
	cout << "Project Euler | Problem 4\n" << endl;

	int const MAX = 1000;
	int current_largest_palindrome = 0;

	for(int i=0; i < MAX; i++) {
		for(int j=0; j < MAX; j++) {
			int product = i*j;
			//cout << "i: " << i << " | j: " << j << " | product: " << product << endl;
			if(isPalindrome(product) && product > current_largest_palindrome) {
				current_largest_palindrome = product;
			}
		}
	}

	cout << "Largest palindrome from a product of two\n numbers below " << MAX << " is: "
			<< current_largest_palindrome << endl;

	return 0;
}

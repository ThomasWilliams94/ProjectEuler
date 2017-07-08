// ACCIDENTALLY OVERWROTE THIS WITH PROBLEM FOUR...

// I DID SOLVE PROBLEM THREE AND IF I CAN BE BOTEHRED I
// WILL REDO IT ... woops.... Version Control would've been good.

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

bool IsPalindrome(int n) {
	// Change number to a string
	string number = to_string(n);
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

	int const MAX = 999;
	int n1 = MAX;
	int n2 = MAX;
	int product = 0;
	bool found = false;

	while (!found) {
		while (n2 > 0) {
			product = n1 * n2;
			if (IsPalindrome(product)) {
				cout << "Palindrome found! " << product << endl;
				found = true;
				break;
			}
			--n2;
		}

		if (--n1 < 0) {
			break;
		}
		n2 = MAX;
	}

	if (!found) {
		cout << "No palindrome found...." << endl;
	}

	return 0;
}

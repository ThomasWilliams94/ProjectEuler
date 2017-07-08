#include <iostream>
using namespace std;

int main() {
	cout << "Project Euler | Problem 9\n" << endl;

	// Trying a brute attack force LOL

	int A, B, C = 0;

	bool found = false;

	for (int a = 0; a < 1000; ++a) {

		for (int b = 0; b < 1000; ++b) {

			for (int c = 0; c < 1000; ++c) {
				if (a + b + c == 1000 && (a * a + b * b) == c * c
						&& a < b && b < c) {
					A = a;
					B = b;
					C = c;
					cout << "a: " << a << " b: " << b << " c: " << c << endl;
					found = true;
				}

				if (found)
					break;
			}
			if (found)
				break;
		}
		if (found)
			break;
	}

	cout << "a: " << A << " | b: " << B << " | c: " << B << " | a*b*c: "
			<< A * B * C << endl;

	return 0;
}

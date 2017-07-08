#include <iostream>
using namespace std;

// coding for specific case of finding FOUR in a row .... could make
// it more generic later. Assumes the grid is at least big enough to
// perfom each of the searches below

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const int NUM_DIGITS = 4;

// Returns -1 if diagonal not possible
// Otherwise returns the product along the right diagonal starting
// at x, y
int searchRightDiagonal(int x, int y, int grid[][NUM_COLS]) {
	/*
	 *  x x x x 0 0 0 0
	 *  0 x x x x 0 0 0
	 *  0 0 x x x x 0 0
	 *  0 0 0 x x x x 0
	 *  0 0 0 0 x x x x
	 *
	 */

	// Only search if x (row number) is smaller than NUM_ROWS - NUM_DIGITS
	// and y is less than NUM_COLS - NUM_DIGTS
	if ((x < 0) || (x > NUM_ROWS - NUM_DIGITS) || (y < 0)
			|| (y > NUM_ROWS - NUM_DIGITS)) {
		return -1;
	}

	long long unsigned int product = 1;

	for (int i = 0; i < NUM_DIGITS; ++i) {
		product *= (grid)[x + i][y + i];
	}

	//DEBUG
	cout << "x: " << x << " y: " << y << " product: " << product << endl;

	return product;

}

// Searches through grid and computes all possible values of four numbers
// on a right diagonal, finding the largest value
int searchRightDiagonals(int grid[][NUM_COLS]) {
	int current, largest = 0;

	// DEBUG
	cout << "Searching right... " << endl;

	for (int x = 0; x < NUM_ROWS; ++x) {
		for (int y = 0; y < NUM_COLS; ++y) {
			current = searchRightDiagonal(x, y, grid);
			if (current > largest) {
				largest = current;
			}
		}
	}

	return largest;
}

// Returns -1 if diagonal not possible
// Otherwise returns the product along the left diagonal starting
// at x, y
int searchLeftDiagonal(int x, int y, int grid[][NUM_COLS]) {
	/*
	 *  0 0 0 0 x x x x
	 *  0 0 0 x x x x 0
	 *  0 0 x x x x 0 0
	 *  0 x x x x 0 0 0
	 *  x x x x 0 0 0 0
	 *
	 */

	// Only search if x (row number) is larger than NUM_DIGITS
	// and y is less than NUM_COLS - NUM_DIGTS
	if (!(x >= NUM_DIGITS - 1) || (y < 0)
			|| (y > NUM_ROWS - NUM_DIGITS)) {
		return -1;
	}

	long long unsigned int product = 1;

	for (int i = 0; i < NUM_DIGITS; ++i) {
		product *= (grid)[x - i][y + i];
	}

	//DEBUG
	cout << "x: " << x << " y: " << y << " product: " << product << endl;

	return product;

}

// Searches through grid and computes all possible values of four numbers
// on a right diagonal, finding the largest value
int searchLeftDiagonals(int grid[][NUM_COLS]) {
	int current, largest = 0;

	// DEBUG
	cout << "Searching left... " << endl;
	for (int x = 0; x < NUM_ROWS; ++x) {
		for (int y = 0; y < NUM_COLS; ++y) {
			current = searchLeftDiagonal(x, y, grid);
			if (current > largest) {
				largest = current;
			}
		}
	}

	return largest;
}

// Returns -1 if vertical not possible
// Otherwise returns the product along the vertical downwards starting
// at x, y
int searchHorizontal(int x, int y, int grid[][NUM_COLS]) {

	if ((x < 0) || (y < 0)
				|| (y > NUM_ROWS - NUM_DIGITS)) {
			return -1;
		}
	long long unsigned int product = 1;

	for (int i = 0; i < NUM_DIGITS; ++i) {
		product *= (grid)[x][y + i];
	}

	//DEBUG
	cout << "x: " << x << " y: " << y << " product: " << product << endl;

	return product;

}


// Returns -1 if vertical not possible
// Otherwise returns the product along the horizontal right starting
// at x, y
int searchVertical(int x, int y, int grid[][NUM_COLS]) {

	if ((x < 0) || (y < 0)
				|| (x > NUM_COLS - NUM_DIGITS)) {
			return -1;
		}
	long long unsigned int product = 1;

	for (int i = 0; i < NUM_DIGITS; ++i) {
		product *= (grid)[x + i][y ];
	}

	//DEBUG
	cout << "x: " << x << " y: " << y << " product: " << product << endl;

	return product;

}


// Searches through grid and computes all possible values of four numbers
// on a vertical, finding the largest value
int searchVerticals(int grid[][NUM_COLS]) {
	int current, largest = 0;

	// DEBUG
	cout << "Searching vertical... " << endl;
	for (int x = 0; x < NUM_ROWS; ++x) {
		for (int y = 0; y < NUM_COLS; ++y) {
			current = searchVertical(x, y, grid);
			if (current > largest) {
				largest = current;
			}
		}
	}

	return largest;
}

// Searches through grid and computes all possible values of four numbers
// on a vertical, finding the largest value
int searchHorizontals(int grid[][NUM_COLS]) {
	int current, largest = 0;

	// DEBUG
	cout << "Searching horizontal... " << endl;
	for (int x = 0; x < NUM_ROWS; ++x) {
		for (int y = 0; y < NUM_COLS; ++y) {
			current = searchHorizontal(x, y, grid);
			if (current > largest) {
				largest = current;
			}
		}
	}

	return largest;
}
void displayGrid(int grid[NUM_ROWS][NUM_COLS]) {
	for (int i = 0; i < NUM_ROWS; ++i) {
		for (int j = 0; j < NUM_COLS; ++j) {
			cout << " " << grid[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	cout << "Project Euler | Problem 10\n" << endl;

	int grid[NUM_ROWS][NUM_COLS] = { { 1, 2, 6, 4, 5 }, { 1, 7, 3, 4, 5 }, { 1,
			2, 3, 4, 9 }, { 1, 2, 0, 4, 5 }, { 8, 2, 3, 4, 5 } };

	displayGrid(grid);
	int biggest_horizontal = searchHorizontals(grid);
	int biggest_vertical = searchVerticals(grid);
	int biggest_right_diag = searchRightDiagonals(grid);
	int biggest_left_diag = searchLeftDiagonals(grid);

	cout << "RIGHT DIAG LARGEST: " << biggest_right_diag << endl;
	cout << " LEFT DIAG LARGEST: " << biggest_left_diag << endl;
	cout << "HORIZONTAL LARGEST: " << biggest_horizontal << endl;
	cout << "  VERTICAL LARGEST: " << biggest_vertical << endl;

	return 0;
}

//E-3 Sudoku

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void printDashedLine() {
	cout << "-------------------------------------" << endl;
}

void printBoard(int lBoard[9][9]) {
	for (int i = 0; i < 9; i++) {
		printDashedLine();

		for (int j = 0; j < 9; j++) {
			cout << "| ";
			if (lBoard[i][j] == 0) {
				cout << " ";
			}
			else {
				cout << lBoard[i][j];
			}
			cout << " ";
		}
		cout << "|" << endl;
	}
	printDashedLine();
}

int main() {
	int lBoard[9][9] = {
		{ 5, 0, 0, 8, 0, 0, 7, 9, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 3, 0 },
		{ 0, 6, 9, 0, 0, 0, 8, 0, 0 },
		{ 0, 4, 0, 6, 3, 5, 0, 0, 0 },
		{ 1, 0, 2, 0, 0, 0, 3, 0, 6 },
		{ 0, 0, 0, 0, 5, 1, 0, 7, 0 },
		{ 0, 0, 1, 0, 0, 0, 9, 2, 0 },
		{ 0, 2, 0, 0, 0, 4, 0, 0, 0 },
		{ 0, 9, 6, 0, 0, 3, 0, 0, 8 }
	};

	printBoard(lBoard);
	return 0;
}

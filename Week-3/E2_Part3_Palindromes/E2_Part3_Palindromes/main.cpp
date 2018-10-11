//Palindrome

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

bool isPalindrome(string palin) {
	int left, right;
	bool stillPalindrome = true; //assume innocent until proven guilty

	left = 0;
	right = palin.size() - 1;

	do {
		while (!isalpha(palin[left])) {
			left++;
		}
		while (!isalpha(palin[right])) {
			right--;
		}

		if (toupper(palin[left]) != toupper(palin[right])) {
			stillPalindrome = false;
		}

		left++;
		right--;

	} while (left != right && right > left && stillPalindrome == true );
	return stillPalindrome;
}

int main() {
	string palin;

	do {

		cout << "Enter in a string: " << endl;
		getline(cin, palin);

		if (isPalindrome(palin)) {
			cout << "'" << palin << "'" << " is a palindrome" << endl;
		}
		else {
			cout << "'" << palin << "'" << " is not a palindrome" << endl;
		}
		cout << endl;
	} while (1);

	return 0;
}

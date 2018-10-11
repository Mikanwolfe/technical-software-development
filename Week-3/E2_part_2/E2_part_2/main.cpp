//caesar's strings

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
	string cipher;
	int shift;
	cout << "Enter string to enrypt:" << endl;
	getline(cin, cipher);
	cout << "Enter amount to shift" << endl;
	cin >> shift;

	for (int i = 0; i < cipher.size(); i++) {

		if (cipher[i] <= 90 && cipher[i] >= 65) {
			cipher[i] += shift;
			if (cipher[i] > 90)
				cipher[i] = (cipher[i] % 90) + 65;
		}
		else if (cipher[i] <= 122 && cipher[i] >= 97) {
			cipher[i] += shift;
			if (cipher[i] > 122) 
				cipher[i] = (cipher[i] % 122) + 97;
		}
	}
	cout << "Output: " << cipher << endl;
	return 0;
}
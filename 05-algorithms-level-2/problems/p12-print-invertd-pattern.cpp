#include<iostream>
#include<string>
using namespace std;
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
void PrintInvertedPattern(int n) {
	for (int i = 65+n-1;i>=65;i--) {
		for (int j = i;j >=65;j--) {
			cout << char(i);
		}
		cout << "\n";
	}
}
void PrintPattern(int n) {
	for (int i = 65;i <= 65+n-1;i++) {
		for (int j = 65;j <= i;j++) {
			cout << char(i);
		}
		cout << "\n";
	}
}

int main() {
	PrintPattern(ReadPositiveNumber("please enter a number : "));
	return 0;
}
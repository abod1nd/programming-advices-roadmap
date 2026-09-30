#include<iostream>
using namespace std;
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
bool CheckPerfect(int Number) {
	int sum = 0;
	for (int i = 1;i < Number;i++) {
		if (Number % i == 0) {
			sum += i;
		}
	}
	return sum == Number;
}
void AllPerfectNumbersFrom1ToN(int N) {
	cout << endl << "ALL PERFECT NUMBERS FROM 1 TO " << N << " ARE : " << endl;

	for (int i = 1;i <= N;i++) {
		if (CheckPerfect(i)) {
			cout << i << endl;
		}
}
}

int main() {
	AllPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a Number : "));
	return 0;
}
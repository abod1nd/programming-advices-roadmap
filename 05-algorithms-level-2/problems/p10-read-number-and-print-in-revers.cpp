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
int ReverseNumber(int n) {
	int Remainder = 0;
	int Number2 = 0;
	while (n > 0) {

		Remainder = n % 10;
		n = n / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}
void PrintDigit(int n) {
	int Remainder = 0;
	while (n > 0) {
		Remainder = n % 10;
		n = n / 10;
		cout << Remainder << endl;
	}
	
}


int main() {
	 PrintDigit(ReverseNumber(ReadPositiveNumber("please enter a number : "))) ;
	return 0;
}
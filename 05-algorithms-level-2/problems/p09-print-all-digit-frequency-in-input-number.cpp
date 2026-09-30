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

short CalculteFrequencyForDigit(int number ,int digit) {
	int Remainder = 0;
	short frequency = 0;

	while (number>0) {
		Remainder = number % 10;
		number = number / 10;
		if (Remainder == digit) {
			frequency++;
		}

	}
	return frequency;
}
void CalculateFrequencyForEachDigitInNumber(int n) {

	for (int i = 0;i <= 9;i++) {
		short DigitFrequency = CalculteFrequencyForDigit(n, i);

		if(DigitFrequency>0)
			{
				cout << "Digit " << i << " Frequency is " <<DigitFrequency<< " Time(s)" << endl;
			}

	}
	
}

int main() {
	CalculateFrequencyForEachDigitInNumber(ReadPositiveNumber("Please enter a number : "));
	return 0;
}
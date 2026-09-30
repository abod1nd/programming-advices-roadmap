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
int checkTheNumberFrequency(int Number,int digit) 
{
	int Remainder = 0;
	int frequency = 0;

	while (Number > 0) {
			
			Remainder = Number % 10;
			Number = Number / 10;
			if (Remainder == digit) {
				frequency++;
			}
	}
	return frequency;
}
void PrintResult(int Frequency,int digit) {
	cout << "Digit " << digit << " Frequency is " << Frequency << " Time(s)" << endl;
}

int main() {
	int Number = ReadPositiveNumber("Please enter a number : ");
	int Digit = ReadPositiveNumber("Please enter the nubmer that you want to check for its frequency : ");
	PrintResult(checkTheNumberFrequency(Number, Digit), Digit);

	return 0;
}
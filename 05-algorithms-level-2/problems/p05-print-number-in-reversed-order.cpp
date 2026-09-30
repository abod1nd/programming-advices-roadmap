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
void PrintInReversed(int n)
{
	int Remainder = 0;
	while (n>0) 
	{
		
		Remainder = n % 10;
		n =n/ 10;
		cout << Remainder;

	}
}

int main() {
	PrintInReversed(ReadPositiveNumber("Please enter a number : "));
	return 0;
}
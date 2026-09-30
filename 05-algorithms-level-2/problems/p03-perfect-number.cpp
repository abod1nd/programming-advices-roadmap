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
	
void PrintResult(int N) {
	if (CheckPerfect(N)) {
		cout << N << " is perfecto " << endl;
	}
	else
	{
		cout << N << " is not Perfecto" << endl;
	}
}
int main() {
	PrintResult(ReadPositiveNumber("Please enter the number that you want to check if it is perfect : "));
	return 0;
}
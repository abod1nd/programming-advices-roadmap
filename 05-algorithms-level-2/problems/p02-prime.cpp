#include<iostream>
#include<cmath>
#include<string>
using namespace std;
enum enPrimOrNot
{
	Prim = 1, NotPrim=2
};
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
enPrimOrNot checkPrim(int n) {
	int m = round( n / 2);
	for (int i = 2; i <= m; i++)
	{
		if (n % i == 0) {
			return enPrimOrNot::NotPrim;
			

		}
	}
	return enPrimOrNot::Prim;
	
}
void PrintAllPrimFrom1ToN(int N) {
	for (int i = 1;i <= N;i++) {
		if (checkPrim(i) == enPrimOrNot::Prim) {
			cout << i << endl;
		}
	}
}
int main() {
	 
	PrintAllPrimFrom1ToN(ReadPositiveNumber("Please enter a number "));


	return 0;
}
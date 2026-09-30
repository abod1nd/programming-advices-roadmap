#include<iostream>
using namespace std;
enum enCheckPalindrome
{
palindrome=1,Notpalindrome=2
};
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
enCheckPalindrome CheckPalindrome(int n) {
	
	if (ReverseNumber(n)==n) {
		
		return enCheckPalindrome::palindrome;
	}
	else
	{
		
		return enCheckPalindrome::Notpalindrome;
	}
}
void PrintResult(enCheckPalindrome check) {
	if(check==enCheckPalindrome::palindrome) cout << "Yes, it is  a Palindrome number :)" << endl;
	else cout << "No , it is NOT a Palindrome number :(" << endl;
}


int main() {

	PrintResult(CheckPalindrome(ReadPositiveNumber("Please Enter The Number That you Want To Check If Its Palindrome : ")));
	return 0;
}
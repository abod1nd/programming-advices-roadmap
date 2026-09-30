#include<iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
int ReadNumber(string message) {
	int number;
	
		cout << message << endl;
		cin >> number;


	return number;
}
bool AskTheUserYesNoQ(string message) {
	bool Q;
	cout << message << endl;
	cin >> Q;
	return Q;
	
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}
void InputUserNumbersInArray(int arr[100], int& arrLingt) {
	
	do
	{
		AddArrayElement(ReadNumber("Please enter a number : "), arr, arrLingt);
	} while (AskTheUserYesNoQ("Do you want to add more numbers ? [0]:No , [1]:yes ? "));
	
}
void PrintArray(int MainArr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << MainArr[i] << " ";

	cout << "\n";
}
int main() {
	int arr[100];
	int arrLength=0;
	InputUserNumbersInArray(arr, arrLength);
	cout << "Array length : " << arrLength << endl;
	cout << "Array elements : ";
	PrintArray(arr, arrLength);
	return 0;

}
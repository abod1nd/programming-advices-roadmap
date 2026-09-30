#include<iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
void PrintArray(int MainArr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << MainArr[i] << " ";

	cout << "\n";
}
void FillArrayWithRandomNumbers(int MainArr[100], int& arrLength) {
	cout << "Please enter the array length : " << endl;
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		MainArr[i] = RandomNumber(1, 100);
	}

}
int FindNumberPositionInArray(int n, int arr[100], int arrLength) {
	for (int i = 0;i < arrLength;i++) {

		if (arr[i] == n) {
			return i;
		}
		
		
	}
	return -1;
}
bool SearshNumInArray(int number,int arr[100],int arrLength) {
	return FindNumberPositionInArray(number, arr, arrLength) != -1;
}
void PrintSearchResult(int index,int n) {
	if (index != -1) {
		cout << "Number you are looking for is : " << n << endl;
		cout << "The number found at position : " << index << endl;
		cout << "The number found its order : " << index+ 1 << endl;
	
	}
	else
	{
		cout << "Number you are looking for is : " << n << endl;
		cout << "The number is not found :-( " << endl;

	}
}


int main() {
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	int n= ReadPositiveNumber("Please enter the number that you want to search for : ");
	
	cout << "\n"; 
	cout << "Array 1 elements :" << endl;
	PrintArray(arr, arrLength);
	PrintSearchResult(FindNumberPositionInArray(n, arr, arrLength), n);


	return 0;
}
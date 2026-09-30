#include<iostream>
using namespace std;
enum enCheckPalindrome
{
	palindrome = 1, Notpalindrome = 2
};
int ReadNumber(string message) {
	int number;
	cout << message << endl;
	cin >> number;

	return number;
}
void CopyArrayInReverse(int arr1[100], int arr2[100], int arrLength) {
	int count = arrLength - 1;

	for (int i = 0;i < arrLength;i++) {
		arr2[i] = arr1[count];
		count--;
	}

}


void FillArray(int arr[100], int& arrLength)
{
	arrLength = 6;  // Set the number of elements in the array to 6.

	// Manually assign values to each element in the array.
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 3;
}
enCheckPalindrome CheckArrayIfPalindrome(int arr[100], int arr2[100], int arrLength) {
	int count = arrLength;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == arr2[count]) {
			count--;

		}
		else if (arr[i] != arr2[count])
		{
			return enCheckPalindrome::Notpalindrome;

		}
	}
	return enCheckPalindrome::palindrome;

}
void PrintResult(enCheckPalindrome check) {
	if (check == enCheckPalindrome::palindrome) cout << "Yes, it is  a Palindrome number :)" << endl;
	else cout << "No , it is NOT a Palindrome number :(" << endl;
}

int FindNumberPositionInArray(int n, int arr[100], int arrLength)
{
	for (int i = 0;i < arrLength;i++)
	{

		if (arr[i] == n)
		{
			return i;
		}


	}
	return -1;
}
bool SearshNumInArray(int number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(number, arr, arrLength) != -1;
}
void PrintArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << "\n";

}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}
void CopyDistinctNums(int arr[100], int arr1[100], int arrLength, int& DestinationLengthinat)
{
	for (int i = 0;i < arrLength;i++)
	{
		if (!SearshNumInArray(arr[i], arr1, DestinationLengthinat)) {
			AddArrayElement(arr[i], arr1, DestinationLengthinat);
		}
	}
}

int main()
{
	int arr1[100], arr2[100], arr1Length = 0, arr2Length = 0;
	FillArray(arr1, arr1Length);
	cout << "\nArray 1 elements : ";
	PrintArray(arr1, arr1Length);
	CopyArrayInReverse(arr1, arr2, arr1Length);
	PrintResult(CheckArrayIfPalindrome(arr1, arr2, arr1Length));
	return 0;
}
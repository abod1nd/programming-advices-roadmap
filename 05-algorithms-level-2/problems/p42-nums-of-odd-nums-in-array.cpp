#include<iostream>
using namespace std;

int RandomNumber(int From, int To) 
{

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumbers(int MainArr[100], int& arrLength) 
{
	cout << "Please enter the array length : " << endl;
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		MainArr[i] = RandomNumber(-100, 100);
	}

}
void PrintArray(int MainArr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << MainArr[i] << " ";

	cout << "\n";
}
int FindNumOfOddNumsInArray(int arr[100], int arrLength) 
{
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 != 0) count++;
	}
	return count;
}
int FindNumOfEvenNumsInArray(int arr[100], int arrLength)
{
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] % 2 == 0) count++;
	}
	return count;
}
int FindNumOfPositiveNumsInArray(int arr[100], int arrLength)
{
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] >= 0) count++;
	}
	return count;
}
int FindNumOfNegativeNumsInArray(int arr[100], int arrLength)
{
	int count = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < 0) count++;
	}
	return count;
}
int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array Elements : ";
	PrintArray(arr, arrLength);
	cout << "\nNegative Numbers count is : \n" << FindNumOfNegativeNumsInArray(arr, arrLength);
	return 0;
}
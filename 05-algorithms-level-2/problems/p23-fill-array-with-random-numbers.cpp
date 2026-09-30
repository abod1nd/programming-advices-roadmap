#include<iostream>
using namespace std;
int RandomNumber(int From, int To) {
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength) {
	cout << "Please enter the array length : " << endl;
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
	
}
void PrintArray(int arr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << "\n";
}
int findMaxOfArray(int arr[100],int arrLength) {

	int max = 0;

	for (int i = 0;i < arrLength;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

	}
	return max;
}
int findMinOfArray(int arr[100], int arrLength) {

	int min = arrLength;

	for (int i = 0;i < arrLength;i++) {
		if (arr[i] < min) {
			min = arr[i];
		}

	}
	return min;
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "Array Elements : ";
	PrintArray(arr, arrLength);
	
	cout << "Max Number is : " << findMaxOfArray(arr, arrLength) << endl;
	cout << "Min Number is : " << findMinOfArray(arr, arrLength) << endl;

	return 0;
}
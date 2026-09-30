#include<iostream>
#include<string>
using namespace std;
enum enPrimOrNot
{
	Prim = 1, NotPrim = 2
};
enPrimOrNot checkPrim(int n) {
	int m = round(n / 2);
	for (int i = 2; i <= m; i++)
	{
		if (n % i == 0) {
			return enPrimOrNot::NotPrim;


		}
	}
	return enPrimOrNot::Prim;

}
int RandomNumber(int From, int To) {
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumbers(int MainArr[100], int& arrLength) {
	cout << "Please enter the array length : " << endl;
	cin >> arrLength;
	for (int i = 0;i < arrLength;i++)
	{
		MainArr[i] = RandomNumber(1, 100);
	}

}
void PrintArray(int MainArr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << MainArr[i] << " ";

	cout << "\n";
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}


void copyArrayUsingAddArrayElement(int MainArr[100], int CopedArr[100], int arrLength, int& arrDestinationLength) {
	

	for (int i = 0;i < arrLength;i++) {
		AddArrayElement(MainArr[i], CopedArr, arrDestinationLength);
	}
}
void copyArraysOddNums(int MainArr[100], int CopedArr[100], int arrLength, int& arrDestinationLength) {


	for (int i = 0;i < arrLength;i++) {
		if (MainArr[i] % 2 != 0) {
			AddArrayElement(MainArr[i], CopedArr, arrDestinationLength);
		}
	}
}
void copyArrayPrimeNums(int MainArr[100], int CopedArr[100], int arrLength, int& arrDestinationLength) {


	for (int i = 0;i < arrLength;i++) {
		if (checkPrim( MainArr[i] )== enPrimOrNot::Prim) {
			AddArrayElement(MainArr[i], CopedArr, arrDestinationLength);
		}
	}
}

int main() {	
	srand((unsigned)time(NULL));

	int arr1[100];
	int arr1Length = 0;
	int arr2[100];
	int arr2Length = 0;

	FillArrayWithRandomNumbers(arr1, arr1Length);
	cout << "Array 1 elements : " << endl;
	PrintArray(arr1, arr1Length);
	cout << "Array 2 elements after copy :	" << endl;
	copyArrayPrimeNums(arr1, arr2, arr1Length,arr2Length);
	PrintArray(arr2, arr2Length);
	return 0;
}

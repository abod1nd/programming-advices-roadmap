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
void swap(int &a, int& b) {
	int temp;
	temp = a;
	a=b;
	b = temp;
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
void FillArraywithOrderedNumbersToN(int MainArr[100], int& arrLength) {
	cout << "Please enter a number : " << endl;
	cin >> arrLength;
	int value = 1;
	for (int i = 0;i < arrLength;i++) {
		MainArr[i] = value;
		value++;
	}
}
void PrintArray(int MainArr[100], int arrLength)
{

	for (int i = 0; i < arrLength; i++)
		cout << MainArr[i] << " ";

	cout << "\n";
}

void copyArray(int MainArr[100], int& arrLength, int CopedArr[100], int& arr1Length) {
	arr1Length = arrLength;
	
	for (int i = 0;i < arrLength;i++) {
		CopedArr[i] = MainArr[i];

	}
}
void copyPrimeNumbersFromArray(int MainArr[100], int& arrLength, int CopedArr[100], int& arr1Length) {
	
	int count = 0;
	for (int i = 0;i < arrLength;i++) {
		if (checkPrim(MainArr[i]) == enPrimOrNot::Prim) {
			CopedArr[count] = MainArr[i];
			count++;
		}

	}
	arr1Length = count;
}
void sumOfTwoArrays(int MainArr[100], int& arrLength, int CopedArr[100], int& arr1Length) {
	int sum = 0;
	int arr3[100];
	cout << "Sum of array1 and array2 elements : \n";

	for (int i = 0;i < arrLength;i++) {
		arr3[i]= MainArr[i] + CopedArr[i];
	}

}
void ShuffleArray(int arr[100], int arr1Length) {
	for (int i = 0;i < arr1Length;i++) {
		swap(arr[i], arr[RandomNumber(0, arr1Length - 1)]);
}
}
void CopyArrayInReverse(int arr1[100],  int arr2[100] ,int arrLength) {
	int count = arrLength - 1;

	for (int i = 0;i < arrLength;i++) {
		arr2[i] = arr1[count];
		count--;
	}

}


int main() {
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLenght;
	int emptyArray[100];
	FillArrayWithRandomNumbers(arr, arrLenght);
	cout << "Array 1 elements : " << endl;
	PrintArray(arr, arrLenght);
	CopyArrayInReverse(arr,  emptyArray,arrLenght);

	cout << "Array 2 elements after copying array 1 in reversed order : " << endl;
	PrintArray(emptyArray, arrLenght);

	return 0;
}
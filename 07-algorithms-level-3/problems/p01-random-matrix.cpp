#include<iostream>
#include<iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void RandomMatrix(int arr[3][3],short Rows, short Cols)
{
	for (int i = 0;i < Cols;i++)
	{
		for (int j = 0;j < Rows;j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}
void PrintArry(int arr[3][3],short Rows, short Cols)
{
	for (int i = 0;i < Cols;i++)
	{
		for (int j = 0;j < Rows;j++)
		{
			cout <<setw(3)<< arr[i][j] << "  ";

		}
		cout << endl;
	}
}
void  RowSum(int arr[3][3],int sumArr[3], short RowNumber, short cols)
{
	int sumArr[3];
	for (short j = 0;j <= cols-1;j++)
	{
		sumArr[j]= arr[RowNumber][j];
	}
	

}
void PrintEachRowSum(int arr[3][3],int sumArr[3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each row in the matrix : \n";
		for (short i = 0;i < Rows;i++)
		{
			RowSum(arr, sumArr, i, Cols);
			printf("Row %d Sum = %d  ", i + 1,sumArr[i]);
			cout << endl;
		}
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[3][3];
	int arr1[3];
	RandomMatrix(arr,3,3);	
	PrintArry(arr,3,3);
	
	PrintEachRowSum(arr, arr1,3, 3);
}
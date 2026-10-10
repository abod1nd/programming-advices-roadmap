#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;


int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 10);
        }
    }
}
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void MultiplyTowMatrices(int arr1[3][3], int arr2[3][3], int sumArrs[3][3] , short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            sumArrs[i][j] = arr1[i][j] * arr2[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3], arrSum[3][3];
    FillMatrixWithRandomNumbers(arr1, 3, 3);
    cout << "Matrix1 : \n";
    PrintMatrix(arr1, 3, 3);

    FillMatrixWithRandomNumbers(arr2, 3, 3);
    cout << "Matrix2 : \n";
    PrintMatrix(arr2, 3, 3);
    MultiplyTowMatrices(arr1, arr2, arrSum, 3, 3);
    cout << "Results : \n";
    PrintMatrix(arrSum, 3, 3);


    cout << "\nThe following is a 3x3 random matrix:\n";

    return 0;
}
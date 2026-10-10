#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

void FillMatrixWithOrderdNumbers(int arr[3][3], short Rows, short Cols)
{
    int Ord = 1;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = Ord;
            Ord++;
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
    cout << endl;

}
void TransposeMatrix(int arr[3][3],int TransArr[3][3],short Rows,short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            TransArr[i][j] = arr[j][i];
        }
     
    }
}

int main()
{
    int cols = 3, rows = 3;
    int arr[3][3], TransArr[3][3];
    FillMatrixWithOrderdNumbers(arr, rows, cols);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, rows, cols);
    TransposeMatrix(arr, TransArr,rows, cols);
    cout << "\n\nThe following is the transposed matrix:\n";
    PrintMatrix(arr, rows, cols);

}
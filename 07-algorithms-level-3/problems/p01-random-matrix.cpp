#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

// توليد رقم عشوائي ضمن مجال محدد
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// ملء المصفوفة بأرقام عشوائية
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

// طباعة محتوى المصفوفة بتنسيق منظم
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

// جمع عناصر صف واحد محدد
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
    int Sum = 0;
    for (short j = 0; j < Cols; j++)
    {
        Sum += arr[RowNumber][j]; // رقم الصف ثابت، ورقم العمود يتغير
    }
    return Sum;
}

// جمع عناصر عمود واحد محدد
int ColsSum(int arr[3][3], short ColsNumber, short Rows)
{
    int Sum = 0;
    for (short i = 0; i < Rows; i++)
    {
        Sum += arr[i][ColsNumber]; // رقم العمود ثابت، ورقم الصف يتغير
    }
    return Sum;
}

// حساب مجموع كل صف وتخزينه في مصفوفة النتائج
void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        arrSum[i] = RowSum(arr, i, Cols);
    }
}

// حساب مجموع كل عمود وتخزينه في مصفوفة النتائج
void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
    for (short j = 0; j < Cols; j++)
    {
        arrSum[j] = ColsSum(arr, j, Rows);
    }
}

// طباعة نتائج مجموع الصفوف
void PrintRowsSumArray(int arrSum[3], short Rows)
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (short i = 0; i < Rows; i++)
    {
        cout << " Row " << i + 1 << " Sum = " << arrSum[i] << endl;
    }
}

// طباعة نتائج مجموع الأعمدة
void PrintColsSumArray(int arrSum[3], short Cols)
{
    cout << "\nThe following are the sum of each column in the matrix:\n";
    for (short j = 0; j < Cols; j++)
    {
        cout << " Col " << j + 1 << " Sum = " << arrSum[j] << endl;
    }
}

int main()
{
    // تهيئة مولد الأرقام العشوائية مرة واحدة
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrRowsSum[3];
    int arrColsSum[3];

    FillMatrixWithRandomNumbers(arr, 3, 3);

    cout << "\nThe following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);

    // حساب وطباعة مجموع الصفوف
    SumMatrixRowsInArray(arr, arrRowsSum, 3, 3);
    PrintRowsSumArray(arrRowsSum, 3);

    // حساب وطباعة مجموع الأعمدة
    SumMatrixColsInArray(arr, arrColsSum, 3, 3);
    PrintColsSumArray(arrColsSum, 3);

    return 0;
}
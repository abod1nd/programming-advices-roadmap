#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

// ===================== Input / Random =====================

int ReadNumber(string Message)
{
    int Number;

    cout << Message << endl;
    cin >> Number;

    while (cin.fail())
    {
        // user didn't input a number
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid Number, Enter a valid one:" << endl;
        cin >> Number;
    }

    return Number;
}


int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}


void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

// ===================== Printing =====================

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(4);
            printf(" %0*d    ", 2, Matrix[i][j]);
        }
        cout << "\n";
    }
}


void PrintArray(int Arr[3], short Length)
{
    for (short i = 0; i < Length; i++)
    {
        cout << setw(4);
        printf(" %0*d    ", 2, Arr[i]);
    }
}

// ===================== P09: Middle Row & Col =====================

void GetMiddleRowOfMatrix(int Matrix[3][3], int MiddleRow[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        MiddleRow[i] = Matrix[1][i];
    }
}


void GetMiddleColOfMatrix(int Matrix[3][3], int MiddleCol[3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        MiddleCol[i] = Matrix[i][1];
    }
}

// ===================== P10: Sum of Matrix =====================

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }
    return Sum;
}

// ===================== P11: Equal Matrices =====================

bool AreMatricesEqual(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
}

// ===================== P12: Typical Matrices =====================

bool AreMatricesTypical(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
        }
    }
    return true;
}

// ===================== P13: Identity Matrix =====================

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != 1)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

// ===================== P14: Scalar Matrix =====================

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int FirstDiagonalElement = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagonalElement)
            {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

// ===================== P15: Count Number in Matrix =====================

int CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    int Count = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number) Count++;
        }
    }
    return Count;
}

// ===================== P16: Sparse Matrix =====================

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));
}

// ===================== P17: Number Exists in Matrix =====================

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number) return true;
        }
    }
    return false;
}

// ===================== P18: Intersected Numbers =====================

vector<int> GetIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    vector<int> vIntersectedNumbers;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            int CurrentNumber = Matrix2[i][j];

            if (IsNumberInMatrix(Matrix1, CurrentNumber, Rows, Cols))
            {
                vIntersectedNumbers.push_back(CurrentNumber);
            }
        }
    }
    return vIntersectedNumbers;
}

// ===================== P19: Min & Max =====================

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Max = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] >= Max)
                Max = Matrix[i][j];
        }
    }
    return Max;
}


int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    int Min = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] < Min)
                Min = Matrix[i][j];
        }
    }
    return Min;
}

// ===================== P20: Palindrome Matrix =====================

bool AreArraysTypical(int Arr1[3], int Arr2[3], short Length)
{
    for (short i = 0; i < Length; i++)
    {
        if (Arr1[i] != Arr2[i])
            return false;
    }
    return true;
}


bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }
    return true;
}

// ===================== Main =====================

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MiddleRow[3], MiddleCol[3];
    int IdentityMatrix[3][3] = { { 1,0,0 },{ 0,1,0 },{ 0,0,1 } };
    int ScalarMatrix[3][3] = { { 9,0,0 },{ 0,9,0 },{ 0,0,9 } };

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    FillMatrixWithRandomNumbers(Matrix2, 3, 3);

    cout << "Matrix1 :" << endl;
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2 :" << endl;
    PrintMatrix(Matrix2, 3, 3);


    //P09
    cout << "\n---------- P09: Middle Row & Col ----------\n";
    GetMiddleRowOfMatrix(Matrix1, MiddleRow, 3, 3);
    cout << "Middle Row of Matrix1 is : " << endl;
    PrintArray(MiddleRow, 3);
    cout << "\n\n";
    GetMiddleColOfMatrix(Matrix1, MiddleCol, 3, 3);
    cout << "Middle Col of Matrix1 is : " << endl;
    PrintArray(MiddleCol, 3);
    cout << "\n";


    //P10
    cout << "\n---------- P10: Sum of Matrix ----------\n";
    cout << "Sum of Matrix1 is : " << SumOfMatrix(Matrix1, 3, 3) << endl;


    //P11
    cout << "\n---------- P11: Equal Matrices ----------\n";
    if (!AreMatricesEqual(Matrix1, Matrix2, 3, 3))
        cout << "No: Matrices are NOT equal." << endl;
    else
        cout << "Yes: Matrices are equal :)" << endl;


    //P12
    cout << "\n---------- P12: Typical Matrices ----------\n";
    if (!AreMatricesTypical(Matrix1, Matrix2, 3, 3))
        cout << "No: Matrices are NOT typical." << endl;
    else
        cout << "Yes: Matrices are typical :)" << endl;


    //P13
    cout << "\n---------- P13: Identity Matrix ----------\n";
    cout << "Matrix :" << endl;
    PrintMatrix(IdentityMatrix, 3, 3);
    if (!IsIdentityMatrix(IdentityMatrix, 3, 3))
        cout << "No: Matrix is NOT identity." << endl;
    else
        cout << "Yes: Matrix is identity :)" << endl;


    //P14
    cout << "\n---------- P14: Scalar Matrix ----------\n";
    cout << "Matrix :" << endl;
    PrintMatrix(ScalarMatrix, 3, 3);
    if (!IsScalarMatrix(ScalarMatrix, 3, 3))
        cout << "No: Matrix is NOT scalar." << endl;
    else
        cout << "Yes: Matrix is scalar :)" << endl;


    //P15
    cout << "\n---------- P15: Count Number in Matrix ----------\n";
    int NumberToCount = ReadNumber("Enter the number to count in Matrix1 ? ");
    cout << "\nNumber " << NumberToCount << " count in Matrix1 is "
        << CountNumberInMatrix(Matrix1, NumberToCount, 3, 3) << endl;


    //P16
    cout << "\n---------- P16: Sparse Matrix ----------\n";
    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "Yes: Matrix1 is sparse :)" << endl;
    else
        cout << "No: Matrix1 is NOT sparse :(" << endl;


    //P17
    cout << "\n---------- P17: Number Exists in Matrix ----------\n";
    int NumberToFind = ReadNumber("Please enter the number to look for in Matrix2 ? ");
    if (IsNumberInMatrix(Matrix2, NumberToFind, 3, 3))
        cout << "\nYes: it is there." << endl;
    else
        cout << "\nNo: it is NOT there." << endl;


    //P18
    cout << "\n---------- P18: Intersected Numbers ----------\n";
    cout << "Intersected Numbers are : " << endl;
    for (const int& Number : GetIntersectedNumbers(Matrix1, Matrix2, 3, 3))
    {
        cout << setw(3) << Number << "   ";
    }
    cout << endl;


    //P19
    cout << "\n---------- P19: Min & Max ----------\n";
    cout << "Minimum Number is : " << MinNumberInMatrix(Matrix1, 3, 3) << endl;
    cout << "Max Number is : " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;


    //P20
    cout << "\n---------- P20: Palindrome Matrix ----------\n";
    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "Yes: Matrix1 is palindrome." << endl;
    else
        cout << "No: Matrix1 is NOT palindrome." << endl;

    return 0;
}
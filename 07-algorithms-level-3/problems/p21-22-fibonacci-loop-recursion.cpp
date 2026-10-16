#include <iostream>

using namespace std;

// ===================== P21: Fibonacci Series Using Loop =====================

void PrintFibonacciSeries(int Number)
{
    int FibNumber = 0, Prev1 = 1, Prev2 = 0;

    cout << "1   ";

    for (int i = 2; i <= Number; i++)
    {
        FibNumber = Prev1 + Prev2;
        cout << FibNumber << "   ";

        Prev2 = Prev1;
        Prev1 = FibNumber;
    }
}

// ===================== P22: Fibonacci Series Using Recursion =====================

void PrintFibonacciUsingRecursion(int Number, int Prev1, int Prev2)
{
    int FibNumber = 0;

    if (Number > 0)
    {
        FibNumber = Prev1 + Prev2;

        Prev2 = Prev1;
        Prev1 = FibNumber;

        cout << FibNumber << "   ";
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
}

// ===================== Main =====================

int main()
{
    //P21
    cout << "\n---------- P21: Fibonacci Series Using Loop ----------\n";
    PrintFibonacciSeries(10);
    cout << endl;


    //P22
    cout << "\n---------- P22: Fibonacci Series Using Recursion ----------\n";
    PrintFibonacciUsingRecursion(10, 0, 1);
    cout << endl;

    return 0;
}
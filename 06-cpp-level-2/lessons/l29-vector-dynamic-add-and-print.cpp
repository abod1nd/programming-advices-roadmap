#include <iostream>
#include<vector>
#include<limits>
using namespace std;
struct stEmployees
{
	string firstName = "";
	string lastName = "";
	int NumOfEmployee=0;
};
int ReadNumber()
{
	int Number;
	cout << "Please enter a number?" << endl;
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


bool AskYesNoQ(string message)
{
	char Answer;
	cout << message;
	cin >> Answer;
	cout << "\n\n";
	return (Answer == 'Y' || Answer == 'y');
}


void ReadStruct(vector <stEmployees>& vEmployees)
{
	stEmployees tempEmployees;
	bool MoreNums;
	int count = 1;
	do
	{
		cout << "Enter the Employee " << count << " first name : " << endl;
		cin >> tempEmployees.firstName;
		cout << "Enter the Employee " << count << " last name : " << endl;
		cin >> tempEmployees.lastName;
		vEmployees.push_back(tempEmployees);
		MoreNums = AskYesNoQ("\nDo you want to enter more numbers ? Y/N\n");
		count++;
	} while (MoreNums);
	tempEmployees.NumOfEmployee = count;

}


void ReadNumbers(vector <int>& vNumbers)
{
	bool MoreNums;
	do
	{
		int n = ReadNumber();
		vNumbers.push_back(n);
		MoreNums = AskYesNoQ("\nDo you want to enter more numbers ? Y/N\n");
	} while (MoreNums);
}
void PrintNumber(const vector<int>& vNumbers)
{
	for (const int& N : vNumbers)
	{
		cout << N << endl;
	}
}


void PrintStruct(const vector <stEmployees>& vEmployees)
{
	int count = 0;
	for (const stEmployees& N : vEmployees)
	{
		cout << "the employee " << count << " first name : " << N.firstName << endl;
		cout << "the employee " << count << " last name : " << N.lastName << endl;
		cout << "\n\n\n";
		++count;

	}
	cout << "\n\n\n The number of the employees is : " << count << endl;
}

int main()
{
	vector<stEmployees>vEmployees;
	ReadStruct(vEmployees);
	PrintStruct(vEmployees);
	return 0;

}
#include<iostream>
#include<string>
using namespace std;
struct stGuessPassword
{
	bool IsItFound;
	int NumOfTrials;
	string password;
};
string ReadString(string message) {
	string word;
	
		cout << message << endl;
		cin >> word;

	
	return word;
}

stGuessPassword GuessPassword3Letter(string Password) {
	stGuessPassword GuessPass;
	string word = "";
	int count = 0;
	for (int i = 65;i <= 90;i++) {


		for (int j = 65;j <= 90;j++) {


			for (int h = 65;h <= 90;h++) {
				word += char(i);
				word += char(j);
				word += char(h);
				count++;
				if (Password == word) {
					GuessPass.IsItFound = true;
					GuessPass.NumOfTrials = count;
					GuessPass.password = word;
					return GuessPass;
				}
				
				
				word = "";
				
				
			}
		}
	}

	GuessPass.IsItFound = false;
	GuessPass.NumOfTrials = count;
	GuessPass.password = "NULL";

	return GuessPass;
	
}
void PrintResult(stGuessPassword GuessPass) {
	if (GuessPass.IsItFound ) {
		cout << "\nPassword is :" << GuessPass.password << endl;
		cout << "Found after " << GuessPass.NumOfTrials << " Trial(s)\n";

	}
	else
	{
		cout << "\nPassword not found " << endl;
		cout << "The number of trial(s) is " << GuessPass.NumOfTrials << endl;
	}
}
	
int main() {
	PrintResult(GuessPassword3Letter(ReadString("Please enter a 3-Letter Password ( all capital) ... \n")));
			return 0;
		}


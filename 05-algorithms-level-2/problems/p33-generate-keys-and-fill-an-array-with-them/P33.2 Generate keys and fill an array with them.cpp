#include<iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
enum enCharType
{
	SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4
};
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}
int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
char GetRandomCharacter(enCharType CharacterT) {
	switch (CharacterT) {
	case enCharType::Digit: {
		return char(RandomNumber(48, 57));break;

	}
	case enCharType::CapitalLetter: {
		return char(RandomNumber(65, 90));break;

	}
	case enCharType::SmallLetter: {
		return char(RandomNumber(97, 122));break;

	}
	case enCharType::SpecialCharacter: {
		return char(RandomNumber(33, 47));break;

	}
	}
}
string GenerateRandomWord(short WordLength, enCharType WordType) {
	string word = "";
	for (int i = 1;i <= WordLength;i++) {
		word = word + GetRandomCharacter(WordType);
	}
	return word;
}
string GenerateKeye(short NumOfSlots) {
	string keye = "";

	for (int i = 1;i <= NumOfSlots;i++) {
		keye = keye + GenerateRandomWord(4, enCharType::CapitalLetter);
		if (i < NumOfSlots) {
			keye = keye + "-";
		}
	}
	return keye;

}
void GenerateKeys(string arr[100], int& NumOfKeys) {
	int key = ReadPositiveNumber("Please enter the number of slots for all the keys : ");
	for (int i = 0;i < NumOfKeys;i++) {
		arr[i] = GenerateKeye(key);
		
	}
}
void PrintStringArray(string arr[100], int arrLength)
{
	cout << "\nArray elements:\n\n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] : ";
		cout << arr[i] << "\n";
	}
	cout << "\n"; 
}

int main() {
	srand((unsigned)time(NULL));
	string arr[100];
	int NumOfKeys;
	NumOfKeys = ReadPositiveNumber("Please enter the number of keys thet you want to generate : ");

	GenerateKeys(arr, NumOfKeys);
	PrintStringArray(arr, NumOfKeys);
	return 0;
}
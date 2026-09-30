#include<iostream>
using namespace std;
enum enCharacterType
{
	SmallLetter=1,CapitalLetter=2,SpecialCharacter=3,Digit=4
};
int RandomNumber(int From, int To) {
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
char GetRandomCharacter(enCharacterType CharacterT) {
	switch (CharacterT) {
	case enCharacterType::Digit: {
		return char(RandomNumber(48, 57));break;

	}
	case enCharacterType::CapitalLetter: {
		return char(RandomNumber(65,90));break;

	}
	case enCharacterType::SmallLetter: {
		return char(RandomNumber(97,122));break;

	}
	case enCharacterType::SpecialCharacter: {
		return char(RandomNumber(33,47));break;

	}
	}
}

int main() {
	srand((unsigned)time(NULL));
	cout << GetRandomCharacter(enCharacterType::SmallLetter) << endl;
	cout << GetRandomCharacter(enCharacterType::Digit) << endl;

	cout << GetRandomCharacter(enCharacterType::Digit) << endl;
	cout << GetRandomCharacter(enCharacterType::SpecialCharacter) << endl;

	cout << GetRandomCharacter(enCharacterType::CapitalLetter) << endl;

	return 0;
}
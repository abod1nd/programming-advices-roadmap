#include<iostream>
#include<cmath>
#include <cstdlib>
#include <ctime>
#include <string> 
using namespace std;

enum enRockPaperScissors
{
	Rock = 1, Paper = 2, Scissor = 3
};

enum enRoundResult
{
	PlayerWins = 1, ComputerWins = 2, Draw = 3
};
struct stGameResults
{
	int PlayerWon = 0,
		ComputerWon = 0,
		DrawTimes = 0;
};
struct stRoundInfo
{
	enRockPaperScissors  Player1Choice;
	enRockPaperScissors ComputerChoice;
	enRoundResult Result;
};

int ReadNumberFromTo(string message, int From, int To) {
	int number;
	do
	{
		cout << message;
		cin >> number;

	} while (number < From || number > To);
	return number;
}

int RandomNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

enRockPaperScissors ReadAChoice(int n)
{
	switch (n)
	{
	case 1:
		return enRockPaperScissors::Rock;

	case 2:
		return enRockPaperScissors::Paper;

	case 3:
		return enRockPaperScissors::Scissor;

	default:
		return enRockPaperScissors::Rock;
	}
}

enRoundResult RoundResult(int PlayerChoice, int ComputerChoice)
{
	if (PlayerChoice - ComputerChoice == 1 || PlayerChoice - ComputerChoice == -2)
		return enRoundResult::PlayerWins;

	else if (PlayerChoice == ComputerChoice)
		return enRoundResult::Draw;
	else
		return enRoundResult::ComputerWins;
}

enRockPaperScissors PlayerChoic() {
	return ReadAChoice(ReadNumberFromTo("Your Choice : [1]:Rock , [2]:Paper , [3]:Scissors ? ", 1, 3));
}

enRockPaperScissors ComputerChoic() {
	return ReadAChoice(RandomNumber(1, 3));
}

string ChoiceName(enRockPaperScissors choice)
{
	switch (choice)
	{
	case enRockPaperScissors::Rock:
		return "Rock";

	case enRockPaperScissors::Paper:
		return "Paper";

	case enRockPaperScissors::Scissor:
		return "Scissor";

	default:
		return "Unknown";
	}
}

string ResultName(enRoundResult Result)
{
	switch (Result)
	{
	case enRoundResult::PlayerWins:
		return "Player Win ";

	case enRoundResult::ComputerWins:
		return "Computer Win ";

	case enRoundResult::Draw:
		return "[No Winner] ";

	default:
		return "[No Winner] ";
	}
}

stRoundInfo StartARound()
{
	stRoundInfo RoundInfo;
	RoundInfo.Player1Choice = PlayerChoic();
	RoundInfo.ComputerChoice = ComputerChoic();
	RoundInfo.Result = RoundResult(RoundInfo.Player1Choice, RoundInfo.ComputerChoice);
	return RoundInfo;
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << "Player1 Choice   : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice  : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner     : " << ResultName(RoundInfo.Result) << endl;
	switch (RoundInfo.Result)
	{
	case enRoundResult::PlayerWins:
		system("color 2F");
		break;

	case enRoundResult::ComputerWins:
		system("color 4F");
		cout << "\a";
		break;

	case enRoundResult::Draw:
		system("color 6F");
		break;
	}
	cout << "\n---------------------------------------------------------\n";
}

int ReadHowManyRounds()
{
	return ReadNumberFromTo("How Many Rounds 1 to 10 ? ", 1, 10);
}

void ResetScreen()
{
	system("cls");
	system("color 07");
}

bool AskYesNoQ(string message)
{
	char Answer;
	cout << message;
	cin >> Answer;
	return (Answer == 'Y' || Answer == 'y');
}

void ShowGameOverScreen()
{
	cout << "\n             ------------------------------------------------------------------\n";
	cout << "                                  +++ G a m e O v e r  +++                      ";
	cout << "\n             ------------------------------------------------------------------\n";
}

void ShowFinalGameResults(stGameResults GameResults)
{
	int GameRounds = GameResults.ComputerWon + GameResults.PlayerWon + GameResults.DrawTimes;
	cout << "\n                 -------------------[Game Result]-----------------------\n";
	cout << "                        Game Rounds        : " << GameRounds << endl;
	cout << "                        Player1 won times  : " << GameResults.PlayerWon << endl;
	cout << "                        Computer won times : " << GameResults.ComputerWon << endl;
	cout << "                        Draw times         : " << GameResults.DrawTimes << endl;
	cout << "                        Final Winner       : ";
	if (GameResults.PlayerWon > GameResults.ComputerWon)
	{
		cout << "you won !!!" << endl;
		system("color 2F");
	}
	else if (GameResults.PlayerWon < GameResults.ComputerWon)
	{
		cout << "you lose , a machine beat you ..." << endl;
		system("color 4F");
	}
	else
	{
		cout << "It's basically a draw ,. " << endl;
		system("color 6F");
	}
}

void PlayGame()
{
	int n = ReadHowManyRounds();

	stRoundInfo Round;
	stGameResults Results;

	for (int i = 1; i <= n; i++)
	{
		cout << "\nRound [" << i << "]" << " begins : " << endl;
		Round = StartARound();
		cout << "\n------------------Round[" << i << "]------------------" << endl;
		PrintRoundResult(Round);

		switch (Round.Result)
		{
		case enRoundResult::PlayerWins:
			Results.PlayerWon++;
			break;

		case enRoundResult::ComputerWins:
			Results.ComputerWon++;
			break;

		case enRoundResult::Draw:
			Results.DrawTimes++;
			break;
		}
	}
	ShowGameOverScreen();
	ShowFinalGameResults(Results);
}

void StartGame()
{
	bool PlayAgain;
	do
	{
		ResetScreen();
		PlayGame();
		
		PlayAgain = AskYesNoQ("\nDo you want to play again ? Y/N? ");

	} while (PlayAgain);
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
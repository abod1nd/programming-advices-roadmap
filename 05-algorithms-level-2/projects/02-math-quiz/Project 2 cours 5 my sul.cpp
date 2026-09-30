#include<iostream>
#include<cmath>
#include <cstdlib>
#include <string> 
using namespace std;
enum enQuestionLevel
{
	Easy = 1, Mid = 2, Hard = 3, Mix = 4

};

enum enOperationType
{
	Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5

};

struct stQuestionInfo
{
	int Num1 = 0, Num2 = 0;
	enQuestionLevel Level;
	enOperationType  OpType;
	int CorrectAns = 0;
	int PlayerAnswer = 0;
	bool AnswerWasRight = false;
};

struct stQuizInfo
{
	int NumOfQuestions = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	short NumOfRightAns = 0;
	short NumOfWrongAns = 0;
};

int RandomNumber(int From, int To)
{
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int ReadNumberFromTo(string message, int From, int To) {
	int number;
	do
	{
		cout << message;
		cin >> number;

	} while (number < From || number > To);
	return number;
}

char OperationSymbol(enOperationType operationType)
{
	switch (operationType)
	{
	case enOperationType::Add:
		return '+';
	case enOperationType::Sub:
		return '-';
	case enOperationType::Mul:
		return '*';
	case enOperationType::Div:
		return '/';
	default:
		return '?';
	}

}

void ResetScreen()
{
	system("cls");
	system("color 07");
}

enOperationType setOperationType()
{
	return (enOperationType)ReadNumberFromTo("Enter Questions Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ", 1, 5);
}

enQuestionLevel setQuestionLevel()
{
	return (enQuestionLevel)ReadNumberFromTo("Enter Questions Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ? ", 1, 4);
}

stQuizInfo FillQuizInfo()
{
	stQuizInfo QuizInfo;
	QuizInfo.NumOfQuestions = ReadNumberFromTo("How many Questions do you want to answer ? ", 1, 10);
	QuizInfo.OperationType = setOperationType();
	QuizInfo.QuestionLevel = setQuestionLevel();

	return QuizInfo;
}

int GetFirstRandomNum(enQuestionLevel QuestionLevel)
{
	int n = 0;
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		n = RandomNumber(1, 9);return n;

	case enQuestionLevel::Mid:
		n = RandomNumber(1, 6);return n;

	case enQuestionLevel::Hard:
		n = RandomNumber(10, 99);return n;

	default:
		n = RandomNumber(1, 9);return n;
	}
}

int GetSecoundNum(enQuestionLevel QuestionLevel)
{
	int n = 0;
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		n = RandomNumber(1, 9);return n;

	case enQuestionLevel::Mid:
		n = RandomNumber(10, 99);return n;

	case enQuestionLevel::Hard:
		n = RandomNumber(10, 99);return n;

	default:
		n = RandomNumber(1, 9);return n;
	}
}

int GetCorrectAns(int num1, int num2, char OpType)
{
	switch (OpType)
	{
	case '+':
		return num1 + num2;
	case'-':
		return num1 - num2;
	case'*':
		return num1 * num2;
	case'/':
		return num1 / num2;
	case'?':
		return num1 + num2;
	default:
		return num1 + num2;
	}

}

int GetPlayerAns()
{
	int n;
	cin >> n;
	return n;

}

string OperationName(enOperationType OpType)
{

	string arr[5] = { "Add","Sub","Mul","Div","MixOp" };
	return arr[OpType - 1];
}

string LevelName(enQuestionLevel QLevel)
{
	string arr[4] = { "Easy","Mid","Hard","Mix" };
	return arr[QLevel - 1];
}

bool CheckAnswer(int PlayerAns, int CorrectAns)
{
	return (PlayerAns == CorrectAns);
}

void PrintQuestion(int num1, int num2, char OpType)
{
	cout << num1 << endl << num2 << " " << OpType << endl << "-----------" << endl;
}

void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

void PrintQustionResult(bool n, int RightAns)
{
	if (n)
	{
		cout << "Right Answer :-) \n\n" << endl;
		SetScreenColor(n);

	}
	else
	{
		cout << "Wrong Answer :-( " << endl;
		SetScreenColor(n);
		cout << "The right answer is : " << RightAns << endl;
	}
}

stQuestionInfo MakeQuestion(stQuizInfo QuizInfo)
{
	stQuestionInfo QuestionInfo;


	if (QuizInfo.QuestionLevel == Mix)
		QuestionInfo.Level = (enQuestionLevel)RandomNumber(1, 3);
	else
		QuestionInfo.Level = QuizInfo.QuestionLevel;


	if (QuizInfo.OperationType == MixOp)
		QuestionInfo.OpType = (enOperationType)RandomNumber(1, 4);
	else
		QuestionInfo.OpType = QuizInfo.OperationType;


	QuestionInfo.Num1 = GetFirstRandomNum(QuestionInfo.Level);
	QuestionInfo.Num2 = GetSecoundNum(QuestionInfo.Level);

	char n = OperationSymbol(QuestionInfo.OpType);
	PrintQuestion(QuestionInfo.Num1, QuestionInfo.Num2, n);
	QuestionInfo.PlayerAnswer = GetPlayerAns();
	QuestionInfo.CorrectAns = GetCorrectAns(QuestionInfo.Num1, QuestionInfo.Num2, n);
	QuestionInfo.AnswerWasRight = CheckAnswer(QuestionInfo.PlayerAnswer, QuestionInfo.CorrectAns);
	PrintQustionResult(QuestionInfo.AnswerWasRight, QuestionInfo.CorrectAns);
	return QuestionInfo;
}

stQuizInfo MakeQuiz()
{
	stQuizInfo QuizInfo;
	stQuestionInfo QuestionInfo;
	QuizInfo = FillQuizInfo();


	for (int i = 1; i <= QuizInfo.NumOfQuestions; i++)
	{
		cout << "\n\nQuestion [" << i << "/" << QuizInfo.NumOfQuestions << "]\n" << endl;
		QuestionInfo = MakeQuestion(QuizInfo);

		if (QuestionInfo.AnswerWasRight)
			QuizInfo.NumOfRightAns++;

		else
			QuizInfo.NumOfWrongAns++;

	}
	return QuizInfo;
}

bool CheckPassOrFail(int numR, int numW)
{
	if (numR >= numW) return true;
	else return false;
}

void ShowQuizResult(stQuizInfo QuizInfo)
{

	if (CheckPassOrFail(QuizInfo.NumOfRightAns, QuizInfo.NumOfWrongAns))
	{
		cout << "\n\n--------------------------------------------------\n";
		cout << "  Final  Results  is  PASS  (●'◡'●) " << endl;
		cout << "--------------------------------------------------\n\n";
	}
	else
	{
		cout << "\n\n--------------------------------------------------\n";
		cout << "  Final  Results  is  FAIL  ≡(▔﹏▔)≡ " << endl;
		cout << "--------------------------------------------------\n\n";
	}
	cout << "Number of Questions     : " << QuizInfo.NumOfQuestions << endl;
	cout << "Questions Level         : " << LevelName(QuizInfo.QuestionLevel) << endl;
	cout << "OpType                  : " << OperationName(QuizInfo.OperationType) << endl;
	cout << "Number of Right Answers : " << QuizInfo.NumOfRightAns << endl;
	cout << "Number of Wrong Answers : " << QuizInfo.NumOfWrongAns << endl;
	cout << "\n\n--------------------------------------------------\n";

}

bool AskYesNoQ(string message)
{
	char Answer;
	cout << message;
	cin >> Answer;
	cout << "\n\n";
	return (Answer == 'Y' || Answer == 'y');
}

void PlayQuiz()
{
	bool PlayAgain;

	do
	{
		ResetScreen();
		stQuizInfo QuizInfo = MakeQuiz();
		ShowQuizResult(QuizInfo);
		PlayAgain = AskYesNoQ("\nDo you want to play again ? Y/N? ");
	} while (PlayAgain);

}

int main()
{
	srand((unsigned)time(NULL));

	PlayQuiz();
	return 0;

}
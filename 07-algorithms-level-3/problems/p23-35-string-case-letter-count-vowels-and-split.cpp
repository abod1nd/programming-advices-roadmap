#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// ===================== Input =====================

string ReadString(string Message)
{
    string Line;

    cout << Message << endl;
    getline(cin >> ws, Line);

    return Line;
}


char ReadChar(string Message)
{
    char Letter;

    cout << Message << endl;
    cin >> Letter;

    return Letter;
}

// ===================== Char Case Helpers =====================

char UppercaseLetter(char Letter)
{
    if (Letter <= 122 && Letter >= 97)
        return char(Letter - 32);
    else
        return Letter;
}


char LowercaseLetter(char Letter)
{
    if (Letter <= 90 && Letter >= 65)
        return char(Letter + 32);
    else
        return Letter;
}

// ===================== P24: Upper First Letter of Each Word =====================

string UpperFirstLetterOfEachWord(string Line)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Line.length(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
            Line[i] = UppercaseLetter(Line[i]);

        IsFirstLetter = (Line[i] == ' ');
    }
    return Line;
}

// ===================== P25: Lower First Letter of Each Word =====================

string LowerFirstLetterOfEachWord(string Line)
{
    bool IsFirstLetter = true;

    for (short i = 0; i < Line.length(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
            Line[i] = LowercaseLetter(Line[i]);

        IsFirstLetter = (Line[i] == ' ');
    }
    return Line;
}

// ===================== P26: Upper / Lower All Letters =====================

string UpperAllLine(string Line)
{
    for (short i = 0; i < Line.length(); i++)
    {
        Line[i] = UppercaseLetter(Line[i]);
    }
    return Line;
}


string LowerAllLine(string Line)
{
    for (short i = 0; i < Line.length(); i++)
    {
        Line[i] = LowercaseLetter(Line[i]);
    }
    return Line;
}

// ===================== P27: Invert Char Case =====================

char InvertChar(char Letter)
{
    return isupper(Letter) ? LowercaseLetter(Letter) : UppercaseLetter(Letter);
}

// ===================== P28: Invert All Letters Case =====================

string InvertAllLine(string Line)
{
    for (short i = 0; i < Line.length(); i++)
    {
        Line[i] = InvertChar(Line[i]);
    }
    return Line;
}

// ===================== P29 - P33: Letter Types (Count / Check) =====================

enum enWhatToCount
{
    SmallLetters = 1,
    CapitalLetters = 2,
    AllLetters = 3,
    SpecificLetterMatchCase = 4,
    SpecificLetterNotMatchCase = 5,
    Vowel = 6
};


bool IsLetterVowel(char Letter)
{
    Letter = LowercaseLetter(Letter);
    return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
}


bool IsLetterOfType(char Letter, enWhatToCount WhatToCount, char SearchLetter = ' ')
{
    switch (WhatToCount)
    {
    case enWhatToCount::SmallLetters:
        return islower(Letter);

    case enWhatToCount::CapitalLetters:
        return isupper(Letter);

    case enWhatToCount::SpecificLetterMatchCase:
        return (Letter == SearchLetter);

    case enWhatToCount::SpecificLetterNotMatchCase:
        return (Letter == SearchLetter) || (Letter == InvertChar(SearchLetter));

    case enWhatToCount::Vowel:
        return IsLetterVowel(Letter);

    default:
        return isalpha(Letter); // isalpha دالة وظيفتها تتأكد اذا "حرف" مو "رمز" وهي بوليانية
    }
}


int CountLetters(string Line, enWhatToCount WhatToCount = enWhatToCount::AllLetters, char SearchLetter = ' ')
{
    int Counter = 0;

    for (short i = 0; i < Line.length(); i++)
    {
        if (IsLetterOfType(Line[i], WhatToCount, SearchLetter))
            Counter++;
    }
    return Counter;
}

// ===================== P34: Print Letters of Type =====================

void PrintLetters(string Line, enWhatToCount WhatToPrint)
{
    for (short i = 0; i < Line.length(); i++)
    {
        if (IsLetterOfType(Line[i], WhatToPrint))
            cout << Line[i] << "\t";
    }
}

// ===================== P35: Print Each Word in String =====================

vector<string> SplitString(string Line, string Delim = " ")
{
    vector<string> vWords;
    string Word;
    size_t Pos = 0;

    while ((Pos = Line.find(Delim)) != string::npos)
    {
        Word = Line.substr(0, Pos);

        if (Word != "")
            vWords.push_back(Word);

        Line.erase(0, Pos + Delim.length());
    }

    if (Line != "")
        vWords.push_back(Line);

    return vWords;
}


void PrintEachWordInString(string Line)
{
    cout << "\nYour string words are:\n\n";

    for (const string& Word : SplitString(Line))
    {
        cout << Word << endl;
    }
}

// ===================== Main =====================

int main()
{
    //P24
    cout << "\n---------- P24: Upper First Letter of Each Word ----------\n";
    string S1 = ReadString("Please enter a string to upper first letter of each word : ");
    cout << "\nString after conversion:\n";
    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;


    //P25
    cout << "\n---------- P25: Lower First Letter of Each Word ----------\n";
    string S2 = ReadString("Please enter a string to lower first letter of each word : ");
    cout << "\nString after conversion:\n";
    S2 = LowerFirstLetterOfEachWord(S2);
    cout << S2 << endl;


    //P26
    cout << "\n---------- P26: Upper / Lower All Letters ----------\n";
    string S3 = ReadString("Please enter a string : ");
    cout << "\nString after Upper:\n";
    S3 = UpperAllLine(S3);
    cout << S3 << endl;
    cout << "\nString after Lower:\n";
    S3 = LowerAllLine(S3);
    cout << S3 << endl;


    //P27
    cout << "\n---------- P27: Invert Char Case ----------\n";
    char C = ReadChar("Please enter a character : ");
    cout << "\nChar after inverting case :\n";
    C = InvertChar(C);
    cout << C << endl;


    //P28
    cout << "\n---------- P28: Invert All Letters Case ----------\n";
    string S4 = ReadString("Please enter a string : ");
    cout << "\nString after inverting all letters case :\n";
    S4 = InvertAllLine(S4);
    cout << S4 << endl;


    //P29
    cout << "\n---------- P29: Count Capital / Small Letters ----------\n";
    string S5 = ReadString("Please enter a string : ");
    cout << "\nString Length         = " << S5.length();
    cout << "\nCapital Letters Count = " << CountLetters(S5, enWhatToCount::CapitalLetters);
    cout << "\nSmall Letters Count   = " << CountLetters(S5, enWhatToCount::SmallLetters);
    cout << "\nAll Letters Count     = " << CountLetters(S5) << endl;


    //P30
    cout << "\n---------- P30: Count Specific Letter ----------\n";
    char SearchChar1 = ReadChar("Please enter a character : ");
    cout << "\nLetter '" << SearchChar1 << "' Count = "
        << CountLetters(S5, enWhatToCount::SpecificLetterMatchCase, SearchChar1) << endl;


    //P31
    cout << "\n---------- P31: Count Letter (Match Case or Not) ----------\n";
    char SearchChar2 = ReadChar("Please enter a character : ");
    if (isalpha(SearchChar2))
    {
        cout << "\nLetter '" << SearchChar2 << "' Or '" << InvertChar(SearchChar2)
            << "' Count = " << CountLetters(S5, enWhatToCount::SpecificLetterNotMatchCase, SearchChar2) << endl;
    }
    else
    {
        cout << "\nLetter '" << SearchChar2 << "' Count = "
            << CountLetters(S5, enWhatToCount::SpecificLetterNotMatchCase, SearchChar2) << endl;
    }


    //P32
    cout << "\n---------- P32: Check Vowel ----------\n";
    char CharToCheck = ReadChar("Please enter a character : ");
    if (IsLetterOfType(CharToCheck, enWhatToCount::Vowel))
        cout << "\nYES: Letter '" << CharToCheck << "' is vowel\n";
    else
        cout << "\nNO: Letter '" << CharToCheck << "' is NOT vowel\n";


    //P33
    cout << "\n---------- P33: Count Vowels ----------\n";
    string S6 = ReadString("Please enter a string : ");
    cout << "\nNumber of vowels is : " << CountLetters(S6, enWhatToCount::Vowel) << endl;


    //P34
    cout << "\n---------- P34: Print Vowels ----------\n";
    cout << "\nVowels in string are : ";
    PrintLetters(S6, enWhatToCount::Vowel);
    cout << endl;


    //P35
    cout << "\n---------- P35: Print Each Word in String ----------\n";
    string S7 = ReadString("Please enter a string : ");
    PrintEachWordInString(S7);

    return 0;
}
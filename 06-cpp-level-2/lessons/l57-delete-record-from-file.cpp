#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


void LoadDataFromFileToVector(string FileName, vector<string>& vectorContent)
{
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::in);
	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vectorContent.push_back(Line);
		}
		MyFile.close();
	}
}
void SaveVectorToFile(string FileName, vector<string>&vectorContent)
{
	fstream MyFile;
	MyFile.open("MyFile.txt", ios::out);
	if (MyFile.is_open())
	{
		for (string &Line : vectorContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		MyFile.close();
	}
}
void DeletDataFromFile(string FileName, string ignor)
{
	vector <string >vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);
	for (string& line : vFileContent)
	{
		if (line.find(ignor) != string::npos)
		{
			line = "";
		}

	}
	SaveVectorToFile(FileName, vFileContent);
}
void UpdatDataFromFile(string FileName, string ignor,string Update)
{
	vector <string >vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);
	for (string& line : vFileContent)
	{
		if (line.find(ignor) != string::npos)
		{
			line = Update;
		}

	}
	SaveVectorToFile(FileName, vFileContent);
}
void PrintFileContent(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))
		{
			cout << line << endl;
		}
		MyFile.close();
	}
}
int main()
{
	cout << "File befor delet : " << endl;
	PrintFileContent("MyFile.txt");
	DeletDataFromFile("MyFile.txt", "if");
	cout << "File after delet : \n\n\n" << endl;
	PrintFileContent("MyFile.txt");


}
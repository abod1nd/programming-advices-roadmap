#include<iostream>
#include <string>
using namespace std;
enum enPassFail{Pass =1,Fail=2};
int ReadMark() {
	int mark;
	cout << "please enter your mark  " << endl;
	cin >> mark;
	return mark;
}
enPassFail checkmark(int mark) {
	if (mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}
void printResult(int mark) {
	if (checkmark(mark) == enPassFail::Pass) 
		cout << "you pass " << endl;
	else 
		cout << "you fail " << endl;
}


int main() {
	
	printResult(ReadMark());

	return 0;


}
#include<iostream>
using namespace std;
int RandomNumber(int From, int To) {
	int RandNum = 0;
	RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
int main() {
	srand((unsigned)time(NULL));
	cout << RandomNumber(23, 342) << endl;
	cout << RandomNumber(23, 342) << endl;
	cout << RandomNumber(23, 342) << endl;
	cout << RandomNumber(23, 342) << endl;
	cout << RandomNumber(23, 342) << endl;


	return 0;
}
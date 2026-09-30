#include<iostream>
using namespace std;
void PrintAllWords() {
	for (int i = 65;i <= 90;i++) {
	

		for (int j = 65;j <= 90;j++) {
			

			for (int h = 65;h <= 90;h++) {
				cout << char(i);
				cout << char(j);
				cout << char(h)<<endl;
				}
		}
	}
}
int main() {
	PrintAllWords();
	return 0;
}
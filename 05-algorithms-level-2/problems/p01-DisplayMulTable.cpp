#include<iostream>
using namespace std;
void DisplayMulTable() {
	cout << "\t\t\t multipliaction Ta From 1 to 10" << endl;
	int c = 1;
	for (int c = 1; c <=10; c++)
	{
		cout << "\t" << c;
	}
	cout << "\n----------------------------------------------------------------------------------------------------\n";
	for (int i = 1;i <= 10;i++) {
		cout << i << "   | \t";
		
		for (int j = 1;j <= 10;j++) {
				
			cout << j * i << "\t";
			

		}
		cout << endl;
		
	}
}
int main() {
	DisplayMulTable();
	return 0;
}
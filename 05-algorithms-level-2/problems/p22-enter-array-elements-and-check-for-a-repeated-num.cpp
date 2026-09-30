#include<iostream>
using namespace std;
int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message << endl;
		cin >> number;

	} while (number <= 0);
	return number;
}

void ReadArrayElement(int size,int arr[]) {
	
	cout << "Enter array elements : " << endl;

	int conter = 1;
	for (int i = 0;i < size;i++) {
		 conter =conter+ i;
		cout << "Element[" << conter << "] : ";
		cin >> arr[i];
	}
	cout << "Original array : ";
	for (int i = 0;i < size;i++) {
		cout << arr[i];
	}
	cout << endl;
	int n;
	cout << "Please enter the number thet you want to check : ";
	cin >> n;

	int frecuncy=0;
	for (int i = 0;i < size;i++) {
		if (arr[n] == arr[i]) frecuncy++;
	}
	cout << n << " is repeated " << frecuncy << " time(s)" << endl;


}
int main() {
	const int size = 5;
	int arr[5];
	ReadArrayElement(size, arr);
}
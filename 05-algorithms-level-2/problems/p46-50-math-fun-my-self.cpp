#include<iostream>
#include<cmath>
using namespace std;
float GetAfterTheComma(float n) {
	return n - int(n);
}
int MyRound(float n) {
	float s = GetAfterTheComma(n);
	if (n >= 0) {
		if (s >= 0.5) 
			return int(n) + 1;
		else 
			return int(n);
	}
	else {
		if (s <= -0.5)
			return int(n)-1;
		else 
			return int(n) ;
	}
}
int MyFloor(float n) {
	float s = GetAfterTheComma(n);
	if (n >= 0)
		return int(n);
	else
			return int(n) - 1;
		
	
}
int MyCeil(float n) {
	float s = GetAfterTheComma(n);
	if (n >= 0)
		return int(n) + 1;
	else
		return int(n);


}
float ReadNumber(string message) {
	float number;
		cout << message << endl;
		cin >> number;

	return number;
}

float MyABS(float Number) {
	if (Number > 0) 
		return Number;
	else 
		return Number / -1;
}
float MySqrt(int n) {
	return pow(n, 0.5);

}
int main() {
	float n = ReadNumber("Enter a float number : ");
	cout << "My  sqrt Result : " << MySqrt(n) << endl;
	cout << "C++ Round Result : " << sqrt(n) << endl;

	return 0;
}

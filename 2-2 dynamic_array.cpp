#include <iostream>
using namespace std;

int main() {
	int* p = new int[10];
	int sum = 0;
	double avr;

	cout << "정수 10개 입력해주세요." << endl;
	for (int i = 0; i < 10; i++) {
		cin >> p[i];
		sum += p[i];
	}
	avr = sum / 10;

	cout << "평균 " << avr;

	delete[] p;
}
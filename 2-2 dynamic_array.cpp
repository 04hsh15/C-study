#include <iostream>
using namespace std;

int main() {
	int* p = new int[10];
	int sum = 0;
	double avr;

	cout << "���� 10�� �Է����ּ���." << endl;
	for (int i = 0; i < 10; i++) {
		cin >> p[i];
		sum += p[i];
	}
	avr = sum / 10;

	cout << "��� " << avr;

	delete[] p;
}
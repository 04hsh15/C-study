#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int* ptr; //�������� ptr�̶�� �����͸� ����
	ptr = &a; //ptr�� a�� �ּҰ��� ����

	cout << "���� a�� �ּҴ� : " << ptr << endl; //�ּҸ� ����� ���� �����Ϳ� �ּҰ��� �����Ƿ� �����͸� ��
	cout << "a�� ���� : " << *ptr; //���� ����� ���� �����͸� �տ� *�� �ٿ���
}
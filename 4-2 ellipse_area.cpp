#include <iostream>
using namespace std;

class ovalArea { //ovalArea Ŭ���� ����
private:
	int width; //�ʺ� ������ ���� ����
	int height; //���� ������ ���� ����
	double area; //���� ������ ���� ����
public:
	ovalArea(); //�Ű����� ���� ������
	ovalArea(int w, int h); //�Ű����� �ִ� ������
	~ovalArea(); //�Ҹ���
	int getA(); //A���� ������ �Լ�
	int getB(); //B���� ������ �Լ�
	double Area(); //���� ��� �� ���̰��� ������ �Լ�
	void set(int w, int h); //�Ű����� ���� �����ڿ� �ʺ�� ���̸� �������� �Լ�
};

ovalArea::ovalArea() {
	width = 1; //�ƹ� �ʱⰪ�̳� ����
	height = 1; //�ƹ� �ʱⰪ�̳� ����
}

ovalArea::ovalArea(int w, int h) {
	width = w; //�Է��� ���� �ʺ� ����
	height = h; //�Է��� ���� ���̿� ����
}

/*ovalArea::ovalArea() : ovalArea(1, 1) {}
ovalArea::ovalArea(int w, int h) {
	width = w;
	height = h;
}*/

ovalArea::~ovalArea() {
	cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl; //�Ҹ� �� ���� ���
}

inline int ovalArea::getA() { //A�� ����
	return width / 2;
}

inline int ovalArea::getB() { //B�� ����
	return height / 2;
}

double ovalArea::Area() { //���� ��� �� ���� ������ area ����
	area = getA() * getB() * 3.14;
	return area;
}

void ovalArea::set(int w, int h) { //�ŰԺ��� ���� �����ڿ� �ʺ�� ���̸� �������ֱ� ���� set
	width = w;
	height = h;
}

int main() {
	ovalArea a; //���� a ���� �� ovalArea() ������ ȣ��
	a.set(10, 20); //a�� �ʺ�� ���� ����
	ovalArea b(3, 4); //��ü b ���� �� ovalArea(int w, int h) ������ ȣ��

	cout << "Ÿ���� ���̴� " << a.Area() << "�̴�." << endl; //a�� ���� ���
	cout << "Ÿ���� ���̴� " << b.Area() << "�̴�." << endl; //b�� ���� ���
}
#include <iostream>
#include <memory>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Test {
public:
	char* name;
	int grade;

	void printINFO() {
		cout << "이름" << name << endl;
		cout << "학년" << grade << endl;
	}

	Test() {
		cout << "생성자 호출" << endl;
	}

	Test(const Test& _Value) {
		cout << "복사 생성자 호출" << endl;
		grade = _Value.grade;
		name = new char[strlen(_Value.name) + 1];
		strcpy(name, _Value.name);
	}

	~Test() {
		cout << "소멸자 호출" << endl;
	}
};

int main() {
	Test A;
	A.name = new char[4];
	strcpy_s(A.name, 4, "SWU");
	A.grade = 1;

	A.printINFO();

	Test B = A;

	cout << "B = A 이후 A의 정보를 변경하면?" << endl;

	strcpy_s(A.name, 6, "SWUNI");
	A.grade = 3;

	A.printINFO();
	B.printINFO();
}
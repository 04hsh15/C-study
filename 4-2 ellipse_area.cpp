#include <iostream>
using namespace std;

class ovalArea { //ovalArea 클래스 선언
private:
	int width; //너비 저장할 변수 선언
	int height; //높이 저장할 변수 선언
	double area; //넓이 저장할 변수 선언
public:
	ovalArea(); //매개변수 없는 생성자
	ovalArea(int w, int h); //매개변수 있는 생성자
	~ovalArea(); //소멸자
	int getA(); //A값을 리턴할 함수
	int getB(); //B값을 리턴할 함수
	double Area(); //넓이 계산 후 넓이값을 리턴할 함수
	void set(int w, int h); //매개변수 없는 생성자에 너비와 높이를 설정해줄 함수
};

ovalArea::ovalArea() {
	width = 1; //아무 초기값이나 설정
	height = 1; //아무 초기값이나 설정
}

ovalArea::ovalArea(int w, int h) {
	width = w; //입력한 값을 너비에 대입
	height = h; //입력한 값을 높이에 대입
}

/*ovalArea::ovalArea() : ovalArea(1, 1) {}
ovalArea::ovalArea(int w, int h) {
	width = w;
	height = h;
}*/

ovalArea::~ovalArea() {
	cout << "Oval 소멸 : width = " << width << ", height = " << height << endl; //소멸 시 문구 출력
}

inline int ovalArea::getA() { //A값 리턴
	return width / 2;
}

inline int ovalArea::getB() { //B값 리턴
	return height / 2;
}

double ovalArea::Area() { //넓이 계산 후 넓이 저장한 area 리턴
	area = getA() * getB() * 3.14;
	return area;
}

void ovalArea::set(int w, int h) { //매게변수 없는 생성자에 너비와 높이를 설정해주기 위한 set
	width = w;
	height = h;
}

int main() {
	ovalArea a; //개세 a 선언 및 ovalArea() 생성자 호출
	a.set(10, 20); //a의 너비와 높이 설정
	ovalArea b(3, 4); //개체 b 선언 및 ovalArea(int w, int h) 생성자 호출

	cout << "타원의 넓이는 " << a.Area() << "이다." << endl; //a의 넓이 출력
	cout << "타원의 넓이는 " << b.Area() << "이다." << endl; //b의 넓이 출력
}
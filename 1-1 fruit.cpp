#include <iostream>//밑에서 쓰일 cout, cin, <<, >>를 사용하기 위함
#include <string>//밑에서 쓰일 string과 getline을 사용하기 위함
using namespace std;//std::를 생략할 수 있음

int main() {//프로그램 시작할 때 들어가야 하는 것
	string name;//크기 상관 없이 빈 문자열 스트링 객체를 생성함
	int apple, banana, orange, ea, price;//정수형을 닮을 수 있는 다섯 가지 빈 인트 객체 생성
	cout << "당신의 이름은 무엇입니까?";//<<이후의 말을 출력함
	getline(cin, name);//name에 이름을 입력 받고, 셋째 칸에 아무것도 쓰지 않았으므로 줄바꿈이 구분문자임
	cout << "반갑습니다. " << name << "님" << endl;//출력 다음 또 출력이 올 거라 줄바꿈을 해주어야 원하는 실행창이 나옴
	cout << "apple의 가격은 얼마입니까?";
	cin >> apple;//입력된 숫자를 apple에 넣음
	cout << "banana의 가격은 얼마입니까?";
	cin >> banana;
	cout << "orange의 가격은 얼마입니까?";
	cin >> orange;
	cout << "apple은 몇 개 있습니까?";
	cin >> ea;
	price = apple * ea;//값에 사과 가격*개수
	cout << "banana는 몇 개 있습니까?";
	cin >> ea;
	price += banana * ea;//값에 현재 price 값과 바나나 가격*개수를 더함
	cout << "orange는 몇 개 있습니까?";
	cin >> ea;
	price += orange * ea - 500;//값에 현재 price 값과 오렌지 가격*개수를 더하고 500원 할인 함
	cout << "총" << price << "원 입니다.";

	return 0;//프로그램 종료를 알림 사실 main이라 안 써도 됨
}
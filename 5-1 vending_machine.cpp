#include <iostream>
#include <string>
using namespace std;

class VendingMachine
{
private:
	string name; // 4번 음료 이름
	int price; // 4번 음료 가격
	int total = 0; // 음료 합산 값
public:
	VendingMachine() {}; // 생성자
	void purchase(double v1);
	void menu(); // 4번 음료 추가 전 메뉴판 출력
	void upgrademenu(); // 4번 음료 추가 후 메뉴판 출력
	string getName(); // 4번 음료 이름 반환
	double getPrice(); // 4번 음료 가격 반환
	double getTotal(); // 음료 합산 값 반환
	void setName(string n); // 4번 음료 이름에 접근해 값 수정
	void setPrice(int p); // 4번 음료 금액에 접근해 값 수정
	void setTotal(int t); // 음료 합산 값에 접근해 값 수정
	int returngap = 200; // 자판기 초기 내부 거스름돈(100원짜리) 개수
	int change; // 줄 거스름돈 개수
	int select; // 선택한 번호
	int money; // 입력한 지폐
};

void VendingMachine::purchase(double v1) {
	cout << "총 금액 : " << v1 << endl;
	cout << "지폐를 입력하세요 : ";
	here: // v1 > money일 때 값 재입력 받은 후 다시 v1과 money를 비교해야 해서 필요함
		cin >> money;
	
		if (v1 == money) { // v1 == money일 때 실행할 조건문
			cout << "거스름돈이 없습니다. 안녕히 가세요." << endl;
			cout << "기기에 남은 거스름돈(100원 개수) : " << returngap << endl;
			total = 0; // 합산 금액 초기화
		}

		if (v1 > money) { // v1 > money일 때 실행할 조건문
			cout << "금액이 부족합니다. 다시 넣어주세요. ";
			goto here; // here이 있는 곳으로 이동하여 money 재입력부터 시작
		}

		if (v1 < money) { // v1 < money일 때 실행할 조건문
			change = ( money - (int)v1 ) / 100; // 거스름돈 개수 계산해서 change에 저장
			if (money % 100 == 0) { // 100원으로 나눠떨어지게 넣었을 때 실행할 조건문
				if (returngap >= change) { // 자판기 속 거스름돈 개수가 모자르지 않을 때 실행할 조건문
					returngap -= change; // 자판기 속 거스름돈 개수에서 줘야 할 거스름돈 개수 뺀 것을 returngap에 새로 저장
					cout << "거스름돈입니다." << endl << "100원 : " << change << "개" << endl;
					cout << "기기에 남은 거스름돈(100원 개수) : " << returngap << endl;
				}
				if (returngap < change) { // 자판기 속 거스름돈 개수가 모자를 때 실행할 조건문
					returngap = 0; // 줄 수 있는 건 다 줘서 0됨
					cout << "거스름돈입니다." << endl;
					cout << "기기 내의 잔돈이 부족합니다. 010-0000-0000으로 연락주세요." << endl;
					cout << "기기에 남은 거스름돈(100원 개수) : " << returngap << endl << endl;
					system("PAUSE"); //계속하려면 아무 키나 누르십시오  .  .  .가 뜸(실행 예시 보여주실 때 있길래 넣음)
				}
			}
			else { // 100원으로 나눠떨어지지 않게 넣었을 때 실행할 조건문
				returngap -= change;
				cout << "거스름돈은 100원만 가능합니다." << endl;
				cout << "100원 : " << change << "개" << endl;
				cout << "기기에 남은 거스름돈(100원 개수) : " << returngap << endl;
			}
			total = 0; // 합산 금액 초기화
		}
}

void VendingMachine::menu() {
	cout << "==========SWING 자판기==========" << endl;
	cout << "1. 코카콜라 : 1200원" << endl << "2. 칠성 사이다 : 1400원" << endl;
	cout << "3. 미에로 화이바 : 1800원" << endl << "4. 준비 중" << endl;
	cout << "5. 계산" << endl << "6. 종료" << endl;
	cout << "추가할 음료 이름을 입력해주세요 : ";
	cin >> name;
	cout << "판매할 가격을 입력하세요 : ";
	cin >> price;
}

void VendingMachine::upgrademenu() {
	cout << "==========SWING 자판기==========" << endl;
	cout << "1. 코카콜라 : 1200원" << endl << "2. 칠성 사이다 : 1400원" << endl;
	cout << "3. 미에로 화이바 : 1800원" << endl;
	cout << "4." << getName() << " : " << getPrice() << "원" << endl;
	// 4번 음료의 이름과 금액을 return해주는 함수를 사용해 뜨게 만듦
	cout << "5. 계산" << endl << "6. 종료" << endl;
	cout << "번호를 선택해주세요 : ";
	cin >> select;
}

string VendingMachine::getName() {
	return name;
}

double VendingMachine::getPrice() {
	return price;
}

double VendingMachine::getTotal() {
	return total;
}

void VendingMachine::setName(string n) {
	name = n;
}

void VendingMachine::setPrice(int p) {
	price = p;
}

void VendingMachine::setTotal(int t) {
	total += t; // 합산 금액에 값을 축적해나가기 위함
}

int main() {
	VendingMachine vending; // VendingMachine의 객체 vending 선언
	VendingMachine* p = &vending; // vending의 객체 포인터로 p 사용

	int num; // 구매할 수량 입력받을 변수
	int value; // 4번 음료의 값을 저장할 변수
	double totalPrice; // 총금액을 저장할 변수

	p->menu(); // 4번 음료 입력 전 메뉴판 출력

	while (1) {
		p->upgrademenu(); // 4번 음료 입력 후 메뉴판 출력

		if (p->select == 1) { // 선택한 번호가 1일 때 실행할 조건문
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> num;
			p->setTotal(num * 1200); // 1번 음료를 고른 만큼 total에 금액 축적

		}

		if (p->select == 2) { // 선택한 번호가 2일 때 실행할 조건문
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> num;
			p->setTotal(num * 1400); // 2번 음료를 고른 만큼 total에 금액 축적
		}

		if (p->select == 3) { // 선택한 번호가 3일 때 실행할 조건문
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> num;
			p->setTotal(num * 1800); // 3번 음료를 고른 만큼 total에 금액 축적
		}

		if (p->select == 4) { // 선택한 번호가 4일 때 실행할 조건문
			cout << "구매할 수량을 입력해주세요 : ";
			cin >> num;

			value = p->getPrice(); // value에 4번 음료의 금액을 저장
			p->setTotal(num * value); // 4번 음료를 고른 만큼 total에 금액 축적
		}

		if (p->select == 5) { // 선택한 번호가 5일 때 실행할 조건문
			cout << "계산 중입니다. 기다려 주세요  .  .  .  ." << endl << endl;

			totalPrice= p->getTotal(); // totalPrice에 합산 금액 입력받음
			p->purchase(totalPrice); // 계산을 위한 purchase 함수 실행
		}

		if (p->select == 6) { // 선택한 번호가 6일 때 실행할 조건문
			break; // 종료해야하므로 반복문 빠져나감
		}
	}
}
#include <iostream>
#include <cstdlib> //rand(난수 생성)와 srand(난수 생성 시 시드값 설정) 함수 사용을 위함
#include <ctime> //time 함수 사용을 위함(현재 시간을 second 단위로 반환, srand와 함께 써서 리턴 값을 난수 생성 시 시드값으로 사용)
using namespace std;

class Random { //Random 클래스 생성
	int num[10]; //랜덤 정수를 저장할 배열 선언
public:
	Random(); //Random 생성자
	void next(); //0~32767 사이의 짝수 랜덤 정수를 출력할 함수
	void nextInRange(); //2~30 사이의 중복 없는 랜덤 정수를 출력할 함수
};

Random::Random() {
	cout << "--0에서 32767까지의 짝수 랜덤 정수 10개--" << endl;
	next();
	cout << endl;
	cout << "==2에서 30까지의 홀수 랜덤 정수 10개(단, 중복되는 값이 없어야 함)==" << endl;
	nextInRange();
}

void Random::next() {
	srand((unsigned int)time(NULL)); //srand로 난수 생성 시 시드 값 설정을 함. 또한 실행할 때마다 다른 정수가 나오게 하기 위해 time 사용

	for (int i = 0; i < 10; i++) { //배열에 랜덤 정수를 넣어줄 반복문
		num[i] = rand();

		if (num[i] % 2 == 1) //짝수가 아니면 i값을 감소시켜 아까와 동일한 인덱스에 다시 랜덤 정수를 넣어줘야 함
			i--;
	}

	for (int i = 0; i < 10; i++) //배열에 들어있는 랜덤 정수를 차례대로 출력할 반복문
		cout << num[i] << " ";

	cout << endl;
}

void Random::nextInRange() {
	srand((unsigned int)time(NULL)); //srand로 난수 생성 시 시드 값 설정을 함. 또한 실행할 때마다 다른 정수가 나오게 하기 위해 time 사용

	for (int i = 0; i < 10; i++) { //배열에 2~30 사이의 랜덤 정수를 넣어줄 반복문
		num[i] = rand() % (30 - 3) + 2;

		for (int k = 0; k < i; k++) { //중복인지 아닌지 조건문을 통해 확인해줄 반복문
			if (num[k] == num[i]) { //중복이면 i값을 감소시켜 아까와 동일한 인덱스에 다시 랜덤 정수를 넣어줘야 함
				i--;
				continue; //i값을 감소시킨 후라 다음 블록의 if문을 검사해줘봤자 이미 한 거라 할 필요가 없으니 continue를 써준 것. 없어도 되긴 함
			}
		}
		if (num[i] % 2 == 0) //랜덤 정수가 홀수면 i값을 감소시켜 아까와 동일한 인덱스에 다시 랜덤 정수를 넣어줘야 함
			i--;
	}

	for (int i = 0; i < 10; i++) //배열에 들어있는 랜덤 정수를 차례대로 출력할 반복문
		cout << num[i] << " ";

	cout << endl;
}

int main() {
	Random randomInt; //randomint 개체 선언 및 Random() 생성자 실행
}
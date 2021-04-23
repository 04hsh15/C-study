#include <iostream>
using namespace std;

int main() {
	int N, i, j, k; //차례대로 결과값 출력을 위해 입력받을 변수, 별 출력을 위해 입력받을 변수1과 변수2와 변수3

	cout << "규칙에 맞게 출력할 별의 개수를 입력하세요: ";
	cin >> N; //결과값 출력을 위해 N에 입력받음

	if (N == 1) { //1은 별 하나만 출력하고 끝날 것이므로 따로 조건문을 만듦
		cout << "*";
	}
	
	else if (N % 2 == 0) { //짝수일 때 실행할 조건문
		for (i = 0; i < N; i++) { //입력받은 N값만큼 반복할 것임
			for (j = 0; j < N / 2; j++) { //입력받은 N의 반만큼 별을 출력함
				cout << "* ";
			}
			cout << endl;
			for (k = 0; k < N / 2; k++) { //입력받은 N의 반만큼의 별을 또 출력함
				cout << " *";
			}
			cout << endl;
		}
	}

	else if (N % 2 == 1) { //홀수일 때 실행할 조건문
		for (i = 0; i < N; i++) { //입력받은 N값만큼 반복할 것임
			for (j = 0; j < N / 2 + 1; j++) { //입력받은 N/2+1만큼의 별을 출력함
				cout << "* ";
			}
			cout << endl;
			for (k = 0; k < N / 2; k++) { //입력받은 N의 반만큼의 별을 또 출력함
				cout << " *";
			}
			cout << endl;
		}
	}
}
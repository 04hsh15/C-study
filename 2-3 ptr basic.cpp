#include <iostream>
using namespace std;

int main() {
	int a = 10;
	int* ptr; //정수형의 ptr이라는 포인터를 선언
	ptr = &a; //ptr에 a의 주소값을 넣음

	cout << "변수 a의 주소는 : " << ptr << endl; //주소를 출력할 때는 포인터에 주소값이 들어갔으므로 포인터명만 씀
	cout << "a의 값은 : " << *ptr; //값을 출력할 때는 포인터명 앞에 *을 붙여줌
}
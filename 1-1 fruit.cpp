#include <iostream>//�ؿ��� ���� cout, cin, <<, >>�� ����ϱ� ����
#include <string>//�ؿ��� ���� string�� getline�� ����ϱ� ����
using namespace std;//std::�� ������ �� ����

int main() {//���α׷� ������ �� ���� �ϴ� ��
	string name;//ũ�� ��� ���� �� ���ڿ� ��Ʈ�� ��ü�� ������
	int apple, banana, orange, ea, price;//�������� ���� �� �ִ� �ټ� ���� �� ��Ʈ ��ü ����
	cout << "����� �̸��� �����Դϱ�?";//<<������ ���� �����
	getline(cin, name);//name�� �̸��� �Է� �ް�, ��° ĭ�� �ƹ��͵� ���� �ʾ����Ƿ� �ٹٲ��� ���й�����
	cout << "�ݰ����ϴ�. " << name << "��" << endl;//��� ���� �� ����� �� �Ŷ� �ٹٲ��� ���־�� ���ϴ� ����â�� ����
	cout << "apple�� ������ ���Դϱ�?";
	cin >> apple;//�Էµ� ���ڸ� apple�� ����
	cout << "banana�� ������ ���Դϱ�?";
	cin >> banana;
	cout << "orange�� ������ ���Դϱ�?";
	cin >> orange;
	cout << "apple�� �� �� �ֽ��ϱ�?";
	cin >> ea;
	price = apple * ea;//���� ��� ����*����
	cout << "banana�� �� �� �ֽ��ϱ�?";
	cin >> ea;
	price += banana * ea;//���� ���� price ���� �ٳ��� ����*������ ����
	cout << "orange�� �� �� �ֽ��ϱ�?";
	cin >> ea;
	price += orange * ea - 500;//���� ���� price ���� ������ ����*������ ���ϰ� 500�� ���� ��
	cout << "��" << price << "�� �Դϴ�.";

	return 0;//���α׷� ���Ḧ �˸� ��� main�̶� �� �ᵵ ��
}
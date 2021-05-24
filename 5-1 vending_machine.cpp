#include <iostream>
#include <string>
using namespace std;

class VendingMachine
{
private:
	string name; // 4�� ���� �̸�
	int price; // 4�� ���� ����
	int total = 0; // ���� �ջ� ��
public:
	VendingMachine() {}; // ������
	void purchase(double v1);
	void menu(); // 4�� ���� �߰� �� �޴��� ���
	void upgrademenu(); // 4�� ���� �߰� �� �޴��� ���
	string getName(); // 4�� ���� �̸� ��ȯ
	double getPrice(); // 4�� ���� ���� ��ȯ
	double getTotal(); // ���� �ջ� �� ��ȯ
	void setName(string n); // 4�� ���� �̸��� ������ �� ����
	void setPrice(int p); // 4�� ���� �ݾ׿� ������ �� ����
	void setTotal(int t); // ���� �ջ� ���� ������ �� ����
	int returngap = 200; // ���Ǳ� �ʱ� ���� �Ž�����(100��¥��) ����
	int change; // �� �Ž����� ����
	int select; // ������ ��ȣ
	int money; // �Է��� ����
};

void VendingMachine::purchase(double v1) {
	cout << "�� �ݾ� : " << v1 << endl;
	cout << "���� �Է��ϼ��� : ";
	here: // v1 > money�� �� �� ���Է� ���� �� �ٽ� v1�� money�� ���ؾ� �ؼ� �ʿ���
		cin >> money;
	
		if (v1 == money) { // v1 == money�� �� ������ ���ǹ�
			cout << "�Ž������� �����ϴ�. �ȳ��� ������." << endl;
			cout << "��⿡ ���� �Ž�����(100�� ����) : " << returngap << endl;
			total = 0; // �ջ� �ݾ� �ʱ�ȭ
		}

		if (v1 > money) { // v1 > money�� �� ������ ���ǹ�
			cout << "�ݾ��� �����մϴ�. �ٽ� �־��ּ���. ";
			goto here; // here�� �ִ� ������ �̵��Ͽ� money ���Էº��� ����
		}

		if (v1 < money) { // v1 < money�� �� ������ ���ǹ�
			change = ( money - (int)v1 ) / 100; // �Ž����� ���� ����ؼ� change�� ����
			if (money % 100 == 0) { // 100������ ������������ �־��� �� ������ ���ǹ�
				if (returngap >= change) { // ���Ǳ� �� �Ž����� ������ ���ڸ��� ���� �� ������ ���ǹ�
					returngap -= change; // ���Ǳ� �� �Ž����� �������� ��� �� �Ž����� ���� �� ���� returngap�� ���� ����
					cout << "�Ž������Դϴ�." << endl << "100�� : " << change << "��" << endl;
					cout << "��⿡ ���� �Ž�����(100�� ����) : " << returngap << endl;
				}
				if (returngap < change) { // ���Ǳ� �� �Ž����� ������ ���ڸ� �� ������ ���ǹ�
					returngap = 0; // �� �� �ִ� �� �� �༭ 0��
					cout << "�Ž������Դϴ�." << endl;
					cout << "��� ���� �ܵ��� �����մϴ�. 010-0000-0000���� �����ּ���." << endl;
					cout << "��⿡ ���� �Ž�����(100�� ����) : " << returngap << endl << endl;
					system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�  .  .  .�� ��(���� ���� �����ֽ� �� �ֱ淡 ����)
				}
			}
			else { // 100������ ������������ �ʰ� �־��� �� ������ ���ǹ�
				returngap -= change;
				cout << "�Ž������� 100���� �����մϴ�." << endl;
				cout << "100�� : " << change << "��" << endl;
				cout << "��⿡ ���� �Ž�����(100�� ����) : " << returngap << endl;
			}
			total = 0; // �ջ� �ݾ� �ʱ�ȭ
		}
}

void VendingMachine::menu() {
	cout << "==========SWING ���Ǳ�==========" << endl;
	cout << "1. ��ī�ݶ� : 1200��" << endl << "2. ĥ�� ���̴� : 1400��" << endl;
	cout << "3. �̿��� ȭ�̹� : 1800��" << endl << "4. �غ� ��" << endl;
	cout << "5. ���" << endl << "6. ����" << endl;
	cout << "�߰��� ���� �̸��� �Է����ּ��� : ";
	cin >> name;
	cout << "�Ǹ��� ������ �Է��ϼ��� : ";
	cin >> price;
}

void VendingMachine::upgrademenu() {
	cout << "==========SWING ���Ǳ�==========" << endl;
	cout << "1. ��ī�ݶ� : 1200��" << endl << "2. ĥ�� ���̴� : 1400��" << endl;
	cout << "3. �̿��� ȭ�̹� : 1800��" << endl;
	cout << "4." << getName() << " : " << getPrice() << "��" << endl;
	// 4�� ������ �̸��� �ݾ��� return���ִ� �Լ��� ����� �߰� ����
	cout << "5. ���" << endl << "6. ����" << endl;
	cout << "��ȣ�� �������ּ��� : ";
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
	total += t; // �ջ� �ݾ׿� ���� �����س����� ����
}

int main() {
	VendingMachine vending; // VendingMachine�� ��ü vending ����
	VendingMachine* p = &vending; // vending�� ��ü �����ͷ� p ���

	int num; // ������ ���� �Է¹��� ����
	int value; // 4�� ������ ���� ������ ����
	double totalPrice; // �ѱݾ��� ������ ����

	p->menu(); // 4�� ���� �Է� �� �޴��� ���

	while (1) {
		p->upgrademenu(); // 4�� ���� �Է� �� �޴��� ���

		if (p->select == 1) { // ������ ��ȣ�� 1�� �� ������ ���ǹ�
			cout << "������ ������ �Է����ּ��� : ";
			cin >> num;
			p->setTotal(num * 1200); // 1�� ���Ḧ �� ��ŭ total�� �ݾ� ����

		}

		if (p->select == 2) { // ������ ��ȣ�� 2�� �� ������ ���ǹ�
			cout << "������ ������ �Է����ּ��� : ";
			cin >> num;
			p->setTotal(num * 1400); // 2�� ���Ḧ �� ��ŭ total�� �ݾ� ����
		}

		if (p->select == 3) { // ������ ��ȣ�� 3�� �� ������ ���ǹ�
			cout << "������ ������ �Է����ּ��� : ";
			cin >> num;
			p->setTotal(num * 1800); // 3�� ���Ḧ �� ��ŭ total�� �ݾ� ����
		}

		if (p->select == 4) { // ������ ��ȣ�� 4�� �� ������ ���ǹ�
			cout << "������ ������ �Է����ּ��� : ";
			cin >> num;

			value = p->getPrice(); // value�� 4�� ������ �ݾ��� ����
			p->setTotal(num * value); // 4�� ���Ḧ �� ��ŭ total�� �ݾ� ����
		}

		if (p->select == 5) { // ������ ��ȣ�� 5�� �� ������ ���ǹ�
			cout << "��� ���Դϴ�. ��ٷ� �ּ���  .  .  .  ." << endl << endl;

			totalPrice= p->getTotal(); // totalPrice�� �ջ� �ݾ� �Է¹���
			p->purchase(totalPrice); // ����� ���� purchase �Լ� ����
		}

		if (p->select == 6) { // ������ ��ȣ�� 6�� �� ������ ���ǹ�
			break; // �����ؾ��ϹǷ� �ݺ��� ��������
		}
	}
}
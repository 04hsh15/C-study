#include <iostream>
using namespace std;

int main() {
	int answer, i, k, row, col;
	//���ʴ�� �¼� ���� ���ο� ���� ��, �迭 ����� ���� �ݺ����� �� ����1�� ����2, �Է¹��� ��� ��
	int seat[3][10] = { 0 }; //�¼� �迭�� ��� 0�� �־� ������� �ʾҴٴ� ǥ�ø� ��

	while (1) { //0�� �Է��ϱ� ������ ��� ������� �ϹǷ� ���� ���� �ݺ���
		cout << "�¼��� �����Ͻðڽ��ϱ�? (1 �Ǵ� 0) ";
		cin >> answer; //�¼� ���� ���ο� ���� ���� �Է� ����
		
		if (answer == 1) { //1�� �Է����� �� ������ �����ϴ� ���� ����� ���ǹ�
			cout << endl << "������ �¼��� ������ �����ϴ�." << endl;
			cout << "-----------------------------------" << endl;
			cout << "1 2 3 4 5 6 7 8 9 10" << endl;
			cout << "-----------------------------------" << endl;
			for (i = 0; i < 3; i++) { //�迭�� �� ����� ���� �ݺ���
				for (k = 0; k < 10; k++) { //�迭�� �� ����� ���� �ݺ���
					cout << seat[i][k] << " ";
				}
				cout << endl;
			}

			while (1) { //�̹� ����� ���� �����ϸ� �ٽ� �ݺ��ؾ��ϹǷ� ���� ���� �ݺ���
				cout << endl << "�� ��, �� ��° �¼��� �����Ͻðڽ��ϱ�? ";
				cin >> row >> col; //���ʴ�� ��� ���� �ֱ� ���� ���ڸ� �Է¹���
				cout << endl;

				if (seat[row - 1][col - 1] == 1) { //�ε����� 0���� �����ϱ� ������ ���� �Է��� �ſ� -1�� ����� ��
					//1�� �ԷµǾ� �ִٸ� �̹� ����� �¼��̱� ������ ������ �ݷ��� ���ǹ�
					cout << "�̹� ����� �ڸ��Դϴ�." << endl << endl;
				}

				else if (seat[row - 1][col - 1] == 0) { //0�� �ԷµǾ� �ִٸ� ���� ���� ���̱� ������ ������ ������ ���ǹ�
					seat[row - 1][col - 1] = 1; //������ �¼��� 1�� �־� ����Ǿ����� ǥ����
					cout << "����Ǿ����ϴ�." << endl;
					cout << "-----------------------------------" << endl;
					cout << "1 2 3 4 5 6 7 8 9 10" << endl;
					cout << "-----------------------------------" << endl;
					for (i = 0; i < 3; i++) {
						for (k = 0; k < 10; k++) {
							cout << seat[i][k] << " ";
						}
						cout << endl;
					}
					cout << endl;
					break; //���� �����Ƿ� ��� �¼��� �����ϰڳĴ� �ݺ������� Ż���ؾ� ��
				}
			}
		}
		else if (answer == 0) { //0�� �Է����� �� ���� ������ ���� ���� ���� ����Ǵ� ���ǹ� 
			cout << endl << "�¼� ���� ����";
			break; //�¼� ������ ���������Ƿ� �ݺ������� Ż���ؾ� ��
		}
		else { //0�� 1 �̿��� ���ڸ� �Է����� �� ���ǿ� ��߳��ٴ� ���� ������ ���ǹ�
			cout << endl << "1�� �Ǵ� 0���� �Է��ϼ���." << endl << endl;
		}
	}
}
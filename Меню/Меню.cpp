#include <iostream>
using namespace std;
int menu() {
	int choice;
	cout << "\n1 - ���� ��������� �������\n";
	cout << "2 - ������� ���������� ��������� ���������\n";
	cout << "3 - ����� �� ���������\n";
	cout << "��� �����: ";
	do {
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "�������� �����! ��������� ����: ";
		}
		else {
			cin.ignore(32767, '\n');
			if (choice < 1 || choice>3) {
				cout << "�������� �����! ��������� ����: ";
			}
		}
	} while (choice < 1 || choice>3);
	cout << endl;
	return choice;
}
void input() {
	cout << "���� ������\n";
}
void calculate() {
	cout << "������ ���������� ��������� ���������\n";
}
int main() {
	setlocale(LC_ALL, "rus");
	while (true) {
		int n = menu();
		switch (n) {
		case 1: input(); break;
		case 2: calculate(); break;
		case 3:
			cout << "���������� ���������...\n";
			system("pause");
			return 0;
		}
	}
}



#include <iostream>
using namespace std;
int menu() {
	int choice;
	cout << "\n1 - ввод элементов матрицы\n";
	cout << "2 - подсчет количества локальных минимумов\n";
	cout << "3 - выход из программы\n";
	cout << "Ваш выбор: ";
	do {
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Неверный выбор! Повторите ввод: ";
		}
		else {
			cin.ignore(32767, '\n');
			if (choice < 1 || choice>3) {
				cout << "Неверный выбор! Повторите ввод: ";
			}
		}
	} while (choice < 1 || choice>3);
	cout << endl;
	return choice;
}
void input() {
	cout << "Ввод данных\n";
}
void calculate() {
	cout << "Расчет количества локальных минимумов\n";
}
int main() {
	setlocale(LC_ALL, "rus");
	while (true) {
		int n = menu();
		switch (n) {
		case 1: input(); break;
		case 2: calculate(); break;
		case 3:
			cout << "Завершение программы...\n";
			system("pause");
			return 0;
		}
	}
}



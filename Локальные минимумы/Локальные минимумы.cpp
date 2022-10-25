#include <iostream>
using namespace std;
int menu() {
	int choice;
	cout << "\n1 - ввод элементов матрицы\n";
	cout << "2 - подсчет количества локальных минимумов\n";
	cout << "3 - печать матрицы\n";
	cout << "4 - выход из программы\n";
	cout << "Ваш выбор: ";
	do {
		cin >> choice;
		if (choice < 1 || choice>4) {
			cout << "Неверный выбор! Повторите ввод: ";
		}
	} while (choice < 1 || choice>4);
	cout << endl;
	return choice;
}
void input(int**&mas,int &n, int &m) {
	cout << "Введите число строк матрицы: ";
	cin >> n;
	cout << "Введите число столбцов матрицы: ";
	cin >> m;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	cout << "Вводите элементы матрицы построчно:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}
}
void print(int** mas, int n, int m) {
	cout << "Исходная матрица:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< mas[i][j]<<"\t";
		}
		cout << endl;
	}
}
void calculate(int** mas, int n, int m) {
	cout << "Расчет количества локальных минимумов\n";
	int amount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool min = true;
			int ibeg = (i - 1) >= 0 ? i - 1 : 0;
			int iend = (i + 1) < n ? i + 1 : n - 1;
			int jbeg = (j - 1)>= 0 ? j - 1 : 0;
			int jend = (j + 1) < m ? j + 1 : m - 1;
			for (int k =ibeg ; k <= iend; k++) {
			    for (int g = jbeg; g <=jend; g++) {
					if (!(k == i && g == j) && mas[k][g] < mas[i][j]) {
						min = false;
					}
				}
			}
			if (min) {
				amount++;
			}
		}
	}
	cout << "Количество локальных минимумов= " << amount << endl;
}
int main() {
	setlocale(LC_ALL, "rus");
	int n = 0, m = 0;//размеры матрицы
	int** mas = NULL;//указатель на матрицу
	while (true) {
		int k = menu();
		switch (k) {
		case 1: input(mas, n, m); break;
		case 2: calculate(mas,n,m); break;
		case 3:print(mas, n, m); break;
		case 4:
			cout << "Завершение программы...\n";
			if (mas != NULL) {
				for (int i = 0; i < n; i++) {
					delete[] mas[i];
				}
				delete[] mas;
			}
			mas = NULL;
			system("pause");
			return 0;
		}
	}
}

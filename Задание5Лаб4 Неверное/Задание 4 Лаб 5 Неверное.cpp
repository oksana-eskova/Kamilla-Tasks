#include <iostream>
using namespace std;
#include <time.h>

int main() {
	srand(time(0));
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "¬ведите число строк матрицы: ";
	cin >> n;
	cout << "¬ведите число столбцов матрицы: ";
	cin >> m;
	//cout << "¬водите элементы матрицы построчно:\n";
	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
	}
	int** result = new int* [n];
	for (int i = 0; i < n; i++) {
		result[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cin >> mas[i][j];
			mas[i][j] = rand() % 11;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int max = mas[i][j];
			for (int k = 0; k <= i; k++) {
				for (int g = 0; g <= j; g++) {
					if (mas[k][g] > max) {
						max = mas[k][g];
					}
				}
			}
			result[i][j] = max;
		}
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] mas[i];
	}
	delete[] mas;
	for (int i = 0; i < n; i++) {
		delete[] result[i];
	}
	delete[] result;
	system("pause");
	return 0;
}
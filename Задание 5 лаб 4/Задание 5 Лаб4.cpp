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
	int** result = new int*[n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
		result[i] = new int[m];
		for (int j = 0; j < m; j++) {
			mas[i][j]=rand()%11;
		}
		for (int j = 0; j < m; j++) {
			result[i][j] = mas[i][j];
			if (j - 1 >= 0 && result[i][j - 1] > result[i][j])
				result[i][j] = result[i][j - 1];
			if (i - 1 >= 0 && result[i - 1][j] > result[i][j])
				result[i][j] = result[i - 1][j];
		}
		delete[] mas[i];
		/*for (int j = 0; j < m; j++) {
			cout << result[i][j] << " ";
		}*/
		//cout << endl;
		if (i - 2 >= 0) delete[] result[i - 2];
	}
	
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}*/
	delete[] mas;
	delete[] result[n-1];
	delete[] result[n - 2];
	delete[] result;
	system("pause");
	return 0;
}
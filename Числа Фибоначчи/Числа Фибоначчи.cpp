//0 1 1 2 3 5 8 13 21 34 
#include <iostream>
using namespace std;
int fibonacci(int n){
	if (n == 1) return 0;
	if (n == 2) return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);
}
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cin >> n;
	cout << "Число Фибоначчи с номером " << n << " = " << fibonacci(n) << endl;
	system("pause");
	return 0;
}

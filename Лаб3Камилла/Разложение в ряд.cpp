#include <iostream>
using namespace std;
double eps = 1e-6;
const double PI = 3.1415926535897932;
//const double PI = atan(1) * 4;
const double E = 2.7182818284590452353602;
double my_abs(double x) {
	if (x < 0) x = -x;
	return x;
}
double sin_Teilor(double x) {
	double s = 0;
	double elem = x;
	int k = 1;
	while (my_abs(elem) > eps) {
		s += elem;
		elem = -elem * x * x / (k + 1) / (k + 2);
		k += 2;
	}
	return s;
}
double my_sin(long double x) {
	int zn = 1;
	if (x < 0) {
		zn = -1;
		x = -x;
	}
	long double sub = 1e19 * 2 * PI;
	while (x > 2 * PI) {
		while (x > sub) {
			x -= sub;
		}
		sub = sub / 10;
	}
	return zn*sin_Teilor(x);
	
}
double cos_Teilor(double x) {
	double s = 0;
	double elem = 1;
	int k = 0;
	while (my_abs(elem) > eps) {
		s += elem;
		elem = -elem * x * x / (k + 1) / (k + 2);
		k += 2;
	}
	return s;
}
double my_cos(double x) {
	if (x < 0)
		x = -x;
	double sub = 1e19 * 2 * PI;
	while (x > 2 * PI) {
		while (x > sub) {
			x -= sub;
		}
		sub = sub / 10;
	}
	return cos_Teilor(x);
}
double ln_1_plus_x(double x) {
	if (x == -1) return -std::numeric_limits<double>::infinity();
	double s = 0;
	double elem = x;
	int k = 1;
	while (my_abs(elem / k) > eps) {
		s += elem / k;
		elem = -elem * x;
		k++;
	}
	return s;
}
double my_ln_abs(double x) {
	if (x == 0) return -std::numeric_limits<double>::infinity();
	x = my_abs(x);
	/*if (x >= 0 && x <= 2) return ln_1_plus_x(x - 1);
	double y = (x - 1) / (x + 1);
	return ln_1_plus_x(y) - ln_1_plus_x(-y);
	*/
	int k = 0;
	while (x >= 2) {
		k++;
		x /= E;
	}
	return k + ln_1_plus_x(x - 1);

}


int main() {
	setlocale(LC_ALL, "rus");
	long double x;
	cout << "Введите x: ";
	cin >> x;
	if (my_abs(x) < 1e-20) {
		cout << "Логарифм нуля не определен!\n";
		system("pause");
		return 0;
	}
	double si = my_sin(x);
	double co = my_cos(x);
	double lo = my_ln_abs(x);
	double min = si;
	if (co < min) min = co;
	if (lo < min) min = lo;
	cout << "Синус= " << si << "("<<sin(x)<<")"<<endl;
	cout << "Косинус= " << co << "(" << cos(x) << ")"<< endl;
	cout << "Логарифм= " << lo << "(" << log(abs(x)) << ")"<< endl;
	cout << "Минимум= " << min << endl;
	system("pause");
	return 0;
}
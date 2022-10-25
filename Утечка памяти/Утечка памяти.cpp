#include <iostream>
using namespace std;
int main() {
	int* p;
	for (int i = 0; i < 4; i++) {
		p = new int[10000];
	}
	delete[] p;
	system("pause");
	return 0;
}
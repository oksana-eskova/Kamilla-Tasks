#include <iostream>
using namespace std;
int main() {
    const double PI = 3.1415;
    double x;
    cin >> x;
    double sub = 1e19 * 2 * PI;
    while (x > 2*PI) {
        while (x > sub) {
            x -= sub;
       }
        sub = sub/10;
    }
    cout << x << endl;
    system("pause");
    return 0;
}
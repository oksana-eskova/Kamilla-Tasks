#include <iostream>
using namespace std;
int main() {
    const short NUMBER = 32767;
    char str[NUMBER];
    cin >> str;
    int index;
    cin >> index;
    int kolNumbers = strlen(str);
    int* numbers = new int[kolNumbers];
    for (int i = 0; i < kolNumbers; i++) {
        numbers[i] = str[i] - '0';
    }
    for (int i = 0; i < kolNumbers - 1; i++) {
        for (int j = i + 1; j < kolNumbers; j++) {
            if (numbers[j] == numbers[i]) {
                numbers[j] =-1;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < kolNumbers; i++) {
        if (numbers[i] >= 0 && numbers[i] <= 9) {
            k++;
        }
    }
    cout << k << endl;
    int j = 0;
    for (int i = kolNumbers-1; i>=0; i--) {
        numbers[j++] = str[i] - '0';
    }
    int digit = numbers[index];
    for (int i = 0; i < kolNumbers; i++) {
        if (numbers[i] == digit) {
            cout << i << " ";
        }
    }
    cout << endl;
    system("pause");
    return 0;
}
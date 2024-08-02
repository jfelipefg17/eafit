#include <iostream>
#include <string>
using namespace std;

int main() {
    int a = 2;
    int b = 6;

    string numbers[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (int i = a; i <= b; ++i) {
        if (i <= 9) {
            cout << numbers[i] << endl;
        } else if (i % 2 == 0) {
            cout << "even" << endl;
        } else {
            cout << "odd" << endl;
        }
    }

    return 0;
}

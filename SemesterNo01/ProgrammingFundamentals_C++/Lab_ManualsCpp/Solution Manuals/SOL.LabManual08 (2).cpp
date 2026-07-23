#include <iostream>
using namespace std;

void circularSwap(int &a, int &b, int &c) {
    a = a + b + c;
    b = a - (b + c);
    c = a - (b + c);
    a = a - (b + c);
}

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "Before swap: a = " << a << ", b = " << b << ", c = " << c << endl;

    circularSwap(a, b, c);

    cout << "After swap: a = " << a << ", b = " << b << ", c = " << c << endl;
}

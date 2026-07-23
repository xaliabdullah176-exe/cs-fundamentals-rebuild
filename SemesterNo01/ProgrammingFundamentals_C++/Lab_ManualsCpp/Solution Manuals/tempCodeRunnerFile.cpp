int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    cout << "Before swap: a = " << a << ", b = " << b << ", c = " << c << endl;

    circularSwap(a, b, c);

    cout << "After swap: a = " << a << ", b = " << b << ", c = " << c << endl;
}

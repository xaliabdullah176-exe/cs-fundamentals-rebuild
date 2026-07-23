#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, num4, num5;
    int temp;
    
    // Input 5 numbers from user
    cout << "Enter 5 integers:" << endl;
    cout << "Number 1: ";
    cin >> num1;
    cout << "Number 2: ";
    cin >> num2;
    cout << "Number 3: ";
    cin >> num3;
    cout << "Number 4: ";
    cin >> num4;
    cout << "Number 5: ";
    cin >> num5;
    
    cout << "\nOriginal numbers: " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;
    
    // Sort in ascending order using simple comparisons and swaps
    // Compare num1 and num2
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    // Compare num2 and num3
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    
    // Compare num3 and num4
    if (num3 > num4) {
        temp = num3;
        num3 = num4;
        num4 = temp;
    }
    
    // Compare num4 and num5
    if (num4 > num5) {
        temp = num4;
        num4 = num5;
        num5 = temp;
    }
    
    // Compare num1 and num2 again
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    // Compare num2 and num3 again
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    
    // Compare num3 and num4 again
    if (num3 > num4) {
        temp = num3;
        num3 = num4;
        num4 = temp;
    }
    
    // Compare num1 and num2 again
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    // Compare num2 and num3 again
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    
    // Compare num1 and num2 again
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    // Print in ascending order
    cout << "\nAscending order: " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5 << endl;
    
    // Print in descending order
    cout << "Descending order: " << num5 << " " << num4 << " " << num3 << " " << num2 << " " << num1 << endl;
    
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    long long number;
    long long original_number;
    
    // Inputing 8-digit number
    cout << "Enter an 8-digit number: ";
    cin >> number;
    
    // Storing original number for palindrome check
    original_number = number;
    
    // Extracting each digit using division and modulo
    int digit1 = number % 10;          // Last digit
    number = number / 10;
    
    int digit2 = number % 10;          // 7th digit
    number = number / 10;
    
    int digit3 = number % 10;          // 6th digit
    number = number / 10;
    
    int digit4 = number % 10;          // 5th digit
    number = number / 10;
    
    int digit5 = number % 10;          // 4th digit
    number = number / 10;
    
    int digit6 = number % 10;          // 3rd digit
    number = number / 10;
    
    int digit7 = number % 10;          // 2nd digit
    number = number / 10;
    
    int digit8 = number % 10;          // 1st digit
    
    cout << "\nOriginal number: " << original_number << endl;
    
    // Printing the number in reverse order
    cout << "Number in reverse order: " << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << digit7 << digit8 << endl;
    
    // Calculating sum of digits
    int sum = digit1 + digit2 + digit3 + digit4 + digit5 + digit6 + digit7 + digit8;
    cout << "Sum of digits: " << sum << endl;
    
    // Checking if palindrome
    // Compare first digit with last digit, second with second-last, etc.
    if (digit1 == digit8 && digit2 == digit7 && digit3 == digit6 && digit4 == digit5) {
        cout << "The number IS a palindrome" << endl;
    } else {
        cout << "The number is NOT a palindrome" << endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter how many prime numbers you want: ";
    cin >> N;

    int count = 0;   // count of primes found
    int num = 2;     // number to be checked

    while (count < N) {
        int i;
        for (i = 2; i < num; i++) {   // check divisibility
            if (num % i == 0) {
                break;  // not a prime number
            }
        }
        if (i == num) {  // num is prime
            cout << num << " ";
            count++;
        }
        num++;
    }

    return 0;
}

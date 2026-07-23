//Question no 10
// 
//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//    int n,marks;
//    float sum = 0;
//    float avg;
//
//    cout << setw(50) <<"This is The Students Avg Calculator"<<endl;
//    cout << setw(40) << "Enter Number Of Students"<<endl;
//    cin >> n;
//
//    do {
//        if (n < 0)
//        {
//            cout << "Please Enter Valid Students Number";
//            cin >> n;
//        }
//        else if (n == 0)
//        {
//            cout << "No Students To Calculate The Average Program Terminated"<<endl;
//            cout << "Thank You";
//            break;
//        }
//        else
//        {
//            break;
//        }
//  
//        }while (true);
//
//        cout << setw(20)<<"Enter The Marks of Students"<<endl;
//
//        for (int i = 1; i <= n; i++)
//        {
//            do
//            {
//                cout << "Enter Marks of Student = " << i << endl;
//                cin >> marks;
//
//                if (marks < 0 || marks>100)
//                {
//                    cout << "Please Enter Valid Marks";
//                }
//                else
//                {
//                    break;
//                }
//                    
//
//            } while (true);
//
//            sum += marks;
//            avg = sum / n;   
//            
//        }
//
//        cout << "The Sum of All the Students marks is = " << sum << endl;
//        cout << "The Avrage of All the Students marks is = " << avg << endl;
//return 0;
//    }
//
//Question no 09

//Bank Account System
//
//#include <iostream>
//using namespace std;
//
//int main() {
//    double balance = 0.0;
//    int choice;
//
//    cout << "Bank Account Menu:\n";
//    cout << "1. Deposit\n";
//    cout << "2. Withdraw\n";
//    cout << "-1. Quit\n";
//
//    do {
//        cout << "Choose an option: ";
//        cin >> choice;
//
//        if (choice == 1) {
//            double deposit;
//            cout << "Enter amount to deposit: ";
//            cin >> deposit;
//            if (deposit > 0) {
//                balance += deposit;
//                cout << "Deposited: " << deposit << endl;
//                cout << "Current balance: " << balance << endl;
//            }
//            else {
//                cout << "Invalid deposit amount.\n";
//            }
//        }
//        else if (choice == 2) {
//            double withdraw;
//            cout << "Enter amount to withdraw: ";
//            cin >> withdraw;
//            if (withdraw > balance) {
//                cout << "Insufficient balance. Withdrawal denied.\n";
//            }
//            else if (withdraw > 0) {
//                balance -= withdraw;
//                cout << "Withdrawn: " << withdraw << endl;
//                cout << "Current balance: " << balance << endl;
//            }
//            else {
//                cout << "Invalid withdrawal amount.\n";
//            }
//        }
//        else if (choice != -1) {
//            cout << "Invalid option. Please choose 1, 2, or -1.\n";
//        }
//    } while (choice != -1);
//
//    cout << "Final balance = " << balance << endl;
//    return 0;
//}

//Question no 04 Floyed Triangle

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n, count = 1;
//
//	do {
//		cin >> n;
//		if (n > 0) {
//			break;
//		}
//		else {
//			cout << "Please Enter a Valid Input Value";
//		}
//	} while (true);
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			cout << count++ << " ";
//		}
//		cout << endl;
//	}
// return 0;
//}

//Question 05
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int n, s;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (s = n - 1; s >= i; s--)
//			cout << " ";
//		for (int j = 1; j <= i; j++)
//			cout << "*";
//		cout << endl;
// 
//	}
// return 0;
// 
//}
// 
// 
//Question No 03
//#include <iostream>
//using namespace std;
//
//int main() {
//    int N;
//    cout << "Enter the upper limit N: ";
//    cin >> N;
//
//    cout << "Armstrong numbers: ";
//
//    for (int num = 100; num <= N; ++num) {
//        int temp = num;
//        int digits = 0;
//
//        // Count digits
//        int t = temp;
//        while (t > 0) {
//            digits++;
//            t /= 10;
//        }
//
//        // Calculate sum of digits raised to the power of digits
//        int sum = 0;
//        t = temp;
//        while (t > 0) {
//            int digit = t % 10;
//            int power = 1;
//            for (int i = 0; i < digits; ++i) {
//                power *= digit;
//            }
//            sum += power;
//            t /= 10;
//        }
//
//        if (sum == num) {
//            cout << num << " ";
//        }
//    }
//
//    cout << endl;
//    return 0;
//}
//Question no 08
//
//#include <iostream>
//using namespace std;
//
//int main() {
//    int N;
//    cout << "Enter a number N: ";
//    cin >> N;
//
//    cout << "Prime factors = ";
//
//    int i = 2;
//    while (N > 1) {
//        if (N % i == 0) {
//            cout << i;
//            N /= i;
//            if (N > 1) cout << ", ";
//        }
//        else {
//            i++;
//        }
//    }
//
//    cout << endl;
//    return 0;
//}
// Question no 01
//#include <iostream>
//using namespace std;
//
//int main() {
//    long long N;
//
//    // Input validation: N must be positive
//    cout << "Enter a positive number N: ";
//    cin >> N;
//
//    while (N <= 0) {
//        cout << "Invalid input. Please enter a positive number: ";
//        cin >> N;
//    }
//
//    long long temp = N;
//    int sumOdd = 0, sumEven = 0;
//
//    // Count digits
//    int digits = 0;
//    long long t = temp;
//    while (t > 0) {
//        digits++;
//        t /= 10;
//    }
//
//    // Use for loop to process each digit
//    for (int i = 0; i < digits; i++) {
//        int digit = temp % 10;
//        if (digit % 2 == 0)
//            sumEven += digit;
//        else
//            sumOdd += digit;
//        temp /= 10;
//    }
//
//    cout << "Sum of odd digits = " << sumOdd << ", Sum of even digits = " << sumEven << endl;
//    return 0;
//}

//Question 02

//#include <iostream>
//using namespace std;
//
//int main() {
//    int r, n;
//
//    // Input validation for r and n
//    cout << "Enter the common ratio r (positive integer): ";
//    cin >> r;
//    while (r <= 0) {
//        cout << "Invalid input. Enter a positive integer for r: ";
//        cin >> r;
//    }
//
//    cout << "Enter the number of terms n (positive integer): ";
//    cin >> n;
//    while (n <= 0) {
//        cout << "Invalid input. Enter a positive integer for n: ";
//        cin >> n;
//    }
//
//    int term = 1;
//    int sum = 0;
//
//    // Geometric series: S = 1 + r + r^2 + ... + r^(n-1)
//    for (int i = 0; i < n; i++) {
//        sum += term;
//        term *= r;
//    }
//
//    cout << "S = " << sum << endl;
//    return 0;
//}
// 
//Question no 06
// 
//#include <iostream>
//using namespace std;
//
//int main() {
//    int N;
//
//    // Input validation
//    cout << "Enter a positive integer N (N ≥ 2): ";
//    cin >> N;
//
//    while (N < 2) {
//        cout << "Invalid input. Please enter an integer N ≥ 2: ";
//        cin >> N;
//    }
//
//    cout << "Unique pairs where i < j:\n";
//
//    //Mine Nested loops Logics to generate pairs
//    for (int i = 1; i < N; i++) {
//        for (int j = i + 1; j <= N; j++) {
//            cout << "(" << i << ", " << j << ")";
//            if (!(i == N - 1 && j == N)) cout << ", ";
//        }
//    }
//
//    cout << endl;
//    return 0;
//}
// Question No 07

//#include <iostream>
//using namespace std;
//
//int main() {
//    int N;
//
//    // Input validation
//    cout << "Enter a positive integer N: ";
//    cin >> N;
//
//    while (N <= 0) {
//        cout << "Invalid input. Please enter a positive integer: ";
//        cin >> N;
//    }
//
//    cout << "Collatz sequence: ";
//
//    // Generating the sequence so we can get the input
//    while (N != 1) {
//        cout << N << " -> ";
//        if (N % 2 == 0) {
//            N = N / 2;
//        }
//        else {
//            N = N * 3 + 1;
//        }
//    }
//
//    cout << "1" << endl;
//    return 0;
//}


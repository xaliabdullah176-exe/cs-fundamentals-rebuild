//Program 1

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    float price, dPrice;
//
//    do {
//        cout << "Enter Price of the Product (Press -1 to Exit): ";
//        cin >> price;
//
//        if (price == -1) {
//            break;
//        }
//
//        if (price < 0) {
//            cout << "Invalid input. Price cannot be negative." << endl;
//            continue;
//        }
//
//        if (price < 100) {
//            dPrice = price - (price * 0.05);
//        }
//        else if (price <= 500) {
//            dPrice = price - (price * 0.1);
//        }
//        else {
//            dPrice = price - (price * 0.15);
//        }
//
//        cout << "The Discounted price is : $" << dPrice << endl;
//
//    } while (true);
//
//    return 0;
//}


//Program 2

//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int n, count = 0;
//
//    do {
//        cout << "Enter an integer (-999 to stop): ";
//        cin >> n;
//
//        if (n == -999) {
//            break;
//        }
//
//        if (n % 3 == 0 && n % 5 == 0) {
//            count++;
//            cout << n << " is divisible by both 3 and 5." << endl;
//        }
//
//    } while (true);
//
//    cout << "Total numbers divisible by both 3 and 5: " << count << endl;
//
//    return 0;
//}
  
//Program 3

//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int N;
//
//    // Input validation using do-while loop
//    do {
//        cout << "Enter a non-negative integer: ";
//        cin >> N;
//
//        if (N < 0) {
//            cout << "Invalid input. Please enter a non-negative integer." << endl;
//        }
//
//    } while (N < 0);
//
//    // Factorial calculation using for loop
//    unsigned long long factorial = 1;
//    for (int i = 1; i <= N; ++i) {
//        factorial *= i;
//    }
//
//    cout << "Factorial of " << N << " = " << factorial << endl;
//
//    return 0;
//}

//Program 4

//#include<iostream>
//    using namespace std;
//
//    int main()
//    {
//        int N, sum = 0;
//
//        // Input validation using do-while loop
//        do {
//            cout << "Enter a positive integer: ";
//            cin >> N;
//
//            if (N <= 0) {
//                cout << "Invalid input. Please enter a positive integer." << endl;
//            }
//
//        } while (N <= 0);
//
//        // Sum of odd numbers using for loop
//        for (int i = 1; i <= N; i += 2) {
//            sum += i;
//        }
//
//        cout << "Sum of odd numbers between 1 and " << N << " = " << sum << endl;
//
//        return 0;
//    }
 
//Program 5
//
//#include<iostream>
//    using namespace std;
//
//    int main()
//    {
//        int n, sum = 0 ,f = 0, s = 1 ;
//
//        // input validation using do-while loop
//        do {
//            cout << "enter a positive integer: ";
//            cin >> n;
//
//            if (n <= 0) {
//                cout << "invalid input. please enter a positive integer." << endl;
//            }
//
//        } while (n <= 0);
//
//        cout << f << "," << s << ",";
//        
//        for (int i = 3; i <= n; i++)
//        {
//            sum = f + s;
//            cout << sum << ",";
//            f = s;
//            s = sum;
//        }
//    }
//
    //Program 6

//#include<iostream>
//    using namespace std;
//
//    int main()
//    {
//        int n, count = 0;
//
//        // input validation using do-while loop
//        do {
//            cout << "Enter a positive integer: ";
//            cin >> n;
//
//            if (n < 0) {
//                cout << "Invalid input. Please enter a positive integer." << endl;
//            }
//
//        } while (n < 0);
//
//        if (n == 0)
//            count = 1;
//
//        for (int i = n; i != 0; count++) {
//            i = i / 10;
//        }
//
//        cout << "Number of Digits = " << count << endl;
//
//        return 0;
//    }

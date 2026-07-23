// Question no 01

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

// Question no 02

// #include <iostream>
// using namespace std;

// bool isPrime(int n)
// {
//     if (n <= 1)
//     {
//         return false;
//     }

//     for (int i = 2; i < n; i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }

// void findFactorial(int n, long long &fact)

// {
//     fact = 1;

//     for (int i = 1; i <= n; i++)
//     {
//         fact = fact * i;
//     }
// }

// int main()
// {
//     int num;
//     long long fact;
//     cout << "Enter a number: ";
//     cin >> num;

//     if (isPrime(num))

//     {
//         findFactorial(num, fact);
//         cout << "Factorial of " << num << " is " << fact << ".";
//     }
//     else
//     {
//         cout << num << " is not a prime number.";
//     }
// }

// Question No 03

// #include <iostream>
//     using namespace std;

// const float PI = 3.14159;

// float getRadius()
// {
//     float r;
//     cout << "Enter the radius of the circle: ";
//     cin >> r;
//     return r;
// }

// float power(int base, int exponent)
// {
//     float result = 1;
//     for (int i = 1; i <= exponent; i++)
//     {
//         result = result * base;
//     }
//     return result;
// }

// float calculateArea(float radius)
// {
//     return PI * power(radius, 2);
// }

// float calculateCircumference(float radius)
// {
//     return 2 * PI * radius;
// }

// int main()
// {
//     float radius = getRadius();
//     float area = calculateArea(radius);
//     float circumference = calculateCircumference(radius);

//     cout << "Area of the circle: " << area << endl;
//     cout << "Circumference of the circle: " << circumference;
// }

// Question No 04:

// #include <iostream>
// using namespace std;

// float principal, rate;
// int years;

// void getLoanDetails()
// {
//     cout << "Enter loan amount: ";
//     cin >> principal;
//     cout << "Enter annual interest rate (in decimal, e.g., 0.05 for 5%): ";
//     cin >> rate;
//     cout << "Enter loan term in years: ";
//     cin >> years;
// }

// float power(float base, int exponent)
// {
//     float result = 1;
//     if (exponent >= 0)
//     {
//         for (int i = 1; i <= exponent; i++)
//         {
//             result = result * base;
//         }
//     }
//     else
//     {
//         for (int i = 1; i <= -exponent; i++)
//         {
//             result = result * base;
//         }
//         result = 1 / result;
//     }
//     return result;
// }

// float calculateMonthlyPayment()
// {
//     float monthlyRate = rate / 12;
//     int totalMonths = years * 12;
//     float top = principal * monthlyRate;
//     float bottom = 1 - power(1 + monthlyRate, -totalMonths);
//     float payment = top / bottom;
//     return payment;
// }

// int main()
// {
//     getLoanDetails();
//     float monthlyPayment = calculateMonthlyPayment();
//     cout << "Monthly payment: " << monthlyPayment;
// }

// Question no 05:

// #include <iostream>
// using namespace std;

// float CalculateTax(float monthlySalary, float taxPercentage = 15.0)
// {
//     float yearly = monthlySalary * 12;
//     float tax = yearly * (taxPercentage / 100);
//     return tax;
// }

// double CalculateTax(double revenue, double expenses)
// {
//     double profit = revenue - expenses;
//     double tax = profit * 0.20;
//     return tax;
// }

// float CalculateTax(float earnings, int dependents)
// {
//     float baseRate = 10.0;
//     float reduction = dependents * 2.0;
//     if (reduction > 10.0)
//         reduction = 10.0;
//     float finalRate = baseRate - reduction;
//     float tax = earnings * (finalRate / 100);
//     return tax;
// }

// int main()
// {
//     float salary, earnings;
//     double revenue, expenses;
//     int dependents;

//     cout << "Enter monthly salary: ";
//     cin >> salary;
//     cout << "Case 1: Tax = " << CalculateTax(salary) << endl;

//     cout << "Enter business revenue: ";
//     cin >> revenue;
//     cout << "Enter business expenses: ";
//     cin >> expenses;
//     cout << "Case 2: Tax = " << CalculateTax(revenue, expenses) << endl;

//     cout << "Enter freelancer earnings: ";
//     cin >> earnings;
//     cout << "Enter number of dependents: ";
//     cin >> dependents;
//     cout << "Case 3: Tax = " << CalculateTax(earnings, dependents);
// }

// Question no 06

// #include <iostream>
// using namespace std;

// bool isPrime(int n, int d = 2)
// {
//     if (n < 2)
//         return false;
//     if (d * d > n)
//         return true;
//     if (n % d == 0)
//         return false;
//     return isPrime(n, d + 1);
// }

// int countPrimeFactors(int n, int i = 2)
// {
//     if (n == 1)
//         return 0;
//     if (n % i == 0 && isPrime(i))
//     {
//         cout << i << " ";
//         return 1 + countPrimeFactors(n / i, i);
//     }
//     else
//     {
//         return countPrimeFactors(n, i + 1);
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     cout << "Prime factors: ";
//     int total = countPrimeFactors(n);
//     cout << "\nTotal prime factors = " << total;
// }

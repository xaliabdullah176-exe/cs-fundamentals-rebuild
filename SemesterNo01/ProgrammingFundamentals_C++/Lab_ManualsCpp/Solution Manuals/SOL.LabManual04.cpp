//Dry Runs Error Traces

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int counter = 0;
//	while {counter > 100}          //The Brackets of while condition is wrong error!!
//	if (counter % 2 == 1)
//		cout << counter << " is odd" << endl;  // while condition opening and closing delimiters are missing;
//	else
//		cout << counter << " is odd" << endl;   //second line(else) must print even
//	counter++; // same as counter = counter + 1;
//	return 0;
//}



// int main()
//{
//	int K = 5;
//	int I = -2;
//	while (I <= K)
//	{
//		I += 2; // same as I = I + 2
//		--K; // same as K = K - 1
//		cout << (I + K) << endl;                //The Code Will Output 4 5 6 and while condition will false;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
// int main()
// {
//	 int number = 4;
//	 while (number >= 0)
//	 
//		 --number; // same as number = number - 1;
//		 cout << number << endl;                              //the output of the code is -1
//
//	 return 0;
 //}


//Question 1
// 
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int chkNum, num1;
//	cout << "enter the corresponding number to print the series" << endl;
//	cout << "enter 1 for series form 1 to 100" << endl;
//	cout << "enter 2 for 100 to 1 series" << endl;
//	cout << "enter 3 to print numbers from 20 to 2" << endl;
//	cout << "enter 4 to print sequence of num 2 5 8 11...." << endl;
//	cout << "enter 5 to print 99 88 77 66....." << endl;
//
//	cin >> chkNum;
//
//	num1 = 1;
//
//	if (chkNum == 1)
//	{
//		cout << "The Series is =" << endl;
//		while (num1 <= 100)
//		{
//
//			cout << num1 << " , ";
//
//			num1++;
//		}
//
//	}
//
//
//	else if (chkNum == 2)
//		{
//		num1 = 100;
//		cout << "The Series is =" << endl;
//		while (num1 >= 1)
//		{
//
//			cout << num1 << " , ";
//
//			num1--;
//		}
//
//	}
//
//	else if (chkNum == 3)
//	{
//		num1 = 20;
//		
//			cout << "The Required Series is" << endl;
//
//			while (num1 >= 2)
//			{
//
//				cout << num1 << " , ";
//				num1 -= 2;
//
//			}
//
//		
//	}
//	else if (chkNum == 4)
//	{
//		num1 = 2;
//
//		cout << "The Required Series is" << endl;
//
//		while (num1 <= 20)
//		{
//
//			cout << num1 << " , ";
//			num1 += 3;
//
//		}
//
//
//	}
//	else if (chkNum == 5)
//	{
//		num1 = 99;
//
//		cout << "The Required Series is" << endl;
//
//		while (num1 >= 0)
//		{
//
//			cout << num1 << " , ";
//			num1 -= 11;
//
//		}
//
//
//	}
//}
//
//



//Question no 2
// 
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int evenNum = 2;
//    int sum = 0;
//   
//    cout << "This Program print series and sum" << endl;
//
//    while (evenNum <= 30)
//    {
//        cout << evenNum << " ";
//        sum += evenNum;
//        cout << "\nSum = " << sum << endl;
//        evenNum += 2;
//    }
//
//    cout << "\nSum = " << sum << endl;
//
//    return 0;
//}

//Question no 3
// 
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int oddNum = 3;
//    int product = 1;
//
//    cout << "This Program print series and sum" << endl;
//
//    while (oddNum <= 19)
//    {
//        cout << oddNum << " ";
//        product *= oddNum;
//        //cout << "\nProduct = " << product << endl;
//        oddNum += 2;
//    }
//
//    cout << "\nProduct = " << product << endl;
//
//    return 0;
//}
//

//Question no 05
// 
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//int main()
//{
//	int num = 1;
//	float sqroot;
//
//	cout << "square root of the first 25 odd positive integers" << endl;
//
//		while (num <= 49)
//	{
//		
//			sqroot = sqrt(num);
//
//		
//			cout << sqroot << " , " ;
//		
//		num += 2;
//
//	}
//
//}

//Question 04
// 
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int a, b;
//
//    cout << "enter two integers (positive or negative): ";
//    cin >> a >> b;
//
//    // convert both numbers to positive
//    a = (a < 0) ? -a : a;
//    b = (b < 0) ? -b : b;
//
//   // using while loop
//    while (b != 0)
//    {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//
//    cout << "gcd (hcf) is: " << a << endl;
//
//    return 0;
//}

//Question no 06
// 
//#include <iostream>
//using namespace std;
//
//int main() {
//    int number;
//    unsigned long long factorial;
//    int choice = 1;
//
//    while (choice == 1) {
//        cout << "Enter a non-negative integer: ";
//        cin >> number;
//
//        if (number < 0) {
//            cout << "Factorial is not defined for negative numbers." << endl;
//        }
//        else {
//            factorial = 1;
//            int i = 1;
//            while (i <= number) {
//                factorial *= i;
//                i++;
//            }
//            cout << "Factorial of " << number << " is " << factorial << endl;
//        }
//
//        cout << "Do you want to calculate another factorial? (1 = Yes, 0 = No): ";
//        cin >> choice;
//    }
//
//    cout << "Program terminated." << endl;
//    return 0;
//}


//Question mo 07
//
//#include <iostream>
//using namespace std;
//
//int main() {
//    int num, originalNum, temp, digit, count = 0, sum = 0;
//
//    cout << "Enter a number: ";
//    cin >> num;
//
//    originalNum = num;
//    temp = num;
//
//    // Step 1: Count digits
//    while (temp > 0) {
//        temp = temp / 10;
//        count = count + 1;
//    }
//
//    temp = num;
//
//    // Step 2: Calculate sum of digits raised to the power of count
//    while (temp > 0) {
//        digit = temp % 10;
//
//        // Manual power calculation (digit^count)
//        int power = 1;
//        int i = 0;
//        while (i < count) {
//            power = power * digit;
//            i = i + 1;
//        }
//
//        sum = sum + power;
//        temp = temp / 10;
//    }
//
//    // Step 3: Compare result
//    if (sum == originalNum) {
//        cout << originalNum << " is an Armstrong number." << endl;
//    }
//    else {
//        cout << originalNum << " is not an Armstrong number." << endl;
//    }
//
//    return 0;
//}

//Question no 08:
#include <iostream>
using namespace std;

int main() {
    float litres = 0, km = 0;
    float totalLitres = 0, totalKm = 0;
    float consumption = 0, average = 0;

    cout << "Enter the litres used (-1 to end): ";
    cin >> litres;

    while (litres != -1) {
        cout << "Enter the kilometres driven: ";
        cin >> km;

        consumption = (litres * 100) / km;
        cout << "The litres/100km for this tank was " << consumption << endl;

        totalLitres = totalLitres + litres;
        totalKm = totalKm + km;

        cout << "Enter the litres used (-1 to end): ";
        cin >> litres;
    }

    if (totalKm > 0) {
        average = (totalLitres * 100) / totalKm;
        cout << "The overall average consumption was: " << average << endl;
    }
    else {
        cout << "No data entered." << endl;
    }

    return 0;
}

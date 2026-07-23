//Question No 8;

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << "$$$\n" << "$\"$\"$\n" << "\\$\\$";
//}

//Activity no 01

//#include <iostream>
//#include <iomanip> //input output manipulation library
//using namespace std;
//int main()
//{
//	cout << setw(20) << "CodingisFun" << endl;
//
//	//setw is basically setting the width for text.
//
//	cout << "Coding" << "is" << "fun" << endl;
//	cout << setw(8) << "Coding" << setw(8) << "is" << setw(8) << "fun" << endl;
//	return 0;
//}

//Question no 01

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num ;
//	
//	cout << "Enter A Number"<<endl;
//		cin >> num;
//
//		if (num % 2 == 0) {
//
//			cout << "The Number is an Even Number"<<endl;
//
//		}
//		else
//			cout << "This is an odd num"<<endl;
// return 0;
//}


//Question no 02

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int x1, x2;
//	cout << "This Program checks the conditions of XOR operations"<<endl;
//	cout << "Enter a number"<<endl;
//		cin >> x1;
//	cout << "Enter a number"<<endl;
//		cin >> x2;
//
//		//converting into boolian Variables
//		bool b1 = (x1 != 0);
//		bool b2 = (x2 != 0);
//
//		//Bool Result Checking the Logic
//		bool result;
//		if ((b1 && !b2) || (!b1 && b2)) {
//			result = true;
//		}
//		else {
//			result = false;
//		}
//
//		// Output
//		cout << "XOR of x1 and x2 is: " << result << endl;
//
//		return 0;
//}

//Question no 03

//#include<iostream>
//using namespace std;
//
//int main() {
//    int temp;
//    cout << "Welcome to The Temperature Checker Program" << endl;
//
//    cout << "|----------------------------------|" << endl;
//    cout << "Enter The Temperature of Your Area" << endl;
//    cout << "|----------------------------------|" << endl;
//
//    cin >> temp;
//
//    if (temp >= 80) {
//        cout << "It is Hot";
//    }
//    else if (temp >= 60) {
//        cout << "It is Warm";
//    }
//    else if (temp >= 40) {
//        cout << "It is Cool";
//    }
//    else {
//        cout << "It is Cold";
//    }
//
//    cout << "\nHave A Nice Day" << endl;
//
//    return 0;
//}

//Question no 04

//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a, b, c;
//	cout << "The Program will Give You The Largest Of The Numbers\n";
//	cout << "Enter 3 numbers"<<endl;
//	cin >> a >> b >> c;
//
//	if (a == b && b == c)
//	{
//		cout << "a b and c are equal";
//	}
//	else if (b >= c && b >= a)
//	{
//		cout << "b is the Largest Number";
//	}
//	else if (a >= b && a >= c)
//	{
//		cout << "a is the largest";
//	}
//	else
//		cout << "c is largest";
//}

//	Question no 05
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int num1, num2;
//	cout << "Enter The First Number\n";
//	cin >> num1;
//	cout << "Enter The Second Number"<<endl;
//	cin >> num2;
//
//	if (num1 > num2) {
//		cout << "The First Num is Greater ";
//	}
//	else if (num1 < num2) {
//		cout << "The First Num is Smaller ";
//	}
//	else
//		cout << "Both Numbers are equal";
//	return 0;
//}


// Question no 06
// 
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char ch;
//	cout << "The program segregates between the vowels and consonents\n";
//	cout << "Input a character"<<endl;
//	cin >> ch;
//
//	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//	{
//		cout << "It is a vowel" << endl;
//	}
//	else
//		cout << "it is a consonant";
//	return 0;
//
//}

//Question no 07
//
//#include<iostream>
//using namespace std;
//
//int main() {
//    int x1, x2, x3, x4, x5, x6, x7, x8, x9;
//
//    cout << "This is a Tic-Tac-Toe Game" << endl;
//    cout << "Only Enter Zero (0) and one (1)";
//
//    cout << "Player 1: Enter (0,1)\nPlayer 2: Enter (0,1) \n for the move" << endl;
//
//    cout << "Player 1 turn: "; cin >> x1;
//    cout << "Player 2 turn: "; cin >> x2;
//    cout << "Player 1 turn: "; cin >> x3;
//    cout << "Player 2 turn: "; cin >> x4;
//    cout << "Player 1 turn: "; cin >> x5;
//    cout << "Player 2 turn: "; cin >> x6;
//    cout << "Player 1 turn: "; cin >> x7;
//    cout << "Player 2 turn: "; cin >> x8;
//    cout << "Player 1 turn: "; cin >> x9;
//
//    while (x1 > 1 || x2 > 1 || x3 > 1 || x4 > 1 || x5 > 1 || x6 > 1 || x7 > 1 || x8 > 1 || x9 > 1) {
//        cout << "Only Choose Between 0 and 1 \n Enter the number again Thank You" << endl; 
//        cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9;
//        
//    }
//
//    // Row checks
//    if (x1 == x2 && x2 == x3) {
//        if (x1 == 0) {
//            cout << "Player 1 wins (Top Row)" << endl;
//        }
//        else if (x1 == 1) {
//            cout << "Player 2 wins (Top Row)" << endl;
//        }
//    }
//    else if (x4 == x5 && x5 == x6) {
//        if (x4 == 0) {
//            cout << "Player 1 wins (Middle Row)" << endl;
//        }
//        else if (x4 == 1) {
//            cout << "Player 2 wins (Middle Row)" << endl;
//        }
//    }
//    else if (x7 == x8 && x8 == x9) {
//        if (x7 == 0) {
//            cout << "Player 1 wins (Bottom Row)" << endl;
//        }
//        else if (x7 == 1) {
//            cout << "Player 2 wins (Bottom Row)" << endl;
//        }
//    }
//    // Diagonal checks
//    else if (x1 == x5 && x5 == x9) {
//        if (x1 == 0) {
//            cout << "Player 1 wins (Main Diagonal)" << endl;
//        }
//        else if (x1 == 1) {
//            cout << "Player 2 wins (Main Diagonal)" << endl;
//        }
//    }
//    else if (x3 == x5 && x5 == x7) {
//        if (x3 == 0) {
//            cout << "Player 1 wins (Anti-Diagonal)" << endl;
//        }
//        else if (x3 == 1) {
//            cout << "Player 2 wins (Anti-Diagonal)" << endl;
//        }
//    }
//    else {
//        cout << "No winner in rows or diagonals." << endl;
//    }
//
//    return 0;
//}

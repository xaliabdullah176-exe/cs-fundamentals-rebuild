#include<iostream>
using namespace std;

int main()
{
	int a, b;

	cout << "Enter the First Num" << endl;

	cin >> a;

	cout << "Enter the Sec Num" << endl;

	cin >> b;
	
	cout << "Before Swapping" << endl;

	//pointer for addresses;
	int * ptr_1 = &a;
	int * ptr_2 = &b;

	cout << "a = " << *ptr_1 << " " << "b = " << *ptr_2 << endl;

	//swapping the values using the pointers;

	*ptr_1 = *ptr_1 + *ptr_2;
	*ptr_2 = *ptr_1 - *ptr_2;
	*ptr_1 = *ptr_1 - *ptr_2;

	cout << "After Swapping" << endl;

	cout << "a = " << *ptr_1 << " " <<"b = " << *ptr_2 << endl;

	//Multiplication of Values using pointers;

	int Mul = (*ptr_1) * (*ptr_2);

	cout << "The Multiplication is :" << endl;

	cout << Mul;
	cout << endl;
	
	system("pause");
	return 0;

}
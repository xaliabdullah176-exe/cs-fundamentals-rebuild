#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << "Enter Values in 3 Integers: " << endl;
	cin >> a >> b >> c;

	const int * ptr_1 = &a;
	int * const ptr_2 = &b;
	const int * const ptr_3 = &c;

	cout << "All and Addresses are :" << endl;
	cout << "address of a: " << ptr_1 << endl;
	cout << "address of b: " << ptr_2 << endl;
	cout << "address of c: " << ptr_3 << endl;

	cout << "All the Values are: " << endl;
	cout << "Value of a: " << *ptr_1 << endl;
	cout << "Value of b: " << *ptr_2 << endl;
	cout << "Value of c: " << *ptr_3 << endl;

	cout << "Changing in addresses and values of : "
	
	/*ptr_1 = &b;
	*ptr_3 = 20, ptr_3=&a;
	ptr_2 = &a;*/

	system("pause");
	return 0;
		
}
#include <iostream>
using namespace std;
int main() 
{
	int firstnum, secnum, sum = 0;
	
	cout << "Enter the First Num"<<endl;
	
	cin >> firstnum;
	
	cout << "Enter the Sec Num" << endl;
	
	cin >> secnum;

	sum = firstnum + secnum;
    
	cout << "The Sum Of Both Integers is : " << sum << endl;
    
	cout << "The Addresses of both variables is: " << endl;

	cout << "Address of firstnum: " << &firstnum <<endl;
	cout << "Address of secnum: " << &secnum <<endl;
	cout << "Address of sum: " << &sum <<endl;

    system("pause");
	return 0;

}
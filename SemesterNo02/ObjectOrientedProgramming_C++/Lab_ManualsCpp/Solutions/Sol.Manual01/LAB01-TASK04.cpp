#include<iostream>
using namespace std;

int* resetToZero(int* p)
{
	*p = 0;
	return p;
}

int main()
{
	int num;
	cout << "Enter the Number to reset value to Zero"<<endl;
	cin >> num;
	
	int * ptr = &num;
	int * reset = resetToZero(ptr);

	cout << "The Resetted Value is : " << *reset <<endl;


	system("pause");
	return 0;
}
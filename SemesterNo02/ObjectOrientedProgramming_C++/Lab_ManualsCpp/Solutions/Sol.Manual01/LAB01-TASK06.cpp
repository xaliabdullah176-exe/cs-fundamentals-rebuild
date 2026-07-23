#include<iostream>
using namespace std;

int increment(int &num);

int main()
{
	int num;
	cout << "Enter A Number for Booster" << endl;
	cin >> num;
	cout << "The Original Value is: " << num;
	cout << "Num :" << num << endl;

	int returned =  increment(num);
	cout << "The Value After Increment is: " << returned << endl;

	cout << "Changing the Returned Number Again: " << endl;
	returned += 20;
	cout << "The Returned Value is: " << returned<<endl;

	system("pause");
	return 0;
}

int increment(int &num)
{
	num += 10;
	return num;
}


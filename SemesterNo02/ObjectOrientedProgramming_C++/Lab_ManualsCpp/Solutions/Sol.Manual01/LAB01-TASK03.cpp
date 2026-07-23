#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout << endl;
	cout << "Swapping Done" << endl;
	cout << endl;
}

int main()
{
	int first, second;
	cout << "This is a swapping Function Program" << endl;

	cout << "Enter First Number" << endl;
	cin >> first;

	cout << "Enter Second Number" << endl;
	cin >> second;

	cout << "Before Swapping: " << endl;
	
	cout << "First Number: " << first << " " << "Second Number: " << second << endl;

	swap(first, second);
    
	cout << "After Swapping: " << endl;

	cout << "First Number: " << first << " " << "Second Number: " << second << endl;
	
	system("pause");
	return 0;

}
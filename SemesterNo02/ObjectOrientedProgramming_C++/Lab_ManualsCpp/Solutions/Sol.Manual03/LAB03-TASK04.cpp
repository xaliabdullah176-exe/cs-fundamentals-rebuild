#include<iostream>
using namespace std;

void input(char** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		char temp[100];

		cout << "Enter name of Item-" << i + 1 << ": ";
		cin >> temp;

		int len = 0;
		while (temp[len] != '\0')
		{
			len++;
		}

		arr[i] = new char[len + 1];

		for (int j = 0; j <= len; j++)
		{
			*(*(arr + i) + j) = *(temp + j);
		}
	}
}

void display(char** arr, int size)
{
	cout << "Items in Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(arr+i) << endl;
	}
}
int main()
{
	int size;
	do
	{
		cout << "Enter Number of Items: ";
		cin >> size;

		if (size <= 0)
		{
			cout << "ERROR: Size must be greater than 0!!" << endl;
			cout << endl;
		}

	} while (size <= 0);

	char** chest = new char* [size];
	input(chest, size);
	display(chest, size);

	for (int i = 0; i < size; i++)
	{
		delete[] chest[i];
	}

	delete[] chest;
	chest = nullptr;

	system("pause");
	return 0;
}
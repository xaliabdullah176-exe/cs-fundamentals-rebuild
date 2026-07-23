#include<iostream>
using namespace std;

void input(int*inv, int size)
{
	cout << "\nEnter " << size << " elements in the Inventory: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Element-" << i + 1 << ": ";
		cin >> *(inv + i);
	}
}

void display(int*arr, int size)
{
	cout << "Your Current Inventory is: [";
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i);

		if (i != size - 1)
		{
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void add(int *arr, int &size, int item, int &count)
{
	if (count == size)
	{
		size += 1;
	}
	for (int i = count; i < size; i++)
	{
		*(arr + i) = item;
	}
	count++;
}

void remove(int &size)
{
	size -= 1;
}

void grow(int*arr, int size, int &count, int newSize)
{
	if (newSize <= count)
	{
		cout << "Inventory cannot be regrown!!" << endl;
		cin >> newSize;
	}

	int *newInv = new int[newSize];
	cout << "Enter " << " new Elements: ";
	for (int i = size; i < newSize; i++)
	{
		cout << "Element-" << i + 1 << ": ";
		cin >> *(newInv + i);
	}

	newInv = arr;
	delete[] arr;
	arr = nullptr;
}

void shrink(int &size, int shrinkSize)
{
	size -= shrinkSize;
}

int main()
{
	int size;
	do
	{
		cout << "Enter the Size of Inventory: ";
		cin >> size;

		if (size <= 0)
		{
			cout << "ERROR: Inventory size must be greater than 0!!!" << endl;
			cout << endl;
		}
	} while (size <= 0);

	int *inv = new int[size];

	input(inv, size);

	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(inv + i) != 0)
		{
			count++;
		}
	}

	int choice;
	do
	{
		cout << "\nCurrent Number of Elements: " << count << endl;
		display(inv, size);

		cout << "\nDo you want to Add, Remove, Grow or Shrink??  (1 for ADD and 2 for REMOVE 3 for GROW 4 for SHRINK and -1 to EXIT)" << endl;
		cin >> choice;

		if (choice == 1)
		{
			int item;
			cout << "\nEnter the Element to Add: ";
			cin >> item;
			add(inv, size, item, count);
            cout << "Item Added Sucessfully....!! ";
		}

		else if (choice == 2)
		{
			cout << "Element removed From end!!" << endl;
			remove(size);
            cout << "Item Removed Sucessfully...! ";
		}

		else if (choice == 3)
		{
			int num;
			cout << "Enter Number of elements you want to enter: ";
			cin >> num;
			grow(inv, size, count, num);
		}

		else if (choice == 4)
		{
			int shrinkSize;
			cout << "Enter the Size you want to Shrink: ";
			cin >> shrinkSize;

			shrink(size, shrinkSize);
		}

		else if (choice == -1)
		{
			cout << "Thank You!! Program Exited!!" << endl;
			display(inv, size);
		}
	} while (choice != -1);

	delete[] inv;
	inv = nullptr;

	system("pause");
	return 0;
}
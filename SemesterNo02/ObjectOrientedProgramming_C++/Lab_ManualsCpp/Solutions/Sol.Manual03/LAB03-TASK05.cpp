#include <iostream>
#include <memory>
using namespace std;

void add(unique_ptr<int[]>& inv, int& size, int capacity, int itemCode)
{
	if (size >= capacity)
	{
		cout << "Cannot add more items because inverntory is full" << endl;
		return;
	}

	inv[size] = itemCode;
	size++;
}

void remove(int& size)
{
	if (size <= 0)
	{
		cout << "Inventory is Empty! Nothing can be removed" << endl;
		return;
	}

	size--;
	cout << "Last item is removed" << endl;
}

// Display inventory
void display(unique_ptr<int[]>& inv, int size)
{
	if (size == 0)
	{
		cout << "Inventory is empty" << endl;
		return;
	}

	cout << "Current Inventory is:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (inv[i] == 1)
		{
			cout << "Mushroom" << endl;
		}
		else if (inv[i] == 2)
		{
			cout << "Star" << endl;
		}
		else if (inv[i] == 3)
		{
			cout << "Fireball" << endl;
		}
		else
		{
			cout << "Unknown Item" << endl;
		}
	}
}


int main()
{
	int num;
	do
	{
		cout << "Enter number of itmes: ";
		cin >> num;

		if (num <= 0)
		{
			cout << "ERROR: NUmber must be greater than 0!!" << endl;
			cout << endl;
		}
	} while (num <= 0);

	int size = 0;

	unique_ptr<int[]> inv = make_unique<int[]>(num);

	add(inv, size, num, 1);
	add(inv, size, num, 2);
	add(inv, size, num, 3);

	display(inv, size);

	remove(size);
	display(inv, size);

	cout << "\nShared pointer Part" << endl;

	shared_ptr<int> mushroom = make_shared<int>(1);
	shared_ptr<int> star = make_shared<int>(2);

	shared_ptr<int> backpack = mushroom;
	shared_ptr<int> powerUp = mushroom;

	cout << "Mushroom use count is: " << mushroom.use_count() << endl;

	cout << "\nWeak pointer Part" << endl;

	weak_ptr<int> weakMushroom = mushroom;

	if (auto locked = weakMushroom.lock())
	{
		cout << "Weak pointer items: " << *locked << endl;
	}

	mushroom.reset();
	backpack.reset();
	powerUp.reset();

	if (weakMushroom.expired())
	{
		cout << "Weak pointer is expierd" << endl;
	}
	else
	{
		cout << "Weak pointer is not expired" << endl;
	}

	return 0;
}
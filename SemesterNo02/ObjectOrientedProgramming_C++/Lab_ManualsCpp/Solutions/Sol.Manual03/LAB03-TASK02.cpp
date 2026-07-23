#include<iostream>
using namespace std;

void input(int**arr, int size)
{
	cout << "\nEnter Elements in [" << size << " x " << size << "] Grid: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Enter at [" << i << "][" << j << "]: ";
			cin >> *(*(arr + i) + j);
		}
	}
}

void display(int**arr, int size)
{
	cout << "\nEntered Grid is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "{";
		for (int j = 0; j < size; j++)
		{
			cout << *(*(arr + i) + j);

			if (j != size - 1)
			{
				cout << ", ";
			}
		}
		cout << "}" << endl;
	}
}

void transposeArray(int**trans, int**arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(*(trans + j) + i) = *(*(arr + i) + j);
		}
	}
}

int main()
{
	int size;
	do
	{
		cout << "Enter The size of Grid: ";
		cin >> size;

		if (size <= 0)
		{
			cout << "ERROR: Grid Size must be greater than 0!!!" << endl;
			cout << endl;
		}
	} while (size <= 0);

	int rows = size;
	int cols = size;

	int**grid = new int*[rows];

	for (int i = 0; i < rows; i++)
	{
		*(grid + i) = new int[cols];
	}

	input(grid, size);
	display(grid, size);

	int**transpose = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		*(transpose + i) = new int[cols];
	}
	transposeArray(transpose, grid, size);
	display(transpose, size);


	for (int i = 0; i < rows; i++)
	{
		delete[] * (grid + i);
	}

	delete[] grid;
	grid = nullptr;

	for (int i = 0; i < rows; i++)
	{
		delete[] * (transpose + i);
	}

	delete[] transpose;
	transpose = nullptr;
	

	system("pause");
	return 0;
}
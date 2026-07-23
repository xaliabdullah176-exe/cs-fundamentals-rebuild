#include <iostream>
using namespace std;

// Functions PROTOTYPES:
void inputGrid(int **arr, int rowSize, int colSize);
void displayGrid(int **arr, int rowSize, int colSize);
int **compressedGrid(int **arr, int rowSize, int colSize, int *size);
void displayCompressed(int **arr, int rowSize, int *sizes);

int main()
{
    int rows, cols;

    do
    {
        cout << "Enter the Number of Rows of Grid: ";
        cin >> rows;
        if (cin.fail() || rows <= 0)
        {
            cout << "Invalid input! Please enter a positive integer." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            rows = 0;
        }
    } while (rows <= 0);

    do
    {
        cout << "Enter the No. of Colums for the Grid: ";
        cin >> cols;
        if (cin.fail() || cols <= 0)
        {
            cout << "Invalid No of Columns! Enter Columns > 0 " << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cols = 0;
        }
    } while (cols <= 0);

    int **warehouse = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        warehouse[i] = new int[cols];
    }

    inputGrid(warehouse, rows, cols);
    displayGrid(warehouse, rows, cols);

    int *sizes = new int[rows];

    int **compactList = compressedGrid(warehouse, rows, cols, sizes);

    displayCompressed(compactList, rows, sizes);

    return 0;
}

// Function Definitions:

void inputGrid(int **arr, int rowSize, int colSize)
{
    cout << " Inputting Stage of Grid : " << endl;
    for (int i = 0; i < rowSize; i++)
    {
        cout << "Enter " << colSize << " values for Row " << i << ":" << endl;
        for (int j = 0; j < colSize; j++)
        {
            cout << "Pos [" << i << "][" << j << "]: ";
            cin >> *(*(arr + i) + j);
        }
    }
}

void displayGrid(int **arr, int rowSize, int colSize)
{
    cout << " Original Grid : " << endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << *(*(arr + i) + j) << "  ";
        }
        cout << endl;
    }
}

int **compressedGrid(int **arr, int rowSize, int colSize, int *size)
{
    int **newArr = new int *[rowSize];

    for (int i = 0; i < rowSize; i++)
    {

        int count = 0;
        for (int j = 0; j < colSize; j++)
        {
            if (*(*(arr + i) + j) != 0)
            {
                count++;
            }
        }
        *(size + i) = count;

        if (count > 0)
        {
            *(newArr + i) = new int[count];
        }
        else
        {
            *(newArr + i) = NULL;
        }

        int k = 0;
        for (int j = 0; j < colSize; j++)
        {
            int val = *(*(arr + i) + j);
            if (val != 0)
            {

                *(*(newArr + i) + k) = val;
                k++;
            }
        }
    }
    return newArr;
}

void displayCompressed(int **arr, int rowSize, int *sizes)
{
    cout << " Compressed Inventory (Jagged Array): " << endl;
    for (int i = 0; i < rowSize; i++)
    {
        cout << "Shelf " << i << " (Size " << *(sizes + i) << "): ";

        for (int j = 0; j < *(sizes + i); j++)
        {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }
}
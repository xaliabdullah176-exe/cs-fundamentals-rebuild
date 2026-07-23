#include <iostream>
#include <iomanip>
using namespace std;

void input(int **arr, int rows, int cols)
{
    cout << "\nEnter Elements in [" << rows << " x " << cols << "] Grid: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter at [" << i << "][" << j << "]: ";
            cin >> *(*(arr + i) + j);
        }
    }
}

void display(int **arr, int rows, int cols)
{
    cout << "\nEntered Grid is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "{";
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(arr + i) + j);

            if (j != cols - 1)
            {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

void traverse(int **arr, int rows, int cols)
{
    cout << "\nTraversal diagonally:\n";
    for (int i = 0; i < rows; i++)
    {
        int a = i;
        int b = 0;
        while (a >= 0 && b < cols)
        {
            cout << arr[a][b] << " ";
            a--;
            b++;
        }
    }

    for (int i = 1; i < cols; i++)
    {
        int a = rows - 1;
        int b = i;
        while (a >= 0 && b < cols)
        {
            cout << arr[a][b] << " ";
            a--;
            b++;
        }
    }
}

int main()
{
    int rows;
    do
    {
        cout << "Enter number of Rows of Grid: ";
        cin >> rows;

        if (rows <= 0)
        {
            cout << "ERROR: Row Size must be greater than 0!!!" << endl;
            cout << endl;
        }
    } while (rows <= 0);

    int cols;
    do
    {
        cout << "Enter number of Columns of Grid: ";
        cin >> cols;

        if (cols <= 0)
        {
            cout << "ERROR: Column Size must be greater than 0!!!" << endl;
            cout << endl;
        }
    } while (cols <= 0);

    int **grid = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        *(grid + i) = new int[cols];
    }

    input(grid, rows, cols);
    display(grid, rows, cols);

    traverse(grid, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[] *(grid + i);
    }

    delete[] grid;
    grid = nullptr;

    system("pause");
    return 0;
}
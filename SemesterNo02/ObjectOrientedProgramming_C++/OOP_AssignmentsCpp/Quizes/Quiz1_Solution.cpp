#include <iostream>
using namespace std;

int main() 
{
    int rows, cols;

    do 
    {
        cout << "Enter number of rows: ";
        cin >> rows;
        if (rows > 0) 
            break;
        cout << "Invalid input, rows must be > 0.\n";
    } while (true);

    do {
        cout << "Enter number of columns: ";
        cin >> cols;
        if (cols > 0) 
            break;
        cout << "Invalid input, columns must be > 0.\n";
    } while (true);

    int** grid = new int*[rows];
    for (int i = 0; i < rows; i++)
        grid[i] = new int[cols];

    cout << "Enter grid values (0 or 1):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
        {
            cin >> grid[i][j];
            while (grid[i][j] != 0 && grid[i][j] != 1) 
            {
                cout << "Invalid input, enter 0 or 1: ";
                cin >> grid[i][j];
            }
        }
    }

    int totalTraps = 0;
    int previousRowOnes = 0;
    for (int i = 0; i < rows; i++) 
    {
        int currentRowOnes = 0;
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 1)
                currentRowOnes++;
        }
        if (currentRowOnes > 0) 
        {
            totalTraps += previousRowOnes * currentRowOnes;
            previousRowOnes = currentRowOnes;
        }
    }

    cout << "Total Traps = " << totalTraps << endl;

    for (int i = 0; i < rows; i++)
        delete[] grid[i];
    delete[] grid;

    return 0;
}
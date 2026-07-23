#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100; // Defining maximum size constant for easy changes

// --- Function 1: Modular Input Function ---
// Handles input for any matrix passed to it.
void inputMatrix(int matrix[][MAX], int rows, int cols, int matrixNumber)
{
    cout << "\n----------------------------------------" << endl;
    cout << "Inputting Values for Matrix " << matrixNumber << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "Enter " << cols << " values for Row " << i << ": ";
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// --- Function 2: Side-by-Side Display Function ---
// Prints two matrices next to each other, handling different heights.
void displaySideBySide(int m1[][MAX], int r1, int c1, int m2[][MAX], int r2, int c2)
{
    cout << "\n----------------------------------------" << endl;
    cout << "Matrices Side by Side" << endl;
    cout << "----------------------------------------" << endl;

    // Headers
    cout << "Matrix 1" << setw(c1 * 5) << " " << "   |      " << "Matrix 2" << endl;

    // 1. Determine which matrix is taller (has more rows)
    int maxRows;
    if (r1 > r2)
        maxRows = r1;
    else
        maxRows = r2;

    // 2. Loop through each row line by line
    for (int i = 0; i < maxRows; i++)
    {
        // --- PRINT LEFT SIDE (Matrix 1) ---
        if (i < r1)
        {
            for (int j = 0; j < c1; j++)
            {
                cout << setw(5) << m1[i][j];
            }
        }
        else
        {
            // If Matrix 1 is shorter, print empty spaces matching the width
            for (int j = 0; j < c1; j++)
            {
                cout << setw(5) << " ";
            }
        }

        // --- PRINT SEPARATOR ---
        cout << "   |   ";

        // --- PRINT RIGHT SIDE (Matrix 2) ---
        if (i < r2)
        {
            for (int j = 0; j < c2; j++)
            {
                cout << setw(5) << m2[i][j];
            }
        }

        // Move to the next line
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}

// --- Function 3: Matrix Multiplication ---
void multiplicationOfMatrices(int mMatrix1[][MAX], int mRow_1, int mCol_1, int mMatrix2[][MAX], int mRow_2, int mCol_2, int resultantMatrix[][MAX])
{
    // Validation
    if (mCol_1 != mRow_2)
    {
        cout << "\n[Error] Multiplication Not Possible!" << endl;
        cout << "Columns of Matrix 1 (" << mCol_1 << ") != Rows of Matrix 2 (" << mRow_2 << ")." << endl;
        return;
    }

    // The Triple Loop
    for (int i = 0; i < mRow_1; i++)
    {
        for (int j = 0; j < mCol_2; j++)
        {
            resultantMatrix[i][j] = 0; // Initialize

            // Loop k: The "Connector"
            for (int k = 0; k < mCol_1; k++)
            {
                resultantMatrix[i][j] += mMatrix1[i][k] * mMatrix2[k][j];
            }
        }
    }

    // Display Result
    cout << "\n----------------------------------------" << endl;
    cout << "Resultant Matrix (Product)" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < mRow_1; i++)
    {
        for (int j = 0; j < mCol_2; j++)
        {
            cout << setw(5) << resultantMatrix[i][j];
        }
        cout << endl;
    }
}

// --- Function 4: Matrix Addition ---
void additionOfMatrices(int aMatrix_1[][MAX], int aRow_1, int aCol_1, int aMatrix_2[][MAX], int aRow_2, int aCol_2, int aResult[][MAX])
{
    cout << "\n----------------------------------------" << endl;
    cout << "Addition of Matrices (Matrix 1 + Matrix 2)" << endl;
    cout << "----------------------------------------" << endl;

    if (aRow_1 != aRow_2 || aCol_1 != aCol_2)
    {
        cout << "[Error] Addition Not Possible! Matrices must be the exact same size." << endl;
        return;
    }
    else
    {
        for (int i = 0; i < aRow_1; i++)
        {
            for (int j = 0; j < aCol_1; j++)
            {
                aResult[i][j] = aMatrix_1[i][j] + aMatrix_2[i][j];
            }
        }
    }

    // Display Result
    cout << "Resultant Matrix (Sum):" << endl;
    for (int i = 0; i < aRow_1; i++)
    {
        for (int j = 0; j < aCol_1; j++)
        {
            cout << setw(5) << aResult[i][j];
        }
        cout << endl;
    }
}

// --- Function 5: Matrix Subtraction ---
void subtractionOfMatrices(int sMatrix_1[][MAX], int sRow_1, int sCol_1, int sMatrix_2[][MAX], int sRow_2, int sCol_2, int sResult[][MAX])
{
    cout << "\n----------------------------------------" << endl;
    cout << "Subtraction of Matrices (Matrix 1 - Matrix 2)" << endl;
    cout << "----------------------------------------" << endl;

    if (sRow_1 != sRow_2 || sCol_1 != sCol_2)
    {
        cout << "[Error] Subtraction Not Possible! Matrices must be the exact same size." << endl;
        return;
    }
    else
    {
        for (int i = 0; i < sRow_1; i++)
        {
            for (int j = 0; j < sCol_1; j++)
            {
                sResult[i][j] = sMatrix_1[i][j] - sMatrix_2[i][j];
            }
        }
    }

    // Display Result
    cout << "Resultant Matrix (Difference):" << endl;
    for (int i = 0; i < sRow_1; i++)
    {
        for (int j = 0; j < sCol_1; j++)
        {
            cout << setw(5) << sResult[i][j];
        }
        cout << endl;
    }
}

// --- Function 6: Calculate Determinant ---
// Handles 1x1, 2x2, and 3x3 matrices.
void calculateDeterminant(int matrix[][MAX], int rows, int cols, int matrixNumber)
{
    cout << "\n----------------------------------------" << endl;
    cout << "Determinant of Matrix " << matrixNumber << endl;
    cout << "----------------------------------------" << endl;

    if (rows != cols)
    {
        cout << "[Error] Determinant not possible! Matrix is not Square." << endl;
        return;
    }

    long long determinant = 0;

    if (rows == 1)
    {
        determinant = matrix[0][0];
    }
    else if (rows == 2)
    {
        // ad - bc
        determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    else if (rows == 3)
    {
        // Expansion by first row
        int a = matrix[0][0];
        int b = matrix[0][1];
        int c = matrix[0][2];
        int d = matrix[1][0];
        int e = matrix[1][1];
        int f = matrix[1][2];
        int g = matrix[2][0];
        int h = matrix[2][1];
        int i = matrix[2][2];

        determinant = a * ((e * i) - (f * h)) - b * ((d * i) - (f * g)) + c * ((d * h) - (e * g));
    }
    else
    {
        cout << "Determinant logic for size > 3x3 is not implemented." << endl;
        return;
    }

    cout << "Determinant of Matrix " << matrixNumber << " is: " << determinant << endl;
}

// --- Function 7: Sort Matrix ---
// Flattens the 2D matrix, sorts it, and rebuilds it.
void sortMatrix(int matrix[][MAX], int rows, int cols, int matrixNumber)
{
    cout << "\n----------------------------------------" << endl;
    cout << "Sorting Matrix " << matrixNumber << " (Ascending Order)" << endl;
    cout << "----------------------------------------" << endl;

    int tempArray[MAX * MAX];
    int k = 0;

    // Step 1: Flatten
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tempArray[k] = matrix[i][j];
            k++;
        }
    }

    int totalElements = rows * cols;

    // Step 2: Bubble Sort
    for (int i = 0; i < totalElements - 1; i++)
    {
        for (int j = 0; j < totalElements - i - 1; j++)
        {
            if (tempArray[j] > tempArray[j + 1])
            {
                int temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }

    // Step 3: Rebuild Matrix
    k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = tempArray[k];
            k++;
        }
    }

    // Display Sorted
    cout << "Sorted Matrix " << matrixNumber << ":" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int matrix1[MAX][MAX], row_1, col_1;
    int matrix2[MAX][MAX], row_2, col_2;
    int result[MAX][MAX]; // To store results of operations

    // --- Input Matrix 1 ---
    cout << "Please Input dimensions for Matrix 1: " << endl;
    while (true)
    {
        cin >> row_1 >> col_1;
        if (row_1 <= 0 || row_1 > MAX || col_1 <= 0 || col_1 > MAX)
            cout << "Invalid Size! Range is 1-" << MAX << ". Try again: ";
        else
            break;
    }

    // --- Input Matrix 2 ---
    cout << "Please Input dimensions for Matrix 2: " << endl;
    while (true)
    {
        cin >> row_2 >> col_2;
        if (row_2 <= 0 || row_2 > MAX || col_2 <= 0 || col_2 > MAX)
            cout << "Invalid Size! Range is 1-" << MAX << ". Try again: ";
        else
            break;
    }

    // 1. Input Values
    inputMatrix(matrix1, row_1, col_1, 1);
    inputMatrix(matrix2, row_2, col_2, 2);

    // 2. Display Side by Side
    displaySideBySide(matrix1, row_1, col_1, matrix2, row_2, col_2);

    // 3. Multiplication
    multiplicationOfMatrices(matrix1, row_1, col_1, matrix2, row_2, col_2, result);

    // 4. Addition
    additionOfMatrices(matrix1, row_1, col_1, matrix2, row_2, col_2, result);

    // 5. Subtraction
    subtractionOfMatrices(matrix1, row_1, col_1, matrix2, row_2, col_2, result);

    // 6. Determinant
    calculateDeterminant(matrix1, row_1, col_1, 1);
    calculateDeterminant(matrix2, row_2, col_2, 2);

    // 7. Sort Matrices
    sortMatrix(matrix1, row_1, col_1, 1);
    sortMatrix(matrix2, row_2, col_2, 2);

    return 0;
}
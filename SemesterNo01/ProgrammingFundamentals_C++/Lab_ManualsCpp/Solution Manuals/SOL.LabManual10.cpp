////Question no 02:
//
// #include <iostream>
// using namespace std;
//
////A Function is to multiply each row by its row number (1-indexed)
//
// void powerupRows(int matrix[][5], int r) {
//    for (int i = 0; i < r; i++) {
//        int multiplier = i + 1; // row number (1-based)
//        for (int j = 0; j < r; j++) {
//            matrix[i][j] *= multiplier;
//        }
//    }
//}
//
// int main() {
//    int N;
//    // Input Validation :
//    cout << "Enter matrix size (N <= 5): "<<endl;
//    while (true)
//    {
//        cin >> N;
//
//        if (N <= 0 || N > 5)
//            cout << "Please enter a Valid Input Size must be (N<=5)";
//        else
//            break;
//    }
//    int matrix[5][5]; // fixed max size
//
//    cout << "Enter the matrix elements:\n";
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    cout << "The Entered Matrix is: " << endl;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout<< matrix[i][j];
//        }
//        cout << endl;
//    }
//
//    // ApplyING The transformation
//    powerupRows(matrix, N);
//
//    cout << "Output Matrix:\n";
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

////Question 01
//
// #include <iostream>
// using namespace std;
//
//// Function to check if a number is even..
//
// bool isEven(int num)
//{
//    return (num % 2 == 0);
//}
//
//// Function to check if a number is an even perfect square...
//
// bool isEvenPerfect(int num) {
//    if (!isEven(num)) return false; // must be even
//
//    //I am checking if num is a perfect square.....
//    for (int i = 1; i * i <= num; i++)
//    {
//        if (i * i == num)
//        {
//            return true;
//        }
//    }
//    return false;
//}
//
//// Function to take input until 'size' even perfect numbers are stored....
//
// void takeEvenPerfectInput(int data[], int size) {
//    int count = 0;
//    int num;
//
//    cout << "Enter numbers (will store only even perfect numbers):\n";
//    while (count < size) {
//        cin >> num;
//
//        // Input validation: ignore negatives
//        if (num < 0)
//        {
//            cout << "Negative numbers ignored.\n";
//            continue;
//        }
//
//        if (isEvenPerfect(num)) {
//            data[count] = num;
//            count++;
//        }
//        else {
//            cout << "Ignored: " << num << " (not even perfect)\n";
//        }
//    }
//}
//
// int main() {
//    int size;
//    cout << "Enter required number of even perfect numbers: ";
//    cin >> size;
//
//    if (size <= 0 || size > 20) { // validation
//        cout << "Invalid size. Must be between 1 and 20.\n";
//        return 0;
//    }
//
//    int data[20]; // max size
//    takeEvenPerfectInput(data, size);
//
//    cout << "Array data after user input: ";
//    for (int i = 0; i < size; i++) {
//        cout << data[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//
//}

// Question 03:

// #include <iostream>
// using namespace std;
//
////A Function to take input in the matrix to get the values
//
// void inputMatrix(int matrix[][5], int N)
// {
//    cout << "Enter elements of the matrix:" << endl;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> matrix[i][j];
//        }
//    }
//}
//
//// Function to calculate sums of main and anti-diagonal
// void sumDiagonals(int matrix[][5], int N, int& mainDiagSum, int& antiDiagSum) {
//     mainDiagSum = 0;
//     antiDiagSum = 0;
//
//     for (int i = 0; i < N; i++) {
//         mainDiagSum += matrix[i][i];           // main diagonal
//         antiDiagSum += matrix[i][N - 1 - i];   // anti-diagonal
//     }
// }
//
// int main() {
//     int N;
//     cout << "Enter size of matrix (N <= 5): ";
//     cin >> N;
//
//     while (true) {
//         if (N > 5 || N <= 0)
//         {
//             cout << "Invalid size! N must be between 1 and 5." << endl;
//         }
//         else break;
//
//         return 0;
//     }
//
//     int matrix[5][5]; // maximum size allowed by the manual
//     int mainDiagSum, antiDiagSum;
//
//     // Inputting thee matrix
//     inputMatrix(matrix, N);
//
//     // Calculate diagonals sums....
//     sumDiagonals(matrix, N, mainDiagSum, antiDiagSum);
//
//     // Outputingg results..
//     cout << "After the sumDiagonals Function:" << endl;
//     cout << "mainDiagSum = " << mainDiagSum << ", antiDiagSum = " << antiDiagSum << endl;
//
//     return 0;
// }

//
////Question No 04

// #include <iostream>
// using namespace std;
//
//// Function to take input in the matrix
// void inputMatrix(int matrix[][5], int N) {
//     cout << "Enter elements of the matrix:" << endl;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> matrix[i][j];
//         }
//     }
// }
//
//// Function to rotate matrix by 90 degrees clockwise
// void rotate90Clockwise(int matrix[][5], int N) {
//     // Step 1: Transpose the matrix
//     for (int i = 0; i < N; i++) {
//         for (int j = i; j < N; j++) {
//             swap(matrix[i][j], matrix[j][i]);
//         }
//     }
//
//     // Step 2: Reverse each row
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N / 2; j++) {
//             swap(matrix[i][j], matrix[i][N - 1 - j]);
//         }
//     }
// }
//
//// Function to display the matrix
// void displayMatrix(int matrix[][5], int N) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
//
// int main() {
//     int N;
//     cout << "Enter size of matrix (N <= 5): ";
//     cin >> N;
//
//     while (N > 5 || N <= 0) {
//         cout << "Invalid size! N must be between 1 and 5." << endl;
//         cout << "Enter size of matrix (N <= 5): ";
//         cin >> N;
//     }
//
//     int matrix[5][5]; // maximum size allowed
//
//     // Input matrix
//     inputMatrix(matrix, N);
//
//     cout << "Before rotation:" << endl;
//     displayMatrix(matrix, N);
//
//     // Rotate matrix
//     rotate90Clockwise(matrix, N);
//
//     cout << "After rotation:" << endl;
//     displayMatrix(matrix, N);
//
//     return 0;
// }
//

// Question No 05:

// #include <iostream>
// using namespace std;

// // Check if a row contains digits 1–9 exactly once
// bool checkRow(int grid[9][9], int row) {
//     int freq[10] = {0}; // index 1–9 used

//     for (int col = 0; col < 9; col++) {
//         int num = grid[row][col];

//         if (num < 1 || num > 9)  // invalid number
//             return false;

//         if (freq[num] == 1)      // duplicate found
//             return false;

//         freq[num] = 1;
//     }
//     return true;
// }

// // Check if a column contains digits 1–9 exactly once
// bool checkColumn(int grid[9][9], int col) {
//     int freq[10] = {0};

//     for (int row = 0; row < 9; row++) {
//         int num = grid[row][col];

//         if (num < 1 || num > 9)
//             return false;

//         if (freq[num] == 1)
//             return false;

//         freq[num] = 1;
//     }
//     return true;
// }

// // Check 3×3 subgrid
// bool checkSubgrid(int grid[9][9], int startRow, int startCol) {
//     int freq[10] = {0};

//     for (int r = 0; r < 3; r++) {
//         for (int c = 0; c < 3; c++) {
//             int num = grid[startRow + r][startCol + c];

//             if (num < 1 || num > 9)
//                 return false;

//             if (freq[num] == 1)
//                 return false;

//             freq[num] = 1;
//         }
//     }
//     return true;
// }

// // Main function required by assignment
// bool isSudokuArray(int grid[9][9]) {

//     // Check all rows
//     for (int i = 0; i < 9; i++) {
//         if (!checkRow(grid, i))
//             return false;
//     }

//     // Check all columns
//     for (int j = 0; j < 9; j++) {
//         if (!checkColumn(grid, j))
//             return false;
//     }

//     // Check each 3×3 box
//     for (int row = 0; row < 9; row += 3) {
//         for (int col = 0; col < 9; col += 3) {
//             if (!checkSubgrid(grid, row, col))
//                 return false;
//         }
//     }

//     return true; // everything is valid
// }

// int main() {
//     int grid[9][9];

//     cout << "Enter 9x9 Sudoku grid:\n";

//     // Input validation
//     for (int i = 0; i < 9; i++) {
//         for (int j = 0; j < 9; j++) {
//             cin >> grid[i][j];

//             if (grid[i][j] < 1 || grid[i][j] > 9) {
//                 cout << "Invalid value! Only digits 1–9 allowed.\n";
//                 return 0;
//             }
//         }
//     }

//     if (isSudokuArray(grid))
//         cout << "Valid Sudoku Array.\n";
//     else
//         cout << "Invalid Sudoku Array.\n";

//     return 0;
// }

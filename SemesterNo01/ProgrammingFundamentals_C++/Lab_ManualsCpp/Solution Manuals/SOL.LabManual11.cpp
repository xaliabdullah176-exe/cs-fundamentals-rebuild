////Question no 01;
//
//#include <iostream>
//using namespace std;
//
//void rotateMatrix90Clockwise(char matrix[][5], int rows) 
//    {
//        char temp[5][5];  //  A Temporary array....
//
//        // Copying with rotation to temp
//        for (int i = 0; i < rows; i++) 
//        {
//            for (int j = 0; j < 5; j++) 
//            {
//                temp[j][rows - 1 - i] = matrix[i][j];
//            }
//        }
//
//        // Step 2: Copy back from temp to original matrix
//        for (int i = 0; i < rows; i++) 
//        {
//            for (int j = 0; j < 5; j++) 
//            {
//                matrix[i][j] = temp[i][j];
//            }
//        }
//    }
//   
//
//void replaceVowels(char matrix[][5], int row)
//{
//    for(int i = 0; i < row; i++)
//    { 
//        for (int j = 0; j < 5; j++)
//        {
//            if (matrix[i][j] == 'a' || matrix[i][j] == 'e' || matrix[i][j] == 'i' ||
//                matrix[i][j] == 'o' || matrix[i][j] == 'u' ||
//                matrix[i][j] == 'A' || matrix[i][j] == 'E' || matrix[i][j] == 'I' ||
//                matrix[i][j] == 'O' || matrix[i][j] == 'U') {
//
//                matrix[i][j] = '?';  // Replace with ?
//                                                            }
//
//        }
//    }
//
//    
//}
//
//void printMatrix(char matrix[][5], int row)
//{
//    for (int i = 0; i < row; i++)
//    {
//
//        for (int j = 0; j < 5; j++)
//        {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main ()
//{
//    char matrix[5][5];
//
//    int row = 5;
//    int col = 5;
//
//     cout << "Input the Values in the matrix" << endl;
//
//      // Inputting in the 2D array Matrix;
//
//     for (int i = 0; i < row; i++)
//     {
//
//         for (int j = 0; j < col; j++)
//         {
//             cin >> matrix[i][j];
//         }
//         cout << endl;
//     }
//      // Output of Matrix
//     cout << "Original Matrix" << endl;
//     printMatrix(matrix, row);
//     cout << endl;
//
//     replaceVowels(matrix, row);
//     cout << "Replaced With ? Matrix" << endl;
//     printMatrix(matrix, row);
//     cout << endl;
//
//     rotateMatrix90Clockwise(matrix, row);
//     cout << "Results with a Rotated Matrix" << endl;
//     printMatrix(matrix, row);
//     cout << endl;
//      
//     return 0;
//}
//





//Question no 02 
//
//#include <iostream>
//using namespace std;
//
//// FUNCTION PROTOTYPES
//void printMatrix(const char data[][5], int rows);
//int getLength(const char word[]);
//bool searchHorizontal(const char data[][5], int rows, char word[], int i, int j);
//bool searchVertical(const char data[][5], int rows, char word[], int i, int j);
//bool searchWord(const char data[][5], int rows, char word[], int& startRow, int& startCol, int& endRow, int& endCol);
//void FindnReplace(char data[][5], int rows, const char word[], const char replacement[]);
//
//int main() {
//    int rows;
//
//    cout << "Enter number of rows: ";
//    cin >> rows;
//
//    char matrix[100][5];
//
//    cout << "Enter matrix:" << endl;
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < 5; j++) 
//        {
//            cin >> matrix[i][j];
//        }
//    }
//
//    cout << "\nMatrix:" << endl;
//    printMatrix(matrix, rows);
//
//    char word[100];
//    cout << "\nWord to find: ";
//    cin >> word;
//
//    char replacement[100];
//    cout << "Replacement: ";
//    cin >> replacement;
//
//    FindnReplace(matrix, rows, word, replacement);
//
//    cout << "\nModified Matrix:" << endl;
//    printMatrix(matrix, rows);
//
//    return 0;
//}
//
//// GETTING LENGTH OF STRING....... 
//int getLength(const char word[]) 
//{
//    int len = 0;
//    while (word[len] != '\0') 
//    {
//        len++;
//    }
//    return len;
//}
//
//// PRINT MATRIX
//void printMatrix(const char data[][5], int rows) {
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < 5; j++) 
//        {
//            cout << data[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//// SEARCH HORIZONTAL (RIGHT to LEFT)
//bool searchHorizontal(const char data[][5], int rows, char word[], int i, int j) {
//    int wordLen = getLength(word);
//
//    // Check if word can fit going LEFT from position j
//    if (j - wordLen + 1 < 0) 
//    {
//        return false;
//    }
//
//    // Match each character going LEFT
//    for (int k = 0; k < wordLen; k++) 
//    {
//        if (data[i][j - k] != word[k]) 
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//// SEARCH VERTICAL (TOP to DOWN)
//bool searchVertical(const char data[][5], int rows, char word[], int i, int j) {
//    int wordLen = getLength(word);
//
//    // Check if word can fit going DOWN from position i
//    if (i + wordLen > rows) 
//    {
//        return false;
//    }
//
//    // Match each character going DOWN
//    for (int k = 0; k < wordLen; k++) 
//    {
//        if (data[i + k][j] != word[k]) 
//        {
//            return false;
//        }
//    }
//
//    return true;
//}
//
//// SEARCH WORD (calls searchHorizontal and searchVertical)
//bool searchWord(const char data[][5], int rows, char word[], int& startRow, int& startCol, int& endRow, int& endCol) {
//
//    int wordLen = getLength(word);
//
//    // Try every position in matrix
//    for (int i = 0; i < rows; i++) 
//    {
//        for (int j = 0; j < 5; j++) 
//        {
//
//            // Check HORIZONTAL (right to left)
//            if (searchHorizontal(data, rows, word, i, j)) 
//            {
//                startRow = i;
//                startCol = j;
//                endRow = i;
//                endCol = j - wordLen + 1;
//                return true;
//            }
//
//            // Check VERTICAL (top to down)
//            if (searchVertical(data, rows, word, i, j)) 
//            {
//                startRow = i;
//                startCol = j;
//                endRow = i + wordLen - 1;
//                endCol = j;
//                return true;
//            }
//        }
//    }
//
//    return false;  // Word not found
//}
//
//// FIND AND REPLACE
//void FindnReplace(char data[][5], int rows, const char word[], const char replacement[]) 
//{
//    int startRow, startCol, endRow, endCol;
//
//    // Make non-const copies for searchWord
//    char searchWord_copy[100];
//    int idx = 0;
//    while (word[idx] != '\0') 
//    {
//        searchWord_copy[idx] = word[idx];
//        idx++;
//    }
//    searchWord_copy[idx] = '\0';
//
//    // Search for word
//    if (searchWord(data, rows, searchWord_copy, startRow, startCol, endRow, endCol)) 
//    {
//
//        cout << "\nFound Word Positions:" << endl;
//        cout << "Start: (" << startRow << ", " << startCol << "), ";
//        cout << "End: (" << endRow << ", " << endCol << ")" << endl;
//
//        int wordLen = getLength(word);
//        int replaceLen = getLength(replacement);
//
//        // Check orientation: HORIZONTAL or VERTICAL?
//        if (startRow == endRow) 
//        {
//            // HORIZONTAL (same row, different columns)
//
//            int col = startCol;
//            int k = 0;
//
//            // Replace characters (right to left)
//            while (k < replaceLen && k < wordLen) 
//            {
//                data[startRow][col] = replacement[k];
//                col--;
//                k++;
//            }
//
//            // Pad with '*' if replacement is shorter
//            while (k < wordLen) 
//            {
//                data[startRow][col] = '*';
//                col--;
//                k++;
//            }
//
//        }
//        else {
//            // VERTICAL (same column, different rows)
//
//            int row = startRow;
//            int k = 0;
//
//            // Replace characters (top to down)
//            while (k < replaceLen && k < wordLen) 
//            {
//                data[row][startCol] = replacement[k];
//                row++;
//                k++;
//            }
//
//            // Pad with '*' if replacement is shorter
//            while (k < wordLen) 
//            {
//                data[row][startCol] = '*';
//                row++;
//                k++;
//            }
//        }
//
//    }
//    else {
//        cout << "\nWord not found!" << endl;
//    }
//}

////Question no 03
//
//
//#include <iostream>
//using namespace std;
//
//// FUNCTION PROTOTYPES
//int leadingSpaces(char row[]);
//int trailingSpaces(char row[]);
//void trim(char matrix[][20], int R);
//void printMatrix(char matrix[][20], int R);
//int stringLength(char row[]);
//
//int main() {
//    int R;
//
//    cout << "Enter number of rows: ";
//    cin >> R;
//
//    char matrix[100][20];
//
//    cout << "Enter rows:" << endl;
//
//    // Inputting.... each row
//    for (int i = 0; i < R; i++) {
//        int j = 0;
//        char ch;
//
//        // Skipping any leftover newline from previous input........
//        if (i == 0) {
//            cin.get(ch); // consume newline after number
//        }
//
//        // Read characters until newline
//        while (true) {
//            cin.get(ch);
//            if (ch == '\n') {
//                matrix[i][j] = '\0';  // End string
//                break;
//            }
//            matrix[i][j] = ch;
//            j++;
//        }
//    }
//
//    cout << "\nOriginal Matrix:" << endl;
//    printMatrix(matrix, R);
//
//    // Trim
//    trim(matrix, R);
//
//    cout << "\nTrimmed Matrix:" << endl;
//    printMatrix(matrix, R);
//
//    return 0;
//}
//
//// GET STRING LENGTH (manual)
//int stringLength(char row[]) {
//    int len = 0;
//    while (row[len] != '\0') {
//        len++;
//    }
//    return len;
//}
//
//// COUNT LEADING SPACES
//int leadingSpaces(char row[]) {
//    int count = 0;
//
//    // Count spaces from start
//    while (row[count] == ' ' && row[count] != '\0') {
//        count++;
//    }
//
//    return count;
//}
//
//// COUNT TRAILING SPACES
//int trailingSpaces(char row[]) {
//    int len = stringLength(row);
//
//    // If empty, return 0
//    if (len == 0) {
//        return 0;
//    }
//
//    int count = 0;
//    int i = len - 1;
//
//    // Count spaces from end
//    while (i >= 0 && row[i] == ' ') {
//        count++;
//        i--;
//    }
//
//    return count;
//}
//
//// TRIM FUNCTION
//void trim(char matrix[][20], int R) {
//
//    for (int i = 0; i < R; i++) {
//
//        int leading = leadingSpaces(matrix[i]);
//        int trailing = trailingSpaces(matrix[i]);
//        int len = stringLength(matrix[i]);
//
//        int contentLen = len - leading - trailing;
//        
//        if (contentLen <= 0) {
//            matrix[i][0] = '\0';
//            continue;
//        }
//
//        // Shift characters left to remove leading spaces
//        for (int j = 0; j < contentLen; j++) {
//            matrix[i][j] = matrix[i][leading + j];
//        }
//
//        // Add null terminator
//        matrix[i][contentLen] = '\0';
//    }
//}
//
//// PRINT MATRIX
//void printMatrix(char matrix[][20], int R) {
//    for (int i = 0; i < R; i++) {
//        cout << "\"";
//
//        // Print each character manually
//        int j = 0;
//        while (matrix[i][j] != '\0') {
//            cout << matrix[i][j];
//            j++;
//        }
//
//        cout << "\"" << endl;
//    }
//}
//
//
//
////Question no 04
//
//
//
//#include <iostream>
//using namespace std;
//
//// FUNCTION PROTOTYPES
//void inputArray(char A[][6], int N);
//void copyUpperTriangle(char A[][6], char B[][6], int N);
//void displayArray(char A[][6], int N);
//
//int main() {
//    int N;
//
//    cout << "Enter size N (NxN matrix): ";
//    cin >> N;
//
//    char A[100][6];  
//    char B[100][6];  
//
//    // Input Array A
//    inputArray(A, N);
//
//    // Display Array A
//    cout << "\nArray A:" << endl;
//    displayArray(A, N);
//
//    // Copy upper triangle to B
//    copyUpperTriangle(A, B, N);
//
//    // Display Array B
//    cout << "\nArray B:" << endl;
//    displayArray(B, N);
//
//    return 0;
//}
//
//// FUNCTION 1: INPUT ARRAY A
//void inputArray(char A[][6], int N) {
//    cout << "Enter elements for Array A (" << N << " rows, " << N << " columns):" << endl;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cin >> A[i][j];
//        }
//        A[i][N] = '\0';  // Last column is null terminator
//    }
//}
//
//// FUNCTION 2: COPY UPPER TRIANGLE
//void copyUpperTriangle(char A[][6], char B[][6], int N) {
//
//    for (int i = 0; i < N; i++) {
//        int bCol = 0;  // Column index for B
//
//        for (int j = 0; j < N; j++) {
//
//            // Check if element is on or above diagonal
//            if (j >= i) {
//                // Copy element from A to B
//                B[i][bCol] = A[i][j];
//                bCol++;
//            }
//            // If below diagonal (j < i), skip it
//        }
//
//        // Fill remaining positions with '\0'
//        while (bCol <= N) {
//            B[i][bCol] = '\0';
//            bCol++;
//        }
//    }
//}
//
//// FUNCTION 3: DISPLAY ARRAY
//void displayArray(char A[][6], int N) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j <= N; j++) {
//            if (A[i][j] == '\0') {
//                cout << "'\\0' ";
//            }
//            else {
//                cout << A[i][j] << " ";
//            }
//        }
//        cout << endl;
//    }
//}

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int inputNum, dimension, depth, sideLen, topRow, leftCol, rightCol, bottomRow, startVal, currentVal, totalDigits, spacing, i, j;
    
    do {
        cout << "Enter a perfect square number: ";
        cin >> inputNum;
        cout << endl;
        
        if (inputNum <= 0) {
            cout << "Invalid Input!" << endl;
        } else {
            dimension = sqrt(inputNum);
            if (inputNum != dimension * dimension) {
                cout << "Invalid Input!" << endl;
            }
        }
    } while (inputNum <= 0 || inputNum != dimension * dimension);
    
    totalDigits = inputNum;
    spacing = 0;
    while (totalDigits > 0) {
        spacing += 1;
        totalDigits = totalDigits / 10;
    }
    
    for (i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            depth = i;
            
            if (j < depth) {
                depth = j;
            }
            
            if (dimension - 1 - i < depth) {
                depth = dimension - 1 - i;
            }
            
            if (dimension - 1 - j < depth) {
                depth = dimension - 1 - j;
            }
            
            startVal = 1;
            for (int k = 0; k < depth; k++) {
                sideLen = dimension - 2 * k;
                int increment;
                if (sideLen == 1) {
                    increment = 1;
                } else {
                    increment = 4 * (sideLen - 1);
                }
                startVal += increment;
            }
            
            sideLen = dimension - 2 * depth;
            topRow = depth;
            leftCol = depth;
            rightCol = depth + sideLen - 1;
            bottomRow = rightCol;
            
            if (sideLen == 1) {
                currentVal = startVal;
            } else if (i == topRow) {
                int position = j - leftCol;
                currentVal = startVal + position;
            } else if (j == rightCol) {
                int position = (sideLen - 1) + (i - topRow);
                currentVal = startVal + position;
            } else if (i == bottomRow) {
                int position = 2 * (sideLen - 1) + (rightCol - j);
                currentVal = startVal + position;
            } else {
                int position = 3 * (sideLen - 1) + (bottomRow - i);
                currentVal = startVal + position;
            }
            
            cout << setw(spacing + 1) << currentVal;
        }
        cout << endl;
    }
    
    return 0;
}
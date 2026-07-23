#include <iostream>
using namespace std;

const int MAXSIZE = 500;

int getLength(char sLength[])
{
    int i = 0;
    int count = 0;
    while (sLength[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    // Char Arrays;
    char compressed[MAXSIZE];
    char myString[MAXSIZE];
    cout << "Enter The Letter in The Block" << endl;
    cin >> myString;
    cout << "The Entered Text in the Block is : " << myString << endl;

    int starLen = getLength(myString);
    cout << "The Size of The Text Entered is : " << starLen << endl;

    int k = 0;

    for (int i = 0; i < starLen; i++)
    {
        int count = 1;

        // Count consecutive duplicates
        // While we are not at end AND current char == next char
        while (i < starLen - 1 && myString[i] == myString[i + 1])
        {
            count++;
            i++; // Skip the duplicate
        }

        // 1. Store the character
        compressed[k] = myString[i];
        k++;

        // 2. Store the count (Convert number to char)
        compressed[k] = count + '0';
        k++;
    }

    // Add the Stop Sign to the new string!
    compressed[k] = '\0';

    cout << "Compressed String: " << compressed << endl;

    // ... inside main, after cout << "Compressed String..." ...

    cout << "Decompressed String: ";

    // Loop through the COMPRESSED string
    int j = 0;
    while (compressed[j] != '\0')
    {

        // 1. Get the character (e.g., 'a')
        char letter = compressed[j];

        // 2. Get the count (e.g., '4')
        // It's at the next position (j + 1)
        char countChar = compressed[j + 1];

        // 3. Convert char to int (Reverse Magic)
        int count = countChar - '0';

        // 4. Print the letter 'count' times
        for (int k = 0; k < count; k++)
        {
            cout << letter;
        }

        j = j + 2;
    }
    cout << endl;

    return 0;
}
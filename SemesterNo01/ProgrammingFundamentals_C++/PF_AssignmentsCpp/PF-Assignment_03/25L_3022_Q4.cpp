#include <iostream>
using namespace std;

int longestOnesAfterRemoval(int nums[], int n)
{
    int maxLen = 0;

    for (int skip = 0; skip < n; skip++)
    {
        int count = 0, currentMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == skip)
                continue;

            if (nums[i] == 1)
            {
                count++;
                if (count > currentMax)
                    currentMax = count;
            }
            else
            {
                count = 0;
            }
        }

        if (currentMax > maxLen)
            maxLen = currentMax;
    }

    return maxLen;
}

int main()
{
    int n;
    int arr[1000];

    do
    {
        cout << "Enter array size: ";
        cin >> n;

        if (n <= 0)
            cout << "Error: size must be greater than 0!\n" << endl;

    } while (n <= 0);

    cout << "\nNote: Enter binary numbers (0 or 1 only)\n";
    cout << "Enter " << n << " elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        if (arr[i] != 0)
            arr[i] = 1;
    }

    cout << "\nEntered array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    int result = longestOnesAfterRemoval(arr, n);
    cout << "\n\nLongest run of 1's after removing one element: " << result << endl;

    cout << endl;
    system("pause");
    return 0;
}

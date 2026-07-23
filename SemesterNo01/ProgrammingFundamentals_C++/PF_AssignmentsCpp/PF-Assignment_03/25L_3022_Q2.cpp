#include <iostream>
using namespace std;

int findKthLargest(int arr[], int n, int k)

{ // simple sorting (descending order)
    // to easily figure out kth order element

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    return arr[k - 1]; // k-th largest
}

int main()
{
    int n, k;
    cout << "Enter number of elements (0-100): ";

    while (true)
    {
        cin >> n;

        if (n < 0 || n > 100)
            cout << "Enter a Valid Size (0-100)" << endl;
        else
            break;
    }

    int arr[100]; // setting elements limits

    cout << "Enter " << n << " integers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " Value: " << endl;

        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "The " << k << "-th largest number is: " << findKthLargest(arr, n, k);

    return 0;
}

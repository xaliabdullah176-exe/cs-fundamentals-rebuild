#include <iostream>
using namespace std;

void mergeArrays(int a[], int n1, int b[], int n2, int c[]) {
    int i = 0, j = 0, k = 0;

    // merge both arrays
    while (i < n1 && j < n2) 
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // copy remaining elements
    while (i < n1)
        c[k++] = a[i++];

    while (j < n2)
        c[k++] = b[j++];
}

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    int a[100];
    cout << "Enter " << n1 << " sorted numbers: ";
    for (int i = 0; i < n1; i++)
        cin >> a[i];

    cout << "Enter size of second array: ";
        cin >> n2;
    int b[100];
    cout << "Enter " << n2 << " sorted numbers: ";
    for (int i = 0; i < n2; i++)
        cin >> b[i];

    int c[200]; // merged array
    mergeArrays(a, n1, b, n2, c);

    cout << "Merged sorted array: ";
    for (int i = 0; i < n1 + n2; i++)
        cout << c[i] << " ";

    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int s = 0; s < n - i - 1; s++)
            cout << " ";
        
        int value = 1;
        
        for (int j = 0; j <= i; j++)
        {
            cout << value << " ";
            value = value * (i - j) / (j + 1);
        }
        
      for (int s = 0; s < n - i - 1; s++)
            cout << " ";
        
        cout << endl;
    }
    
    return 0;
}
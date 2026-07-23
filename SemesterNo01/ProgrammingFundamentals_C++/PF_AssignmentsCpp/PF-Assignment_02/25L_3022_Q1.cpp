#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter number of lines for diamond: ";
    cin >> n;
    
    // Upper half of diamond 
    for (int i = 1; i <= n; i++)
    {
        
        for (int s = i; s <= n - 1; s++)
            cout << " ";
        
    
        for (int j = 1; j <= i; j++)
            cout << "*";
        
        
        for (int j = 2; j <= i; j++)
            cout << "*";
        
    
        for (int s = i; s <= n - 1; s++)
            cout << " ";
        
        cout << endl;
    }
    
    // Lower half of diamond
    for (int i = n - 1; i >= 1; i--)
    {
        
        for (int s = 1; s <= n - i; s++)
            cout << " ";
        
        
        for (int j = 1; j <= i; j++)
            cout << "*";
        
    
        for (int j = 2; j <= i; j++)
            cout << "*";
        
    
        for (int s = 1; s <= n - i; s++)
            cout << " ";
        
        cout << endl;
    }
    
    return 0;
}
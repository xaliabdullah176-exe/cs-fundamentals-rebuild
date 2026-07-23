#include <iostream>
using namespace std;

int _removeDuplicates(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j])
             {
                // shifting elements to the left

                for (int k = j; k < n - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                n--;   // reducing size
                j--;   // checking again and again from same position
            }
        }
    }
    return n; // returning new size
}

int main() {
    int n;
    cout << "Enter number of elements(0-100): ";

    while(true)
    {
        cin >> n;
    if(n < 0 || n > 100)
   {
    cout<<"Enter a Valid Number from (0-100) "<<endl;
    cout<<"Re-Enter.... : "<<endl;  
   }
    else
        break;
    }

    int arr[100];
    cout << "Enter " << n << " numbers: "<<endl;
    for (int i = 0; i < n; i++)
    {
    cout<<" Enter the Num " << i + 1 << endl;
        cin >> arr[i];
    }

    //original array
    cout<<"Original Array"<<endl;

    for (int i = 0; i < n; i++)
    {
    cout << arr[i] << " "; 
        
    }
    cout<<endl;  

    n = _removeDuplicates(arr, n); 

    cout << "Array after removing duplicates: "<<endl;
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

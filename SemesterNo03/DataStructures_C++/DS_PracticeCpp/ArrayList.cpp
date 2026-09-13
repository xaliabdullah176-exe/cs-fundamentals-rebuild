// #include <iostream>
// #include <cstring>
// #include <string>
// #include <cmath>
// using namespace std;

// class ArrayList // Class Declaration
// {

//     int size;
//     int totalCapacity;
//     int *arr;

// public:
//     ArrayList() // Array List Constructors
//     {
//         size = 0;
//         totalCapacity = 5;
//         arr = new int[totalCapacity];
//     }
//     ArrayList(int size, int totalCapacity)
//     {
//         this->size = size;
//         this->totalCapacity = totalCapacity;
//     }
//     void insert(int value) // insert function
//     {
//         if (isFull())
//         {
//             cout << "Array is Growing" << endl;
//             reGrow();
//         }
//         arr[size] = value;
//         size++;
//     }

//     bool isFull() // Checker
//     {
//         if (size == totalCapacity)
//             return true;
//         return false;
//     }
//     void reGrow() // ReGrow Function
//     {
//         int *temp = new int[2 * size];

//         for (int i = 0; i < size; i++)
//         {
//             temp[i] = arr[i];
//         }

//         delete[] arr;
//         arr = temp;
//         totalCapacity *= 2;
//     }
//     void display() // Display Function
//     {
//         for (int i = 0; i < size; i++)
//         {
//             cout << *(arr + i) << " ";
//         }
//         cout << endl;
//     }

//     int LinearSearch(int targetValue)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (arr[i] == targetValue)
//                 return i;
//         }
//         return -1;
//     }
//     void removeData(int data)
//     {
//         if (isEmpty())
//             cout << "ArrayList is Full.. No Data to delete" << endl;

//         else
//         {
//             int index = LinearSearch(data);

//             int i;
//             while(i < size)
//             {
//                 if (arr[i] != index)
//                 cout << "there is no such index exist against which the data should delete"<<endl;
//                 i++;
//             }

//             if (data == size)
//             {
//                 size--;
//             }
//             else
//             {
//                 for(int i = index; i<size-1; i++)
//                 {
//                    arr[i] = arr[i+1];
//                 }
//                 size--;
//             }
//         }
//     }
//     bool isEmpty()
//     {
//         if (size == 0)
//             return true;
//         return false;
//     }
// };

// int main() // Main Function
// {
//     /*Creating methods in the ArrayList()
//     1-Insert 2-Search 3-Display 4-ReGrow 5-Delete 6-Update...*/
//     ArrayList alist;
//     alist.insert(10);
//     alist.insert(20);
//     alist.insert(30);
//     alist.insert(40);
//     alist.insert(50);
//     alist.insert(90);
//     alist.display();

//     cout << endl;

//     int index = alist.LinearSearch(90);

//     if (index == -1)
//     {
//         cout << "Data Not Found in ArrayList()" << endl;
//     }
//     else
//     {
//         cout << "The Data is found at the index " << index << endl;
//     }
//     alist.removeData(20);
//     return 0;
// }

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

class ArrayList
{
private:
    int size;
    int TotalCapacity;
    int *arr;

public:
    // Default and Overloaded Constructors
    ArrayList()
    {
        size = 0;
        TotalCapacity = 5;
        arr = new int[TotalCapacity];
    }

    ArrayList(int size, int TotalCapacity)
    {
        this->size = size;
        this->TotalCapacity = TotalCapacity;
        // this->arr = new int[TotalCapacity];
    }
    // Insert Function
    void insert(int value)
    {
        if (isFull())
        {
            cout << "The Array is Growing " << endl;
            reGrow();
        }
        arr[size] = value;
        size++;
    }
    // Checker Bool
    bool isFull()
    {
        if (size == TotalCapacity)
            return true;
        return false;
    }
    // Regrow Function
    void reGrow()
    {
        int *temp = new int[2 * TotalCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        TotalCapacity *= 2;
    }
    // Display Function
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(arr + i) << " ";
        }
    }
    //Checks if the Array is Empty;
    bool isEmpty()
    {
     if(size == 0)
         return true;
    return false;
    }
    // LinearSearch Algorithm
    int linearSearch(int targetValue)
    {
         if(isEmpty())
         {
            cout<<"The Array is Empty Please Recheck and Add Elements "<<endl;
            return -2;
         }
         else
         {
            for(int i = 0; i<size; i++)
            {
                if (arr[i] = targetValue)
                    return i;    
            }
            return -1;
         }
    }

    void clearArray()
    {
        size = 0;
        TotalCapacity = 5;
        arr = new int[TotalCapacity];
    }
    
    void removeElements(int element)
    {
        if(!isEmpty())
        {
            int index = linearSearch(element);

        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ArrayList Array;
    Array.insert(10);
    Array.insert(20);
    Array.insert(30);
    Array.insert(40);
    Array.insert(50);
    Array.insert(50);
        
    Array.display();

    cout<<endl;
   
    int index = Array.linearSearch(30);
    
    cout << index;

    return 0;
}
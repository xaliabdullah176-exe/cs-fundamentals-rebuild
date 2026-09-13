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

    // Checks if the Array is Empty;
    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }
    // LinearSearch Algorithm
    int linearSearch(int targetValue)
    {
        if (isEmpty())
        {
            cout << "The Array is Empty Please Recheck and Add Elements " << endl;
            return -2;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] == targetValue)
                    return i;
            }
            return -1;
        }
    }

    void clearArray()
    {
        size = 0;
        TotalCapacity = 5;
        delete[] arr;
        arr = new int[TotalCapacity];
    }

    // Getters for the Total and size;
    int getTotalCapacity()
    {
        return TotalCapacity;
    }

    int getSizeOfArray()
    {
        return size;
    }

    void removeElements(int element)
    {
        int index = linearSearch(element);
        if (!isEmpty())
        {
            if (index == -1)
            {
                cout << "There is no Element Found to be deleted....!!!" << endl;
            }

            else if (index == size - 1)
            {
                cout << endl;
                cout << "deleting from the index " << index << endl;
                size--;
            }
            else
            {

                for (int i = index; i < size - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                cout << endl;
                cout << "deleting from the index " << index << endl;

                size--;
            }
        }
        else
        {
            cout << "Nothing to Delete Please Add Elements in the Array" << endl;
        }
    }
    int removeDuplicates()
    {
        if (!isEmpty())
        {
            int duplicatesFound = 0;
            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j < size; j++)
                {
                    if (arr[i] == arr[j])
                    {
                        for (int k = j; k < size - 1; k++)
                        {
                            arr[k] = arr[k + 1];
                        }
                        size--;
                        j--;
                        duplicatesFound++;
                    }
                }
            }
            return duplicatesFound;
        }
        else
        {
            cout << "Array List is Empty Please insert some Elements to start Comparisons" << endl;
            return 0;
        }
    }

    void updateArray(int oldValue, int newValue)
    {
        int index = linearSearch(oldValue);
        if (!isEmpty())
        {
            if (index != -1)
            {
                arr[index] = newValue;
            }
            else
            {
                cout << "Data Not Found " << endl;
            }
        }
        else
        {
            cout << "The List is Empty " << endl;
        }
    }

    // Display Function
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(arr + i) << " ";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ArrayList Array;
    Array.insert(10);
    Array.insert(30);
    Array.insert(10);
    Array.insert(10);
    Array.insert(10);
    Array.insert(20);
    Array.insert(30);
    Array.insert(40);
    Array.insert(40);
    Array.insert(50);
    Array.insert(50);

    // Array.display();

    cout << endl;

    // Array.clearArray();

    //     int index = Array.linearSearch(40);
    //     if (index == -1)
    //     {
    //         cout << "Data Not Found " << endl;
    //     }
    //     else
    //     {
    //         cout << "Data Fount at the index " << index << endl;
    //     }
    //     cout << endl;

    //     //Array.removeElements(50);

    //     cout << endl;

    //  //   Array.removeElements(10);

    //     cout << endl;

    //     Array.display();
    cout << endl;
    cout << "The TotalCapacity of Array is: " << Array.getTotalCapacity();
    cout << endl;
    cout << "The TotalCapacity of Array is: " << Array.getSizeOfArray();
    cout << endl;
    // Array.clearArray();
    Array.updateArray(40, -999);

    Array.display();
    cout << endl;
    cout << endl;
    
    int duplicatesFound = Array.removeDuplicates();

    if(duplicatesFound == 0)
    {
        cout<<"No, Duplicates Exist in the array so it is a Set (A unique Array)"<<endl;
    }
    else
    {
        cout<<"Array After the Removal of duplicates is "<<endl;
        Array.display();
    }

    cout<<endl;
    Array.clearArray();
    Array.removeDuplicates();
    Array.display();



    return 0;

    // Alhamdulillah Array List Almost complete
}
#include <iostream>
using namespace std;

class ArrayList
{

    int size;
    int totalCapacity;
    int *arr;

public:
    ArrayList()
    {
        size = 0;
        totalCapacity = 5;
        arr = new int[totalCapacity];
    }
    ArrayList(int size, int totalCapacity)
    {
        this->size = size;
        this->totalCapacity = totalCapacity;
    }
    void insert(int value)
    {
        if (isFull())
        {
             cout << "Array is Growing" << endl;
             reGrow();
        }
            arr[size] = value;
            size++;
    }

    bool isFull()
    {
        if (size == totalCapacity)
            return true;
        return false;
    }
    void reGrow()
    {
        int *temp = new int[2 * size];

        for(int i = 0; i<size; i++ )
        {
            temp[i] = arr[i];
        }
        
        delete [] arr;
        arr = temp;
        totalCapacity*= 2;
    }
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
    ArrayList alist;
    alist.insert(10);
    alist.insert(20);
    alist.insert(30);
    alist.insert(40);
    alist.insert(50);
    alist.insert(10);
    alist.display();
    return 0;
}
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
        if (!isFull())
        {
            arr[size] = value;
            size++;
        }
        else
        {
            cout << "Array is Full" << endl;
        }
    }

    bool isFull()
    {
        if (size == totalCapacity)
            return true;
        return false;
    }
   void display()
   {
        for(int i = 0; i<size; i++)
        {
            cout<< *(arr + i)<<" ";
        }
   }
};

int main()
{
    ArrayList alist;
    alist.insert(10);
    return 0;
}
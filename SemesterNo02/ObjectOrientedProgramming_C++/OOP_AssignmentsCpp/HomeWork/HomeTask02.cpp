#include <iostream>
using namespace std;

class myArray
{
    int size;
    int *ptr;

public:
    myArray()
    {
        size = 0;
        ptr = nullptr;
    }
    myArray(int size)
    {
        this->size = size;
        ptr = new int[size];
    }
    myArray(int *arr, int size)
    {
        this->size = size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(ptr + i) = *(arr + i);
        }
    }
    myArray(const myArray &obj)
    {
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(ptr + i) = *(obj.ptr + i);
        }
    }
    myArray &operator=(const myArray &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        if (ptr != nullptr)
        {
            delete[] ptr;
            ptr = nullptr;
        }
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(ptr + i) = *(obj.ptr + i);
        }
        return *this;
    }
    int &operator[](const int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Invalid Index!" << endl;
            return ptr[0]; // Return first element to prevent crashing
        }
        return ptr[i];
    }

    const int &operator[](const int i) const
    {
        if (i < 0 || i >= size)
        {
            cout << "Invalid Index!" << endl;
            return ptr[0];
        }
        return ptr[i];
    }

    myArray &operator++()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i]++;
        }
        return *this;
    }

    myArray operator++(int)
    {
        myArray temp = *this;

        for (int i = 0; i < size; i++)
        {
            ptr[i]++;
        }
        return temp;
    }
    myArray &operator+=(const myArray &obj)
    {
        if (size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                ptr[i] += obj.ptr[i];
            }
        }
        return *this;
    }
    myArray operator+(const myArray &obj) const
    {
        myArray temp = *this;
        temp += obj;
        return temp;
    }

    bool operator==(const myArray &obj) const
    {
        if (size != obj.size)
            return false;
        for (int i = 0; i < size; i++)
        {
            if (ptr[i] != obj.ptr[i])
                return false;
        }
        return true;
    }

    ~myArray()
    {

        if (ptr != nullptr)
        {
            delete[] ptr;
            ptr = nullptr;
        }
    }
};

int main()
{
    // 1. Constructor call (3 size ka array banaya)
    myArray arr1(3);

    // 2. Subscript Operator [] call (Values daal rahe hain)
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;

    // 3. Copy Constructor call (arr1 ko dekh kar arr2 banaya)
    myArray arr2 = arr1;

    // 4. Addition (+) aur Assignment (=) operator call
    myArray arr3(3);
    arr3 = arr1 + arr2;

    // 5. Increment (++) operator call
    arr1++;

    cout << "OOP Homework Done..." << endl;

    return 0;
}

// Task 1:

// #include <iostream>
// using namespace std;

// float average(const float *arr, int size);

// int main()
// {

//     int eSize;

//     cout << "Please Input the total size of energy Levels: " << endl;
//     cin >> eSize;

//     float *arr = new float[eSize];
//     //
//     cout << "Enter The Energy Levels for the Given Energy Analyser :" << endl;

//     for (int i = 0; i < eSize; i++)
//     {
//         cin >> *(arr + i);
//     }
//     cout << " [ ";
//     for (int i = 0; i < eSize; i++)
//     {

//         cout << *(arr + i) << " , ";
//     }
//     cout << " ] ";
//     float avg = average(arr, eSize);

//     cout << " Returning the Average Values from the Energy Analyzer :" << endl;

//     cout << avg;

//     delete[] arr;
//     arr = nullptr;
// }

// float average(const float *arr, int eSize)
// {
//     float sum = 0, Avg;

//     for (int i = 0; i < eSize; i++)
//     {
//         sum += *(arr + i);
//     }

//     Avg = sum / eSize;

//     return Avg;
// }

// Task02:

// #include <iostream>
// using namespace std;

// void sortingMoods(float *arr, int arrSize);

// int main()
// {
//     int noOfMoods;
//     cout << "Enter the Number of Moods for the sorter: " << endl;
//     cin >> noOfMoods;

//     float *arr = new float[noOfMoods];

//     cout << "Enter Each \"Power Level\" of Mood in sorter array: " << endl;

//     for (int i = 0; i < noOfMoods; i++)
//         cin >> *(arr + i);

//     cout << "The Power Levels Before Sorting of Mood are : " << endl;

//     cout << " [ ";

//     for (int i = 0; i < noOfMoods; i++)
//         cout << *(arr + i) << " ";

//     cout << " ] ";

//     sortingMoods(arr,noOfMoods);

//     cout << "The Power Levels After Sorting of Mood are : " << endl;

//     cout << " [ ";

//     for (int i = 0; i < noOfMoods; i++)
//         cout << *(arr + i) << " ";

//     cout << " ] ";

//     delete[] arr;

//     return 0 ;
// }
// void sortingMoods(float *arr, int arrSize)
// {
//     cout<<"BubbleSorting : "<<endl;

//     for(int i = 0; i <arrSize; i++)
//     {
//         for (int j = 0 ; j < arrSize - 1 - i ; j++ )
//         {
//             if (*(arr + j) > *(arr + j + 1))
//               {
//                 float temp = *(arr + j);
//                 *(arr + j) = *(arr + j + 1);
//                 *(arr + j + 1) = temp;
//               }
//         }
//     }
// }

// Task 03 :

// #include <iostream>
// using namespace std;

// int getLength(const char *str)
// {
//     int count = 0;
//     while (*(str + count) != '\0')
//     {
//         count++;
//     }
//     return count;
// }

// void concat(const char *src, char *dest)
// {
//     int srcLen = getLength(src);
//     int destLen = getLength(dest);

//     for (int i = destLen; i >= 0; i--)
//     {
//         *(dest + i + srcLen + 1) = *(dest + i);
//     }

//     for (int i = 0; i < srcLen; i++)
//     {
//         *(dest + i) = *(src + i);
//     }

//     *(dest + srcLen) = ' ';

//     cout << dest << endl;
// }

// int main()
// {
//     char dest[100] = "SquarePants";
//     const char *src = "SpongeBob";

//     concat(src, dest);

//     return 0;
// }

// // // Task 04:

// #include <iostream>
// using namespace std;

// int main()
// {
//     int size;
//     cout << "Enter number of snacks Patrick ate: ";
//     cin >> size;

//     float *snacks = new float[size];
//     float *cumulative = new float[size];

//     cout << "Enter power level of each snack: " << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cin >> *(snacks + i);
//     }

//     float currentSum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         currentSum += *(snacks + i);
//         *(cumulative + i) = currentSum;
//     }

//     cout << "Cumulative Power Array: [ ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << *(cumulative + i) << " ";
//     }
//     cout << "]" << endl;

//     delete[] snacks;
//     delete[] cumulative;

//     return 0;
// }

// // // Task 05:

// #include <iostream>
// using namespace std;

// int main()
// {
//     int size;
//     cout << "Enter number of employees: ";
//     cin >> size;

//     int *ids = new int[size];

//     cout << "Enter Employee IDs: " << endl;
//     for (int i = 0; i < size; i++)
//     {
//         cin >> *(ids + i);
//     }

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             if (*(ids + i) == *(ids + j))
//             {
//                 for (int k = j; k < size - 1; k++)
//                 {
//                     *(ids + k) = *(ids + k + 1);
//                 }
//                 size--;
//                 j--;
//             }
//         }
//     }

//     cout << "Unique Employee IDs: [ ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << *(ids + i) << " ";
//     }
//     cout << "]" << endl;

//     delete[] ids;
//     return 0;
// }

// // // Task 06:

#include <iostream>
using namespace std;

int main()
{
    int capacity;
    cout << "Enter initial net size: ";
    cin >> capacity;

    int *net = new int[capacity];
    int count = 0;
    int inputID;

    cout << "Enter Jellyfish IDs (-1 to stop): " << endl;

    while (true)
    {
        cin >> inputID;
        if (inputID == -1)
            break;

        if (count == capacity)
        {
            cout << "--- Net full! Doubling size... ---" << endl;
            int newCapacity = capacity * 2;
            int *newNet = new int[newCapacity];

            for (int i = 0; i < capacity; i++)
            {
                *(newNet + i) = *(net + i);
            }

            delete[] net;
            net = newNet;
            capacity = newCapacity;
        }

        *(net + count) = inputID;
        count++;
    }

    cout << "Final Jellyfish in Net: [ ";
    for (int i = 0; i < count; i++)
    {
        cout << *(net + i) << " ";
    }
    cout << "]" << endl;

    delete[] net;
    return 0;
}
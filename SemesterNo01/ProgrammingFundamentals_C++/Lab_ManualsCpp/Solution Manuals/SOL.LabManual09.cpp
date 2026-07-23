//Question No 01

//#include<iostream>
//using namespace std;
//
//void findUniqueElements(int arr[], int size) {
//    bool foundUnique = false;
//    cout << "\nUnique elements in the array are:\n";
//    for (int i = 0; i < size; i++) {
//        bool isUnique = true;
//        for (int j = 0; j < size; j++) {
//            if (i != j && arr[i] == arr[j]) {
//                isUnique = false;
//                break;
//            }
//        }
//        if (isUnique) {
//            cout << arr[i] << " ";
//            foundUnique = true;
//        }
//    }
//
//    if (!foundUnique) {
//        cout << "No unique elements found in the array.";
//    }
//
//    cout << endl;
//}
//
//int main() {
//    int size;
//
//    cout << "Enter the size of the array (0 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (0 - 1000): ";
//        else
//            break;
//    }
//
//    int arr[1000];
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> arr[i];
//    }
//
//    cout << "\nOriginal array:\n";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    findUniqueElements(arr, size);
//
//   }





//Question 03
// 
//
//#include<iostream>
//using namespace std;
//
//int findMajorityElement(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        int count = 1;
//        for (int j = i + 1; j < size; j++) {
//            if (arr[i] == arr[j])
//                count++;
//        }
//        if (count > size / 2)
//            return arr[i];
//    }
//    return -1; // here the return of -1 is indicating no majority element.
//}
//
//int main() {
//    int size;
//
//    cout << "Enter the size of the array (1 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int arr[1000];
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> arr[i];
//    }
//
//    cout << "\nOriginal array:\n";
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    cout << "The original Size of the Array is " << size << endl;
//    cout << "The Half Size of The Array Arr is " << float(size) / 2 << endl;
//
//    int majority = findMajorityElement(arr, size);
//    if (majority != -1)
//        cout << "Majority element is: " << majority << endl;
//    else
//        cout << "No majority element found." << endl;
//
//    return 0;
//}






//Question no 06
//
//#include<iostream>
//using namespace std;
//
//
//void intersectionElement(int arr[], int arr2[], int size, int size2) {
//    int common[1000];
//    int commonSize = 0;
//
// for (int i = 0; i < size; i++) {
//   for (int j = 0; j < size2; j++) {
//     if (arr[i] == arr2[j]) {
//       //// Checking if already in common[]
//          bool alreadyExists = false;
//            for (int k = 0; k < commonSize; k++) {
//               if (common[k] == arr[i]) {
//                    alreadyExists = true;
//                        break;
//                    }
//                }
//                if (!alreadyExists) {
//                    common[commonSize] = arr[i];
//                    commonSize++;
//                }
//                break; // No need to check further in arr2
//            }
//        }
//    }
//
//     ////Printing result
//    cout << "\nUnique common elements:"<<endl;
//    if (commonSize == 0) {
//        cout << "No common elements found.\n";
//    }
//    else {
//        for (int i = 0; i < commonSize; i++) {
//            cout << common[i] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    int size, size2;
//
//    //// Input for first array to get  values
//    cout << "Enter the size of the array (1 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int arr[1000];
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> arr[i];
//    }
//
//    cout << endl;
//
//    //// Input for second array so get values
//    cout << "Enter the size of the array 2 (1 - 1000): ";
//    while (true) {
//        cin >> size2;
//        if (size2 <= 0 || size2 > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int arr2[1000];
//    cout << "Enter " << size2 << " values:\n";
//    for (int i = 0; i < size2; i++) {
//        cout << "Index " << i << ": ";
//        cin >> arr2[i];
//    }
//
//    ////Calling the function to find and print intersection
//    intersectionElement(arr, arr2, size, size2);
//
//    return 0;
//}





//Question 02

//#include <iostream>
//using namespace std;
//
//// Function to perform one right shift
//void rightShift(int arr[], int size) {
//    int last = arr[size - 1];
//    for (int i = size - 1; i > 0; i--) {
//        arr[i] = arr[i - 1];
//    }
//    arr[0] = last;
//}
//
//// Function to perform one left shift
//void leftShift(int arr[], int size) {
//    int first = arr[0];
//    for (int i = 0; i < size - 1; i++) {
//        arr[i] = arr[i + 1];
//    }
//    arr[size - 1] = first;
//}
//
//// Function to display the array
//void displayArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i];
//        if (i < size - 1) cout << ", ";
//    }
//    cout << endl;
//}
//
//// Function to perform multiple shifts and show result after each
//void performShift(int arr[], int size, int shiftCount, char direction) {
//    for (int i = 0; i < shiftCount; i++) {
//        if (direction == 'r') {
//            rightShift(arr, size);
//        }
//        else if (direction == 'l') {
//            leftShift(arr, size);
//        }
//        cout << "After shift " << i + 1 << ": ";
//        displayArray(arr, size);
//    }
//}
//
//int main() {
//    int size;
//
//    // Input for array size
//    cout << "Enter the size of the array (1 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int arr[1000];
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> arr[i];
//    }
//
//    int shiftCount;
//    char direction;
//
//    // Input for shift count
//    cout << "\nEnter number of shifts: ";
//    cin >> shiftCount;
//
//    // Input for direction
//    cout << "Enter direction ('l' for left, 'r' for right): ";
//    cin >> direction;
//
//    // Normalize shift count
//    shiftCount = shiftCount % size;
//
//    // Perform the shift and show result after each
//    performShift(arr, size, shiftCount, direction);
//
//    return 0;
//}





//Question no 04
//
//#include <iostream>
//using namespace std;
//
//// Function to rearrange even and odd numbers
//void rearrangeEvenOdd(int original[], int size, int result[]) {
//    int evenIndex = 0;
//
//    // First pass: copy even numbers
//    for (int i = 0; i < size; i++) {
//        if (original[i] % 2 == 0) {
//            result[evenIndex] = original[i];
//            evenIndex++;
//        }
//    }
//
//    // Second pass: copy odd numbers
//    for (int i = 0; i < size; i++) {
//        if (original[i] % 2 != 0) {
//            result[evenIndex] = original[i];
//            evenIndex++;
//        }
//    }
//}
//
//// Function to display the array
//void displayArray(int arr[], int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i];
//        if (i < size - 1) cout << ", ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int size;
//
//    // Input for array size
//    cout << "Enter the size of the array (1 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int original[1000], result[1000];
//
//    // Input array values
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> original[i];
//    }
//
//    // Rearrange and display
//    rearrangeEvenOdd(original, size, result);
//    cout << "\nRearranged array (even first): ";
//    displayArray(result, size);
//
//    return 0;
//}





//Question no 05
// 
//#include <iostream>
//using namespace std;
//
//// Function to calculate sum of digits of a number
//int sumOfDigits(int num) {
//    int sum = 0;
//    while (num != 0) {
//        int digit = num % 10;
//        sum = sum + digit;
//        num = num / 10;
//    }
//    return sum;
//}
//
//// Function to display an array
//void displayArray(int arr[], int size, const char label[]) {
//    cout << label;
//    for (int i = 0; i < size; i++) {
//        cout << arr[i];
//        if (i < size - 1) cout << ", ";
//    }
//    cout << endl;
//}
//
//int main() {
//    int size;
//
//    // Input array size
//    cout << "Enter the size of the array (1 - 1000): ";
//    while (true) {
//        cin >> size;
//        if (size <= 0 || size > 1000)
//            cout << "Invalid size. Enter again (1 - 1000): ";
//        else
//            break;
//    }
//
//    int original[1000], digitSums[1000];
//
//    // Input array values
//    cout << "Enter " << size << " values:\n";
//    for (int i = 0; i < size; i++) {
//        cout << "Index " << i << ": ";
//        cin >> original[i];
//    }
//
//    // Calculate sum of digits for each element
//    for (int i = 0; i < size; i++) {
//        digitSums[i] = sumOfDigits(original[i]);
//    }
//
//    // Display both arrays
//    cout << "\nOriginal Array: ";
//    displayArray(original, size, "");
//
//    cout << "Sum of Digits: ";
//    displayArray(digitSums, size, "");
//
//    return 0;
//}



//Question no 07

// #include <iostream>
// using namespace std;

// bool isAlphabet(char c) {
//     return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
// }

// char toLower(char c) {
//     if (c >= 'A' && c <= 'Z') {
//         return c + ('a' - 'A');
//     }
//     return c;
// }

// bool isVowel(char c) {
//     return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
// }

// void countVowelsAndConsonants(char arr[], int& vowelCount, int& consonantCount) {
//     vowelCount = 0;
//     consonantCount = 0;

//     for (int i = 0; arr[i] != '\0'; i++) {
//         if (isAlphabet(arr[i])) {
//             char c = toLower(arr[i]);
            
//             if (isVowel(c)) {
//                 vowelCount++;
//             } else {
//                 consonantCount++;
//             }
//         }
//     }
// }

// int main() {
//     char inputString[256];

//     cout << "Hey there! Please type in a sentence: ";
//     cin.getline(inputString, 256);

//     int vowels = 0;
//     int consonants = 0;

//     countVowelsAndConsonants(inputString, vowels, consonants);

//     cout << "\nAlright, I counted them up!" << endl;
//     cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;

//     return 0;
// }


// //Question no 08


// #include <iostream>
// using namespace std;

// int getStringLength(char arr[]) {
//     int length = 0;
//     while (arr[length] != '\0') {
//         length++;
//     }
//     return length;
// }

// bool isAlphabet(char c) {
//     return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
// }

// char toLower(char c) {
//     if (c >= 'A' && c <= 'Z') {
//         return c + ('a' - 'A');
//     }
//     return c;
// }

// bool isPalindrome(char arr[]) {
//     int start = 0;
//     int end = getStringLength(arr) - 1;

//     while (start < end) {
//         while (start < end && !isAlphabet(arr[start])) {
//             start++;
//         }

//         while (start < end && !isAlphabet(arr[end])) {
//             end--;
//         }

//         if (toLower(arr[start]) != toLower(arr[end])) {
//             return false;
//         }

//         start++;
//         end--;
//     }

//     return true;
// }

// int main() {
//     char inputString[256];

//     cout << "Go ahead, type in a word or phrase to check: ";
//     cin.getline(inputString, 256);

//     if (isPalindrome(inputString)) {
//         cout << "\nYep, that's a palindrome!" << endl;
//     } else {
//         cout << "\nNope, that one's not a palindrome." << endl;
//     }

//     return 0;
// }



// //Question no 09

// #include <iostream>
// using namespace std;

// int getStringLength(char arr[]) {
//     int length = 0;
//     while (arr[length] != '\0') {
//         length++;
//     }
//     return length;
// }

// void printWordsReversed(char sentence[]) {
//     int length = getStringLength(sentence);
//     int endOfWord = length;

//     for (int i = length - 1; i >= -1; i--) {
//         if (sentence[i] == ' ' || i == -1) {
//             for (int j = i + 1; j < endOfWord; j++) {
//                 cout << sentence[j];
//             }
//             endOfWord = i;
//             if (i != -1) {
//                 cout << " ";
//             }
//         }
//     }
// }

// int main() {
//     char inputString[256];

//     cout << "Please enter a sentence you'd like me to reverse: ";
//     cin.getline(inputString, 256);

//     cout << "\nHere it is, all flipped around:\n";
//     printWordsReversed(inputString);
    
//     cout << endl; 

//     return 0;
// }
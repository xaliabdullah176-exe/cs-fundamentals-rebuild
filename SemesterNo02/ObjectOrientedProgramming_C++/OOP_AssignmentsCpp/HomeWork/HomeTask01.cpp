#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void getInput(char *str, int maxSize);
void display(char *str);
void searchByChar(char *str, char key);
int countVowels(char *str);
void extractVowels(char *str);
void reverseString(char *str);
void demoBuiltInFunctions(char *str);

int main()
{
    int size;
    cout << "Enter the maximum size of your string: ";
    cin >> size;

    char *myStr = new char[size + 1];

    getInput(myStr, size);

    cout << " Displaying String " << endl;
    display(myStr);

    char key;
    cout << "Enter character to search: ";
    cin >> key;
    searchByChar(myStr, key);

    cout << " Vowel Frequency : " << endl;
    cout << "Total Vowels: " << countVowels(myStr) << endl;

    cout << " Extracted Vowels :" << endl;
    extractVowels(myStr);

    cout << " Built-in Function Demo " << endl;
    demoBuiltInFunctions(myStr);

    cout << " Reversing String: " << endl;
    reverseString(myStr);
    cout << "Reversed string: ";
    display(myStr);

    delete[] myStr;

    return 0;
}

void getInput(char *str, int maxSize)
{
    cout << "Enter the text: ";
    cin.ignore();
    cin.getline(str, maxSize + 1);
}

void display(char *str)
{
    char *ptr = str;
    while (*ptr != '\0')
    {
        cout << *ptr;
        ptr++;
    }
    cout << endl;
}

void searchByChar(char *str, char key)
{
    int count = 0;
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == key)
        {
            cout << "Found '" << key << "' at index: " << i << endl;
            count++;
        }
    }
    if (count == 0)
        cout << "Character not found." << endl;
}

int countVowels(char *str)
{
    int count = 0;
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        char c = tolower(*(str + i));
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            count++;
        }
    }
    return count;
}

void extractVowels(char *str)
{
    cout << "Vowels in string: ";
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        char c = tolower(*(str + i));
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cout << *(str + i) << " ";
        }
    }
    cout << endl;
}

void reverseString(char *str)
{
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void demoBuiltInFunctions(char *str)
{
    cout << "Length (strlen): " << strlen(str) << endl;

    char temp[] = "Hello";
    if (strcmp(str, temp) == 0)
    {
        cout << "String matches 'Hello'" << endl;
    }
    else
    {
        cout << "String does not match 'Hello'" << endl;
    }

    cout << "First char to Upper: " << (char)toupper(*str) << endl;
}
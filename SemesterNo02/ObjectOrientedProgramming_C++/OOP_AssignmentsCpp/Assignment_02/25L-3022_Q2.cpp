#include <iostream>
#include <stdexcept>
using namespace std;

class MyString
{
private:
    char *str;
    int length;

    // Helper: Custom length calculator without built-in functions
    int calcLen(const char *s) const
    {
        int l = 0;
        while (*(s + l) != '\0')
            l++;
        return l;
    }

    // Helper: Custom copy without built-in functions
    // Note: Added 'const' here to fix the operator+ issue!
    void copyStr(char *dest, const char *src, int len) const
    {
        for (int i = 0; i < len; i++)
        {
            *(dest + i) = *(src + i);
        }
        *(dest + len) = '\0';
    }

public:
    // 1. Default Constructor
    MyString()
    {
        length = 0;
        str = new char[1];
        *str = '\0';
    }

    // 2. Parameterized Constructor
    MyString(const char *input)
    {
        length = calcLen(input);
        str = new char[length + 1];
        copyStr(str, input, length);
    }

    // 3. Copy Constructor (Rule of Three)
    MyString(const MyString &other)
    {
        length = other.length;
        str = new char[length + 1];
        copyStr(str, other.str, length);
    }

    // 4. Copy Assignment Operator (Rule of Three)
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        { // Self-assignment check
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            copyStr(str, other.str, length);
        }
        return *this;
    }

    // 5. Destructor (Rule of Three)
    ~MyString()
    {
        delete[] str;
    }

    // Member Functions
    int lengthOfString() const { return length; }

    int countWords() const
    {
        if (length == 0)
            return 0;
        int words = 0;
        bool inWord = false;
        for (int i = 0; i < length; i++)
        {
            if (*(str + i) != ' ' && !inWord)
            {
                words++;
                inWord = true;
            }
            else if (*(str + i) == ' ')
            {
                inWord = false;
            }
        }
        return words;
    }

    void toUpperCase() const
    {
        for (int i = 0; i < length; i++)
        {
            if (*(str + i) >= 'a' && *(str + i) <= 'z')
            {
                *(str + i) = *(str + i) - 32;
            }
        }
    }

    void toLowerCase() const
    {
        for (int i = 0; i < length; i++)
        {
            if (*(str + i) >= 'A' && *(str + i) <= 'Z')
            {
                *(str + i) = *(str + i) + 32;
            }
        }
    }

    void toSentenceCase() const
    {
        if (length > 0)
        {
            toLowerCase();
            if (*str >= 'a' && *str <= 'z')
            {
                *str = *str - 32;
            }
        }
    }

    MyString reverse() const
    {
        MyString rev;
        delete[] rev.str;
        rev.length = length;
        rev.str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            *(rev.str + i) = *(str + (length - 1 - i));
        }
        *(rev.str + length) = '\0';
        return rev;
    }

    void display() const
    {
        cout << str << endl;
    }

    // Operator Overloading
    MyString operator+(const MyString &other) const
    {
        MyString res;
        delete[] res.str;
        res.length = length + other.length;
        res.str = new char[res.length + 1];
        copyStr(res.str, str, length);
        copyStr(res.str + length, other.str, other.length);
        return res;
    }

    MyString operator+(const char *otherStr) const
    {
        MyString res;
        delete[] res.str;
        int otherLen = calcLen(otherStr);
        res.length = length + otherLen;
        res.str = new char[res.length + 1];
        copyStr(res.str, str, length);
        copyStr(res.str + length, otherStr, otherLen);
        return res;
    }

    friend MyString operator+(const char *lhs, const MyString &rhs)
    {
        MyString res(lhs);
        return res + rhs;
    }

    MyString &operator+=(const MyString &other)
    {
        *this = *this + other;
        return *this;
    }

    MyString &operator+=(const char *otherStr)
    {
        *this = *this + otherStr;
        return *this;
    }

    bool operator==(const MyString &other) const
    {
        if (length != other.length)
            return false;
        for (int i = 0; i < length; i++)
        {
            if (*(str + i) != *(other.str + i))
                return false;
        }
        return true;
    }

    bool operator!=(const MyString &other) const { return !(*this == other); }

    bool operator<(const MyString &other) const
    {
        int minLen = (length < other.length) ? length : other.length;
        for (int i = 0; i < minLen; i++)
        {
            if (*(str + i) < *(other.str + i))
                return true;
            if (*(str + i) > *(other.str + i))
                return false;
        }
        return length < other.length;
    }

    bool operator>(const MyString &other) const { return other < *this; }
    bool operator<=(const MyString &other) const { return !(*this > other); }
    bool operator>=(const MyString &other) const { return !(*this < other); }

    char &operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            throw out_of_range("Index out of bounds");
        }
        return *(str + index);
    }

    MyString operator()() const
    {
        return reverse();
    }

    friend ostream &operator<<(ostream &os, const MyString &obj)
    {
        os << obj.str;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &obj)
    {
        char buffer[1000]; // Temporary buffer for input
        is.getline(buffer, 1000);
        obj = MyString(buffer);
        return is;
    }
};

int main()
{
    int choice;
    MyString s1, s2;
    do
    {
        cout << "\n============= Custom Text Processing Engine =============" << endl;
        cout << "1. Enter new string" << endl;
        cout << "2. Display string" << endl;
        cout << "3. Show length" << endl;
        cout << "4. Count words" << endl;
        cout << "5. Convert to uppercase" << endl;
        cout << "6. Convert to lowercase" << endl;
        cout << "7. Convert to sentence case" << endl;
        cout << "8. Reverse string" << endl;
        cout << "9. Concatenate another string" << endl;
        cout << "10. Compare with another string" << endl;
        cout << "11. Access character using index []" << endl;
        cout << "12. Test assignment operator =" << endl;
        cout << "13. Test function call operator ()" << endl;
        cout << "14. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clean buffer for next getline

        if (choice == 1)
        {
            cout << "Enter string: ";
            cin >> s1;
        }
        else if (choice == 2)
        {
            cout << "String is: " << s1 << endl;
        }
        else if (choice == 3)
        {
            cout << "Length: " << s1.lengthOfString() << endl;
        }
        else if (choice == 4)
        {
            cout << "Words: " << s1.countWords() << endl;
        }
        else if (choice == 5)
        {
            s1.toUpperCase();
            cout << "Uppercase: " << s1 << endl;
        }
        else if (choice == 6)
        {
            s1.toLowerCase();
            cout << "Lowercase: " << s1 << endl;
        }
        else if (choice == 7)
        {
            s1.toSentenceCase();
            cout << "Sentence Case: " << s1 << endl;
        }
        else if (choice == 8)
        {
            cout << "Reversed: " << s1.reverse() << endl;
        }
        else if (choice == 9)
        {
            cout << "Enter second string: ";
            cin >> s2;
            s1 += s2;
            cout << "Concatenated: " << s1 << endl;
        }
        else if (choice == 10)
        {
            cout << "Enter second string to compare: ";
            cin >> s2;
            cout << "Equal? " << (s1 == s2) << "\ns1 < s2? " << (s1 < s2) << endl;
        }
        else if (choice == 11)
        {
            int idx;
            cout << "Enter index: ";
            cin >> idx;
            try
            {
                cout << "Char: " << s1[idx] << endl;
            }
            catch (exception &e)
            {
                cout << e.what() << endl;
            }
        }
        else if (choice == 12)
        {
            s2 = s1;
            cout << "Copied string s2: " << s2 << endl;
        }
        else if (choice == 13)
        {
            cout << "Called (): " << s1() << endl;
        }
        else if (choice != 14)
        {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 14);
    return 0;
}
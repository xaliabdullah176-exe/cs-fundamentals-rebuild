#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout << "Enter a single character: ";
    cin >> ch;

    // Check if it's a number (0-9)
    if (ch >= '0' && ch <= '9')
    {
        cout << "A Number" << endl;
    }
    // Check if it's a lowercase alphabet (a-z)
    else if (ch >= 'a' && ch <= 'z')
    {
        cout << "Lowercase Alphabet" << endl;
    }
    // Check if it's an uppercase alphabet (A-Z)
    else if (ch >= 'A' && ch <= 'Z')
    {
        cout << "Uppercase Alphabet" << endl;
    }
    // Check if it's a punctuation mark
    else if (ch == ',' || ch == '.' || ch == '?' || ch == '"' || ch == '\'' ||
             ch == ';' || ch == ':' || ch == '`')
    {
        cout << "Punctuation marks" << endl;
    }
    // Check if it's brackets/parenthesis
    else if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
    {
        cout << "Brackets/Parenthesis" << endl;
    }
    // Check if it's a symbol
    else if (ch == '_' || ch == '-' || ch == '+' || ch == '*' || ch == '&' ||
             ch == '^' || ch == '%' || ch == '$' || ch == '#' || ch == '@' ||
             ch == '!' || ch == '~' || ch == '<' || ch == '>' || ch == '/' ||
             ch == '\\')
    {
        cout << "Symbols" << endl;
    }
    // Check if it's a space
    else if (ch == ' ')
    {
        cout << "Space" << endl;
    }
    // Everything else is a special character
    else
    {
        cout << "Special Character" << endl;
    }

    return 0;
}
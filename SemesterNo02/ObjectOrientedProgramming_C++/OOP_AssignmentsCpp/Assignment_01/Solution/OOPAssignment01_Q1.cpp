#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string trim(string s)
{
    string result = "";
    const char *ptr = s.c_str();
    int length = s.length();
    int start = 0;
    int end = length - 1;

    while (start < length && (*(ptr + start) == ' ' || *(ptr + start) == '\t' || *(ptr + start) == '\r'))
    {
        start++;
    }
    while (end >= 0 && (*(ptr + end) == ' ' || *(ptr + end) == '\t' || *(ptr + end) == '\r'))
    {
        end--;
    }
    for (int i = start; i <= end; i++)
    {
        result += *(ptr + i);
    }
    return result;
}

int main()
{
    ifstream inFile("menu_data.txt");
    if (!inFile)
    {
        cout << "ERROR: menu_data.txt not found!" << endl;
        return 1;
    }

    int rows = 0;
    string line;
    while (getline(inFile, line))
    {
        if (trim(line) != "")
        {
            rows++;
        }
    }

    inFile.clear();
    inFile.seekg(0, ios::beg);

    string **tempGrid = new string *[rows];

    for (int i = 0; i < rows; i++)
    {
        *(tempGrid + i) = new string[7];

        getline(inFile, line);

        int col = 0;
        string currentToken = "";
        const char *linePtr = line.c_str();
        int lineLen = line.length();

        for (int c = 0; c < lineLen; c++)
        {
            if (*(linePtr + c) == ',')
            {
                if (col < 7)
                    *(*(tempGrid + i) + col) = trim(currentToken);
                currentToken = "";
                col++;
            }
            else
            {
                currentToken += *(linePtr + c);
            }
        }
        if (col < 7)
            *(*(tempGrid + i) + col) = trim(currentToken);

        while (col < 6)
        {
            col++;
            *(*(tempGrid + i) + col) = "";
        }
    }
    inFile.close();

    string **menu = new string *[rows];

    for (int i = 0; i < rows; i++)
    {
        *(menu + i) = new string[8];

        for (int j = 0; j < 7; j++)
        {
            *(*(menu + i) + j) = *(*(tempGrid + i) + j);
        }

        *(*(menu + i) + 7) = "\0";
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] *(tempGrid + i);
    }
    delete[] tempGrid;

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            bool swapNeeded = false;

            string cuisine1 = *(*(menu + j) + 1);
            string cuisine2 = *(*(menu + j + 1) + 1);

            if (cuisine1 != cuisine2)
            {
                swapNeeded = cuisine1 > cuisine2;
            }
            else
            {
                string rest1 = *(*(menu + j) + 4);
                string rest2 = *(*(menu + j + 1) + 4);

                if (rest1 != rest2)
                {
                    swapNeeded = rest1 > rest2;
                }
                else
                {
                    string cat1 = *(*(menu + j) + 0);
                    string cat2 = *(*(menu + j + 1) + 0);

                    if (cat1 != cat2)
                    {
                        swapNeeded = cat1 > cat2;
                    }
                    else
                    {
                        string pStr1 = *(*(menu + j) + 3);
                        string pStr2 = *(*(menu + j + 1) + 3);

                        double p1 = 0, p2 = 0;
                        if (pStr1 != "")
                            p1 = stod(pStr1);
                        if (pStr2 != "")
                            p2 = stod(pStr2);

                        swapNeeded = p1 > p2;
                    }
                }
            }

            if (swapNeeded)
            {
                string *temp = *(menu + j);
                *(menu + j) = *(menu + j + 1);
                *(menu + j + 1) = temp;
            }
        }
    }

    ofstream outFile("sorted_menu.txt");
    outFile << "=== HEISENBERG'S ORGANIZED MENU ===\n\n";

    for (int i = 0; i < rows; i++)
    {
        string outLine = *(*(menu + i) + 0) + " | " + *(*(menu + i) + 2) + " | " + *(*(menu + i) + 3) + " RS | " + *(*(menu + i) + 4) + "\n";
        outFile << outLine;
        cout << outLine;
    }
    outFile.close();
    cout << "\nFile 'sorted_menu.txt' created successfully!\n";

    string searchType;
    cout << "\nEnter Cuisine Type to search: ";
    cin >> searchType;

    cout << "\nSearch Results:\n";
    bool found = false;
    for (int i = 0; i < rows; i++)
    {
        string currentCuisine = *(*(menu + i) + 1);

        if (currentCuisine.find(searchType) != -1)
        {
            cout << "- " << *(*(menu + i) + 2) << " (" << currentCuisine << ")\n";
            found = true;
        }
    }

    if (!found)
        cout << "No items found.\n";

    for (int i = 0; i < rows; i++)
    {
        delete[] *(menu + i);
    }
    delete[] menu;
    menu = NULL;

    return 0;
}
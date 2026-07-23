#include <iostream>
#include <string>
using namespace std;

int g_rowCount = 0;
int *g_colSizes = NULL;

string **CreateDynamicArray(char *ws)
{
    int hashCount = 0;

    for (int i = 0; *(ws + i) != '\0'; i++)
    {
        if (*(ws + i) == '#')
        {
            hashCount++;
        }
    }

    g_rowCount = hashCount + 1;

    string **dictionary = new string *[g_rowCount];

    g_colSizes = new int[g_rowCount];

    int length = 0;
    while (*(ws + length) != '\0')
    {
        length++;
    }

    int row = 0;
    int start = 0;

    for (int i = 0; i <= length; i++)
    {

        if (*(ws + i) == '#' || *(ws + i) == '\0')
        {

            int spaceCount = 0;
            for (int k = start; k < i; k++)
            {
                if (*(ws + k) == ' ')
                {
                    spaceCount++;
                }
            }
            int cols = spaceCount + 1;

            *(dictionary + row) = new string[cols];

            *(g_colSizes + row) = cols;

            string currentWord = "";
            int colIndex = 0;

            for (int k = start; k < i; k++)
            {
                if (*(ws + k) == ' ')
                {

                    *(*(dictionary + row) + colIndex) = currentWord;

                    currentWord = "";
                    colIndex++;
                }
                else
                {

                    currentWord += *(ws + k);
                }
            }

            *(*(dictionary + row) + colIndex) = currentWord;

            row++;
            start = i + 1;
        }
    }

    return dictionary;
}

int main()
{

    char input[] = "abandon discontinue vacate#absent missing unavailable#cable wire#calculate compute determine measure#safety security refuge";
    string **thesaurus = CreateDynamicArray(input);

    char choice;

    do
    {
        string searchWord;
        cout << "\nEnter word to paraphrase: ";
        cin >> searchWord;

        bool found = false;

        // Search the dictionary
        for (int i = 0; i < g_rowCount; i++)
        {
            if (*(*(thesaurus + i) + 0) == searchWord)
            {
                int lastIndex = *(g_colSizes + i) - 1;
                cout << "Replaced word: " << *(*(thesaurus + i) + lastIndex) << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Word not found in thesaurus." << endl;
        }

        cout << "\nDo you want to search again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    for (int i = 0; i < g_rowCount; i++)
    {
        delete[] *(thesaurus + i);
    }
    delete[] thesaurus;
    delete[] g_colSizes;

    thesaurus = NULL;
    g_colSizes = NULL;

    cout << "Exiting program. Goodbye!" << endl;

    return 0; 
}
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int g_rows = 1;
int g_cols = 2;

void addItem(string ***cartPtr, string id, string name);
void addAttribute(string ***cartPtr, string id, string attrName, string attrValue);
void getItemInfo(string **cart, string id);
void totalCartValue(string **cart, string attrName);
void avgCartValue(string **cart, string attrName);
void removeItem(string ***cartPtr, string id);
void removeAttribute(string **cart, string id, string attrName);
void clearCart(string ***cartPtr);
void filterByAttribute(string **cart, string attrName, string attrValue);
void sortCartByAttr(string **cart, string attrName);

int main()
{
    string **cart = new string *[g_rows];
    *(cart + 0) = new string[g_cols];

    *(*(cart + 0) + 0) = "ID";
    *(*(cart + 0) + 1) = "Name";

    int choice;
    string inputId, inputName;

    cout << "===== SHOPPING CART MENU =====" << endl;

    do
    {
        cout << "\n1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Add Attribute" << endl;
        cout << "4. Remove Attribute" << endl;
        cout << "5. Get Item Info" << endl;
        cout << "6. Sort Cart By Attribute" << endl;
        cout << "7. Total Cart Value" << endl;
        cout << "8. Average Cart Value" << endl;
        cout << "9. Filter By Attribute" << endl;
        cout << "10. Clear Cart" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Item ID: ";
            cin >> inputId;
            cout << "Enter Item Name: ";
            cin >> inputName;
            addItem(&cart, inputId, inputName);
            break;
        case 2:
            cout << "Enter Item ID to Remove: ";
            cin >> inputId;
            removeItem(&cart, inputId);
            break;
        case 3:
        {
            string attrName, attrValue;
            cout << "Enter Item ID: ";
            cin >> inputId;
            cout << "Enter Attribute Name: ";
            cin >> attrName;
            cout << "Enter Attribute Value: ";
            cin >> attrValue;
            addAttribute(&cart, inputId, attrName, attrValue);
            break;
        }
        case 4:
        {
            string attrName;
            cout << "Enter Item ID: ";
            cin >> inputId;
            cout << "Enter Attribute Name to Remove: ";
            cin >> attrName;
            removeAttribute(cart, inputId, attrName);
            break;
        }
        case 5:
            cout << "Enter Item ID: ";
            cin >> inputId;
            getItemInfo(cart, inputId);
            break;
        case 6:
        {
            string attrName;
            cout << "Enter Attribute to Sort By: ";
            cin >> attrName;
            sortCartByAttr(cart, attrName);
            break;
        }
        case 7:
        {
            string attrName;
            cout << "Enter Price Attribute Name: ";
            cin >> attrName;
            totalCartValue(cart, attrName);
            break;
        }
        case 8:
        {
            string attrName;
            cout << "Enter Price Attribute Name: ";
            cin >> attrName;
            avgCartValue(cart, attrName);
            break;
        }
        case 9:
        {
            string attrName, attrValue;
            cout << "Enter Attribute Name: ";
            cin >> attrName;
            cout << "Enter Attribute Value: ";
            cin >> attrValue;
            filterByAttribute(cart, attrName, attrValue);
            break;
        }
        case 10:
            clearCart(&cart);
            break;
        case 0:
            cout << "\nThank you for using Shopping Cart System!" << endl;
            break;
        }

    } while (choice != 0);

    for (int i = 0; i < g_rows; i++)
    {
        delete[] *(cart + i);
    }
    delete[] cart;
    cart = NULL;

    return 0;
}

void addItem(string ***cartPtr, string id, string name)
{
    string **oldCart = *cartPtr;
    int newRows = g_rows + 1;

    string **newCart = new string *[newRows];
    for (int i = 0; i < newRows; i++)
    {
        *(newCart + i) = new string[g_cols];
    }

    for (int i = 0; i < g_rows; i++)
    {
        for (int j = 0; j < g_cols; j++)
        {
            *(*(newCart + i) + j) = *(*(oldCart + i) + j);
        }
    }

    *(*(newCart + g_rows) + 0) = id;
    *(*(newCart + g_rows) + 1) = name;

    for (int j = 2; j < g_cols; j++)
    {
        *(*(newCart + g_rows) + j) = "";
    }

    for (int i = 0; i < g_rows; i++)
    {
        delete[] *(oldCart + i);
    }
    delete[] oldCart;

    g_rows = newRows;
    *cartPtr = newCart;

    cout << "\nItem added successfully!\n";
}

void addAttribute(string ***cartPtr, string id, string attrName, string attrValue)
{
    string **cart = *cartPtr;
    int colIndex = -1;

    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }

    if (colIndex == -1)
    {
        int newCols = g_cols + 1;
        string **newCart = new string *[g_rows];

        for (int i = 0; i < g_rows; i++)
        {
            *(newCart + i) = new string[newCols];

            for (int j = 0; j < g_cols; j++)
            {
                *(*(newCart + i) + j) = *(*(cart + i) + j);
            }

            if (i == 0)
            {
                *(*(newCart + i) + g_cols) = attrName;
            }
            else
            {
                *(*(newCart + i) + g_cols) = "";
            }
        }

        for (int i = 0; i < g_rows; i++)
        {
            delete[] *(cart + i);
        }
        delete[] cart;

        cart = newCart;
        *cartPtr = newCart;
        colIndex = g_cols;
        g_cols = newCols;
    }

    bool itemFound = false;

    for (int i = 1; i < g_rows; i++)
    {
        if (*(*(cart + i) + 0) == id)
        {
            *(*(cart + i) + colIndex) = attrValue;
            itemFound = true;
            break;
        }
    }

    if (itemFound)
    {
        cout << "\nAttribute added successfully!\n";
    }
    else
    {
        cout << "\nItem ID not found!\n";
    }
}

void getItemInfo(string **cart, string id)
{
    bool found = false;
    for (int i = 1; i < g_rows; i++)
    {
        if (*(*(cart + i) + 0) == id)
        {
            cout << "\nItem ID: " << id << endl;
            for (int j = 1; j < g_cols; j++)
            {
                if (*(*(cart + i) + j) != "")
                {
                    cout << *(*(cart + 0) + j) << ": " << *(*(cart + i) + j) << endl;
                }
            }
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\nItem not found!" << endl;
}

void totalCartValue(string **cart, string attrName)
{
    int colIndex = -1;
    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }

    if (colIndex == -1)
    {
        cout << "\nAttribute '" << attrName << "' not found!" << endl;
        return;
    }

    double total = 0.0;
    for (int i = 1; i < g_rows; i++)
    {
        string val = *(*(cart + i) + colIndex);
        if (val != "")
        {
            total += stod(val);
        }
    }
    cout << "\nTotal Cart Value: " << total << endl;
}

void avgCartValue(string **cart, string attrName)
{
    int colIndex = -1;
    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }

    if (colIndex == -1)
    {
        cout << "\nAttribute '" << attrName << "' not found!" << endl;
        return;
    }

    double total = 0.0;
    int count = 0;
    for (int i = 1; i < g_rows; i++)
    {
        string val = *(*(cart + i) + colIndex);
        if (val != "")
        {
            total += stod(val);
            count++;
        }
    }

    if (count > 0)
        cout << "\nAverage Cart Value: " << (total / count) << endl;
    else
        cout << "\nAverage Cart Value: 0" << endl;
}

void removeItem(string ***cartPtr, string id)
{
    string **cart = *cartPtr;
    int targetRow = -1;

    for (int i = 1; i < g_rows; i++)
    {
        if (*(*(cart + i) + 0) == id)
        {
            targetRow = i;
            break;
        }
    }

    if (targetRow == -1)
    {
        cout << "\nItem not found!\n";
        return;
    }

    int newRows = g_rows - 1;
    string **newCart = new string *[newRows];
    int newRowIndex = 0;

    for (int i = 0; i < g_rows; i++)
    {
        if (i == targetRow)
            continue;

        *(newCart + newRowIndex) = new string[g_cols];
        for (int j = 0; j < g_cols; j++)
        {
            *(*(newCart + newRowIndex) + j) = *(*(cart + i) + j);
        }
        newRowIndex++;
    }

    for (int i = 0; i < g_rows; i++)
    {
        delete[] *(cart + i);
    }
    delete[] cart;

    *cartPtr = newCart;
    g_rows = newRows;
    cout << "\nItem removed successfully!\n";
}

void removeAttribute(string **cart, string id, string attrName)
{
    int colIndex = -1;
    int targetRow = -1;

    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }
    for (int i = 1; i < g_rows; i++)
    {
        if (*(*(cart + i) + 0) == id)
        {
            targetRow = i;
            break;
        }
    }

    if (colIndex != -1 && targetRow != -1)
    {
        *(*(cart + targetRow) + colIndex) = "";
        cout << "\nAttribute removed successfully!\n";
    }
    else
    {
        cout << "\nItem or Attribute not found!\n";
    }
}

void filterByAttribute(string **cart, string attrName, string attrValue)
{
    int colIndex = -1;
    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }

    if (colIndex == -1)
    {
        cout << "\nAttribute not found!\n";
        return;
    }

    cout << "\nFiltered Items:\n";
    bool found = false;
    for (int i = 1; i < g_rows; i++)
    {
        if (*(*(cart + i) + colIndex) == attrValue)
        {
            cout << *(*(cart + i) + 0) << " - " << *(*(cart + i) + 1) << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No items match this filter.\n";
}

void clearCart(string ***cartPtr)
{
    string **cart = *cartPtr;
    string **newCart = new string *[1];
    *(newCart + 0) = new string[g_cols];

    for (int j = 0; j < g_cols; j++)
    {
        *(*(newCart + 0) + j) = *(*(cart + 0) + j);
    }

    for (int i = 0; i < g_rows; i++)
    {
        delete[] *(cart + i);
    }
    delete[] cart;

    *cartPtr = newCart;
    g_rows = 1;
    cout << "\nCart cleared successfully!\n";
}

void sortCartByAttr(string **cart, string attrName)
{
    int colIndex = -1;
    for (int j = 0; j < g_cols; j++)
    {
        if (*(*(cart + 0) + j) == attrName)
        {
            colIndex = j;
            break;
        }
    }

    if (colIndex == -1)
    {
        cout << "\nAttribute not found!\n";
        return;
    }

    for (int i = 1; i < g_rows - 1; i++)
    {
        for (int j = 1; j < g_rows - i; j++)
        {
            string val1 = *(*(cart + j) + colIndex);
            string val2 = *(*(cart + j + 1) + colIndex);

            bool swapNeeded = false;

            if (val1 != "" && val2 != "" && isdigit(val1[0]) && isdigit(val2[0]))
            {
                if (stod(val1) > stod(val2))
                    swapNeeded = true;
            }
            else
            {
                if (val1 > val2)
                    swapNeeded = true;
            }

            if (swapNeeded)
            {
                string *temp = *(cart + j);
                *(cart + j) = *(cart + j + 1);
                *(cart + j + 1) = temp;
            }
        }
    }

    cout << "\nCart sorted successfully!\n";
    cout << "Items in Cart:\n";
    for (int i = 1; i < g_rows; i++)
    {
        cout << *(*(cart + i) + 0) << " - " << *(*(cart + i) + 1) << " - " << *(*(cart + i) + colIndex) << endl;
    }
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to Create/Overwrite the file
void createLibraryFile()
{
    ofstream outFile("library.txt");

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int n, id, copies;
    string title, author;

    cout << "How many books to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Book ID: ";
        cin >> id;
        // VALIDATION: ID should not be negative
        while (id < 0) 
        {
            cout << "Invalid ID. Enter again: ";
            cin >> id;
        }

        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        
        cout << "Enter Copies: ";
        cin >> copies;
        // VALIDATION: Copies cannot be negative
        while (copies < 0) 
        {
            cout << "Invalid number of copies. Enter again: ";
            cin >> copies;
        }

        // Write to file
        outFile << id << " " << title << " " << author << " " << copies << endl;
    }

    outFile.close();
    cout << "Library file created successfully." << endl;
}

// Function to Append new books
void appendBooks()
{
    ofstream outFile("library.txt", ios::app); // Append mode

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int n, id, copies;
    string title, author;

    cout << "How many new books to append? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Book ID: ";
        cin >> id;
        // VALIDATION
        while (id < 0) 
        {
            cout << "Invalid ID. Enter again: ";
            cin >> id;
        }

        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        
        cout << "Enter Copies: ";
        cin >> copies;
        // VALIDATION
        while (copies < 0) 
        {
            cout << "Invalid number of copies. Enter again: ";
            cin >> copies;
        }

        outFile << id << " " << title << " " << author << " " << copies << endl;
    }

    outFile.close();
    cout << "Books appended successfully." << endl;
}

// Function to Display all books
void displayBooks()
{
    ifstream inFile("library.txt");

    if (!inFile)
    {
        cout << "File not found! Create it first." << endl;
        return;
    }

    int id, copies;
    string title, author;

    cout << "\n--- Current Library Inventory ---" << endl;
    cout << "ID\tTitle\t\tAuthor\t\tCopies" << endl;

    // Reads until end of file
    while (inFile >> id >> title >> author >> copies)
    {
        cout << id << "\t" << title << "\t\t" << author << "\t\t" << copies << endl;
    }

    inFile.close();
}

// Function to Search for a book by ID
void searchBook()
{
    ifstream inFile("library.txt");

    if (!inFile)
    {
        cout << "File not found!" << endl;
        return;
    }

    int searchID, id, copies;
    string title, author;
    bool found = false;

    cout << "Enter Book ID to search: ";
    cin >> searchID;

    while (inFile >> id >> title >> author >> copies)
    {
        if (id == searchID)
        {
            cout << "\nBook Found!" << endl;
            cout << "ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Copies: " << copies << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Not Found." << endl;
    }

    inFile.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Create Library File\n2. Append Books\n3. Display All Books\n4. Search Book\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            createLibraryFile();
        else if (choice == 2)
            appendBooks();
        else if (choice == 3)
            displayBooks();
        else if (choice == 4)
            searchBook();
        else if (choice == 5)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid choice!" << endl;

    } while (choice != 5);

    return 0;
}

// Question no 02

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createServiceFile()
{
    ofstream outFile("service.txt");

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int n, id, cost;
    string vehicleNo, type;

    cout << "How many service records to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Service ID: ";
        cin >> id;
        cout << "Enter Vehicle No: ";
        cin >> vehicleNo;
        cout << "Enter Type: ";
        cin >> type;
        cout << "Enter Cost: ";
        cin >> cost;

        while (cost < 0)
        {
            cout << "Invalid Cost. Enter again: ";
            cin >> cost;
        }

        outFile << id << " " << vehicleNo << " " << type << " " << cost << endl;
    }

    outFile.close();
    cout << "Service file created." << endl;
}

void appendService()
{
    ofstream outFile("service.txt", ios::app);

    if (!outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int n, id, cost;
    string vehicleNo, type;

    cout << "How many new records to append? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Service ID: ";
        cin >> id;
        cout << "Enter Vehicle No: ";
        cin >> vehicleNo;
        cout << "Enter Type: ";
        cin >> type;
        cout << "Enter Cost: ";
        cin >> cost;

        while (cost < 0)
        {
            cout << "Invalid Cost. Enter again: ";
            cin >> cost;
        }

        outFile << id << " " << vehicleNo << " " << type << " " << cost << endl;
    }

    outFile.close();
    cout << "Records appended." << endl;
}

void displayServices()
{
    ifstream inFile("service.txt");

    if (!inFile)
    {
        cout << "File not found!" << endl;
        return;
    }

    int id, cost;
    string vehicleNo, type;

    cout << "\n--- Service Records ---" << endl;
    cout << "ID\tVehicle\t\tType\t\tCost" << endl;

    while (inFile >> id >> vehicleNo >> type >> cost)
    {
        cout << id << "\t" << vehicleNo << "\t\t" << type << "\t\t" << cost << endl;
    }

    inFile.close();
}

void calculateRevenue()
{
    ifstream inFile("service.txt");

    if (!inFile)
    {
        cout << "File not found!" << endl;
        return;
    }

    int id, cost;
    string vehicleNo, type;
    long totalRevenue = 0;

    while (inFile >> id >> vehicleNo >> type >> cost)
    {
        totalRevenue = totalRevenue + cost;
    }

    cout << "\nTotal Revenue Generated: " << totalRevenue << endl;

    inFile.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Create Service File\n2. Append Record\n3. Display Records\n4. Calculate Revenue\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            createServiceFile();
        else if (choice == 2)
            appendService();
        else if (choice == 3)
            displayServices();
        else if (choice == 4)
            calculateRevenue();
        else if (choice == 5)
            cout << "Exiting..." << endl;
        else
            cout << "Invalid choice!" << endl;

    } while (choice != 5);

    return 0;
}

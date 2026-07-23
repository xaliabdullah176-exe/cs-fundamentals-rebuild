#include <iostream>
using namespace std;

int main()
{
    int cNum, qty, userID = 1, serviceTax, Total, price;
    serviceTax = 0;
    Total = 0;
    // Here the do while loop will run the principal code until the user enters 0 to exit
    do
    {
        cout << "================================" << endl;
        cout << "Welcome to Fast Hub Coffee Shop" << endl;
        cout << "================================" << endl;
        // Menu Display
        cout << "Menu: " << endl;
        cout << "1. Espresso - Rs 230" << endl;
        cout << "2. Latte - Rs 150" << endl;
        cout << "3. Cappuccino - Rs 250" << endl;
        // Taking user input for coffee choice and quantity
        cout << "Enter your choice (1-3) or 0 to exit: ";
        cin >> cNum;
        cout << "Enter the number of cups: ";
        cin >> qty;
        // Calculating price based on choice and quantity
        if (cNum == 1)
        {
            cout << "You ordered " << qty << " Espresso(s)." << endl;
            price = 230 * qty;
        }
        else if (cNum == 2)
        {
            cout << "You ordered " << qty << " Latte(s)." << endl;
            price = 150 * qty;
        }
        else if (cNum == 3)
        {
            cout << "You ordered " << qty << " Cappuccino(s)." << endl;
            price = 250 * qty;
        }
        else if (cNum < 0 || cNum > 3)
        {
            cout << "Invalid choice. Please select a valid option." << endl;
            continue;
        }
        else if (cNum == 0)
        {
            cout << "Thank you for visiting Fast Hub Coffee Shop!" << endl;
            break;
        }
        // Asking for additional options and updating price accordingly
        cout << "Need Added Sugar? (Y for Yes, N for No): ";
        char sugar;
        cin >> sugar;
        if (sugar == 'Y' || sugar == 'y')
        {
            price += 30 * qty;
            cout << "Added sugar for " << qty << " cup(s)." << endl;
        }

        cout << "Need Whipped Cream? (Y for Yes, N for No): ";
        char cream;
        cin >> cream;
        if (cream == 'Y' || cream == 'y')
        {
            price += 50 * qty;
            cout << "Added whipped cream for " << qty << " cup(s)." << endl;
        }
        // Calculating service tax and total amount
        serviceTax = price * 0.20;
        Total = price + serviceTax;
        // Displaying order summary
        cout << "================================" << endl;
        cout << "Your order will be ready shortly. Enjoy your coffee!" << endl;
        cout << "================================" << endl;
        cout << "Summary Of Your Order" << endl;
        cout << "======================" << endl;
        cout << "User ID: " << userID << endl;
        cout << "Coffee Type: " << cNum << endl;
        cout << "Quantity: " << qty << endl;
        cout << "Price: Rs " << price << endl;
        cout << "Service Tax: Rs " << serviceTax << endl;
        cout << "Total Amount: Rs " << Total << endl;
        cout << "======================" << endl;
        // Incrementing user ID for next order
        userID++;
    } while (cNum != 0);
}
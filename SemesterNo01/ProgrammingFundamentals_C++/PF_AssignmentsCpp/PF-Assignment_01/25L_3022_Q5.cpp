#include <iostream>
using namespace std;

int main() {
    //  Displaying Program Information
    cout << "========================================" << endl;
    cout << "  Pakistan Zip Code City Identifier" << endl;
    cout << "========================================" << endl;
    cout << "Enter a 5-digit zip code to find the city and province" << endl;
    cout << endl;
    
    //  Declaring variables
    int zipCode;
    int firstTwoDigits;
    
    //  A Message about zip codes
    cout << "Examples of zip codes:" << endl;
    cout << "75xxx → Karachi, Sindh" << endl;
    cout << "54xxx → Lahore, Punjab" << endl;
    cout << "51xxx → Islamabad, Federal Capital" << endl;
    cout << "42xxx → Faisalabad, Punjab" << endl;
    cout << endl;
    
    //  Getting input from user
    cout << "Enter 5-digit zip code: ";
    cin >> zipCode;
    cout << endl;
    
    //  Validating zip code (should be 5 digits)
    if (zipCode < 10000 || zipCode > 99999) {
        cout << "Error: Please enter a valid 5-digit zip code!" << endl;
        return 0;
    }
    
    //  Extracting first two digits
    firstTwoDigits = zipCode / 1000;  // This gives us first 2 digits
    
    cout << "Zip Code: " << zipCode << endl;
    cout << "First two digits: " << firstTwoDigits << endl;
    cout << endl;
    
    //  Identifying city and province using if-else statements
    cout << "========================================" << endl;
    cout << "           LOCATION DETAILS" << endl;
    cout << "========================================" << endl;
    
    // Sindh Province Cities
    if (firstTwoDigits == 75) {
        cout << "City: Karachi" << endl;
        cout << "Province: Sindh" << endl;
        cout << "Description: Largest city and economic hub of Pakistan" << endl;
    }
    else if (firstTwoDigits == 70) {
        cout << "City: Hyderabad" << endl;
        cout << "Province: Sindh" << endl;
        cout << "Description: Second largest city of Sindh province" << endl;
    }
    
    // Punjab Province Cities
    else if (firstTwoDigits == 54) {
        cout << "City: Lahore" << endl;
        cout << "Province: Punjab" << endl;
        cout << "Description: Provincial capital and cultural center" << endl;
    }
    else if (firstTwoDigits == 42) {
        cout << "City: Faisalabad" << endl;
        cout << "Province: Punjab" << endl;
        cout << "Description: Industrial city known for textiles" << endl;
    }
    else if (firstTwoDigits == 61) {
        cout << "City: Multan" << endl;
        cout << "Province: Punjab" << endl;
        cout << "Description: City of saints and historical significance" << endl;
    }
    else if (firstTwoDigits == 35) {
        cout << "City: Gujranwala" << endl;
        cout << "Province: Punjab" << endl;
        cout << "Description: Industrial city in central Punjab" << endl;
    }
    
    // Federal Capital
    else if (firstTwoDigits == 51 || firstTwoDigits == 44) {
        cout << "City: Islamabad" << endl;
        cout << "Province: Federal Capital Territory" << endl;
        cout << "Description: Capital city of Pakistan" << endl;
    }
    
    // Khyber Pakhtunkhwa Cities
    else if (firstTwoDigits == 25) {
        cout << "City: Peshawar" << endl;
        cout << "Province: Khyber Pakhtunkhwa" << endl;
        cout << "Description: Provincial capital and gateway to Afghanistan" << endl;
    }
    
    // Balochistan Cities
    else if (firstTwoDigits == 87) {
        cout << "City: Quetta" << endl;
        cout << "Province: Balochistan" << endl;
        cout << "Description: Provincial capital and fruit garden of Pakistan" << endl;
    }
    
    // Azad Kashmir
    else if (firstTwoDigits == 13) {
        cout << "City: Muzaffarabad" << endl;
        cout << "Province: Azad Jammu & Kashmir" << endl;
        cout << "Description: Capital of Azad Kashmir" << endl;
    }
    
    // If zip code doesn't match any known pattern then we will use the else statement
    else {
        cout << "City: Unknown" << endl;
        cout << "Province: Unknown" << endl;
        cout << "Description: Zip code not found in our database" << endl;
        cout << endl;
        cout << "Known zip code prefixes:" << endl;
        cout << "75 → Karachi, Sindh" << endl;
        cout << "70 → Hyderabad, Sindh" << endl;
        cout << "54 → Lahore, Punjab" << endl;
        cout << "42 → Faisalabad, Punjab" << endl;
        cout << "61 → Multan, Punjab" << endl;
        cout << "35 → Gujranwala, Punjab" << endl;
        cout << "51/44 → Islamabad, Federal Capital" << endl;
        cout << "25 → Peshawar, Khyber Pakhtunkhwa" << endl;
        cout << "87 → Quetta, Balochistan" << endl;
        cout << "13 → Muzaffarabad, Azad Kashmir" << endl;
    }
    
    cout << "========================================" << endl;
    
    return 0;
}
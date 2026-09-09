#include <iostream>
using namespace std;

const double PI = 3.14159;

int main()
{
    float radius, price;

    cout << "Enter the Price First in USD and the Radius in Inches of the pizza Later " << endl;

    cin >> radius >> price;

    if (price < 0 || radius <= 0)
        cout << "The Price and the Radius cannot be less than zero enter greater than 0 " << endl;
    else
        cin >> radius >> price;

    // Computing the Area per Sq Inch

    double areaOfPizza = PI * (radius) * (radius);

    // Computing the Price of pizza per square inches;

    double pricePerSqInch = (price) / (areaOfPizza);

    cout << " The Final Price per Square inches of the Pizza is: " << endl;
    cout << pricePerSqInch << "$" << " per sq inch" << endl;

    system("pause");
    return 0;
}
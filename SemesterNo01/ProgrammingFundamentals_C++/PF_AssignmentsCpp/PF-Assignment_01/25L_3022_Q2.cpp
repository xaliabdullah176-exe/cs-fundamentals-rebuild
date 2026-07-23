#include <iostream>
using namespace std;

int main()
{
    int choice;
    cout << "Choose One Shape From the List: " << endl;
    cout << "1. Square (Area and Perimeter)" << endl;
    cout << "2. Rectangle (Area and Perimeter)" << endl;
    cout << "3. Circle (Area and Circumference)" << endl;
    cout << "4. Triangle (Perimeter and Type)" << endl;
    cout << "Enter a Number (1-4) for Your Required Shape. Thank You!" << endl;

    cin >> choice;

    // 1. Square
    if (choice == 1)
    {
        int side, Area_of_Square, Perimeter_of_Square;
        cout << "\nWelcome!! This Program Calculates the Area and Perimeter of a Square" << endl;

        cout << "Enter the Side of Square: ";
        cin >> side;

        Area_of_Square = side * side;
        Perimeter_of_Square = 4 * side;

        cout << "The Area of Square = " << Area_of_Square << endl;
        cout << "The Perimeter of Square = " << Perimeter_of_Square << endl;
    }

    // 2. Rectangle
    else if (choice == 2)
    {
        int length, width, Area_of_Rect, Perimeter_of_Rect;
        cout << "\nWelcome!! This Program Calculates the Area and Perimeter of a Rectangle" << endl;

        cout << "Enter the Length and Width of the Rectangle: ";
        cin >> length >> width;

        Area_of_Rect = length * width;
        Perimeter_of_Rect = 2 * (length + width);

        cout << "The Area of Rectangle = " << Area_of_Rect << endl;
        cout << "The Perimeter of Rectangle = " << Perimeter_of_Rect << endl;

        if (length == width)
            cout << "This Rectangle is also a Square!" << endl;
        else
            cout << "This Shape is a Rectangle." << endl;
    }

    // 3. Circle
    else if (choice == 3)
    {
        const float pi = 3.14;
        float radius, Area_of_Circle, Circum_of_Circle;
        cout << "\nWelcome!! This Program Calculates the Area and Circumference of a Circle" << endl;

        cout << "Enter the Radius of Circle: ";
        cin >> radius;

        Area_of_Circle = pi * radius * radius;
        Circum_of_Circle = 2 * pi * radius;

        cout << "The Area of the Circle = " << Area_of_Circle << endl;
        cout << "The Circumference of the Circle = " << Circum_of_Circle << endl;
    }

    // 4. Triangle
    else if (choice == 4)
    {
        int Side_1, Side_2, Side_3, Perimeter_Of_Triangle;
        cout << "\nWelcome!! This Program Calculates the Perimeter of a Triangle" << endl;
        cout << "It also Determines the Type of Triangle" << endl;

        cout << "Enter the 3 Sides of Triangle: ";
        cin >> Side_1 >> Side_2 >> Side_3;

        Perimeter_Of_Triangle = Side_1 + Side_2 + Side_3;
        cout << "The Perimeter of the Triangle = " << Perimeter_Of_Triangle << endl;

        if (Side_1 == Side_2 && Side_2 == Side_3)
            cout << "The Triangle is Equilateral" << endl;
        else if (Side_1 == Side_2 || Side_1 == Side_3 || Side_2 == Side_3)
            cout << "The Triangle is Isosceles" << endl;
        else
            cout << "The Triangle is Scalene" << endl;
    }

    // Invalid choice
    else
    {
        cout << "Error! Please Enter a Valid Number From 1-4 and Run the Program Again." << endl;
    }
    
    return 0;
}

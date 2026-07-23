#include <iostream>
#include <stdexcept>
using namespace std;

class Rational
{
private: // Private Access Modifier Storing the Values of Variables so they cannot be changed;
    int numerator;
    int denominator;

    int gcd(int a, int b) // Ya mera GCD ka helper function ka code ha jo k hme higest Common Factor nikal kr de raha ha jo k dono same table se
                          // Rational Fraction ki expression ko divide krta ha ... Aur isko private is liye banaya ha k kyuu k only class k andr hi
                          // isko use krna ha ok ..
    {
        a = (a < 0) ? -a : a;
        b = (b < 0) ? -b : b;

        while (b != 0)
        {
            int rem = (a % b);
            a = b;
            b = rem;
        }

        //( 1. Agar a negative hai, a = -a;
        // 2. Agar b negative hai, b = -b;
        // 3. Jab tak b zero nahi hota, remainder nikalo aur swap karo
        // 4. Return a;)  -> Ya Iski logic bnaye ha mene hala k Saad Bhai na Assignment ma di hui thi lakin phir bhi

        return a;
    }

public: // Public Access Modifiers Storing the class Constructors and Member functions;
    Rational()
    {
        numerator = 0;
        denominator = 1;
        reduce();
    }
    Rational(int n, int d)
    {
        numerator = n;
        denominator = d;
        if (d == 0)
        {
            denominator = 1;
            cout << "Runtime Error.....!!! The denominator Must not be zero, Because division with zero is undefined !!!" << endl;
        }
        else
        {
            if (d < 0)
            {
                numerator = -n;
                denominator = -d;
            }
        }
        reduce();
    }
    Rational(int num)
    {
        numerator = num;
        denominator = 1;

        reduce();
    }

    void reduce() // this is the reduction Function to reduce the Fraction to its lowest (GCD FORM). and Show the simplified
                  // Rational Fraction result that is required.
    {
        int commonFactor = gcd(numerator, denominator);

        numerator = numerator / commonFactor;
        denominator = denominator / commonFactor;

        if (denominator < 0)
        {
            numerator = -(numerator);
            denominator = -(denominator);
        }
    }

    void display() const
    {
        cout << "=========================" << endl;
        cout << " Displaying The Fractions" << endl;
        cout << "=========================" << endl;
        cout << "\nThe given Fraction is: " << numerator << " / " << denominator << endl;
    }

    double toDecimal() const
    {
        double decimal = double(numerator) / denominator;
        return decimal;
    }

    // Ya Member functions operator overloading kr rahy hain aur mere compiler ko samjha rahy bheeee k rational numbers ko kese LCM le kr add
    // kia jata ha tw ya aik mazay ka kam, ha aur ye enhjoyable kam ha hahahha

    Rational operator+(const Rational &other) const
    {

        int newNum = ((numerator * other.denominator) + (denominator * other.numerator));
        int newDen = (denominator * other.denominator);

        return Rational(newNum, newDen);
    }

    Rational operator-(const Rational &other) const
    {

        int newNum = ((numerator * other.denominator) - (denominator * other.numerator));
        int newDen = (denominator * other.denominator);

        return Rational(newNum, newDen);
    }

    Rational operator*(const Rational &other) const
    {

        int newNum = ((numerator * other.numerator));
        int newDen = (denominator * other.denominator);

        return Rational(newNum, newDen);
    }

    Rational operator/(const Rational &other) const
    {

        int newNum = ((numerator * other.denominator));
        int newDen = ((denominator * other.numerator));

        return Rational(newNum, newDen);
    }

    Rational &operator+=(const Rational &other)
    {
        numerator = ((numerator * other.denominator) + (denominator * other.numerator));
        denominator = (denominator * other.denominator);
        reduce();
        return *this;
    }

    Rational &operator-=(const Rational &other)
    {
        numerator = ((numerator * other.denominator) - (denominator * other.numerator));
        denominator = (denominator * other.denominator);
        reduce();
        return *this;
    }

    Rational &operator*=(const Rational &other)
    {
        numerator = ((numerator * other.numerator));
        denominator = (denominator * other.denominator);
        reduce();
        return *this;
    }

    Rational &operator/=(const Rational &other)
    {
        numerator = ((numerator * other.denominator));
        denominator = ((denominator * other.numerator));
        reduce();
        return *this;
    }
    bool operator==(const Rational &other) const
    {
        return ((numerator * other.denominator) == (denominator * other.numerator));
    }

    bool operator!=(const Rational &other) const
    {
        return ((numerator * other.denominator) != (denominator * other.numerator));
    }

    bool operator>=(const Rational &other) const
    {
        return ((numerator * other.denominator) >= (denominator * other.numerator));
    }

    bool operator<=(const Rational &other) const
    {
        return ((numerator * other.denominator) <= (denominator * other.numerator));
    }

    bool operator<(const Rational &other) const
    {
        return ((numerator * other.denominator) < (denominator * other.numerator));
    }

    bool operator>(const Rational &other) const
    {
        return ((numerator * other.denominator) > (denominator * other.numerator));
    }

    Rational &operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }

    Rational &operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp(numerator, denominator);
        numerator += denominator;
        reduce();
        return temp;
    }

    Rational operator--(int)
    {
        Rational temp(numerator, denominator);
        numerator -= denominator;
        reduce();
        return temp;
    }

    Rational operator()() const
    {
        if (numerator == 0)
        {
            throw runtime_error("Invalid Step!! Division By 0 is not Possible !!.. Try Again");
        }
        return Rational(denominator, numerator);
    }
    friend ostream &operator<<(ostream &os, const Rational &r)
    {
        os << r.numerator << " / " << r.denominator << endl;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r)
    {
        int num, den;
        is >> num >> den;

        if (den == 0)
        {
            cout << "Error !! denominator cannot be zero.. Please Enter the Value of Denominator again.. Resetting" << endl;
            r.numerator = 0;
            r.denominator = 1;
            cout << "Default Values Setting to 0/1 on the fractional part..." << endl;
        }
        else
        {

            r.numerator = num;
            r.denominator = den;
            if (r.denominator < 0)
            { // Sign check
                r.numerator = -r.numerator;
                r.denominator = -r.denominator;
            }
            r.reduce(); // Simplify lazmi hai
        }

        return is;
    }
};

int main()
{
    int choice;
    Rational r1, r2, result;

    do
    {
        cout << "\n====================================================" << endl;
        cout << "               Rational Number System               " << endl;
        cout << "====================================================" << endl;
        cout << "1.  Add two rational numbers" << endl;
        cout << "2.  Subtract two rational numbers" << endl;
        cout << "3.  Multiply two rational numbers" << endl;
        cout << "4.  Divide two rational numbers" << endl;
        cout << "5.  Compound assignment operations (+=)" << endl;
        cout << "6.  Compare two rational numbers (==)" << endl;
        cout << "7.  Convert to decimal" << endl;
        cout << "8.  Reciprocal (member function)" << endl;
        cout << "9.  Prefix & Postfix Increment" << endl;
        cout << "10. Prefix & Postfix Decrement" << endl;
        cout << "11. Function call operator ()" << endl;
        cout << "12. Operations with integers" << endl;
        cout << "13. Exit" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input! Please enter a valid number." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter 1st Rational Number (num den): ";
            cin >> r1;
            cout << "Enter 2nd Rational Number (num den): ";
            cin >> r2;
            result = r1 + r2;
            cout << "Result: " << result;
            break;
        case 2:
            cout << "Enter 1st Rational Number (num den): ";
            cin >> r1;
            cout << "Enter 2nd Rational Number (num den): ";
            cin >> r2;
            result = r1 - r2;
            cout << "Result: " << result;
            break;
        case 3:
            cout << "Enter 1st Rational Number (num den): ";
            cin >> r1;
            cout << "Enter 2nd Rational Number (num den): ";
            cin >> r2;
            result = r1 * r2;
            cout << "Result: " << result;
            break;
        case 4:
            cout << "Enter 1st Rational Number (num den): ";
            cin >> r1;
            cout << "Enter 2nd Rational Number (num den): ";
            cin >> r2;
            result = r1 / r2;
            cout << "Result: " << result;
            break;
        case 5:
            cout << "Enter base Rational Number (num den): ";
            cin >> r1;
            cout << "Enter Rational Number to add (+=) (num den): ";
            cin >> r2;
            r1 += r2;
            cout << "Result after += : " << r1;
            break;
        case 6:
            cout << "Enter 1st Rational Number: ";
            cin >> r1;
            cout << "Enter 2nd Rational Number: ";
            cin >> r2;
            if (r1 == r2)
                cout << "They are Equal!" << endl;
            else if (r1 < r2)
                cout << "1st is less than 2nd!" << endl;
            else
                cout << "1st is greater than 2nd!" << endl;
            break;
        case 7:
            cout << "Enter Rational Number: ";
            cin >> r1;
            cout << "Decimal value: " << r1.toDecimal() << endl;
            break;
        case 8:
        case 11:
            cout << "Enter Rational Number: ";
            cin >> r1;
            try
            {
                result = r1(); // Function call operator
                cout << "Reciprocal is: " << result;
            }
            catch (const exception &e)
            {
                cout << "Exception: " << e.what() << endl;
            }
            break;
        case 9:
            cout << "Enter Rational Number: ";
            cin >> r1;
            cout << "Original: " << r1;
            cout << "After Prefix (++r1): " << ++r1;
            result = r1++;
            cout << "Postfix return value (r1++): " << result;
            cout << "Final value after Postfix: " << r1;
            break;
        case 10:
            cout << "Enter Rational Number: ";
            cin >> r1;
            cout << "Original: " << r1;
            cout << "After Prefix (--r1): " << --r1;
            result = r1--;
            cout << "Postfix return value (r1--): " << result;
            cout << "Final value after Postfix: " << r1;
            break;
        case 12:
            cout << "Enter Rational Number: ";
            cin >> r1;
            cout << "Adding integer 5 to it (r1 + 5)..." << endl;
            result = r1 + 5;
            cout << "Result: " << result;
            break;
        case 13:
            cout << "Exiting... Best of luck with the submission!" << endl;
            break;
        default:
            cout << "Invalid choice! Enter between 1 and 13." << endl;
        }
    } while (choice != 13);

    return 0;
}

// // Test Cases
// // Simple Fractional Arethematic
// Rational r1;
// r1.display();
// Rational r2(5, -2);
// r2.display();
// cout << endl;
// cout << r2.toDecimal();
// // Operator Overloading + - * /
// Rational a(1, 2);
// Rational b(1, 3);
// Rational c = a + b;
// cout << endl;
// c.display();
// cout << endl;
// Rational sub = a - b;
// sub.display();
// cout << endl; // Expected: 1/6
// Rational mul = a * b;
// mul.display();
// cout << endl; // Expected: 1/6
// Rational div = a / b;
// div.display();
// cout << endl; // Expected: 3/2
// // Operator Overloading += -= *=

// Rational r(9, 2);
// r += Rational(16, 4);
// r.display(); // Expected output: 5/6
// r /= Rational(16, 4);
// r.display();

// // Operator Overloading == != >= <= < >
// //  Comparison Test
// Rational x(1, 2);
// Rational y(2, 4);
// Rational z(3, 4);

// cout << "\n--- Comparison Tests ---" << endl;
// cout << "Is 1/2 == 2/4? " << (x == y) << endl; // Expected: 1
// cout << "Is 1/2 < 3/4? " << (x < z) << endl;   // Expected: 1
// cout << "Is 3/4 <= 1/2? " << (z <= x) << endl; // Expected: 0

// // Test cases of ++ --
// Rational inc1(3, 4);
// cout << "Original: ";
// inc1.display();

// cout << "\nPrefix ++: ";
// (++inc1).display(); // Expected: 7/4

// Rational inc2(3, 4);
// cout << "\nPostfix ++: ";
// Rational old = inc2++;
// old.display();  // Expected: 3/4 (old value)
// inc2.display(); // Expected: 7/4 (new value)

// // Testing the Overloaded () methods
// Rational rec(2, 3);
// rec.display();
// cout << "\n--- Reciprocal Test ---" << endl;
// Rational result = rec(); // Ye function call operator ko trigger karega
// result.display();        // Expected: 3/2
// //Stream Operator Overloading >> <<
// Rational streamTest;
// cout << "\nEnter a rational number (num den): ";
// cin >> streamTest;                             // Ab ye chalega!
// cout << "You entered: " << streamTest << endl; // Ye bhi chalega!
//}
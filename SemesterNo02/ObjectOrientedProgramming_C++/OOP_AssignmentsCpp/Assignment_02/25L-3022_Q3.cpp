#include <iostream>
using namespace std;

class CalendarDate
{
private:
    int day, month, year;

    bool isLeapYear(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const
    {
        if (m == 2)
            return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        return 31;
    }

    bool isValid(int d, int m, int y) const
    {
        if (y < 1 || m < 1 || m > 12)
            return false;
        if (d < 1 || d > daysInMonth(m, y))
            return false;
        return true;
    }

    // Convert Date to total days since 01-01-2000
    int toTotalDays() const
    {
        int total = 0;
        for (int y = 2000; y < year; y++)
        {
            total += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; m++)
        {
            total += daysInMonth(m, year);
        }
        total += day - 1;
        return total;
    }

    // Convert total days back to Date
    void fromTotalDays(int totalDays)
    {
        year = 2000;
        while (true)
        {
            int daysInYear = isLeapYear(year) ? 366 : 365;
            if (totalDays >= daysInYear)
            {
                totalDays -= daysInYear;
                year++;
            }
            else
            {
                break;
            }
        }
        month = 1;
        while (true)
        {
            int dim = daysInMonth(month, year);
            if (totalDays >= dim)
            {
                totalDays -= dim;
                month++;
            }
            else
            {
                break;
            }
        }
        day = totalDays + 1;
    }

public:
    CalendarDate()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    CalendarDate(int d, int m, int y)
    {
        if (isValid(d, m, y))
        {
            day = d;
            month = m;
            year = y;
        }
        else
        {
            cout << "Invalid Date! Reset to: 01-01-2000" << endl;
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    CalendarDate(int totalDays)
    {
        fromTotalDays(totalDays);
    }

    CalendarDate(const CalendarDate &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }

    bool isLeapYear() const
    {
        return isLeapYear(year);
    }

    bool isValid() const
    {
        return isValid(day, month, year);
    }

    void addDays(int n)
    {
        fromTotalDays(toTotalDays() + n);
    }

    void subtractDays(int n)
    {
        fromTotalDays(toTotalDays() - n);
    }

    void print(int fmt) const
    {
        if (fmt == 1)
        {
            cout << (day < 10 ? "0" : "") << day << "-" << (month < 10 ? "0" : "") << month << "-" << year << endl;
        }
        else if (fmt == 2)
        {
            const char *months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
            cout << months[month] << " " << day << ", " << year << endl;
        }
        else if (fmt == 3)
        {
            cout << year << "/" << (month < 10 ? "0" : "") << month << "/" << (day < 10 ? "0" : "") << day << endl;
        }
    }

    // Arithmetic
    CalendarDate operator+(int n) const { return CalendarDate(toTotalDays() + n); }
    friend CalendarDate operator+(int n, const CalendarDate &d) { return d + n; }
    CalendarDate operator-(int n) const { return CalendarDate(toTotalDays() - n); }
    int operator-(const CalendarDate &other) const { return toTotalDays() - other.toTotalDays(); }

    // Compound
    CalendarDate &operator+=(int n)
    {
        addDays(n);
        return *this;
    }
    CalendarDate &operator-=(int n)
    {
        subtractDays(n);
        return *this;
    }

    // Increment/Decrement
    CalendarDate &operator++()
    {
        addDays(1);
        return *this;
    }
    CalendarDate operator++(int)
    {
        CalendarDate temp(*this);
        addDays(1);
        return temp;
    }
    CalendarDate &operator--()
    {
        subtractDays(1);
        return *this;
    }
    CalendarDate operator--(int)
    {
        CalendarDate temp(*this);
        subtractDays(1);
        return temp;
    }

    // Comparison
    bool operator==(const CalendarDate &o) const { return toTotalDays() == o.toTotalDays(); }
    bool operator!=(const CalendarDate &o) const { return toTotalDays() != o.toTotalDays(); }
    bool operator<(const CalendarDate &o) const { return toTotalDays() < o.toTotalDays(); }
    bool operator>(const CalendarDate &o) const { return toTotalDays() > o.toTotalDays(); }
    bool operator<=(const CalendarDate &o) const { return toTotalDays() <= o.toTotalDays(); }
    bool operator>=(const CalendarDate &o) const { return toTotalDays() >= o.toTotalDays(); }

    void operator()() const
    {
        print(1);
        print(2);
        print(3);
    }

    friend ostream &operator<<(ostream &os, const CalendarDate &d)
    {
        os << (d.day < 10 ? "0" : "") << d.day << "-" << (d.month < 10 ? "0" : "") << d.month << "-" << d.year;
        return os;
    }

    friend istream &operator>>(istream &is, CalendarDate &d)
    {
        int dd, mm, yy;
        is >> dd >> mm >> yy;
        if (d.isValid(dd, mm, yy))
        {
            d.day = dd;
            d.month = mm;
            d.year = yy;
        }
        else
        {
            cout << "Invalid Date! Reset to: 01-01-2000" << endl;
            d.day = 1;
            d.month = 1;
            d.year = 2000;
        }
        return is;
    }
};

int main()
{
    int choice;
    CalendarDate d1, d2;
    do
    {
        cout << endl;
        cout << "============================================" << endl;
        cout << "         Calendar Management System         " << endl;
        cout << "============================================" << endl;
        cout << "1.  Enter a new date" << endl;
        cout << "2.  Display date" << endl;
        cout << "3.  Add days" << endl;
        cout << "4.  Subtract days" << endl;
        cout << "5.  Compare two dates" << endl;
        cout << "6.  Find difference between two dates" << endl;
        cout << "7.  Test increment operators (++ prefix & postfix)" << endl;
        cout << "8.  Test decrement operators (-- prefix & postfix)" << endl;
        cout << "9.  Test compound operators += and -=" << endl;
        cout << "10. Check leap year" << endl;
        cout << "11. Display in all formats (function call operator)" << endl;
        cout << "12. Exit" << endl;
        cout << "--------------------------------------------" << endl;
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
            cout << "Enter date (DD MM YYYY): ";
            cin >> d1;
            break;
        case 2:
            cout << "Date is: " << d1 << endl;
            break;
        case 3:
            int addD;
            cout << "Add days: ";
            cin >> addD;
            d1 += addD;
            cout << "New Date: " << d1 << endl;
            break;
        case 4:
            int subD;
            cout << "Subtract days: ";
            cin >> subD;
            d1 -= subD;
            cout << "New Date: " << d1 << endl;
            break;
        case 5:
            cout << "Enter second date (DD MM YYYY): ";
            cin >> d2;
            cout << "Equal? " << (d1 == d2 ? "Yes" : "No") << endl;
            cout << "First < Second? " << (d1 < d2 ? "Yes" : "No") << endl;
            cout << "First > Second? " << (d1 > d2 ? "Yes" : "No") << endl;
            break;
        case 6:
            cout << "Enter second date (DD MM YYYY): ";
            cin >> d2;
            cout << "Difference: " << (d1 - d2) << " days" << endl;
            break;
        case 7:
            cout << "Original: " << d1 << endl;
            cout << "Prefix (++d1): " << ++d1 << endl;
            cout << "Postfix (d1++): " << d1++ << " (now " << d1 << ")" << endl;
            break;
        case 8:
            cout << "Original: " << d1 << endl;
            cout << "Prefix (--d1): " << --d1 << endl;
            cout << "Postfix (d1--): " << d1-- << " (now " << d1 << ")" << endl;
            break;
        case 9:
            int cDays;
            cout << "Add using += : ";
            cin >> cDays;
            d1 += cDays;
            cout << "New Date: " << d1 << endl;
            break;
        case 10:
            cout << "Leap year? " << (d1.isLeapYear() ? "Yes" : "No") << endl;
            break;
        case 11:
            d1();
            break;
        case 12:
            cout << "Exiting Calendar System. !!!" << endl;
            break;
        default:
            cout << "Invalid choice! Enter between 1 and 12." << endl;
        }
    } while (choice != 12);

    return 0;
}
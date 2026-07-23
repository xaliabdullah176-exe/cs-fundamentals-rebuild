#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <limits>
using namespace std;


// TASK 1 - Function Templates: GetMax and GetMin


// Single-type template
template <class T>
T GetMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T GetMin(T a, T b) {
    return (a < b) ? a : b;
}

// Two-type template (for Task 1d)
template <class T, class U>
T GetMax(T a, U b) {
    return (a > (T)b) ? a : (T)b;
}

template <class T, class U>
T GetMin(T a, U b) {
    return (a < (T)b) ? a : (T)b;
}


// TASK 2 - Class Template: Pair


template <class T>
class Pair {
private:
    T values[2];
public:
    // Default constructor (needed for Task 5)
    Pair() {
        values[0] = T();
        values[1] = T();
    }

    // Parameterized constructor
    Pair(T a, T b) {
        values[0] = a;
        values[1] = b;
    }

    // GetMax defined inside the class
    T getmax() {
        return (values[0] > values[1]) ? values[0] : values[1];
    }

    // GetMin declared inside, defined outside
    T getmin();

    // Friend operator<< for Task 5
    friend ostream& operator<<(ostream& os, const Pair<T>& p) {
        os << "(" << p.values[0] << ", " << p.values[1] << ")";
        return os;
    }
};

// GetMin defined outside the class
template <class T>
T Pair<T>::getmin() {
    return (values[0] < values[1]) ? values[0] : values[1];
}

// ============================================================
// TASK 3 - Template Specialization: Container
// ============================================================

// General template
template <class T>
class Container {
private:
    T element;
public:
    Container(T arg) : element(arg) {}
    T increase();
};

template <class T>
T Container<T>::increase() {
    return ++element;
}

// Specialized template for char
template <>
class Container<char> {
private:
    char element;
public:
    Container(char arg) : element(arg) {}
    char uppercase();
};

// uppercase() without toupper() and not inline
char Container<char>::uppercase() {
    if (element >= 'a' && element <= 'z') {
        return element - ('a' - 'A');
    }
    return element;
}

// ============================================================
// TASK 4 - Non-Type Template Parameter: Sequence
// ============================================================

template <class T, int N>
class Sequence {
private:
    T memblock[N];
public:
    void setmember(int x, T value);
    T getmember(int x);
};

template <class T, int N>
void Sequence<T, N>::setmember(int x, T value) {
    memblock[x] = value;
}

template <class T, int N>
T Sequence<T, N>::getmember(int x) {
    return memblock[x];
}

// ============================================================
// TASK 8 - Custom Exception: ArrayIndexOutOfBoundsException
// ============================================================

class ArrayIndexOutOfBoundsException : public exception {
private:
    string msg;
public:
    ArrayIndexOutOfBoundsException(int index) {
        msg = "Yikes! Tom grabbed index " + to_string(index) +
              " but the shelf only has 5 slots (0-4)! Jerry is safe!";
    }
    void printMessage() const {
        cout << "[ArrayIndexOutOfBoundsException] " << msg << endl;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

int globalArray[5] = {10, 20, 30, 40, 50};

int getElementAtIndex(int index) {
    if (index < 0 || index >= 5) {
        throw ArrayIndexOutOfBoundsException(index);
    }
    return globalArray[index];
}

// ============================================================
// TASK 10 - Custom Exception: TrapPowerException
// ============================================================

class TrapPowerException : public exception {
private:
    string message;
public:
    TrapPowerException(string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// ============================================================
// MAIN - All Tasks demonstrated
// ============================================================

int main() {
    // ----------------------------------------------------------
    // TASK 1a/b - GetMax and GetMin with explicit types
    // ----------------------------------------------------------
    cout << "========== TASK 1b: Explicit Type Templates ==========" << endl;
    {
        int i = 5, j = 6, k;
        long l = 10, m = 5, n;
        k = GetMax<int>(i, j);
        n = GetMin<long>(l, m);
        cout << "GetMax<int>(5,6) = " << k << endl;
        cout << "GetMin<long>(10,5) = " << n << endl;
    }

    // ----------------------------------------------------------
    // TASK 1c - Without explicit type (type deduction)
    // ----------------------------------------------------------
    cout << "\n========== TASK 1c: Type Deduction ==========" << endl;
    {
        int i = 5, j = 6, k;
        long l = 10, m = 5, n;
        k = GetMax(i, j);
        n = GetMin(l, m);
        cout << "GetMax(5,6) = " << k << endl;
        cout << "GetMin(10,5) = " << n << endl;
        cout << "Program still works - Jerry escapes again!" << endl;
    }

    // ----------------------------------------------------------
    // TASK 1d - Two-type templates
    // ----------------------------------------------------------
    cout << "\n========== TASK 1d: Two-Type Templates ==========" << endl;
    {
        char i = 'Z';
        int j = 6, k;
        long l = 10, m = 5, n;
        k = GetMax<int, long>(i, m);
        n = GetMin<int, char>(j, l);
        cout << "GetMax<int,long>('Z', 5) = " << k << endl;
        cout << "GetMin<int,char>(6, 10) = " << n << endl;
    }

    // ----------------------------------------------------------
    // TASK 1e - Two-type without explicit (may cause ambiguity)
    // ----------------------------------------------------------
    cout << "\n========== TASK 1e: Two-Type Without Explicit ==========" << endl;
    cout << "(Explicit types kept to avoid ambiguity - Tom is confused by mixed types!)" << endl;

    // ----------------------------------------------------------
    // TASK 2 - Pair class template
    // ----------------------------------------------------------
    cout << "\n========== TASK 2: Pair Class Template ==========" << endl;
    {
        Pair<double> myobject(1.012, 1.01234);
        cout << "Pair(1.012, 1.01234)" << endl;
        cout << "getmax() = " << myobject.getmax() << endl;
        cout << "getmin() = " << myobject.getmin() << endl;
    }

    // ----------------------------------------------------------
    // TASK 3 - Template Specialization
    // ----------------------------------------------------------
    cout << "\n========== TASK 3: Template Specialization ==========" << endl;
    {
        Container<int> myint(7);
        Container<char> mychar('j');
        cout << "Container<int>(7).increase() = " << myint.increase() << endl;
        cout << "Container<char>('j').uppercase() = " << mychar.uppercase() << endl;
    }

    // ----------------------------------------------------------
    // TASK 4 - Non-Type Template Parameter: Sequence
    // ----------------------------------------------------------
    cout << "\n========== TASK 4: Sequence with Non-Type Parameter ==========" << endl;
    {
        Sequence<int, 5> myints;
        Sequence<double, 5> myfloats;
        myints.setmember(0, 100);
        myfloats.setmember(3, 3.1416);
        cout << "myints.getmember(0) = " << myints.getmember(0) << endl;
        cout << "myfloats.getmember(3) = " << myfloats.getmember(3) << endl;
    }

    // ----------------------------------------------------------
    // TASK 5 - Storing Pair inside Sequence
    // ----------------------------------------------------------
    cout << "\n========== TASK 5: Pair Inside Sequence ==========" << endl;
    {
        Pair<double> y(2.23, 3.45);
        Sequence<Pair<double>, 5> myPairs;
        myPairs.setmember(0, y);
        cout << "myPairs.getmember(0) = " << myPairs.getmember(0) << endl;
    }

    // ----------------------------------------------------------
    // TASK 6 - Exception Handling: int, double, catch-all
    // ----------------------------------------------------------
    cout << "\n========== TASK 6: Exception Handling (int/double/unknown) ==========" << endl;
    {
        int choice;
        cout << "Enter 1 to throw int, 2 to throw double, 3 for unknown: ";
        cin >> choice;

        try {
            if (choice == 1) {
                throw 42;
            } else if (choice == 2) {
                throw 3.14;
            } else {
                throw "Chaos in the kitchen!";
            }
        } catch (int e) {
            cout << "Caught integer exception: " << e << endl;
        } catch (double e) {
            cout << "Caught double exception: " << e << endl;
        } catch (...) {
            cout << "Caught unknown chaos - Tom broke something again!" << endl;
        }
    }

    // ----------------------------------------------------------
    // TASK 7 - Kitchen Mixing: invalid_argument via cin.fail()
    // ----------------------------------------------------------
    cout << "\n========== TASK 7: Kitchen Mixing Disaster ==========" << endl;
    {
        auto add = [](double a, double b) -> double {
            return a + b;
        };

        double a, b;
        cout << "Enter two numbers to add (enter letters to trigger disaster): ";
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            try {
                throw invalid_argument("Non-numeric ingredient detected! Jerry's recipe is ruined!");
            } catch (const invalid_argument& e) {
                cout << "Exception caught: " << e.what() << endl;
            }
        } else {
            cin >> b;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                try {
                    throw invalid_argument("Second ingredient is invalid! Disaster!");
                } catch (const invalid_argument& e) {
                    cout << "Exception caught: " << e.what() << endl;
                }
            } else {
                cout << "Result of add(" << a << ", " << b << ") = " << add(a, b) << endl;
            }
        }
    }

    // ----------------------------------------------------------
    // TASK 8 - Out-of-Bounds: ArrayIndexOutOfBoundsException
    // ----------------------------------------------------------
    cout << "\n========== TASK 8: Out-of-Bounds Trouble ==========" << endl;
    {
        int idx;
        cout << "Enter an index to access (0-4, try 7 to see Tom fail): ";
        cin >> idx;
        try {
            int val = getElementAtIndex(idx);
            cout << "Element at index " << idx << " = " << val << endl;
        } catch (ArrayIndexOutOfBoundsException& e) {
            e.printMessage();
        }
    }

    // ----------------------------------------------------------
    // TASK 9 - File Handling with runtime_error
    // ----------------------------------------------------------
    cout << "\n========== TASK 9: The Broken Recipe File ==========" << endl;
    {
        // Create a sample file first
        ofstream outFile("tom_jerry_scroll.txt");
        if (outFile.is_open()) {
            outFile << "Jerry's Secret Recipe:\n";
            outFile << "1. Grab the biggest cheese.\n";
            outFile << "2. Outsmart Tom.\n";
            outFile << "3. Run really fast!\n";
            outFile.close();
        }

        try {
            ifstream inFile("tom_jerry_scroll.txt");
            if (!inFile.is_open()) {
                throw runtime_error("File could not be opened! Tom must have hidden it!");
            }

            // Check if empty
            inFile.seekg(0, ios::end);
            if (inFile.tellg() == 0) {
                throw runtime_error("File is empty! Tom shredded the recipe!");
            }
            inFile.seekg(0, ios::beg);

            cout << "File contents:" << endl;
            string line;
            while (getline(inFile, line)) {
                cout << "  " << line << endl;
            }
            inFile.close();
        } catch (const runtime_error& e) {
            cout << "Runtime error: " << e.what() << endl;
        }
    }

    // ----------------------------------------------------------
    // TASK 10 - TrapPowerException
    // ----------------------------------------------------------
    cout << "\n========== TASK 10: Ultimate Chaos Control ==========" << endl;
    {
        int power;
        cout << "Enter trap power level (0-100): ";
        cin >> power;
        try {
            if (power < 0 || power > 100) {
                throw TrapPowerException(
                    "BOOM! Trap power " + to_string(power) +
                    " is out of range! Must be between 0 and 100. Tom blew up the house!"
                );
            }
            cout << "Trap power " << power << " is safe. Jerry set the trap successfully!" << endl;
        } catch (const TrapPowerException& e) {
            cout << "TrapPowerException: " << e.what() << endl;
        }
    }

    cout << "\n========== All Tasks Complete! Jerry wins again! ==========" << endl;
    return 0;
}

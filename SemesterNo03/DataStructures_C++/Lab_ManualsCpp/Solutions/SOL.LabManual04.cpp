#include <iostream>
#include <string>
#include <stack>
#include <climits>

using namespace std;

class ParkingStack
{
private:
    int capacity;
    int top;
    string *arr;

public:
    // Default constructor (kept for completeness / rule of thumb)
    ParkingStack()
    {
        capacity = 5;
        top = -1;
        arr = new string[capacity];
    }

    // Capacity is supplied by the user at runtime (Requirement 1)
    ParkingStack(int capacity)
    {
        this->capacity = capacity;
        top = -1;
        arr = new string[capacity];
    }

    // push() - park a new car at the top of the stack
    void push(const string &s)
    {
        if (isFull())
        {
            cout << " !! Stack Overflow !! Parking lane is full, cannot park \""
                 << s << "\".\n";
            return;
        }
        arr[++top] = s;
        cout << " Car \"" << s << "\" parked successfully at position "
             << top << ".\n";
    }

    // pop() - remove the most recently parked car
    string pop()
    {
        if (isEmpty())
        {
            cout << " !! Stack Underflow !! No car to remove, lane is empty.\n";
            return "";
        }
        string element = arr[top];
        top--;
        return element;
    }

    // peek() - show the car currently at the top without removing it
    string peek()
    {
        if (isEmpty())
        {
            cout << " Stack Underflow - lane is empty, nothing to peek.\n";
            return "";
        }
        return arr[top]; // fixed: was the invalid "top[arr]"
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    // display() - show all parked cars from top to bottom, non-destructively
    void display()
    {
        if (isEmpty())
        {
            cout << " Parking lane is empty.\n";
            return;
        }
        cout << " Cars in lane (top -> bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~ParkingStack()
    {
        delete[] arr;
    }
};

void runParkingSystem()
{
    int capacity;
    cout << "\nEnter the parking lane capacity: ";
    cin >> capacity;

    ParkingStack S(capacity);
    int choice;

    do
    {
        cout << "\n------ Welcome to Single-Lane Parking System !! ------\n";
        cout << "Press 2, To Store CarPlate No. After Parking the Car\n";
        cout << "Press 3, To Watch the Most Recent Parked Car\n";
        cout << "Press 4, To Remove CarPlate No. After Taking out the Car\n";
        cout << "Press 5, To Display the Parked Cars from the ParkingLane\n";
        cout << "Press -1, To Exit the Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 2:
        {
            string plate;
            cout << "Enter Car Plate No.: ";
            cin >> plate;
            S.push(plate);
            break;
        }
        case 3:
        {
            string p = S.peek();
            if (!p.empty())
                cout << " Most recently parked car: " << p << endl;
            break;
        }
        case 4:
        {
            string removed = S.pop();
            if (!removed.empty())
                cout << " Car \"" << removed << "\" has left the lane.\n";
            break;
        }
        case 5:
            S.display();
            break;
        case -1:
            cout << "Exiting Parking System...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != -1);
}

// PART B : std::stack Problem Set

/* ---------- Task 01 : Balanced Parentheses (2) ---------- */
bool isBalanced(string exp)
{
    stack<char> st;

    for (size_t i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
                return false; // closing with nothing open

            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{'))
            {
                st.pop();
            }
            else
            {
                return false; // mismatched pair
            }
        }
        // any other character is ignored
    }

    return st.empty(); // balanced only if every opener was closed
}

void runTask1()
{
    string exp;
    cout << "\n--- Task 1: Balanced Parentheses ---\n";
    cout << "Enter an expression (only {} [] ()): ";
    cin >> exp;
    cout << "Output: " << (isBalanced(exp) ? "True" : "False") << endl;
}

/* ---------- Task 02 : Postfix Expression Evaluator (3) ---------- */
int evaluatePostfix(const string &exp)
{
    stack<int> st;

    for (size_t i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            st.push(ch - '0'); // single-digit operand
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int b = st.top();
            st.pop(); // second operand
            int a = st.top();
            st.pop(); // first operand
            int result = 0;

            switch (ch)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            }
            st.push(result);
        }
        // ignore any other character (spaces etc.)
    }

    return st.top();
}

void runTask2()
{
    string exp;
    cout << "\n--- Task 2: Postfix Expression Evaluator ---\n";
    cout << "Enter a postfix expression (no spaces, single-digit operands): ";
    cin >> exp;
    cout << "Output: " << evaluatePostfix(exp) << endl;
}

/* ---------- Task 03 : MinStack -> O(1) getMin (5) ---------- */
class SpecialStack
{
    stack<int> st;
    stack<int> minStack;

public:
    void push(int x)
    {
        st.push(x);

        // Push x on minStack if it's a new minimum (or ties the current one),
        // otherwise repeat the current minimum so both stacks stay in sync.
        if (minStack.empty() || x <= minStack.top())
        {
            minStack.push(x);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        if (st.empty())
        {
            cout << " !! Stack Underflow !!\n";
            return;
        }
        st.pop();
        minStack.pop();
    }

    int peek()
    {
        if (st.empty())
        {
            cout << " !! Stack Underflow !!\n";
            return -1;
        }
        return st.top();
    }

    int getMin()
    {
        if (minStack.empty())
        {
            cout << " !! Stack is empty !!\n";
            return -1;
        }
        return minStack.top();
    }

    bool isEmpty()
    {
        return st.empty();
    }
};

void runTask3()
{
    SpecialStack ms;
    int choice;

    do
    {
        cout << "\n--- Task 3: MinStack ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Get Minimum\n-1. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            ms.push(val);
            break;
        }
        case 2:
            ms.pop();
            break;
        case 3:
            cout << "Top element: " << ms.peek() << endl;
            break;
        case 4:
            cout << "Minimum element: " << ms.getMin() << endl;
            break;
        case -1:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != -1);
}

/* ---------- Task 04 : Largest Rectangle in Histogram (10) ---------- */
// Classic O(n) stack-based approach: for every bar, find how far it can
// extend to the left and right while remaining the shortest bar in that
// span, using a stack of indices with increasing bar heights.

int largestRectangleArea(int arr[], int n)
{
    stack<int> st; // stores indices, heights are increasing
    int maxArea = 0;
    int i = 0;

    while (i < n)
    {
        if (st.empty() || arr[st.top()] <= arr[i])
        {
            st.push(i);
            i++;
        }
        else
        {
            int topIndex = st.top();
            st.pop();

            int width;
            if (st.empty())
                width = i; // extends all the way left
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, arr[topIndex] * width);
        }
    }

    // Pop any remaining bars; each extends to the right edge of the histogram
    while (!st.empty())
    {
        int topIndex = st.top();
        st.pop();

        int width;
        if (st.empty())
            width = i;
        else
            width = i - st.top() - 1;

        maxArea = max(maxArea, arr[topIndex] * width);
    }

    return maxArea;
}

void runTask4()
{
    int n;
    cout << "\n--- Task 4: Largest Rectangle in Histogram ---\n";
    cout << "Enter number of bars: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " bar heights: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Largest Rectangle Area: " << largestRectangleArea(arr, n) << endl;

    delete[] arr;
}

// MAIN - Top level menu every part/task together

int main()
{
    int choice;

    do
    {
        cout << "\n================ DS Lab Manual 04 ================\n";
        cout << "1. Part A  - Single-Lane Parking System (Array Stack)\n";
        cout << "2. Task 1  - Balanced Parentheses\n";
        cout << "3. Task 2  - Postfix Expression Evaluator\n";
        cout << "4. Task 3  - MinStack\n";
        cout << "5. Task 4  - Largest Rectangle in Histogram\n";
        cout << "-1. Exit\n";
        cout << "====================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            runParkingSystem();
            break;
        case 2:
            runTask1();
            break;
        case 3:
            runTask2();
            break;
        case 4:
            runTask3();
            break;
        case 5:
            runTask4();
            break;
        case -1:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != -1);

    return 0;
}
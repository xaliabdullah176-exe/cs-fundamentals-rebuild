#include <iostream>
#include <string>
using namespace std;

// ============================================================
//   TASK 9 - Forward Declaration
//   Declaring SpyHQ before SpyAgent so SpyAgent can
//   declare it as a friend class without circular dependency
// ============================================================

class SpyHQ;

// ============================================================
//   SpyAgent Class
//   (Includes all features: Task 2 to Task 8)
// ============================================================

class SpyAgent
{
private:
    string name;
    int missions;

public:
    // Constructors
    SpyAgent()
    {
        name = "";
        missions = 0;
    }

    SpyAgent(string n, int m)
    {
        name = n;
        missions = m;
    }

    void display()
    {
        cout << "Agent: " << name << " | Missions: " << missions << endl;
    }

    int getMissions() { return missions; }
    string getName() { return name; }

    // ============================================================
    //   TASK 2 - Unary & Binary Operators as Friend Functions
    // ============================================================

    friend SpyAgent &operator++(SpyAgent &a);
    friend SpyAgent &operator--(SpyAgent &a);

    friend SpyAgent operator+(const SpyAgent &a, const SpyAgent &b);
    friend SpyAgent operator-(const SpyAgent &a, const SpyAgent &b);
    friend SpyAgent operator*(const SpyAgent &a, const SpyAgent &b);
    friend SpyAgent operator/(const SpyAgent &a, const SpyAgent &b);

    // ============================================================
    //   TASK 4 - Comparison Operators
    // ============================================================

    friend bool operator==(const SpyAgent &a, const SpyAgent &b);
    friend bool operator!=(const SpyAgent &a, const SpyAgent &b);
    friend bool operator>(const SpyAgent &a, const SpyAgent &b);

    // ============================================================
    //   TASK 5 - Assignment Operators (Member Functions)
    // ============================================================

    SpyAgent &operator=(const SpyAgent &other)
    {
        if (this == &other)
            return *this; // self-assignment check
        name = other.name;
        missions = other.missions;
        return *this;
    }

    SpyAgent &operator+=(const SpyAgent &other)
    {
        missions += other.missions;
        return *this;
    }

    SpyAgent &operator-=(const SpyAgent &other)
    {
        missions -= other.missions;
        return *this;
    }

    // ============================================================
    //   TASK 6 - Additional Comparison Operators
    // ============================================================

    friend bool operator<(const SpyAgent &a, const SpyAgent &b);
    friend bool operator<=(const SpyAgent &a, const SpyAgent &b);
    friend bool operator>=(const SpyAgent &a, const SpyAgent &b);

    // ============================================================
    //   TASK 7 - Mixed Operand Overloading
    // ============================================================

    // Case 1: SpyAgent + int  (member handles obj + value)
    SpyAgent operator+(int val)
    {
        return SpyAgent(name, missions + val);
    }

    // Case 3: SpyAgent - int  (member handles obj - value)
    SpyAgent operator-(int val)
    {
        return SpyAgent(name, missions - val);
    }

    // Case 2: int + SpyAgent  (friend handles value + obj)
    friend SpyAgent operator+(int val, const SpyAgent &a);

    // ============================================================
    //   TASK 8 - Friend Class
    // ============================================================

    friend class SpyHQ;
};

// ============================================================
//   TASK 2 - Friend Function Definitions (Unary)
// ============================================================

SpyAgent &operator++(SpyAgent &a)
{
    a.missions++;
    cout << "Agent " << a.name << " promoted. Missions: " << a.missions << endl;
    return a;
}

SpyAgent &operator--(SpyAgent &a)
{
    a.missions--;
    cout << "Agent " << a.name << " demoted. Missions: " << a.missions << endl;
    return a;
}

// ============================================================
//   TASK 2 - Friend Function Definitions (Binary)
// ============================================================

SpyAgent operator+(const SpyAgent &a, const SpyAgent &b)
{
    return SpyAgent("Combined", a.missions + b.missions);
}

SpyAgent operator-(const SpyAgent &a, const SpyAgent &b)
{
    return SpyAgent("Difference", a.missions - b.missions);
}

SpyAgent operator*(const SpyAgent &a, const SpyAgent &b)
{
    return SpyAgent("Multiplied", a.missions * b.missions);
}

SpyAgent operator/(const SpyAgent &a, const SpyAgent &b)
{
    return SpyAgent("Divided", a.missions / b.missions);
}

// ============================================================
//   TASK 4 - Comparison Operator Definitions
// ============================================================

bool operator==(const SpyAgent &a, const SpyAgent &b) { return a.missions == b.missions; }
bool operator!=(const SpyAgent &a, const SpyAgent &b) { return a.missions != b.missions; }
bool operator>(const SpyAgent &a, const SpyAgent &b) { return a.missions > b.missions; }

// ============================================================
//   TASK 6 - Additional Comparison Operator Definitions
// ============================================================

bool operator<(const SpyAgent &a, const SpyAgent &b) { return a.missions < b.missions; }
bool operator<=(const SpyAgent &a, const SpyAgent &b) { return a.missions <= b.missions; }
bool operator>=(const SpyAgent &a, const SpyAgent &b) { return a.missions >= b.missions; }

// ============================================================
//   TASK 7 - int + SpyAgent (Friend Function Definition)
// ============================================================

SpyAgent operator+(int val, const SpyAgent &a)
{
    return SpyAgent(a.name, val + a.missions);
}

// ============================================================
//   TASK 3 - SpyLog Class (Friend Function + Stream Operators)
// ============================================================

class SpyLog
{
private:
    string agentName;
    string operation;
    int clearance;

public:
    SpyLog()
    {
        agentName = "";
        operation = "";
        clearance = 0;
    }

    friend void printLog(const SpyLog &log);

    // >> Input Operator
    friend istream &operator>>(istream &in, SpyLog &log)
    {
        cout << "Enter agent name: ";
        in >> log.agentName;
        cout << "Enter operation: ";
        in.ignore();
        getline(in, log.operation);
        cout << "Enter clearance level: ";
        in >> log.clearance;
        return in;
    }

    // << Output Operator
    friend ostream &operator<<(ostream &out, const SpyLog &log)
    {
        out << "Agent: " << log.agentName
            << " | Operation: " << log.operation
            << " | Clearance: " << log.clearance;
        return out;
    }
};

void printLog(const SpyLog &log)
{
    cout << "Pink Panther is processing log..." << endl;
    cout << "Agent: " << log.agentName
         << " | Operation: " << log.operation
         << " | Clearance: " << log.clearance << endl;
}

// ============================================================
//   TASK 8 - SpyHQ Class (Friend Class of SpyAgent)
// ============================================================

class SpyHQ
{
public:
    void showAgentDetails(SpyAgent &agent)
    {
        // Direct access to SpyAgent private members via friend class
        cout << "[SpyHQ Access] Agent Name: " << agent.name
             << " | Missions: " << agent.missions << endl;
    }
};

// ============================================================
//                          MAIN
// ============================================================

int main()
{

    // ---- TASK 2: Friend Function Operators ----
    cout << "========== TASK 2: Friend Function Operators ==========" << endl;
    SpyAgent a("Panther", 10);
    SpyAgent b("Clouseau", 5);

    ++a;
    --b;

    SpyAgent c = a + b;
    cout << "Combined Missions: " << c.getMissions() << endl;

    SpyAgent d = a - b;
    cout << "Mission Difference: " << d.getMissions() << endl;

    SpyAgent e = a * b;
    cout << "Multiplied Missions: " << e.getMissions() << endl;

    SpyAgent f = a / b;
    cout << "Division: " << f.getMissions() << endl;

    // ---- TASK 3: Stream Operators ----
    cout << "\n========== TASK 3: Stream Operators ==========" << endl;
    SpyLog log;
    cin >> log;
    printLog(log);

    // ---- TASK 4: Comparison Operators ----
    cout << "\n========== TASK 4: Comparison Operators ==========" << endl;
    SpyAgent p("Panther", 11);
    SpyAgent q("Clouseau", 4);

    if (p > q)
        cout << "Agent " << p.getName() << " has more missions than " << q.getName() << endl;
    if (p != q)
        cout << "Agents are not equal" << endl;
    if (p == p)
        cout << "Agent compared with itself: equal" << endl;

    // ---- TASK 5: Assignment Operators ----
    cout << "\n========== TASK 5: Assignment Operators ==========" << endl;
    SpyAgent x("Panther", 15);
    SpyAgent y("Clouseau", 5);

    x = y;
    cout << "Agent Panther assigned data from Clouseau" << endl;
    x.display();

    x += SpyAgent("", 15);
    cout << "Agent Panther updated missions: " << x.getMissions() << endl;

    x -= SpyAgent("", 3);
    cout << "After -= 3, missions: " << x.getMissions() << endl;

    // ---- TASK 6: Additional Comparison Operators ----
    cout << "\n========== TASK 6: Additional Comparisons ==========" << endl;
    SpyAgent m("Panther", 10);
    SpyAgent n("Clouseau", 20);

    if (m < n)
        cout << m.getName() << " has less missions than " << n.getName() << endl;
    if (m <= n)
        cout << m.getName() << " <= " << n.getName() << endl;
    if (n >= m)
        cout << n.getName() << " >= " << m.getName() << endl;

    // ---- TASK 7: Mixed Operand Overloading ----
    cout << "\n========== TASK 7: Mixed Operands ==========" << endl;
    SpyAgent ag("Panther", 10);

    SpyAgent r1 = ag + 5;
    cout << "SpyAgent + int (10+5): " << r1.getMissions() << endl;

    SpyAgent r2 = 5 + ag;
    cout << "int + SpyAgent (5+10): " << r2.getMissions() << endl;

    SpyAgent r3 = ag - 3;
    cout << "SpyAgent - int (10-3): " << r3.getMissions() << endl;

    // ---- TASK 8: Friend Class ----
    cout << "\n========== TASK 8: Friend Class SpyHQ ==========" << endl;
    SpyAgent secret("Panther", 10);
    SpyHQ hq;
    hq.showAgentDetails(secret);

    // ---- TASK 9: Forward Declaration (already done at top) ----
    cout << "\n========== TASK 9: Forward Declaration ==========" << endl;
    cout << "'class SpyHQ;' declared at top before SpyAgent." << endl;
    cout << "This avoids circular dependency between SpyAgent and SpyHQ." << endl;

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// ============================================================
//                        TASK 1
//   SpyAgent - Unary & Binary Operators (Member Functions)
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

    // ---- Unary Operators (Member Functions) ----

    SpyAgent &operator++()
    {
        missions++;
        cout << "Agent " << name << " promoted. Missions: " << missions << endl;
        return *this;
    }

    SpyAgent &operator--()
    {
        missions--;
        cout << "Agent " << name << " demoted. Missions: " << missions << endl;
        return *this;
    }

    // ---- Binary Operators (Member Functions) ----

    SpyAgent operator+(const SpyAgent &other)
    {
        return SpyAgent("Combined", missions + other.missions);
    }

    SpyAgent operator-(const SpyAgent &other)
    {
        return SpyAgent("Difference", missions - other.missions);
    }

    SpyAgent operator*(const SpyAgent &other)
    {
        return SpyAgent("Multiplied", missions * other.missions);
    }

    SpyAgent operator/(const SpyAgent &other)
    {
        return SpyAgent("Divided", missions / other.missions);
    }
};

int main()
{
    SpyAgent a("Panther", 10);
    SpyAgent b("Clouseau", 5);

    // Unary
    ++a;
    --b;

    // Binary
    SpyAgent c = a + b;
    cout << "Combined Missions: " << c.getMissions() << endl;

    SpyAgent d = a - b;
    cout << "Mission Difference: " << d.getMissions() << endl;

    SpyAgent e = a * b;
    cout << "Multiplied Missions: " << e.getMissions() << endl;

    SpyAgent f = a / b;
    cout << "Division: " << f.getMissions() << endl;

    return 0;
}

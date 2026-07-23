#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// CHARACTER (BASE CLASS) Parent Absolute

class Character {
private:
    string name;
    int age;

public:
    Character() {
        name = "Unknown";
        age = 0;
    }

    Character(string n, int a) {
        setName(n);
        setAge(a);
    }

    void setName(string n) {
        if (n.empty())
            throw invalid_argument("Name cannot be empty!");
        name = n;
    }

    void setAge(int a) {
        if (a < 0)
            throw invalid_argument("Age cannot be negative!");
        age = a;
    }

    string getName() { return name; }
    int getAge() { return age; }

    void displayCharacterInfo() {
        cout << "Name: " << name << endl;
        cout << "Age:  " << age << endl;
    }
};

// HUMAN (DERIVED FROM CHARACTER) Single Level inheritance
class Human : virtual public Character {
private:
    string nationality;
    string personality;

public:
    Human() : Character() {
        nationality = "Unknown";
        personality = "Unknown";
    }

    Human(string n, int a, string nat, string per) : Character(n, a) {
        setNationality(nat);
        setPersonality(per);
    }

    void setNationality(string nat) {
        if (nat.empty())
            throw invalid_argument("Nationality cannot be empty!");
        nationality = nat;
    }

    void setPersonality(string per) {
        if (per.empty())
            throw invalid_argument("Personality cannot be empty!");
        personality = per;
    }

    string getNationality() { return nationality; }
    string getPersonality() { return personality; }

    void displayHumanTraits() {
        cout << "=== Human Information ===" << endl;
        displayCharacterInfo();
        cout << "Nationality: " << nationality << endl;
        cout << "Personality: " << personality << endl;
    }

    void think() {
        cout << getName() << " uses logic and human intelligence to solve problems." << endl;
    }
};

//  ALIEN (DERIVED FROM CHARACTER) 
class Alien : virtual public Character {
private:
    string planetOrigin;
    string specialPower;

public:
    Alien() : Character() {
        planetOrigin = "Unknown";
        specialPower = "Unknown";
    }

    Alien(string n, int a, string planet, string power) : Character(n, a) {
        setPlanetOrigin(planet);
        setSpecialPower(power);
    }

    void setPlanetOrigin(string planet) {
        if (planet.empty())
            throw invalid_argument("Planet origin cannot be empty!");
        planetOrigin = planet;
    }

    void setSpecialPower(string power) {
        if (power.empty())
            throw invalid_argument("Special power cannot be empty!");
        specialPower = power;
    }

    string getPlanetOrigin() { return planetOrigin; }
    string getSpecialPower() { return specialPower; }

    void displayAlienTraits() {
        cout << "=== Alien Information ===" << endl;
        displayCharacterInfo();
        cout << "Planet of Origin: " << planetOrigin << endl;
        cout << "Special Power:    " << specialPower << endl;
    }

    void usePower() {
        cout << getName() << " uses " << specialPower << " to unleash a blazing attack!" << endl;
    }
};

//  HUMANALIENCOMBO (DERIVED FROM HUMAN AND ALIEN) Omnitrix objects
class HumanAlienCombo : public Human, public Alien {
private:
    int omnitrixID;
    string omnitrixVersion;

public:
    HumanAlienCombo() : Character(), Human(), Alien() {
        omnitrixID = 0;
        omnitrixVersion = "Unknown";
    }

    HumanAlienCombo(string n, int a, string nat, string per,
        string planet, string power,
        int id, string version)
        : Character(n, a), Human(n, a, nat, per), Alien(n, a, planet, power) {
        setOmnitrixID(id);
        setOmnitrixVersion(version);
    }

    void setOmnitrixID(int id) {
        if (id <= 0)
            throw invalid_argument("Omnitrix ID must be positive!");
        omnitrixID = id;
    }

    void setOmnitrixVersion(string version) {
        if (version.empty())
            throw invalid_argument("Omnitrix version cannot be empty!");
        omnitrixVersion = version;
    }

    int getOmnitrixID() { return omnitrixID; }
    string getOmnitrixVersion() { return omnitrixVersion; }

    void activateOmnitrix() {
        cout << "Omnitrix activated - transformation sequence initiated!" << endl;
    }

    void displayAbilities() {
        think();
        usePower();
    }

    void displayHybridProfile() {
        cout << "=== Ben10 Hybrid Profile (Fixed Diamond) ===" << endl;
        displayCharacterInfo();
        cout << "Nationality:      " << getNationality() << endl;
        cout << "Personality:      " << getPersonality() << endl;
        cout << "Planet Origin:    " << getPlanetOrigin() << endl;
        cout << "Special Power:    " << getSpecialPower() << endl;
        cout << "Omnitrix ID:      " << omnitrixID << endl;
        cout << "Omnitrix Version: " << omnitrixVersion << endl;
    }
};

//MAIN function:
 int main() {

    // Human objects Only
    try {
        Human h1("Ben Tennyson", 16, "American", "Brave");
        h1.displayHumanTraits();
        h1.think();
        cout << endl;

        Human h2("Gwen Tennyson", 16, "American", "Intelligent");
        h2.displayHumanTraits();
        h2.think();
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Alien objects Only
    try {
        Alien a1("Heatblast", 200, "Pyros", "Fire Manipulation");
        a1.displayAlienTraits();
        a1.usePower();
        cout << endl;

        Alien a2("XLR8", 150, "Kinet", "Super Speed");
        a2.displayAlienTraits();
        a2.usePower();
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Hybrid objects only;
    try {
        HumanAlienCombo ben("Ben Tennyson Hybrid", 16, "American", "Brave",
            "Pyros", "Fire Manipulation", 1001, "V2.5");
        ben.displayHybridProfile();
        ben.displayAbilities();
        ben.activateOmnitrix();
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    //  Exception Handling Demo
    cout << "=== Exception Handling Demo ===" << endl;
    try {
        Human h3("", 16, "American", "Brave");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        Alien a3("Heatblast", -5, "Pyros", "Fire Manipulation");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        HumanAlienCombo b2("Ben", 16, "American", "Brave",
            "Pyros", "Fire", -99, "V1");
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
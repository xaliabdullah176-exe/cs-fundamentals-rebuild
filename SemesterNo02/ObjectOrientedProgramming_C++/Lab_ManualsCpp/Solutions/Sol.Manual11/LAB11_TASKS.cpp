#include <iostream>
#include <string>
using namespace std;

// 
//          PART 1: MULTI-LEVEL INHERITANCE
// 

// Base Class: Trainer
class Trainer {
protected:
    string name;
    int age;
public:
    void setName(string n) { name = n; }
    void setAge(int a)     { age = a; }
    void showInfo() {
        cout << "Trainer Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class: GymTrainer (inherits Trainer)
class GymTrainer : public Trainer {
protected:
    string gymName;
    string specialtyType;
public:
    void setGym(string g)  { gymName = g; }
    void setType(string t) { specialtyType = t; }
    void showInfo() {
        Trainer::showInfo();
        cout << "Gym: " << gymName << endl;
        cout << "Specialty Type: " << specialtyType << endl;
    }
};

// Derived Class: GymLeader (inherits GymTrainer)
class GymLeader : public GymTrainer {
private:
    string badgeReward;
public:
    void setBadge(string b) { badgeReward = b; }
    void showInfo() {
        GymTrainer::showInfo();
        cout << "Badge Reward: " << badgeReward << endl;
    }
};


// 
//          PART 2: MULTIPLE INHERITANCE
// 

// Independent Class: Professor
class Professor {
protected:
    string field;
public:
    void setField(string f) { field = f; }
    void showProfessorInfo() {
        cout << "Field: " << field << endl;
    }
};

// ProfessorTrainer (inherits Trainer AND Professor)
class ProfessorTrainer : public Trainer, public Professor {
private:
    string researchArea;
public:
    void setResearch(string r) { researchArea = r; }
    void showInfo() {
        Trainer::showInfo();
        showProfessorInfo();
        cout << "Research Area: " << researchArea << endl;
    }
};


// 
//          PART 3: HIERARCHICAL INHERITANCE
// 

// Base Class: Pokemon
class Pokemon {
protected:
    string name;
    int level;
public:
    void setPokemon(string n, int l) {
        name = n;
        level = l;
    }
    void showInfo() {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
    }
};

// FirePokemon
class FirePokemon : public Pokemon {
private:
    int flamePower;
public:
    void setFlamePower(int f) { flamePower = f; }
    void showInfo() {
        Pokemon::showInfo();
        cout << "Type: Fire | Flame Power: " << flamePower << endl;
    }
};

// WaterPokemon
class WaterPokemon : public Pokemon {
private:
    int waterPressure;
public:
    void setWaterPressure(int w) { waterPressure = w; }
    void showInfo() {
        Pokemon::showInfo();
        cout << "Type: Water | Water Pressure: " << waterPressure << endl;
    }
};

// ElectricPokemon
class ElectricPokemon : public Pokemon {
private:
    int voltage;
public:
    void setVoltage(int v) { voltage = v; }
    void showInfo() {
        Pokemon::showInfo();
        cout << "Type: Electric | Voltage: " << voltage << endl;
    }
};

// GrassPokemon
class GrassPokemon : public Pokemon {
private:
    int growthRate;
public:
    void setGrowthRate(int g) { growthRate = g; }
    void showInfo() {
        Pokemon::showInfo();
        cout << "Type: Grass | Growth Rate: " << growthRate << endl;
    }
};

// FlyingPokemon
class FlyingPokemon : public Pokemon {
private:
    int flightSpeed;
public:
    void setFlightSpeed(int s) { flightSpeed = s; }
    void showInfo() {
        Pokemon::showInfo();
        cout << "Type: Flying | Flight Speed: " << flightSpeed << endl;
    }
};


// 
//          PART 4: INDEPENDENT CLASS (No Inheritance)
// 

class Badge {
private:
    int badgeID;
    string badgeInfo;
public:
    void setBadge(int id, string info) {
        badgeID = id;
        badgeInfo = info;
    }
    void showBadge() {
        cout << "Badge ID: " << badgeID
             << " | Badge: " << badgeInfo << endl;
    }
};


// 
//                      MAIN FUNCTION

int main() {

    cout << "========================================" << endl;
    cout << "         POKEMON WORLD SYSTEM           " << endl;
    cout << "========================================" << endl;

    // --- TRAINERS ---
    cout << "\n--- Trainers ---" << endl;

    Trainer t1, t2, t3;

    t1.setName("Ash Ketchum"); t1.setAge(15); t1.showInfo(); cout << endl;
    t2.setName("Misty");       t2.setAge(16); t2.showInfo(); cout << endl;
    t3.setName("Gary Oak");    t3.setAge(16); t3.showInfo(); cout << endl;

    // --- GYM TRAINERS ---
    cout << "\n--- Gym Trainers ---" << endl;

    GymTrainer gt1, gt2;

    gt1.setName("Daisy"); gt1.setAge(18);
    gt1.setGym("Cerulean Gym"); gt1.setType("Water");
    gt1.showInfo(); cout << endl;

    gt2.setName("Flint"); gt2.setAge(22);
    gt2.setGym("Cinnabar Gym"); gt2.setType("Fire");
    gt2.showInfo(); cout << endl;

    // --- GYM LEADERS ---
    cout << "\n--- Gym Leaders ---" << endl;

    GymLeader gl1, gl2;

    gl1.setName("Brock"); gl1.setAge(20);
    gl1.setGym("Pewter Gym"); gl1.setType("Rock");
    gl1.setBadge("Boulder Badge");
    gl1.showInfo(); cout << endl;

    gl2.setName("Lt. Surge"); gl2.setAge(25);
    gl2.setGym("Vermilion Gym"); gl2.setType("Electric");
    gl2.setBadge("Thunder Badge");
    gl2.showInfo(); cout << endl;

    // --- PROFESSOR ---
    cout << "\n--- Professor ---" << endl;

    Professor prof;
    prof.setField("Pokemon Evolution");
    prof.showProfessorInfo(); cout << endl;

    // --- PROFESSOR TRAINER ---
    cout << "\n--- Professor Trainer ---" << endl;

    ProfessorTrainer pt;
    pt.setName("Professor Willow"); pt.setAge(35);
    pt.setField("Pokemon Behavior");
    pt.setResearch("Field Research");
    pt.showInfo(); cout << endl;

    // --- POKEMON ---
    cout << "\n--- Pokemon ---" << endl;

    // Base class only — Eevee
    Pokemon eevee;
    eevee.setPokemon("Eevee", 10);
    eevee.showInfo(); cout << endl;

    // Derived types
    ElectricPokemon pikachu;
    pikachu.setPokemon("Pikachu", 25);
    pikachu.setVoltage(90);
    pikachu.showInfo(); cout << endl;

    FirePokemon charizard;
    charizard.setPokemon("Charizard", 50);
    charizard.setFlamePower(120);
    charizard.showInfo(); cout << endl;

    WaterPokemon squirtle;
    squirtle.setPokemon("Squirtle", 20);
    squirtle.setWaterPressure(80);
    squirtle.showInfo(); cout << endl;

    GrassPokemon bulbasaur;
    bulbasaur.setPokemon("Bulbasaur", 18);
    bulbasaur.setGrowthRate(70);
    bulbasaur.showInfo(); cout << endl;

    FlyingPokemon pidgeotto;
    pidgeotto.setPokemon("Pidgeotto", 30);
    pidgeotto.setFlightSpeed(85);
    pidgeotto.showInfo(); cout << endl;

    // --- BADGES ---
    cout << "\n--- Badges ---" << endl;

    Badge b1, b2, b3;
    b1.setBadge(101, "Thunder Badge");  b1.showBadge();
    b2.setBadge(102, "Cascade Badge");  b2.showBadge();
    b3.setBadge(103, "Boulder Badge");  b3.showBadge();

    return 0;
}
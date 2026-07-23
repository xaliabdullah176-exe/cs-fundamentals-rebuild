#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Pokemon; // forward declaration

class Badge {
private:
    int badgeID;
    string badgeInfo;
public:
    Badge() : badgeID(0), badgeInfo("") {}
    void setBadge(int id, string info) {
        badgeID = id;
        badgeInfo = info;
    }
    void showBadge() {
        cout << "Badge ID: " << badgeID
            << " | Badge: " << badgeInfo << endl;
    }
};

class Trainer {
protected:
    string name;
    int age;
    Pokemon** pokemons;
    int pokemonCount;
    Badge* badges;
    int badgeCount;
public:
    Trainer() : pokemonCount(0), badgeCount(0), pokemons(nullptr), badges(nullptr) {}
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    void addPokemon(Pokemon* p) {
        Pokemon** newArr = new Pokemon * [pokemonCount + 1];
        for (int i = 0; i < pokemonCount; i++)
            newArr[i] = pokemons[i];
        newArr[pokemonCount] = p;
        delete[] pokemons;
        pokemons = newArr;
        pokemonCount++;
    }

    void addBadge(int id, string info) {
        Badge* newArr = new Badge[badgeCount + 1];
        for (int i = 0; i < badgeCount; i++)
            newArr[i] = badges[i];
        newArr[badgeCount].setBadge(id, info);
        delete[] badges;
        badges = newArr;
        badgeCount++;
    }

    virtual void showInfo(); // defined after Pokemon

    virtual ~Trainer() {
        delete[] badges;
        delete[] pokemons;
    }
};

class GymTrainer : public Trainer {
protected:
    string gymName;
    string specialtyType;
public:
    void setGym(string g) { gymName = g; }
    void setType(string t) { specialtyType = t; }
    void showInfo() override {
        Trainer::showInfo();
        cout << "Gym: " << gymName << endl;
        cout << "Specialty Type: " << specialtyType << endl;
    }
};

class GymLeader final : public GymTrainer {
private:
    string badgeReward;
public:
    void setBadge(string b) { badgeReward = b; }
    void showInfo() override {
        GymTrainer::showInfo();
        cout << "Badge Reward: " << badgeReward << endl;
    }
};

class Professor {
protected:
    string field;
public:
    void setField(string f) { field = f; }
    void showProfessorInfo() {
        cout << "Field: " << field << endl;
    }
};

class ProfessorTrainer : public Trainer, public Professor {
private:
    string researchArea;
public:
    void setResearch(string r) { researchArea = r; }
    void showInfo() override {
        Trainer::showInfo();
        showProfessorInfo();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Pokemon {
protected:
    string name;
    int level;
public:
    Pokemon(string n, int l) : name(n), level(l) {}
    virtual void showInfo() = 0;
    virtual ~Pokemon() {}
};

class FirePokemon : public Pokemon {
private:
    int flamePower;
public:
    FirePokemon(string n, int l, int fp) : Pokemon(n, l), flamePower(fp) {}
    void showInfo() override {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
        cout << "Type: Fire | Flame Power: " << flamePower << endl;
    }
};

class WaterPokemon : public Pokemon {
private:
    int waterPressure;
public:
    WaterPokemon(string n, int l, int wp) : Pokemon(n, l), waterPressure(wp) {}
    void showInfo() override {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
        cout << "Type: Water | Water Pressure: " << waterPressure << endl;
    }
};

class ElectricPokemon : public Pokemon {
private:
    int voltage;
public:
    ElectricPokemon(string n, int l, int v) : Pokemon(n, l), voltage(v) {}
    void showInfo() override {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
        cout << "Type: Electric | Voltage: " << voltage << endl;
    }
};

class GrassPokemon : public Pokemon {
private:
    int growthRate;
public:
    GrassPokemon(string n, int l, int g) : Pokemon(n, l), growthRate(g) {}
    void showInfo() override {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
        cout << "Type: Grass | Growth Rate: " << growthRate << endl;
    }
};

class FlyingPokemon : public Pokemon {
private:
    int flightSpeed;
public:
    FlyingPokemon(string n, int l, int s) : Pokemon(n, l), flightSpeed(s) {}
    void showInfo() override {
        cout << "Pokemon: " << name << " | Level: " << level << endl;
        cout << "Type: Flying | Flight Speed: " << flightSpeed << endl;
    }
};

// Trainer::showInfo defined HERE after Pokemon is fully known
inline void Trainer::showInfo() {
    cout << "Trainer Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Total Pokemon: " << pokemonCount << endl;
    cout << "Total Badges: " << badgeCount << endl;
    for (int i = 0; i < pokemonCount; i++)
        pokemons[i]->showInfo();
    for (int i = 0; i < badgeCount; i++)
        badges[i].showBadge();
}

int main() {
    cout << "========================================" << endl;
    cout << "         POKEMON WORLD SYSTEM           " << endl;
    cout << "========================================" << endl;

    Pokemon* pikachu = new ElectricPokemon("Pikachu", 25, 90);
    Pokemon* charizard = new FirePokemon("Charizard", 50, 120);
    Pokemon* bulbasaur = new GrassPokemon("Bulbasaur", 18, 70);
    Pokemon* squirtle = new WaterPokemon("Squirtle", 20, 80);
    Pokemon* pidgeotto = new FlyingPokemon("Pidgeotto", 30, 85);

    cout << "\n--- Trainers ---" << endl;
    Trainer t1, t2, t3;
    t1.setName("Ash Ketchum"); t1.setAge(15);
    t2.setName("Misty");       t2.setAge(16);
    t3.setName("Gary Oak");    t3.setAge(16);

    t1.addPokemon(pikachu);
    t1.addPokemon(charizard);
    t1.addPokemon(bulbasaur);
    t1.addPokemon(squirtle);
    t1.addPokemon(pidgeotto);

    t1.addBadge(101, "Thunder Badge");
    t1.addBadge(102, "Cascade Badge");
    t1.addBadge(103, "Boulder Badge");

    t1.showInfo(); cout << endl;
    t2.showInfo(); cout << endl;
    t3.showInfo(); cout << endl;

    cout << "\n--- Gym Trainers ---" << endl;
    GymTrainer gt1, gt2;
    gt1.setName("Daisy"); gt1.setAge(18);
    gt1.setGym("Cerulean Gym"); gt1.setType("Water");
    gt2.setName("Flint"); gt2.setAge(22);
    gt2.setGym("Cinnabar Gym"); gt2.setType("Fire");
    gt1.showInfo(); cout << endl;
    gt2.showInfo(); cout << endl;

    cout << "\n--- Gym Leaders ---" << endl;
    GymLeader gl1, gl2;
    gl1.setName("Brock");     gl1.setAge(20);
    gl1.setGym("Pewter Gym"); gl1.setType("Rock");
    gl1.setBadge("Boulder Badge");
    gl2.setName("Lt. Surge");    gl2.setAge(25);
    gl2.setGym("Vermilion Gym"); gl2.setType("Electric");
    gl2.setBadge("Thunder Badge");
    gl1.showInfo(); cout << endl;
    gl2.showInfo(); cout << endl;

    cout << "\n--- Professor Trainer ---" << endl;
    ProfessorTrainer pt;
    pt.setName("Professor Willow"); pt.setAge(35);
    pt.setField("Pokemon Behavior");
    pt.setResearch("Field Research");
    pt.showInfo(); cout << endl;

    cout << "\n--- Casting Demonstration ---" << endl;

    Trainer* basePtr = new GymLeader();
    static_cast<GymLeader*>(basePtr)->setBadge("Earth Badge");
    static_cast<GymLeader*>(basePtr)->setName("Giovanni");
    static_cast<GymLeader*>(basePtr)->setAge(40);
    static_cast<GymLeader*>(basePtr)->setGym("Viridian Gym");
    static_cast<GymLeader*>(basePtr)->setType("Ground");

    cout << "\nstatic_cast result:" << endl;
    static_cast<GymLeader*>(basePtr)->showInfo();

    cout << "\ndynamic_cast test (GymLeader -> GymLeader):" << endl;
    GymLeader* safePtr = dynamic_cast<GymLeader*>(basePtr);
    if (safePtr != nullptr)
        cout << "dynamic_cast SUCCESS!" << endl;
    else
        cout << "dynamic_cast FAILED!" << endl;

    cout << "\ndynamic_cast test (Trainer* -> GymLeader*) on wrong type:" << endl;
    Trainer* trainerPtr = new Trainer();
    GymLeader* failPtr = dynamic_cast<GymLeader*>(trainerPtr);
    if (failPtr == nullptr)
        cout << "dynamic_cast FAILED safely (nullptr returned)!" << endl;

    cout << "\ntypeid demonstration:" << endl;
    cout << "basePtr points to: " << typeid(*basePtr).name() << endl;
    cout << "trainerPtr points to: " << typeid(*trainerPtr).name() << endl;

    delete pikachu; delete charizard; delete bulbasaur;
    delete squirtle; delete pidgeotto;
    delete basePtr;
    delete trainerPtr;

    return 0;
}
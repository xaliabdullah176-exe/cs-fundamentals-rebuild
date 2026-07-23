#include <iostream>
#include <string>
using namespace std;

class TownsvilleGuardian
{
private:
    string heroName;
    int energyLevel;
    int villainsDefeated;
    string superPower;

public:
    // Default Constructor
    TownsvilleGuardian()
    {
        heroName = "New Recruit";
        energyLevel = 60;
        villainsDefeated = 0;
        superPower = "Chemical X Burst";
    }

    // Overloaded Constructor
    TownsvilleGuardian(string name, int energy, string power)
    {
        heroName = name;
        energyLevel = energy;
        villainsDefeated = 0;
        superPower = power;
    }

    // Destructor
    ~TownsvilleGuardian()
    {
        cout << "Guardian signing off... Townsville is safe!" << endl;
    }

    // ─── Accessor Functions (Getters) ───────────────────────────────────────
    string getHeroName() const
    {
        return heroName;
    }

    int getEnergyLevel() const
    {
        return energyLevel;
    }

    int getVillainsDefeated() const
    {
        return villainsDefeated;
    }

    // ─── Mutator Functions (Setters) ────────────────────────────────────────
    void setEnergyLevel(int energy)
    {
        if (energy >= 0 && energy <= 100)
            energyLevel = energy;
        else
            cout << "Invalid energy level! Must be between 0 and 100." << endl;
    }

    void defeatVillain()
    {
        villainsDefeated++;
    }

    // ─── Utility Functions ──────────────────────────────────────────────────
    void displayStatus() const
    {
        cout << "Hero: " << heroName << endl;
        cout << "Energy Level: " << energyLevel << endl;
        cout << "Villains Defeated: " << villainsDefeated << endl;
        cout << "Super Power: " << superPower << endl;
    }

    void battle(int villainStrength)
    {
        if (energyLevel > villainStrength)
        {
            cout << "Villain defeated!" << endl;
            defeatVillain();
            energyLevel -= 10;
            if (energyLevel < 0)
                energyLevel = 0;
        }
        else
        {
            cout << "Retreat! Call Professor Utonium!" << endl;
        }
    }

    void recharge()
    {
        energyLevel += 15;
        if (energyLevel > 100)
            energyLevel = 100;
    }

    // ─── Object Passing & Returning ─────────────────────────────────────────
    int compareEnergy(TownsvilleGuardian otherGuardian) const
    {
        if (energyLevel > otherGuardian.energyLevel)
            return 1;
        else if (energyLevel < otherGuardian.energyLevel)
            return -1;
        else
            return 0;
    }

    TownsvilleGuardian nextBattleReady() const
    {
        int newEnergy = energyLevel + 5;
        if (newEnergy > 100)
            newEnergy = 100;

        TownsvilleGuardian next(heroName, newEnergy, superPower);
        next.villainsDefeated = villainsDefeated;
        return next;
    }
};

// ─── Main ────────────────────────────────────────────────────────────────────
int main()
{
    cout << "==============================" << endl;
    cout << "  Townsville Guardian Program " << endl;
    cout << "==============================" << endl;

    // 1. Default constructor
    cout << "\n--- Default Constructor ---" << endl;
    TownsvilleGuardian g1;
    g1.displayStatus();

    // 2. Overloaded constructor
    cout << "\n--- Overloaded Constructor ---" << endl;
    TownsvilleGuardian g2("Blossom", 85, "Ice Breath");
    g2.displayStatus();

    // 3a. Accessor functions
    cout << "\n--- Accessor Functions ---" << endl;
    cout << "Hero Name: " << g2.getHeroName() << endl;
    cout << "Energy Level: " << g2.getEnergyLevel() << endl;
    cout << "Villains Defeated: " << g2.getVillainsDefeated() << endl;

    // 3b. Mutator functions
    cout << "\n--- Mutator Functions ---" << endl;
    g2.setEnergyLevel(90);
    cout << "Energy after setEnergyLevel(90): " << g2.getEnergyLevel() << endl;
    g2.setEnergyLevel(150); // invalid
    g2.defeatVillain();
    cout << "Villains after defeatVillain(): " << g2.getVillainsDefeated() << endl;

    // 3c. Utility functions
    cout << "\n--- Battle (strong villain - strength 80) ---" << endl;
    g2.battle(80); // energyLevel 90 > 80 = win
    cout << "\n--- Battle (strong villain - strength 95) ---" << endl;
    g2.battle(95); // energyLevel 80 < 95 = retreat

    cout << "\n--- Recharge ---" << endl;
    g2.recharge();
    cout << "Energy after recharge: " << g2.getEnergyLevel() << endl;

    cout << "\n--- Display Status after battles ---" << endl;
    g2.displayStatus();

    // 4. Compare energy
    cout << "\n--- Compare Energy ---" << endl;
    int cmp = g2.compareEnergy(g1);
    if (cmp == 1)
        cout << g2.getHeroName() << " has MORE energy than " << g1.getHeroName() << endl;
    else if (cmp == -1)
        cout << g2.getHeroName() << " has LESS energy than " << g1.getHeroName() << endl;
    else
        cout << "Both guardians have EQUAL energy." << endl;

    // 5. nextBattleReady
    cout << "\n--- Next Battle Ready ---" << endl;
    TownsvilleGuardian g3 = g2.nextBattleReady();
    cout << "Original " << g2.getHeroName() << " energy: " << g2.getEnergyLevel() << endl;
    cout << "New ready guardian energy:  " << g3.getEnergyLevel() << endl;

    // 6. Destructor called automatically at scope end
    cout << "\n--- Program Ending - Destructors Called ---" << endl;
    return 0;
}
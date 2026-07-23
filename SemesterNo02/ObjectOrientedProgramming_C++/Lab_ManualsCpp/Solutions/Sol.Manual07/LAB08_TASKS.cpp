#include <iostream>
using namespace std;

class AnpanMedBot
{
private:
    char *name;
    int healingCapacity;
    static int totalBots;

    int myStrLen(const char *s) const
    {
        int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }

    void myStrCpy(char *dest, const char *src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void validateHealingCapacity(int h)
    {
        if (h < 0)
            healingCapacity = 0;
        else if (h > 1000)
            healingCapacity = 1000;
        else
            healingCapacity = h;
    }

public:
    AnpanMedBot()
    {
        const char *defaultName = "UnknownBot";
        int len = myStrLen(defaultName);
        name = new char[len + 1];
        myStrCpy(name, defaultName);
        healingCapacity = 0;
        totalBots++;
    }

    AnpanMedBot(const char *botName, int botHealingCapacity)
    {
        if (botName == nullptr || botName[0] == '\0')
        {
            const char *defaultName = "UnknownBot";
            int len = myStrLen(defaultName);
            name = new char[len + 1];
            myStrCpy(name, defaultName);
        }
        else
        {
            int len = myStrLen(botName);
            name = new char[len + 1];
            myStrCpy(name, botName);
        }
        validateHealingCapacity(botHealingCapacity);
        totalBots++;
    }

    AnpanMedBot(const AnpanMedBot &other)
    {
        int len = myStrLen(other.name);
        name = new char[len + 1];
        myStrCpy(name, other.name);
        healingCapacity = other.healingCapacity;
        totalBots++;
    }

    AnpanMedBot(AnpanMedBot &&other)
    {
        name = other.name;
        other.name = nullptr;
        healingCapacity = other.healingCapacity;
    }

    AnpanMedBot &operator=(const AnpanMedBot &other)
    {
        if (this == &other)
            return *this;
        delete[] name;
        int len = myStrLen(other.name);
        name = new char[len + 1];
        myStrCpy(name, other.name);
        healingCapacity = other.healingCapacity;
        return *this;
    }

    ~AnpanMedBot()
    {
        delete[] name;
    }

    static void showTotalBots()
    {
        cout << "Total Bots Created: " << totalBots << endl;
    }

    AnpanMedBot *setName(const char *botName)
    {
        if (botName == nullptr || botName[0] == '\0')
        {
            cout << "Invalid name! Keeping old name." << endl;
            return this;
        }
        delete[] name;
        int len = myStrLen(botName);
        name = new char[len + 1];
        myStrCpy(name, botName);
        return this;
    }

    AnpanMedBot &setHealingCapacity(int botHealingCapacity)
    {
        validateHealingCapacity(botHealingCapacity);
        return *this;
    }

    const char *getName() const
    {
        return name;
    }

    int getHealingCapacity() const
    {
        return healingCapacity;
    }

    void operator++()
    {
        healingCapacity += 50;
        if (healingCapacity > 1000)
            healingCapacity = 1000;
    }

    AnpanMedBot operator+(const AnpanMedBot &other)
    {
        int combinedCapacity = healingCapacity + other.healingCapacity;
        if (combinedCapacity > 1000)
            combinedCapacity = 1000;
        return AnpanMedBot("CombinedBot", combinedCapacity);
    }

    void display() const
    {
        cout << "Bot Name: " << (name ? name : "NULL") << endl;
        cout << "Healing Capacity: " << healingCapacity << endl;
    }
};

int AnpanMedBot::totalBots = 0;

int main()
{
    int size = 0;
    do
    {
        cout << "Enter number of Medical Helper Bots: ";
        cin >> size;
        if (size <= 0)
            cout << "Number must be greater than 0. Try again." << endl;
    } while (size <= 0);

    cin.ignore();

    AnpanMedBot *bots = new AnpanMedBot[size];

    char tempName[200];
    int capacity;

    for (int i = 0; i < size; i++)
    {
        cout << "\n--- Bot " << i + 1 << " ---" << endl;

        cout << "Enter bot name: ";
        cin.getline(tempName, 200);

        cout << "Enter healing capacity (0-1000): ";
        cin >> capacity;
        cin.ignore();

        bots[i].setName(tempName)->setHealingCapacity(capacity);
    }

    cout << "\n====== All Bots ======" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\nBot " << i + 1 << ":" << endl;
        bots[i].display();
    }

    cout << "\n====== After ++bots[0] ======" << endl;
    ++bots[0];
    bots[0].display();

    if (size >= 2)
    {
        cout << "\n====== SuperBot = bots[0] + bots[1] ======" << endl;
        AnpanMedBot superBot;
        superBot = bots[0] + bots[1];
        superBot.display();
    }

    cout << "\n====== Deep Copy Demo ======" << endl;
    AnpanMedBot copiedBot(bots[0]);
    copiedBot.display();

    cout << "\n====== Move Constructor Demo ======" << endl;
    AnpanMedBot tempBot("MoveTest", 300);
    AnpanMedBot movedBot(move(tempBot));
    movedBot.display();
    cout << "Original after move: "
         << (tempBot.getName() == nullptr ? "nullptr (moved)" : tempBot.getName()) << endl;

    cout << "\n====== Cascading Setter Demo ======" << endl;
    AnpanMedBot chainBot;
    chainBot.setName("HeroBot")->setHealingCapacity(300).setHealingCapacity(600);
    chainBot.display();

    cout << "\n====== Static Function ======" << endl;
    AnpanMedBot::showTotalBots();

    delete[] bots;

    return 0;
}
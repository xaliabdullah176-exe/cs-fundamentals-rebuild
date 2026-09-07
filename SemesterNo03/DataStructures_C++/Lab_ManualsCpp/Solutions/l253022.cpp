#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
    class Compartment
    {
    public:
        int id;
        string cargo;
        Compartment *next;
        Compartment(int id, string cargo)
        {
            this->id = id;
            this->cargo = cargo;
            this->next = nullptr;
        }
    };

    Compartment *head;

public:
    Train()
    {
        head = nullptr;
    }

    // 1. Attach at start (VIP)
    void attachAtStart(int id, string cargo)
    {
        Compartment *newComp = new Compartment(id, cargo);
        newComp->next = head;
        head = newComp;
        cout << "Compartment " << id << " (" << cargo << ") attached at start." << endl;
    }

    // 2. Attach at end (Normal)
    void attachAtEnd(int id, string cargo)
    {
        Compartment *newComp = new Compartment(id, cargo);
        if (head == nullptr)
        {
            head = newComp;
            cout << "Compartment " << id << " (" << cargo << ") attached at end." << endl;
            return;
        }
        Compartment *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newComp;
        cout << "Compartment " << id << " (" << cargo << ") attached at end." << endl;
    }

    // 3. Attach after a specific compartment
    void attachAfter(int targetId, int newId, string cargo)
    {
        Compartment *temp = head;
        while (temp != nullptr && temp->id != targetId)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Target compartment " << targetId << " not found." << endl;
            return;
        }
        Compartment *newComp = new Compartment(newId, cargo);
        newComp->next = temp->next;
        temp->next = newComp;
        cout << "Compartment " << newId << " (" << cargo << ") attached after " << targetId << "." << endl;
    }

    // 4. Detach a compartment
    void detach(int id)
    {
        if (head == nullptr)
        {
            cout << "Train is empty." << endl;
            return;
        }
        if (head->id == id)
        {
            Compartment *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Compartment " << id << " detached." << endl;
            return;
        }
        Compartment *prev = head;
        Compartment *curr = head->next;
        while (curr != nullptr && curr->id != id)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Compartment " << id << " not found." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
        cout << "Compartment " << id << " detached." << endl;
    }

    // 5. Search a compartment
    void search(int id)
    {
        Compartment *temp = head;
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                cout << "Compartment " << id << " is in the train." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Compartment " << id << " is not in the train." << endl;
    }

    // 6. Display the train
    void display()
    {
        cout << "Train Composition:" << endl;
        Compartment *temp = head;
        while (temp != nullptr)
        {
            cout << temp->id << " (" << temp->cargo << ") -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 7. Count compartments
    void countCompartments()
    {
        int count = 0;
        Compartment *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        cout << "Total Compartments: " << count << endl;
    }

    // 9. Swap two compartments (swap their data, keep positions of nodes)
    void swapCompartments(int id1, int id2)
    {
        if (id1 == id2)
        {
            cout << "Cannot swap a compartment with itself." << endl;
            return;
        }
        Compartment *first = head;
        while (first != nullptr && first->id != id1)
        {
            first = first->next;
        }
        Compartment *second = head;
        while (second != nullptr && second->id != id2)
        {
            second = second->next;
        }
        if (first == nullptr || second == nullptr)
        {
            cout << "One or both compartments not found." << endl;
            return;
        }
        int tempId = first->id;
        string tempCargo = first->cargo;

        first->id = second->id;
        first->cargo = second->cargo;

        second->id = tempId;
        second->cargo = tempCargo;

        cout << "Compartments " << id1 << " and " << id2 << " swapped." << endl;
    }

    // destructor, destructs the train properly
    ~Train()
    {
        Compartment *temp = head;
        while (temp != nullptr)
        {
            Compartment *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

int main()
{
    Train train;
    int choice;

    do
    {
        cout << "\n=== Thomas & Friends: Train Compartment Manager ===" << endl;
        cout << "1. Attach Compartment at Start (VIP)" << endl;
        cout << "2. Attach Compartment at End (Normal)" << endl;
        cout << "3. Attach Compartment After a Specific Compartment" << endl;
        cout << "4. Detach Compartment" << endl;
        cout << "5. Search Compartment" << endl;
        cout << "6. Display Train" << endl;
        cout << "7. Count Compartments" << endl;
        cout << "9. Swap Two Compartments" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int id, targetId, newId, id1, id2;
        string cargo;

        switch (choice)
        {
        case 1:
            cout << "Enter Compartment ID: ";
            cin >> id;
            cout << "Enter Cargo Type (Passengers, Coal, Mail, Toys): ";
            cin >> cargo;
            train.attachAtStart(id, cargo);
            break;

        case 2:
            cout << "Enter Compartment ID: ";
            cin >> id;
            cout << "Enter Cargo Type (Passengers, Coal, Mail, Toys): ";
            cin >> cargo;
            train.attachAtEnd(id, cargo);
            break;

        case 3:
            cout << "Enter Target Compartment ID: ";
            cin >> targetId;
            cout << "Enter New Compartment ID: ";
            cin >> newId;
            cout << "Enter Cargo Type (Passengers, Coal, Mail, Toys): ";
            cin >> cargo;
            train.attachAfter(targetId, newId, cargo);
            break;

        case 4:
            cout << "Enter Compartment ID to detach: ";
            cin >> id;
            train.detach(id);
            break;

        case 5:
            cout << "Enter Compartment ID to search: ";
            cin >> id;
            train.search(id);
            break;

        case 6:
            train.display();
            break;

        case 7:
            train.countCompartments();
            break;

        case 9:
            cout << "Enter first Compartment ID: ";
            cin >> id1;
            cout << "Enter second Compartment ID: ";
            cin >> id2;
            train.swapCompartments(id1, id2);
            break;

        case 0:
            cout << "Exiting. The train comes to a stop." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}

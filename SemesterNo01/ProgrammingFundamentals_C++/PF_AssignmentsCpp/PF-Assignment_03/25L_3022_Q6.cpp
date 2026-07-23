#include <iostream>
using namespace std;

void displayState(int path[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "  " << path[i];
    }
    cout << endl;
}

int main()
{
    int path[] = {0, 0, 0, -1, 1, 1, 1};
    int length = sizeof(path) / sizeof(int);
    int turn = 1;

    cout << "Starting State:\n";
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 3 -> 4\n";
    swap(path[2], path[3]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 5 -> 3\n";
    swap(path[4], path[2]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 6 -> 5\n";
    swap(path[5], path[4]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 4 -> 6\n";
    swap(path[3], path[5]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 2 -> 4\n";
    swap(path[1], path[3]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 1 -> 2\n";
    swap(path[0], path[1]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 3 -> 1\n";
    swap(path[2], path[0]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 5 -> 3\n";
    swap(path[4], path[2]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 7 -> 5\n";
    swap(path[6], path[4]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 6 -> 7\n";
    swap(path[5], path[6]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 4 -> 6\n";
    swap(path[3], path[5]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 2 -> 4\n";
    swap(path[1], path[3]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 3 -> 2\n";
    swap(path[2], path[1]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 5 -> 3\n";
    swap(path[4], path[2]);
    displayState(path, length);
    cout << endl;

    cout << "Move " << turn++ << ": Frog on 4 -> 5\n";
    swap(path[3], path[4]);
    displayState(path, length);
    cout << endl;

    cout << "Final State:\n";
    displayState(path, length);
    cout << endl;

    system("pause");
    return 0;
}

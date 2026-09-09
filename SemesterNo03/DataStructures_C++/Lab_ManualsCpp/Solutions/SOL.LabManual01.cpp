#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;
// Task 1:

// Complexity Analysis:
// swapRows: swaps only pointers/ints (constant work) -> f(k) = c -> O(1)
// swapRowsByCopy: copies k elements one by one -> f(k) = k -> O(k)
// swapRows is independent of row length because it only reassigns
// the row pointer (an address), not the data itself.
// swapRowsByCopy does k operations, so for k = 1,000,000 it does
// roughly 1,000,000 times more work than swapRows.

template <class T>
void swapRows(T **grid, int *rowSizes, int r1, int r2)
{
    T *temp = grid[r1];
    grid[r1] = grid[r2];
    grid[r2] = temp;

    int tempSize = rowSizes[r1];
    rowSizes[r1] = rowSizes[r2];
    rowSizes[r2] = tempSize;
}

// Note: only valid/meaningful when rowSizes[r1] == rowSizes[r2].
// If lengths differ, this copies min-length safely but will not
// fully swap the longer row's extra elements.
template <class T>
void swapRowsByCopy(T **grid, int *rowSizes, int r1, int r2)
{
    int len = min(rowSizes[r1], rowSizes[r2]);
    for (int j = 0; j < len; j++)
    {
        T temp = grid[r1][j];
        grid[r1][j] = grid[r2][j];
        grid[r2][j] = temp;
    }
}

void task1Demo()
{
    int rowSizes[] = {3, 3};
    int **grid = new int *[2];
    grid[0] = new int[3]{1, 2, 3};
    grid[1] = new int[3]{4, 5, 6};

    cout << "Before swap:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < rowSizes[i]; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    swapRows(grid, rowSizes, 0, 1);

    cout << "After swapRows:" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < rowSizes[i]; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
        delete[] grid[i];
    delete[] grid;
}

// Task 2:
// (raw T** jagged array, exactly as required by the Task 2 spec)

template <class T>
class ParkingGrid
{
private:
    T **grid;
    int *slotCount;
    int levels;
    bool initialized;
    mutable long opCount;

public:
    ParkingGrid()
    {
        grid = nullptr;
        slotCount = nullptr;
        levels = 0;
        initialized = false;
        opCount = 0;
    }

    // Rule of Three (Section 2.3): a raw pointer member means the
    // compiler-generated copy would duplicate ownership and cause a
    // double free. Copying is disabled rather than implemented.
    ParkingGrid(const ParkingGrid &) = delete;
    ParkingGrid &operator=(const ParkingGrid &) = delete;

    ~ParkingGrid()
    {
        if (initialized)
        {
            for (int i = 0; i < levels; i++)
                delete[] grid[i];
            delete[] grid;
            delete[] slotCount;
            grid = nullptr;
            slotCount = nullptr;
        }
    }

    void configure()
    {
        do
        {
            cout << "Enter number of levels: ";
            cin >> levels;
            if (levels <= 0)
                cout << "Invalid! Levels must be > 0." << endl;
        } while (levels <= 0);

        slotCount = new int[levels];
        grid = new T *[levels];

        cout << "Enter number of slots for each level:" << endl;
        for (int i = 0; i < levels; i++)
        {
            int s;
            do
            {
                cout << "Level " << (i + 1) << " slots: ";
                cin >> s;
                if (s <= 0)
                    cout << "Invalid! Slots must be > 0." << endl;
            } while (s <= 0);

            slotCount[i] = s;
            grid[i] = new T[s];
            for (int j = 0; j < s; j++)
                grid[i][j] = 0;
        }
        initialized = true;
    }

    void inputOccupancy()
    {
        if (!initialized)
        {
            cout << "Configure the grid first!" << endl;
            return;
        }

        int lvl;
        do
        {
            cout << "Enter level number (1 to " << levels << "): ";
            cin >> lvl;
            if (lvl < 1 || lvl > levels)
                cout << "Invalid level!" << endl;
        } while (lvl < 1 || lvl > levels);

        int idx = lvl - 1;
        cout << "Enter occupancy hours for each slot on Level " << lvl << ":" << endl;
        for (int j = 0; j < slotCount[idx]; j++)
        {
            T hours;
            do
            {
                cout << " Slot " << (j + 1) << ": ";
                cin >> hours;
                if (hours < 0 || hours > 24)
                    cout << " Invalid! Hours must be 0-24." << endl;
            } while (hours < 0 || hours > 24);
            grid[idx][j] = hours;
        }
    }

    void display() const
    {
        cout << endl
             << "=== Parking Grid (hours occupied) ===" << endl;
        for (int i = 0; i < levels; i++)
        {
            cout << "Level " << (i + 1) << " (" << slotCount[i] << " slots): ";
            for (int j = 0; j < slotCount[i]; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }

    // f(n) = n (each of the n total slots accessed once) -> O(n)
    // opCount is reset each call so it reports f(n) for THIS call only,
    // not a running total across multiple calls in the same session.
    T totalHours() const
    {
        opCount = 0;
        T sum = 0;
        for (int i = 0; i < levels; i++)
            for (int j = 0; j < slotCount[i]; j++)
            {
                sum += grid[i][j];
                opCount++;
            }
        return sum;
    }
    /*
Complexity Verification:

Configuration          Total Slots (n)     Measured opCount
3 levels × 4 slots          12                    12
5 levels × 10 slots         50                    50
10 levels × 10 slots        100                   100

The measured operation count matches f(n) = n because
totalHours() accesses each parking slot exactly once.
Therefore, Big-O = O(n).
*/

    // f(n) = n, NOT L*maxSlots, since jagged rows sum to n overall -> O(n)
    void averagePerLevel() const
    {
        for (int i = 0; i < levels; i++)
        {
            T levelSum = 0;
            for (int j = 0; j < slotCount[i]; j++)
                levelSum += grid[i][j];
            cout << "Level " << (i + 1) << " average : "
                 << (double)levelSum / slotCount[i] << endl;
        }
    }

    // Bonus: Max/Min Occupied Slot report. f(n) = n -> O(n)
    void maxMinReport() const
    {
        if (!initialized)
        {
            cout << "Configure the grid first!" << endl;
            return;
        }

        T maxVal = grid[0][0], minVal = grid[0][0];
        int maxLvl = 1, maxSlot = 1, minLvl = 1, minSlot = 1;

        for (int i = 0; i < levels; i++)
        {
            for (int j = 0; j < slotCount[i]; j++)
            {
                if (grid[i][j] > maxVal)
                {
                    maxVal = grid[i][j];
                    maxLvl = i + 1;
                    maxSlot = j + 1;
                }
                if (grid[i][j] < minVal)
                {
                    minVal = grid[i][j];
                    minLvl = i + 1;
                    minSlot = j + 1;
                }
            }
        }

        cout << "Max occupied slot: Level " << maxLvl << ", Slot " << maxSlot
             << " (" << maxVal << " hrs)" << endl;
        cout << "Min occupied slot: Level " << minLvl << ", Slot " << minSlot
             << " (" << minVal << " hrs)" << endl;
    }

    // Bonus: Underused Levels report. f(n) = n -> O(n)
    void underusedLevels(double threshold) const
    {
        if (!initialized)
        {
            cout << "Configure the grid first!" << endl;
            return;
        }

        cout << "Levels with average below " << threshold << ":" << endl;
        bool foundAny = false;

        for (int i = 0; i < levels; i++)
        {
            T levelSum = 0;
            for (int j = 0; j < slotCount[i]; j++)
                levelSum += grid[i][j];
            double avg = (double)levelSum / slotCount[i];

            if (avg < threshold)
            {
                cout << "  Level " << (i + 1) << " average: " << avg << endl;
                foundAny = true;
            }
        }

        if (!foundAny)
            cout << "  None." << endl;
    }

    long getOpCount() const { return opCount; }
    bool isInitialized() const { return initialized; }
};

void task2Menu()
{
    ParkingGrid<int> pg;
    int choice;
    do
    {
        cout << endl
             << "=== Smart Parking Management ===" << endl;
        cout << "1. Input Slot Occupancy" << endl
             << "2. Display Parking Grid" << endl;
        cout << "3. Calculate Total Occupied Hours" << endl
             << "4. Average Occupied Hours Per Level" << endl;
        cout << "5. Show Operation Count" << endl;
        cout << "6. Max/Min Occupied Slot Report" << endl;
        cout << "7. Underused Levels Report" << endl;
        cout << "0. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!pg.isInitialized())
                pg.configure();
            pg.inputOccupancy();
            break;
        case 2:
            pg.display();
            break;
        case 3:
            cout << "Total Occupied Hours : " << pg.totalHours() << endl;
            break;
        case 4:
            pg.averagePerLevel();
            break;
        case 5:
            cout << "Operation Count: " << pg.getOpCount() << endl;
            break;
        case 6:
            pg.maxMinReport();
            break;
        case 7:
        {
            double t;
            cout << "Enter average-hours threshold: ";
            cin >> t;
            pg.underusedLevels(t);
            break;
        }
        case 0:
            cout << "Exiting Task 2..." << endl;
            break;
        default:
            cout << "Invalid choice! Enter 0-7." << endl;
        }
    } while (choice != 0);
}

// Task 3:
//  DynamicArray: a resizable array that doubles its capacity when full.

template <class T>
class DynamicArray
{
private:
    T *data;
    int count;
    int cap;
    long copyCount; // total element copies made inside grow()

    // grow(): allocate double capacity, copy old elements, delete old block.
    // f(current size k) = k copies -> O(k). Doubling means this happens
    // only O(log n) times across n pushes, so total copies stay O(n)
    // and the AMORTIZED cost per push_back is O(1).
    void grow()
    {
        int newCap = (cap == 0) ? 1 : cap * 2;
        T *newData = new T[newCap];
        for (int i = 0; i < count; i++)
        {
            newData[i] = data[i];
            copyCount++;
        }
        delete[] data;
        data = newData;
        cap = newCap;
        cout << "  [grow] capacity is now " << cap << endl;
    }

public:
    DynamicArray(int initialCap = 2)
    {
        cap = initialCap;
        count = 0;
        data = new T[cap];
        copyCount = 0;
    }

    // Rule of Three: raw pointer member -> disable default copy/assign.
    DynamicArray(const DynamicArray &) = delete;
    DynamicArray &operator=(const DynamicArray &) = delete;

    ~DynamicArray()
    {
        delete[] data;
        data = nullptr;
    }

    void push_back(const T &value)
    {
        if (count == cap)
            grow();
        data[count] = value; // single store, not counted as a "copy"
        count++;
    }

    T &at(int index)
    {
        if (index < 0 || index >= count)
        {
            cout << "Index out of range! Returning first element." << endl;
            return data[0];
        }
        return data[index];
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= count)
        {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < count - 1; i++)
            data[i] = data[i + 1];
        count--;
    }

    int size() const { return count; }
    int capacity() const { return cap; }
    long getCopyCount() const { return copyCount; }
};

// (b)/(c) Demonstration: push 1..20, print capacity changes, report copy stats.
void task3Demo()
{
    DynamicArray<int> arr(1);

    cout << "Pushing 1 to 20 into DynamicArray<int>..." << endl;
    for (int i = 1; i <= 20; i++)
    {
        arr.push_back(i);
    }

    cout << endl
         << "Final size: " << arr.size() << ", Final capacity: " << arr.capacity() << endl;
    cout << "Total element copies during grow(): " << arr.getCopyCount() << endl;
    cout << "Average copies per push_back: "
         << (double)arr.getCopyCount() / 20 << endl;

    // Explanation:
    // Capacity doubles (1,2,4,8,16,32) instead of +1 each time because doubling
    // makes grows happen only O(log n) times total, spreading the O(k) copy
    // cost thinly across many cheap pushes -> amortized O(1) per push.
    // If capacity increased by 1 each time instead, grow() would run on
    // EVERY push, copying 0+1+2+...+(n-1) = n(n-1)/2 elements total -> O(n^2)
    // for n pushes, far worse than doubling's O(n) total copies.

    cout << endl
         << "Array contents: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr.at(i) << " ";
    cout << endl;
}

// Task 3(d):
// Same parking grid concept, but each row is now a DynamicArray<T>
// instead of a fixed-size heap array, so a level can grow at run time.

template <class T>
class ParkingGridDynamic
{
private:
    DynamicArray<T> *grid; // array of dynamic arrays -- one per level
    int levels;
    bool initialized;

public:
    ParkingGridDynamic() : grid(nullptr), levels(0), initialized(false) {}

    ParkingGridDynamic(const ParkingGridDynamic &) = delete;
    ParkingGridDynamic &operator=(const ParkingGridDynamic &) = delete;

    ~ParkingGridDynamic()
    {
        delete[] grid; // each DynamicArray's own destructor frees its block
        grid = nullptr;
    }

    void configure()
    {
        do
        {
            cout << "Enter number of levels: ";
            cin >> levels;
            if (levels <= 0)
                cout << "Invalid! Levels must be > 0." << endl;
        } while (levels <= 0);

        grid = new DynamicArray<T>[levels];

        cout << "Enter number of slots for each level:" << endl;
        for (int i = 0; i < levels; i++)
        {
            int s;
            do
            {
                cout << "Level " << (i + 1) << " slots: ";
                cin >> s;
                if (s <= 0)
                    cout << "Invalid! Slots must be > 0." << endl;
            } while (s <= 0);

            for (int j = 0; j < s; j++)
                grid[i].push_back(0); // start every slot at 0 hours
        }
        initialized = true;
    }

    void inputOccupancy()
    {
        if (!initialized)
        {
            cout << "Configure the grid first!" << endl;
            return;
        }

        int lvl;
        do
        {
            cout << "Enter level number (1 to " << levels << "): ";
            cin >> lvl;
            if (lvl < 1 || lvl > levels)
                cout << "Invalid level!" << endl;
        } while (lvl < 1 || lvl > levels);

        int idx = lvl - 1;
        cout << "Enter occupancy hours for each slot on Level " << lvl << ":" << endl;
        for (int j = 0; j < grid[idx].size(); j++)
        {
            T hours;
            do
            {
                cout << " Slot " << (j + 1) << ": ";
                cin >> hours;
                if (hours < 0 || hours > 24)
                    cout << " Invalid! Hours must be 0-24." << endl;
            } while (hours < 0 || hours > 24);
            grid[idx].at(j) = hours;
        }
    }

    void display() const
    {
        cout << endl
             << "=== Parking Grid (Dynamic Rows) ===" << endl;
        for (int i = 0; i < levels; i++)
        {
            cout << "Level " << (i + 1) << " (" << grid[i].size() << " slots): ";
            for (int j = 0; j < grid[i].size(); j++)
                cout << grid[i].at(j) << " ";
            cout << endl;
        }
    }

    // Cost unchanged from Task 2: still touches each of the n slots
    // exactly once, and DynamicArray::at() is O(1), so f(n) = n -> O(n).
    // Switching to DynamicArray rows changes HOW memory grows, not the
    // cost of reading it.
    T totalHours() const
    {
        T sum = 0;
        for (int i = 0; i < levels; i++)
            for (int j = 0; j < grid[i].size(); j++)
                sum += grid[i].at(j);
        return sum;
    }

    void averagePerLevel() const
    {
        for (int i = 0; i < levels; i++)
        {
            T levelSum = 0;
            for (int j = 0; j < grid[i].size(); j++)
                levelSum += grid[i].at(j);
            cout << "Level " << (i + 1) << " average : "
                 << (double)levelSum / grid[i].size() << endl;
        }
    }

    // Task 3(d): append a new slot to an existing level at run time --
    // impossible with the fixed-size T** grid of Task 2 without a full
    // rebuild. Here it's just one push_back() (amortized O(1)).
    void addSlot()
    {
        if (!initialized)
        {
            cout << "Configure the grid first!" << endl;
            return;
        }

        int lvl;
        do
        {
            cout << "Enter level number (1 to " << levels << "): ";
            cin >> lvl;
            if (lvl < 1 || lvl > levels)
                cout << "Invalid level!" << endl;
        } while (lvl < 1 || lvl > levels);

        T hours;
        do
        {
            cout << "Enter occupancy hours for the new slot: ";
            cin >> hours;
            if (hours < 0 || hours > 24)
                cout << "Invalid! Hours must be 0-24." << endl;
        } while (hours < 0 || hours > 24);

        grid[lvl - 1].push_back(hours);
        cout << "Slot added to Level " << lvl << ". New slot count: "
             << grid[lvl - 1].size() << endl;
    }

    bool isInitialized() const { return initialized; }
};

/* Task 3(e) — Short Answer:
   The raw jagged array (Task 2) is the better fit for a facility whose
   layout is fixed once built (a level's slot count never changes),
   since it uses exactly the memory needed with no spare capacity.
   The array of DynamicArrays (Task 3) is the better fit if the
   facility repaints new slots onto existing levels over time, since
   adding a slot is a single amortized O(1) push_back() instead of a
   full manual rebuild of that row -- at the cost of some unused
   reserved capacity in each row until it fills up. */

void task3dMenu()
{
    ParkingGridDynamic<int> pg;
    int choice;
    do
    {
        cout << endl
             << "=== Dynamic Parking Grid (Task 3d) ===" << endl;
        cout << "1. Input Slot Occupancy" << endl;
        cout << "2. Display Parking Grid" << endl;
        cout << "3. Calculate Total Occupied Hours" << endl;
        cout << "4. Average Occupied Hours Per Level" << endl;
        cout << "5. Add a New Slot to a Level" << endl;
        cout << "0. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (!pg.isInitialized())
                pg.configure();
            pg.inputOccupancy();
            break;
        case 2:
            pg.display();
            break;
        case 3:
            cout << "Total Occupied Hours : " << pg.totalHours() << endl;
            break;
        case 4:
            pg.averagePerLevel();
            break;
        case 5:
            pg.addSlot();
            break;
        case 0:
            cout << "Exiting Task 3d..." << endl;
            break;
        default:
            cout << "Invalid choice! Enter 0-5." << endl;
        }
    } while (choice != 0);
}

// Main Function:

int main()
{
    int choice;
    do
    {
        cout << endl
             << "=== Data Structures Lab 01 ===" << endl;
        cout << "1. Task 1 - Row Swap Demonstration" << endl;
        cout << "2. Task 2 - Smart Parking Management" << endl;
        cout << "3. Task 3 - Dynamic Array Demonstration" << endl;
        cout << "4. Task 3(d) - Dynamic Parking Grid (Add-Slot Demo)" << endl;
        cout << "0. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            task1Demo();
        else if (choice == 2)
            task2Menu();
        else if (choice == 3)
            task3Demo();
        else if (choice == 4)
            task3dMenu();
        else if (choice != 0)
            cout << "Invalid choice!" << endl;
    } while (choice != 0);
    return 0;
}
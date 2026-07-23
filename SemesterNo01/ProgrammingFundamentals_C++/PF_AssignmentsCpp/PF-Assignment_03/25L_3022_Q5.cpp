#include <iostream>
using namespace std;

void arrangeJobs(int duration[], int n, int cust[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (duration[j] < duration[i])
            {
                int temp = duration[i];
                duration[i] = duration[j];
                duration[j] = temp;

                int tempCust = cust[i];
                cust[i] = cust[j];
                cust[j] = tempCust;
            }
        }
    }

    cout << "\nOrder of service (Customer IDs): ";
    for (int i = 0; i < n; i++)
        cout << "C" << cust[i] << " ";
    cout << endl;
}

int totalWaitTime(int duration[], int n)
{
    int total = 0, sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum += duration[i];
        total += sum;
    }
    return total;
}

int main()
{
    int n;
    int duration[100];
    int cust[100];

    do
    {
        cout << "Enter number of customers: ";
        cin >> n;

        if (n <= 0)
            cout << "Invalid input! Must be greater than 0.\n" << endl;

    } while (n <= 0);

    cout << "\nEnter job durations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Customer " << i + 1 << ": ";
        cin >> duration[i];
        cust[i] = i + 1;
    }

    arrangeJobs(duration, n, cust);

    int minWait = totalWaitTime(duration, n);
    cout << "\nMinimum Total Waiting Time: " << minWait << endl;

    cout << endl;
    system("pause");
    return 0;
}



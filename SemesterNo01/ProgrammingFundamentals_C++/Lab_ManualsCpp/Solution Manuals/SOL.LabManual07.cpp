#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int continueChoice = 0;
    int questionNumber;

    do
    {
        cout << "Please Enter QN: (1 2 3 4 5 6 7 8 9 10): ";
        cin >> questionNumber;

        switch (questionNumber)
        {
        case 1:
        {
            int monthlyIncome;
            do
            {
                cout << "Please enter your Monthly Income: ";
                cin >> monthlyIncome;
                if (monthlyIncome <= 0)
                {
                    cout << "Error: Income must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (monthlyIncome <= 0);

            cout << "\"Now enter your expenses one by one!\"" << endl;

            int rentExpense;
            cout << "Expenses on Rent: ";
            cin >> rentExpense;

            int groceryExpense;
            cout << "Expense on Groceries: ";
            cin >> groceryExpense;

            int utilityExpense;
            cout << "Expense on Utilities: ";
            cin >> utilityExpense;

            int transportExpense;
            cout << "Expense on Transport: ";
            cin >> transportExpense;

            int entertainmentExpense;
            cout << "Expense on Entertainment: ";
            cin >> entertainmentExpense;

            int miscellaneousExpense;
            cout << "Enter any other expenses: ";
            cin >> miscellaneousExpense;

            cout << endl;

            int totalMonthlyExpense = rentExpense + groceryExpense + utilityExpense + 
                                      transportExpense + entertainmentExpense + miscellaneousExpense;
            cout << "Your total Monthly expense is: " << totalMonthlyExpense << endl;

            int balanceRemaining = monthlyIncome - totalMonthlyExpense;
            cout << "Remaining balance: " << balanceRemaining << endl;

            int rentPercent = (rentExpense * 100) / monthlyIncome;
            int groceryPercent = (groceryExpense * 100) / monthlyIncome;
            int utilityPercent = (utilityExpense * 100) / monthlyIncome;
            int transportPercent = (transportExpense * 100) / monthlyIncome;
            int entertainmentPercent = (entertainmentExpense * 100) / monthlyIncome;
            int miscellaneousPercent = (miscellaneousExpense * 100) / monthlyIncome;

            cout << "\nYour expense Percentage is given below: " << endl;
            cout << "Rent: " << rentPercent << "%" << endl;
            cout << "Groceries: " << groceryPercent << "%" << endl;
            cout << "Utility: " << utilityPercent << "%" << endl;
            cout << "Transport: " << transportPercent << "%" << endl;
            cout << "Entertainment: " << entertainmentPercent << "%" << endl;
            cout << "Other expenses: " << miscellaneousPercent << "%" << endl;
            break;
        }
        case 2:
        {
            double currentSeaLevel;
            do
            {
                cout << "Please current sea level: ";
                cin >> currentSeaLevel;
                if (currentSeaLevel <= 0)
                {
                    cout << "Error: Income must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (currentSeaLevel <= 0);

            double annualRiseRate = 1.5 / 100;
            double twoYearRiseRate = 2 * annualRiseRate;
            double levelIncrease = twoYearRiseRate * currentSeaLevel;
            double projectedLevel = levelIncrease + currentSeaLevel;

            cout << "Sea level after 2 years: " << projectedLevel << endl;
            cout << "Increase in the sea level: " << levelIncrease << endl;
        }
        break;

        case 3:
        {
            float sideA, sideB, sideC;

            do
            {
                cout << "Enter side a: ";
                cin >> sideA;
                if (sideA <= 0)
                {
                    cout << "Error: Side must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (sideA <= 0);

            do
            {
                cout << "Enter side b: ";
                cin >> sideB;
                if (sideB <= 0)
                {
                    cout << "Error: Side must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (sideB <= 0);

            do
            {
                cout << "Enter side c: ";
                cin >> sideC;
                if (sideC <= 0)
                {
                    cout << "Error: Side must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (sideC <= 0);

            float numerator = (sideA * sideA) + (sideC * sideC) - (sideB * sideB);
            double cosineValue = numerator / (2 * sideA * sideC);
            double angleDegrees = acos(cosineValue) * (180 / 3.14);
            cout << fixed << setprecision(1) << endl;
            cout << "Theta is: " << angleDegrees << endl;
        }
        break;

        case 4:
        {
            int inputNumber;
            do
            {
                cout << "Enter a number: ";
                cin >> inputNumber;
                if (inputNumber <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
                else if (inputNumber < 1000 || inputNumber > 9999)
                {
                    cout << "Error: Number must be a 4-digit number!!" << endl;
                    cout << endl;
                }
            } while (inputNumber <= 0 || inputNumber < 1000 || inputNumber > 9999);

            int originalNumber = inputNumber;
            int reversedNumber = 0;
            while (inputNumber > 0)
            {
                int digit = inputNumber % 10;
                reversedNumber = reversedNumber * 10 + digit;
                inputNumber = inputNumber / 10;
            }
            if (originalNumber == reversedNumber)
            {
                cout << "Number is Palindrome" << endl;
            }
            else if (originalNumber != reversedNumber)
            {
                cout << "Number is not Palindrome" << endl;
            }
        }
        break;

        case 5:
        {
            int testNumber;
            int repeatChoice;

            do
            {
                cout << "Enter a positive number: ";
                cin >> testNumber;

                if (testNumber <= 0)
                {
                    cout << "Error: Number must be positive!" << endl;
                }
                else
                {
                    long long factorialValue = 1;
                    bool isFactorial = false;

                    for (int counter = 1; factorialValue <= testNumber; counter++)
                    {
                        if (factorialValue == testNumber)
                        {
                            cout << testNumber << " is the factorial of " << (counter - 1) << endl;
                            isFactorial = true;
                            break;
                        }
                        factorialValue *= counter;
                    }

                    if (!isFactorial)
                    {
                        cout << testNumber << " is NOT a factorial of any number." << endl;
                    }
                }

                cout << "\nDo you want to check another number? (1 = Yes, 0 = No): ";
                cin >> repeatChoice;
                cout << endl;
            } while (repeatChoice == 1);

            cout << "Program terminated." << endl;
        }
        break;

        case 6:
        {
            int limit;

            do
            {
                cout << "Enter a number: ";
                cin >> limit;
                if (limit <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (limit <= 0);

            cout << "Prime Numbers till " << limit << " are: " << endl;
            int current = 2;
            while (current <= limit)
            {
                int isPrime = 1;
                for (int divisor = 2; divisor <= current - 1; divisor++)
                {
                    if (current % divisor == 0)
                    {
                        isPrime = 0;
                    }
                }
                if (isPrime == 1)
                {
                    cout << current << " ";
                }
                current++;
            }
        }
        break;

        case 7:
        {
            int terms;

            do
            {
                cout << "Enter a number: ";
                cin >> terms;
                if (terms <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (terms <= 0);

            double harmonicSum = 0.0;
            for (int index = 1; index <= terms; index++)
            {
                harmonicSum += 1.0 / index;
            }
            cout << fixed << setprecision(4) << "Harnonic Sum: " << harmonicSum << endl;
        }
        break;

        case 8:
        {
            int targetNumber;

            do
            {
                cout << "Enter a number: ";
                cin >> targetNumber;
                if (targetNumber <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (targetNumber <= 0);

            int previous = 0;
            int current = 1;
            int nextFib = 0;
            nextFib = previous + current;

            if (targetNumber == 0 || targetNumber == 1)
            {
                cout << "Found" << endl;
            }
            for (int iteration = 1; iteration <= targetNumber * targetNumber; iteration++)
            {
                previous = current;
                current = nextFib;
                nextFib = previous + current;
                if (nextFib == targetNumber)
                {
                    cout << "Found" << endl;
                }
                else if (nextFib != targetNumber)
                {
                    cout << "Not Found" << endl;
                }
            }
        }
        break;

        case 9:
        {
            int size;

            do
            {
                cout << "Enter a number: ";
                cin >> size;
                if (size <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (size <= 0);

            for (int row = 1; row <= size; row++)
            {
                for (int col = 1; col <= size; col++)
                {
                    if (row == 1 || col == 1 || row == size || col == size)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        break;

        case 10:
        {
            int patternSize;
            do
            {
                cout << "Enter a number: ";
                cin >> patternSize;
                if (patternSize <= 0)
                {
                    cout << "Error: Number must be greater than 0!!" << endl;
                    cout << endl;
                }
            } while (patternSize <= 0);

            for (int row = 1; row <= patternSize; row++)
            {
                for (int spc = 1; spc <= patternSize - row; spc++)
                {
                    cout << "  ";
                }
                for (int ascending = 1; ascending <= row; ascending++)
                {
                    cout << ascending << " ";
                }
                for (int descending = row - 1; descending >= 1; descending--)
                {
                    cout << descending << " ";
                }
                cout << endl;
            }
            for (int row = patternSize - 1; row >= 1; row--)
            {
                for (int spc = 1; spc <= patternSize - row; spc++)
                {
                    cout << "  ";
                }
                for (int ascending = 1; ascending <= row; ascending++)
                {
                    cout << ascending << " ";
                }
                for (int descending = row - 1; descending >= 1; descending--)
                {
                    cout << descending << " ";
                }
                cout << endl;
            }
        }
        break;

        default:
            cout << "Wrong Input \n";
        }

        cout << "\nPress 1 if you want to run another question\n Press any other key to exit: ";
        cin >> continueChoice;

    } while (continueChoice == 1);

    system("pause");
    return 0;
}
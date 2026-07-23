#include <iostream>
using namespace std;

int main()
{
    float marks;
    // User will enter his marks obtained
    cout << "Enter your obtained marks percentage : ";
    cin >> marks;
    // Condition to check the grade
    float gpa;
    string grade;

    // Logic Of Program
    {
        if (marks >= 90)
        {
            gpa = 4.00;
            grade = "A+";
        }
        else if (marks >= 86 && marks < 90)
        {
            gpa = 4.00;
            grade = "A";
        }
        else if (marks >= 82 && marks < 86)
        {
            gpa = 3.67;
            grade = "A-";
        }
        else if (marks >= 78 && marks < 82)
        {
            gpa = 3.33;
            grade = "B+";
        }
        else if (marks >= 74 && marks < 78)
        {
            gpa = 3.00;
            grade = "B";
        }
        else if (marks >= 70 && marks < 74)
        {
            gpa = 2.67;
            grade = "B-";
        }
        else if (marks >= 66 && marks < 70)
        {
            gpa = 2.33;
            grade = "C+";
        }
        else if (marks >= 62 && marks < 66)
        {
            gpa = 2.00;
            grade = "C";
        }
        else if (marks >= 58 && marks < 62)
        {
            gpa = 1.67;
            grade = "C-";
        }
        else if (marks >= 54 && marks < 58)
        {
            gpa = 1.33;
            grade = "D+";
        }
        else if (marks >= 50 && marks < 54)
        {
            gpa = 1.00;
            grade = "D";
        }
        else if (marks < 50)
        {
            gpa = 0.00;
            grade = "F";
        }
        else
        {
            cout << "Error! Please Enter a Valid Marks Percentage and Run the Program Again." << endl;
        }
    }
    // The Output of Program (Student Grade And Gpa).

    cout << "Your Grade is : " << grade << endl;
    cout << "Your GPA is : " << gpa << endl;
    return 0;
}

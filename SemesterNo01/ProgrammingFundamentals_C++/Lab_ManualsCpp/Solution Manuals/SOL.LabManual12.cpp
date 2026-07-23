// //// Question no 01
// //
// #include <iostream>
// #include <fstream>  
// #include <string>
// using namespace std;


// void writeEmployee(string filename) 
// {
//    ofstream outFile;  
//    outFile.open(filename); 

//    if (!outFile.is_open()) 
//    {  
//        cout << "Error: Could not open file!" << endl;
//        return;
//    }

//    outFile << "ID Name Department Salary" << endl;

//    int id, salary;
//    string name, dept;

//    cout << "Enter Employee ID: ";
//    cin >> id;
//    cout << "Enter Employee Name: ";
//    cin >> name;
//    cout << "Enter Department: ";
//    cin >> dept;
//    cout << "Enter Monthly Salary: ";
//    cin >> salary;

//    outFile << id << " " << name << " " << dept << " " << salary << endl;

//    outFile.close();  
//    cout << "Employee added successfully!" << endl;
// }

// void displayEmployees(string filename) {
//    ifstream inFile; 
//    inFile.open(filename);

//    if (!inFile.is_open()) {
//        cout << "Error: File not found!" << endl;
//        return;
//    }

//    string line;
//    cout << "\nEmployee Records:" << endl;

   
//    getline(inFile, line);  
   
//    while (!inFile.eof()) { 
//        int id, salary;
//        string name, dept;

//        inFile >> id >> name >> dept >> salary;

//        if (!inFile.eof()) 
//        {  
//            cout << id << ", " << name << ", " << dept << ", " << salary << endl;
//        }
//    }

//    inFile.close();
// }

// void appendEmployee(string filename) {
//    ofstream outFile;
  
//    outFile.open(filename, ios::app);

//    if (!outFile.is_open()) {
//        cout << "Error: Could not open file!" << endl;
//        return;
//    }

//    int id, salary;
//    string name, dept;

//    cout << "\nEnter Employee ID: ";
//    cin >> id;
//    cout << "Enter Employee Name: ";
//    cin >> name;
//    cout << "Enter Department: ";
//    cin >> dept;
//    cout << "Enter Monthly Salary: ";
//    cin >> salary;

   
//    outFile << id << " " << name << " " << dept << " " << salary << endl;

//    outFile.close();
//    cout << "Employee appended successfully!" << endl;
// }


// void calculateAnnualPayroll(string filename) {
//    ifstream inFile;
//    inFile.open(filename);

//    if (!inFile.is_open()) {
//        cout << "Error: File not found!" << endl;
//        return;
//    }

//    string line;
//    getline(inFile, line);  

//    int totalAnnual = 0;

//    while (!inFile.eof()) {
//        int id, salary;
//        string name, dept;

//        inFile >> id >> name >> dept >> salary;

//        if (!inFile.eof()) {
//            totalAnnual += salary * 12; 
//        }
//    }

//    inFile.close();
//    cout << "\nTotal Annual Payroll: " << totalAnnual << endl;
// }

// int main() {
//    string filename = "employees.txt";
//    int choice;

//    while (true) {
//        cout << "\n=== Employee Payroll System ===" << endl;
//        cout << "1. Write new employee file" << endl;
//        cout << "2. Display all employees" << endl;
//        cout << "3. Append new employee" << endl;
//        cout << "4. Calculate annual payroll" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;

//        if (choice == 1) {
//            writeEmployee(filename);
//        }
//        else if (choice == 2) {
//            displayEmployees(filename);
//        }
//        else if (choice == 3) {
//            appendEmployee(filename);
//        }
//        else if (choice == 4) {
//            calculateAnnualPayroll(filename);
//        }
//        else if (choice == 5) {
//            cout << "Goodbye!" << endl;
//            break;
//        }
//        else {
//            cout << "Invalid choice!" << endl;
//        }
//    }

//    return 0;
// }



//Question  no 02

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// //Function 1: WRITE student records to file
// void writeStudent(string filename) {
//    ofstream outFile;
//    outFile.open(filename);

//    if (!outFile.is_open()) {
//        cout << "Error: Could not open file!" << endl;
//        return;
//    }

//    // Writing header
//    outFile << "RollNo Name Subject Marks" << endl;

//    int rollNo, marks;
//    string name, subject;

//    cout << "Enter Roll Number: ";
//    cin >> rollNo;
//    cout << "Enter Student Name: ";
//    cin >> name;
//    cout << "Enter Subject: ";
//    cin >> subject;
//    cout << "Enter Marks: ";
//    cin >> marks;

//   //  Writing student data to file
//    outFile << rollNo << " " << name << " " << subject << " " << marks << endl;

//    outFile.close();
//    cout << "Student record added successfully!" << endl;
// }

// //Function 2: READ and DISPLAY all student records so we can see them
// void displayStudents(string filename) {
//    ifstream inFile;
//    inFile.open(filename);

//    if (!inFile.is_open()) {
//        cout << "Error: File not found!" << endl;
//        return;
//    }

//    string line;
//    cout << "\nStudent Records:" << endl;

//   //  Skipping the header line
//    getline(inFile, line);

//   //  Reading all student records
//    while (!inFile.eof()) {
//        int rollNo, marks;
//        string name, subject;

//        inFile >> rollNo >> name >> subject >> marks;

//        if (!inFile.eof()) {
//            cout << rollNo << ", " << name << ", " << subject << ", " << marks << endl;
//        }
//    }

//    inFile.close();
// }

// //Function 3: APPENDDING new student record (add without deleting old data)
// void appendStudent(string filename) {
//    ofstream outFile;
//    outFile.open(filename, ios::app);  // APPEND mode!

//    if (!outFile.is_open()) {
//        cout << "Error: Could not open file!" << endl;
//        return;
//    }

//    int rollNo, marks;
//    string name, subject;

//    cout << "\nEnter Roll Number: ";
//    cin >> rollNo;
//    cout << "Enter Student Name: ";
//    cin >> name;
//    cout << "Enter Subject: ";
//    cin >> subject;
//    cout << "Enter Marks: ";
//    cin >> marks;

//   //  Appending to file
//    outFile << rollNo << " " << name << " " << subject << " " << marks << endl;

//    outFile.close();
//    cout << "Student record appended successfully!" << endl;
// }

// void calculateAverageMarks(string filename) {
//    ifstream inFile;
//    inFile.open(filename);

//    if (!inFile.is_open()) {
//        cout << "Error: File not found!" << endl;
//        return;
//    }

//    string searchSubject;
//    cout << "\nEnter subject name to calculate average: ";
//    cin >> searchSubject;

//    string line;
//    getline(inFile, line);  // Skipping header

//    int totalMarks = 0;   // Summation of all marks in this subject
//    int count = 0;        

//    // Reading each student record
//    while (!inFile.eof()) {
//        int rollNo, marks;
//        string name, subject;

//        inFile >> rollNo >> name >> subject >> marks;

//        if (!inFile.eof()) {
//         //    CHECK: Does this student's subject match what we're looking for?
//            if (subject == searchSubject) 
//            {
//                totalMarks += marks;  
//            }
//        }
//    }

//    inFile.close();

//     //Calculating and display average
//    if (count == 0) {
//        cout << "No students found in " << searchSubject << endl;
//    }
//    else {
//        double average = (double)totalMarks / count;  
//        cout << "Average Marks in " << searchSubject << ": " << average << endl;
//    }
// }

// int main() {
//    string filename = "students.txt";
//    int choice;

//    while (true) {
//        cout << "\n=== Student Academic Records System ===" << endl;
//        cout << "1. Write new student file" << endl;
//        cout << "2. Display all students" << endl;
//        cout << "3. Append new student" << endl;
//        cout << "4. Calculate average marks for a subject" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;

//        if (choice == 1) {
//            writeStudent(filename);
//        }
//        else if (choice == 2) {
//            displayStudents(filename);
//        }
//        else if (choice == 3) {
//            appendStudent(filename);
//        }
//        else if (choice == 4) {
//            calculateAverageMarks(filename);  // NEW FUNCTION!
//        }
//        else if (choice == 5) {
//            cout << "Goodbye!" << endl;
//            break;
//        }
//        else {
//            cout << "Invalid choice!" << endl;
//        }
//    }

//    return 0;
// }


// ////Question 03 :

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream testFile("input.txt");
    if (testFile.is_open()) {
        testFile << "3 Ali Ahmad Khan 3 2.4 3.3 7.1 L12-2000 Kiran Ali Panday 2 7.0 6 L12-3000 Imran Javed Khan 1 2.2 L12-3001";
        testFile.close();
        cout << "input.txt created successfully!" << endl;
    }

    ifstream inFile;
    inFile.open("input.txt");

    if (!inFile.is_open()) {
        cout << "Error: Could not open input.txt" << endl;
        cout << "Please ensure input.txt is in the same folder as your program." << endl;
        return 1;
    }

    int numStudents;
    inFile >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        string firstName, middleName, lastName;
        inFile >> firstName >> middleName >> lastName;

        int numAssignments;
        inFile >> numAssignments;

        double totalMarks = 0.0;
        for (int j = 0; j < numAssignments; j++) {
            double mark;
            inFile >> mark;
            totalMarks += mark;
        }

        string rollNumber;
        inFile >> rollNumber;

        cout << rollNumber << " " << lastName << " " << totalMarks << endl;
    }

    inFile.close();

    return 0;
}
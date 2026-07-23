// Name: Ali Abdullah                  Section: BS-SE 2B
// Roll No: 25L-3022                   Date: 03/04/2026

#include <iostream>
using namespace std;

class Address
{
private:
    char *street;
    char *city;
    char *country;

public:
    Address(const char *street, const char *city, const char *country)
    {
        // Address for the (Street Part)->>>
        int len = 0;
        while (*(street + len) != '\0')
        {
            len++;
        }
        this->street = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->street + i) = *(street + i);
        }
        *(this->street + len) = '\0';

        // Address for the (city Part)->>>
        int len2 = 0;
        while (*(city + len2) != '\0')

        {
            len2++;
        }
        this->city = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->city + j) = *(city + j);
        }
        *(this->city + len2) = '\0';

        // Address for the (country part)->>>

        int len3 = 0;
        while (*(country + len3) != '\0')
        {
            len3++;
        }
        this->country = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
        {
            *(this->country + k) = *(country + k);
        }
        *(this->country + len3) = '\0';
    }
    Address(const Address &other)
    {
        // Copying the Address of (Street)

        int len = 0;
        while (*(other.street + len) != '\0')
        {
            len++;
        }
        this->street = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->street + i) = *(other.street + i);
        }
        *(this->street + len) = '\0';

        // Copying the Address of (City)

        int len2 = 0;
        while (*(other.city + len2) != '\0')
        {
            len2++;
        }
        this->city = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->city + j) = *(other.city + j);
        }
        *(this->city + len2) = '\0';

        // Copying the Address of (Country)

        int len3 = 0;
        while (*(other.country + len3) != '\0')
        {
            len3++;
        }
        this->country = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
        {
            *(this->country + k) = *(other.country + k);
        }
        *(this->country + len3) = '\0';
    }
    Address &operator=(const Address &other)
    {
        if (this == &other)
            return *this;
        delete[] this->street;
        delete[] this->city;
        delete[] this->country;

        // Address of Street (Operators)

        int len = 0;
        while (*(other.street + len) != '\0')
            len++;
        this->street = new char[len + 1];
        for (int i = 0; i < len; i++)
            *(this->street + i) = *(other.street + i);
        *(this->street + len) = '\0';

        // Address of City (Operators)

        int len2 = 0;
        while (*(other.city + len2) != '\0')
            len2++;
        this->city = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
            *(this->city + j) = *(other.city + j);
        *(this->city + len2) = '\0';

        // Address of Country (Operators)

        int len3 = 0;
        while (*(other.country + len3) != '\0')
            len3++;
        this->country = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
            *(this->country + k) = *(other.country + k);
        *(this->country + len3) = '\0';

        return *this;
    }
    ~Address()
    {
        delete[] this->street;
        delete[] this->city;
        delete[] this->country;
    }
    void display() const
    {
        cout << "Address: " << this->street << ", " << this->city << ", " << this->country << endl;
    }
};

// This is (Class 2) for the courses:

class Course
{
private:
    char *courseCode; // Dynamically Allocated
    char *courseName;
    int creditHours;

public:
    Course(const char *courseCode, const char *courseName, int creditHours)
    {
        // Len Extraction + Deep Copy for the courseCode
        int len = 0;
        while (*(courseCode + len) != '\0')
        {
            len++;
        }
        this->courseCode = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->courseCode + i) = *(courseCode + i);
        }
        *(this->courseCode + len) = '\0';
        // Len Extraction + Deep Copy for the courseName

        int len2 = 0;
        while (*(courseName + len2) != '\0')
        {
            len2++;
        }
        this->courseName = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->courseName + j) = *(courseName + j);
        }
        *(this->courseName + len2) = '\0';

        // Direct Initialization for the creditHours
        this->creditHours = creditHours;
    }
    Course(const Course &other)
    {
        // Len Extraction + Deep Copy for the courseCode
        int len = 0;
        while (*(other.courseCode + len) != '\0')
        {
            len++;
        }
        this->courseCode = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->courseCode + i) = *(other.courseCode + i);
        }
        *(this->courseCode + len) = '\0';
        // Len Extraction + Deep Copy for the courseName

        int len2 = 0;
        while (*(other.courseName + len2) != '\0')
        {
            len2++;
        }
        this->courseName = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->courseName + j) = *(other.courseName + j);
        }
        *(this->courseName + len2) = '\0';

        // Direct Initialization for the creditHours
        this->creditHours = other.creditHours;
    }
    Course &operator=(const Course &other)
    {
        if (this == &other)
            return *this;

        delete[] courseCode;
        delete[] courseName;

        // Len Extraction + Deep Copy for the courseCode
        int len = 0;
        while (*(other.courseCode + len) != '\0')
        {
            len++;
        }
        this->courseCode = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->courseCode + i) = *(other.courseCode + i);
        }
        *(this->courseCode + len) = '\0';
        // Len Extraction + Deep Copy for the courseName

        int len2 = 0;
        while (*(other.courseName + len2) != '\0')
        {
            len2++;
        }
        this->courseName = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->courseName + j) = *(other.courseName + j);
        }
        *(this->courseName + len2) = '\0';

        // Direct Initialization for the creditHours
        this->creditHours = other.creditHours;

        return *this;
    }
    ~Course()
    {
        delete[] courseCode;
        delete[] courseName;
    }
    const char *getCode() const
    {
        return courseCode;
    }
    void display() const
    {
        cout << "[Course] " << courseCode << " - " << courseName << " (" << creditHours << " Credit Hours)" << endl;
    }
};

// PROFESSOR CLASS (CLASS 3)>>

class Professor
{
private:
    char *name;
    char *employeeId;
    char *specialization;
    Address address;

public:
    Professor(const char *name, const char *employeeId, const char *specialization, const Address &Addr) : address(Addr)
    {
        // Len Extraction + Deep Copy for the courseCode
        int len = 0;
        while (*(name + len) != '\0')
        {
            len++;
        }
        this->name = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->name + i) = *(name + i);
        }
        *(this->name + len) = '\0';
        // Len Extraction + Deep Copy for the courseName

        int len2 = 0;
        while (*(employeeId + len2) != '\0')
        {
            len2++;
        }
        this->employeeId = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->employeeId + j) = *(employeeId + j);
        }
        *(this->employeeId + len2) = '\0';

        // Len Extraction + Deep Copy For Specialization

        int len3 = 0;
        while (*(specialization + len3) != '\0')
        {
            len3++;
        }
        this->specialization = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
        {
            *(this->specialization + k) = *(specialization + k);
        }
        *(this->specialization + len3) = '\0';
    }
    Professor(const Professor &other) : address(other.address)
    {
        // Len Extraction + Deep Copy for the courseCode   (Copy Constructor Part)
        int len = 0;
        while (*(other.name + len) != '\0')
        {
            len++;
        }
        this->name = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->name + i) = *(other.name + i);
        }
        *(this->name + len) = '\0';
        // Len Extraction + Deep Copy for the courseName  (Copy Constructor Part)

        int len2 = 0;
        while (*(other.employeeId + len2) != '\0')
        {
            len2++;
        }
        this->employeeId = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->employeeId + j) = *(other.employeeId + j);
        }
        *(this->employeeId + len2) = '\0';

        // Len Extraction + Deep Copy For Specialization (Copy Consteructor Part)

        int len3 = 0;
        while (*(other.specialization + len3) != '\0')
        {
            len3++;
        }
        this->specialization = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
        {
            *(this->specialization + k) = *(other.specialization + k);
        }
        *(this->specialization + len3) = '\0';
    }
    Professor &operator=(const Professor &other)
    {
        if (this == &other)
            return *this;

        delete[] name;
        delete[] employeeId;
        delete[] specialization;

        address = other.address;

        // Len Extraction + Deep Copy for the courseCode   (Copy Constructor Part)
        int len = 0;
        while (*(other.name + len) != '\0')
        {
            len++;
        }
        this->name = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            *(this->name + i) = *(other.name + i);
        }
        *(this->name + len) = '\0';
        // Len Extraction + Deep Copy for the courseName  (Copy Constructor Part)

        int len2 = 0;
        while (*(other.employeeId + len2) != '\0')
        {
            len2++;
        }
        this->employeeId = new char[len2 + 1];
        for (int j = 0; j < len2; j++)
        {
            *(this->employeeId + j) = *(other.employeeId + j);
        }
        *(this->employeeId + len2) = '\0';

        // Len Extraction + Deep Copy For Specialization (Copy Consteructor Part)

        int len3 = 0;
        while (*(other.specialization + len3) != '\0')
        {
            len3++;
        }
        this->specialization = new char[len3 + 1];
        for (int k = 0; k < len3; k++)
        {
            *(this->specialization + k) = *(other.specialization + k);
        }
        *(this->specialization + len3) = '\0';

        return *this;
    }
    ~Professor()
    {
        delete[] name;
        delete[] employeeId;
        delete[] specialization;
    }

    const char *getId() const
    {
        return employeeId;
    }

    void display() const
    {
        cout << "========================================" << endl;
        cout << "Professor: " << name << " [ID: " << employeeId << "]" << endl;
        cout << "Specialization: " << specialization << endl;
        address.display();
        cout << "========================================" << endl;
    }
};

class Student
{
private:
    char *name;
    char *rollNumber;
    int semester;
    Address address;          // COMPOSITION
    Course **enrolledCourses; // AGGREGATION
    int courseCount;

public:
    Student(const char *name, const char *roll,
            int semester, const Address &addr) : address(addr)
    {

        int len = 0;
        while (*(name + len) != '\0')
            len++;
        this->name = new char[len + 1];
        for (int i = 0; i < len; i++)
            *(this->name + i) = *(name + i);
        *(this->name + len) = '\0';

        int len2 = 0;
        while (*(roll + len2) != '\0')
            len2++;
        this->rollNumber = new char[len2 + 1];
        for (int i = 0; i < len2; i++)
            *(this->rollNumber + i) = *(roll + i);
        *(this->rollNumber + len2) = '\0';

        this->semester = semester;
        this->enrolledCourses = nullptr;
        this->courseCount = 0;
    }

    ~Student()
    {
        delete[] name;
        delete[] rollNumber;
        delete[] enrolledCourses; // sirf array delete — courses nahi!
    }

    const char *getRoll() const { return rollNumber; }

    void display() const
    {
        cout << "========================================" << endl;
        cout << "Student: " << name << " [Roll: " << rollNumber << "]" << endl;
        cout << "Semester: " << semester << endl;
        address.display();
        cout << "Enrolled Courses:" << endl;
        if (courseCount == 0)
            cout << "No courses enrolled" << endl;
        else
            for (int i = 0; i < courseCount; i++)
            {
                cout << "[" << i + 1 << "] ";
                (*(enrolledCourses + i))->display();
            }
        cout << "========================================" << endl;
    }

    void enrollCourse(Course* course)
    {
     for(int i = 0; i < courseCount; i++ )
     {
        if(*(enrolledCourses + i) == course)
        {
            cout<<"Error!! Already Enrolled in the Course "<<course->getCode()<<endl;
            return;
        }
     }
     Course** newArr = new Course* [courseCount + 1];
     //  old copy copy 
    for(int i = 0; i < courseCount; i++)
        *(newArr + i) = *(enrolledCourses + i);
    
    //  New course addition 
    *(newArr + courseCount) = course;
    
    // deleting old
    delete[] enrolledCourses;
    
    // Updating
    enrolledCourses = newArr;
    courseCount++;
    cout << "> Enrolled in " << course->getCode() << endl;
}
    };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

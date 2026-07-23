#include<iostream>
using namespace std;

int main()
{
    // Displaying the title of the program
    cout<<"================================="<<endl;
    cout<<"|This is a simple Sgpa Calculator|"<<endl;
    cout<<"================================="<<endl;
    cout<<"\nDeveloped by: Ali Abdullah 25L-3022"<<endl;
    cout<<"================================="<<endl;
    cout<<"\n This Program Uses the Following Formula for the sgpa calculation"<<endl;
    cout<<"|-----------------------------------------------------------------------|"<<endl; 
    cout<<" SGPA = Sum(gradePoint x creditHours) / Sum(Total number of Credit Hours)"<<endl; 
    cout<<"|-----------------------------------------------------------------------|"<<endl; 
    
    // Grades Table For reference
    cout<<"\nGrades Table For Reference:"<<endl;
    cout<<"|--------------------------------|"<<endl;
    cout<<"| Letter Grade | Grade Points    |"<<endl;
    cout<<"|--------------|-----------------|"<<endl;
    cout<<"|      A+      |      4.00       |"<<endl;
    cout<<"|      A       |      4.00       |"<<endl;
    cout<<"|      A-      |      3.67       |"<<endl;
    cout<<"|      B+      |      3.33       |"<<endl;
    cout<<"|      B       |      3.00       |"<<endl;
    cout<<"|      B-      |      2.67       |"<<endl;
    cout<<"|      C+      |      2.33       |"<<endl;
    cout<<"|      C       |      2.00       |"<<endl;
    cout<<"|      C-      |      1.67       |"<<endl;
    cout<<"|      D+      |      1.33       |"<<endl;
    cout<<"|      D       |      1.00       |"<<endl;
    cout<<"|      D-      |      0.67       |"<<endl;
    cout<<"|      F       |      0.00       |"<<endl;
    cout<<"|--------------------------------|"<<endl;
    
    // Asking the user for how many courses
    int numCourses;
    cout<<"\nHow many courses are you taking this semester? ";
    cin>>numCourses;
    
    // Validating input
    if(numCourses <= 0)
    {
        cout<<"Invalid number of courses!"<<endl;
        return 0;
    }
    
    // Variables declaration
    float gradePoint, creditHour, totalGradePoints = 0, totalCreditHours = 0, sgpa;
    
    cout<<"\nEnter the Grade Points and Credit Hours for "<<numCourses<<" Courses:"<<endl;
    cout<<"|--------------------------------------------------------------|"<<endl;
    
    // Looping to input data for each course 
    for(int i = 1; i <= numCourses; i++)
    {
        cout<<"\nCourse "<<i<<" - Grade Points (e.g., A+ = 4.00, B+ = 3.33): ";
        cin>>gradePoint;
        
        cout<<"Course "<<i<<" - Credit Hours (e.g., 1, 2, 3): ";
        cin>>creditHour;
        
        // Add to totals
        totalGradePoints += (gradePoint * creditHour);
        totalCreditHours += creditHour;
    }
    
    // Calculate SGPA
    sgpa = totalGradePoints / totalCreditHours;
    
    // Display Results
    cout<<"\n|--------------------------|"<<endl;
    cout<<"Your Results are as follows"<<endl;
    cout<<"|--------------------------|"<<endl;
    
    cout<<"\nTotal Grade Points = "<<totalGradePoints<<endl;
    cout<<"Total Credit Hours = "<<totalCreditHours<<endl;
    cout<<"|----------------------------------|"<<endl;
    
    cout<<"\nYour SGPA is = "<<sgpa<<endl;
    cout<<"|----------------------------------|"<<endl;
    
    cout<<"\nThank You for using this Program!"<<endl;
    
    return 0;
}
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
    cout<<"\nInstructions: "<<endl;
    // Variable Declaration for 9 courses.
       
       float gradePoint1, creditHour1, totalGradePoints = 0, totalCreditHours = 0, sgpa;
     
       float gradePoint2, creditHour2;
       
       float gradePoint3, creditHour3;
       
       float gradePoint4, creditHour4;
     
       float gradePoint5, creditHour5;
       
       float gradePoint6, creditHour6;
    
       float gradePoint7, creditHour7;
                
       float gradePoint8, creditHour8;
       
       float gradePoint9, creditHour9;

        // Grades Table For reference;
        cout<<"|--------------------------------|"<<endl;
        cout<<"Please enter your grade points and credit hours for each course correctly."<<endl;
        cout<<"\nGrades Table For Reference:"<<endl;
        cout<<"|--------------------------------|"<<endl;
        cout<<"| Letter Grade | Grade Points    |"<<endl;\
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

        // User Inputs for 9 courses
        
    cout<<"\nEnter the Grade Points and Credit Hours for 9 Courses:"<<endl;
    // Course 1
        cout<<"Course 1 (Applied Physics) - Grade Points:(eg A+ 4.00,B+ 3.33 etc) ";
        cin>>gradePoint1;
        cout<<"Course 1 - Credit Hours: (eg 1,2,3 etc) ";
        cin>>creditHour1;
    // Course 2
        cout<<"Course 2 (Calculus and Analytic Geometry) - Grade Points: ";
        cin>>gradePoint2;
        cout<<"Course 2  - Credit Hours: ";
        cin>>creditHour2; 
    // Course 3 
        cout<<"Course 3 (Programming Fundamentals-Lab) - Grade Points: ";
        cin>>gradePoint3;
        cout<<"Course 3 - Credit Hours: ";
        cin>>creditHour3;
    // Course 4
        cout<<"Course 4 (Programming Fundamentals) - Grade Points: ";
        cin>>gradePoint4;
        cout<<"Course 4 - Credit Hours: ";
        cin>>creditHour4;
    // Course 5
        cout<<"Course 5 (Pakistan Studies) - Grade Points: ";
        cin>>gradePoint5;
        cout<<"Course 5 - Credit Hours: ";
        cin>>creditHour5;   
    // Course 6
        cout<<"Course 6 (Functional English) - Grade Points: ";
        cin>>gradePoint6;
        cout<<"Course 6 - Credit Hours: ";
        cin>>creditHour6;
    // Course 7
        cout<<"Course 7 (Function English-Lab) - Grade Points: ";
        cin>>gradePoint7;
        cout<<"Course 7 - Credit Hours: ";
        cin>>creditHour7;
    // Course 8
        cout<<"Course 8 (Introduction to ICT) - Grade Points: ";
        cin>>gradePoint8;
        cout<<"Course 8 - Credit Hours: ";
        cin>>creditHour8;
    // Course 9
        cout<<"Course 9 (Ideology and Constitution of Pakistan) - Grade Points: ";
        cin>>gradePoint9;
        cout<<"Course 9 - Credit Hours: ";
        cin>>creditHour9;

        // Calculating Total Grade Points and Total Credit Hours
        totalGradePoints = (gradePoint1 * creditHour1) +
                           (gradePoint2 * creditHour2) + 
                           (gradePoint3 * creditHour3) + 
                           (gradePoint4 * creditHour4) + 
                           (gradePoint5 * creditHour5) + 
                           (gradePoint6 * creditHour6) + 
                           (gradePoint7 * creditHour7) + 
                           (gradePoint8 * creditHour8) + 
                           (gradePoint9 * creditHour9);
        
        //Calculating Total Credit Hours
        totalCreditHours = creditHour1 + 
                           creditHour2 + 
                           creditHour3 +
                           creditHour4 +
                           creditHour5 +
                           creditHour6 + 
                           creditHour7 + 
                           creditHour8 +
                           creditHour9 ;

        //Calculation of the Sgpa
        sgpa = totalGradePoints / totalCreditHours;
        
        //Displaying the all the Results
        cout<<"|--------------------------|"<<endl;
        cout<<"Your Results are as follows"<<endl;
        cout<<"|--------------------------|"<<endl;
        
        cout<<"\n|--------------------------------|"<<endl;
        cout<<"for course 1 : "<<gradePoint1<<" x "<<creditHour1<<" = "<<(gradePoint1 * creditHour1)<<endl;
        cout<<"for course 2 : "<<gradePoint2<<" x "<<creditHour2<<" = "<<(gradePoint2 * creditHour2)<<endl;
        cout<<"for course 3 : "<<gradePoint3<<" x "<<creditHour3<<" = "<<(gradePoint3 * creditHour3)<<endl;
        cout<<"for course 4 : "<<gradePoint4<<" x "<<creditHour4<<" = "<<(gradePoint4 * creditHour4)<<endl;
        cout<<"for course 5 : "<<gradePoint5<<" x "<<creditHour5<<" = "<<(gradePoint5 * creditHour5)<<endl;
        cout<<"for course 6 : "<<gradePoint6<<" x "<<creditHour6<<" = "<<(gradePoint6 * creditHour6)<<endl;
        cout<<"for course 7 : "<<gradePoint7<<" x "<<creditHour7<<" = "<<(gradePoint7 * creditHour7)<<endl;
        cout<<"for course 8 : "<<gradePoint8<<" x "<<creditHour8<<" = "<<(gradePoint8 * creditHour8)<<endl;
        cout<<"for course 9 : "<<gradePoint9<<" x "<<creditHour9<<" = "<<(gradePoint9 * creditHour9)<<endl;
        cout<<"|----------------------------------|"<<endl;

        //Displaying the Total Grade Points and Total Credit Hours 
        cout<<"\nTotal Grade Points = "<<totalGradePoints<<endl;
        cout<<"Total Credit Hours = "<<totalCreditHours<<endl;
        cout<<"|----------------------------------|"<<endl;
        //Displaying the Sgpa
        cout<<"\nYour SGPA is = "<<sgpa<<endl;
        cout<<"|----------------------------------|"<<endl;
        cout<<"\nThank You for using this Program!"<<endl;
    return 0;
                            


}


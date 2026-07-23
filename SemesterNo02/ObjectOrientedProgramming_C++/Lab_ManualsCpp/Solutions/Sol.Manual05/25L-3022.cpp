#include<iostream>
using namespace std;

class HeroMissionDate
{
private:
	//Private Data members:
	int Day;
	int Month;
	int Year;
public:
	//Public Data Members and Member Functions: 
	HeroMissionDate()
	{
		
		Day = 1;
		Month = 1;
		Year = 1926;
		cout << " January 1, 1926 (The day Professor Utonium started his laboratory journal)" << endl;
			
	}
	HeroMissionDate(int d, int m, int y)
	{

		Day = d;
		Month = m;
		Year = y;
		cout << "This is an Overloaded constructor to get specific dates : " << endl;

	}

	~HeroMissionDate()
	{
		cout << "Saving Townsville ends... Destructor called!" << endl;
	}

	void print()
	{
		cout << "The Printed Mission Date is: " << endl;
		cout << Day << " / " << Month << " / " << Year << " " << endl;
	}

	void input()
	{
		cout << "Please Enter Specific Values For Day Month and Year: "<<endl;
		cout << "Enter the Day" << endl;
		cin >> Day;
		cout << "Enter the Month" << endl;
		cin >> Month;
		cout << "Enter the Year" << endl;
		cin >> Year;
	}

	void setYear(int y) //Setter Function: 
	{
			Year = y;
	}

	int getDay()
	{
		return Day;
	}

	int getMonth()
	{
		return Month;
	}

	// comparing current date with another date :

	int Compare(HeroMissionDate otherDate)
	{
		if (Year != otherDate.Year)
		{
			if (Year > otherDate.Year)
				return 1;
			else
				return -1;
		}
			
		if (Month != otherDate.Month)
		{
			if (Year > otherDate.Year)
				return 1;
			else
				return -1;
		}
		
		if (Day != otherDate.Day)
		{
			if (Year > otherDate.Year)
				return 1;
			else
				return -1;
		}

		return 0; // dates are equal
	}

	// 2. IncrementMonth - returns NEW object with month+1
	HeroMissionDate IncrementMonth() 
	{
		int newMonth = Month + 1;
		int newYear = Year;

		if (newMonth > 12) 

		{  // if December, roll over to January
			newMonth = 1;
			newYear++;
		}

		return HeroMissionDate(Day, newMonth, newYear);
	}


};

int main()
{
	cout << "\n\nTesting All the Methods in the Main Function: " << endl;

	cout << " \nTesting The Default Constructor: " << endl;
	HeroMissionDate Blossom;
	Blossom.print();

	cout << " \nTesting The Overloaded Constructor: " << endl;
	HeroMissionDate Buttercup(14, 9, 2026);
	Buttercup.print();

	cout << " \nTesting The input and print Methods: " << endl;
	HeroMissionDate Bubbles;
	Bubbles.input();
	Bubbles.print();

	cout << "\nTesting the setYear Method :" << endl;
	Blossom.setYear(2026);
	Blossom.print();

	cout << "\nCalling the Getter Function on Buttercup :" << endl;
	cout << "The Day is: " << Buttercup.getDay() << endl;
	cout << "The Month is: " << Buttercup.getMonth()<< endl ;
	
	//Checking the Comaprison Functionality :

	cout << "\nComparing the Dates of Mission Blossom and Buttercup :" << endl;
	int results = Buttercup.Compare(Blossom);

	if (results == 1)
	{
		cout << " Blossom Mission Happened After the Buttercup Mission : " << endl;
	}
	else if (results == -1)
	{
		cout << " Blossom Mission Happened Earlier than the Buttercup Mission : " << endl;
	}
	else
	{
	    cout << " Blossom Mission Happened at the same time as the Buttercup Mission : " << endl;
		
	}

	// Checking the Increment Functionality :
    
	cout << " \nThe Increment Function here Incrementing the Buttercup's mission Month : " << endl;
    
	HeroMissionDate NewMissionDate = Buttercup.IncrementMonth();

	cout << " The Original Mission Date is : ";  Buttercup.print();
	cout << " The Incremented Mission Date is : "; NewMissionDate.print();

	cout << " \n Sucessfully Ending the Mission !! ... Watch the Distructors on Fire : "<<endl;

	system("pause");

	return 0; 

}
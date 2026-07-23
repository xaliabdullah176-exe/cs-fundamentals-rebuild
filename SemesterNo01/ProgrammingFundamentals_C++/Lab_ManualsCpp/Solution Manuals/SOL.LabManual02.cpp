
//Lab Manual Tasks;

//Question No 05;

//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//Swapping Program by 3 Variables;
//
//	int num_1, num_2, temp;
//
//	cout << "Enter first Number" << endl;
//	cin >> num_1;
//
//	cout << "Enter first Number" << endl;
//	cin >> num_2;
//
//	cout << num_1 << endl;
//	cout << num_2 << endl;
//
//	//Program Logic 3rd var	
//	{
//		temp = num_1;
//		num_1 = num_2;
//		num_2 = temp;
//	}
//	cout << "The First number is " << num_1 << endl;
//	cout << "The second number is " << num_2 << endl;
//}


//Question No 06


//#include<iostream>
//using namespace std;
//
//int main()
//{
//	//Swapping Program by 2 Variables;
//
//	int num_1, num_2;
//
//	cout << "Enter first Number" << endl;
//	cin >> num_1;
//
//	cout << "Enter first Number" << endl;
//	cin >> num_2;
//
//	cout << num_1 << endl;
//	cout << num_2 << endl;
//
//	//Program Logic 3rd var	
//	{
//		num_1 = num_1 + num_2;
//		num_2 = num_1 - num_2;
//		num_1 = num_1 - num_2;
//
//
//	}
//	cout << "The First number is " << num_1 << endl;
//	cout << "The second number is " << num_2 << endl;
//}


//Question no 01;
//
//#include<iostream>
//#include<iomanip>
//
//using namespace std;
//
//int main()
//{
//	int price;
//	double price_per_sq_inch;
//	float radius, area;
//	const float pi = 3.14;
//
//	cout << "Enter The Radius of Pizza"<<endl;
//	cin >> radius;
//	cout << "Enter The Price of Pizza"<<endl;
//	cin >> price;
//
// //Code Logic
// 
//	{
//		area = pi * radius * radius;
//		price_per_sq_inch = price / area;
//	}
//	cout << "The Price Per Square Inch Is" << endl;
//	cout << fixed << setprecision(4) << price_per_sq_inch;
//    
//}

//Question No 04;
// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main()
// {
// 	//personal Budget Balance Program
// 	float monthly_income, rent, groceries, utilities, transportation, entertainment, other_expenses ;
//     float total_expenses, remaining_balance;

//     //User Input

// 	cout << "Enter Total Monthly Income" << endl;
// 	cin >> monthly_income;
// 	cout << "Enter Rent Expenses" << endl;
// 	cin >> rent;
// 	cout << "Enter Groceries Expenses" << endl;
// 	cin >> groceries;
// 	cout << "Enter Utilities Expenses" << endl;
// 	cin >> utilities;
// 	cout << "Enter Transportation Expenses" << endl;
// 	cin >> transportation;
// 	cout << "Enter Entertainment Expenses" << endl;
// 	cin >> entertainment;
// 	cout << "Enter Other Expenses" << endl;
// 	cin >> other_expenses;

// 	// Program Logic
// 	{
// 		total_expenses = rent + groceries + utilities + transportation + entertainment + other_expenses;
// 		remaining_balance = monthly_income - total_expenses;
// 	}
//     cout << "Total Expenses: " << total_expenses << endl;
//     cout << "Remaining Balance: " << remaining_balance << endl;
//     //percentage of income spent on each expense
//     float rent_percentage = (rent / monthly_income) * 100;
//     float groceries_percentage = (groceries / monthly_income) * 100;
//     float utilities_percentage = (utilities / monthly_income) * 100;
//     float transportation_percentage = (transportation / monthly_income) * 100;
//     float entertainment_percentage = (entertainment / monthly_income) * 100;
//     float other_expenses_percentage = (other_expenses / monthly_income) * 100;

//     //program logic
//     {
//         cout << fixed << setprecision(2);
//         cout << "Percentage of Income Spent on Each Expense:" << endl;
//         cout << "Rent: " << rent_percentage << "%" << endl;
//         cout << "Groceries: " << groceries_percentage << "%" << endl;
//         cout << "Utilities: " << utilities_percentage << "%" << endl;
//         cout << "Transportation: " << transportation_percentage << "%" << endl;
//         cout << "Entertainment: " << entertainment_percentage << "%" << endl;
//         cout << "Other Expenses: " << other_expenses_percentage << "%" << endl;
//     }

// }

//Question no 02

// #include <iostream>

// using namespace std;

// int main() {
//     double height, width, coveragePerGallon;

//     // Get user input
//     cout << "Enter the height of the wall in feet: ";
//     cin >> height;

//     cout << "Enter the width of the wall in feet: ";
//     cin >> width;

//     cout << "Enter the coverage of paint in square feet per gallon: ";
//     cin >> coveragePerGallon;

//     // Calculate area
//     double area = height * width;

//     // Calculate raw gallons needed
//     double rawGallons = area / coveragePerGallon;

//     cout<< rawGallons<<endl; }


// Question no 3
// #include <iostream>
// using namespace std;

// int main() {
//     double costPrice;
//     double markedUpPrice, sellingPrice;

//     // Get the original cost price from the user
//     cout << "Enter the original cost price of the item: ";
//     cin >> costPrice;

//     // Apply 80% markup
//     markedUpPrice = costPrice * 1.80;

//     // Apply 10% discount
//     sellingPrice = markedUpPrice * 0.90;

//     // Display the final selling price
//     cout << "\nThe final selling price of the item is:" << sellingPrice << endl;

//     return 0;
// }
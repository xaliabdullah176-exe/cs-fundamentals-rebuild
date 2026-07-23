#include <iostream>
using namespace std;

int main() {
cout<<"==========================="<<endl;
cout<<"Welcome to my Caffeine Hub!"<<endl;
cout<<"==========================="<<endl;
  int typeOfCoffee, numberOfCups;
cout<<"Please select from the following options:"<<endl;

cout<<"|-------------------------|"<<endl;
cout<<"|  Order a drink       |"<<endl;
cout<<"The following drinks are available:"<<endl;
cout<<"1. Espresso (Rs 150 + tax)"<<endl;
cout<<"2. Cappuccino (Rs 180 + tax)"<<endl;
cout<<"3. Latte (Rs 200 + tax)  "<<endl;
cout<<"|-------------------------|"<<endl;

cout<<"Enter the number corresponding to your choice: ";
cin>>typeOfCoffee;
cout<<"Enter the number of cups you would like to order: ";
cin>>numberOfCups;

double bill = 0.0;

if(typeOfCoffee==1) 
{
     bill = numberOfCups * 150 * 1.10; // Corrected: includes 10% tax
}
else if(typeOfCoffee==2) 
{
     bill = numberOfCups * 180 * 1.10; // Corrected: includes 10% tax
}
else if(typeOfCoffee==3) 
{
     bill = numberOfCups * 200 * 1.10; // Corrected: includes 10% tax
}
else 
{
    cout<<"Invalid choice. Please restart your order."<<endl;
    return 0;
}
char addSugar, addWhippedCream;
cout<<"Would you like to add sugar? (y/n): ";
cin>>addSugar;
cout<<"Would you like to add whipped cream? (y/n): ";
cin>>addWhippedCream;
if (addSugar=='y' || addSugar=='Y') 
{
   bill += 20;
    cout<<"Sugar added. ";
}
if (addWhippedCream=='y' || addWhippedCream=='Y') 
{
   bill += 30;
    cout<<"Whipped cream added. ";
}
cout<<"Your total bill is: Rs "<<bill<<endl;
cout<<"Processing your order..."<<endl;
cout<<"Order completed! Enjoy your coffee!"<<endl;
cout<<"|----------------------------------------------------|"<<endl;
cout<<"Thank you for visiting Caffeine Hub! Enjoy your drink!"<<endl;
cout<<"|----------------------------------------------------|"<<endl;
return 0;
}
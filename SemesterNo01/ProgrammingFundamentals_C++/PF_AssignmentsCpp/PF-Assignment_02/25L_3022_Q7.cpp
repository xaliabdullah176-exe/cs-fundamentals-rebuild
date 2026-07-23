

//In While Loop
// #include<iostream>
// using namespace std;

// int main()
// {
//     int i = 1 , num, rang, result;

//     cout<<"======================================================="<<endl;
//     cout<<"This Program prints a multiplication table of a Number"<<endl;
//     cout<<"======================================================="<<endl;
 
//     cout<<"Enter the number for table"<<endl;

//     cin>>num;  
    
//     cout<<"Enter the Range For the table"<<endl;

//     cin>>rang;

//     while(i <= rang)
//     {
//          result  = num * i;
         
//          cout<<num << " x " << i << " = " << result << endl;   

//          i++;
//     }
// return 0;
// }

//In For Loop
#include<iostream>
using namespace std;

int main()
{
    int num, rang, result;

    cout<<"======================================================="<<endl;
    cout<<"This Program prints a multiplication table of a Number"<<endl;
    cout<<"======================================================="<<endl;
 
    cout<<"Enter the number for table"<<endl;

    cin>>num;  
    
    cout<<"Enter the Range For the table"<<endl;

    cin>>rang;

    for(int i = 1; i <= rang; i++)
    {
         result = num * i;
         
         cout<<num << " x " << i << " = " << result << endl;
    }
    
    return 0;
}
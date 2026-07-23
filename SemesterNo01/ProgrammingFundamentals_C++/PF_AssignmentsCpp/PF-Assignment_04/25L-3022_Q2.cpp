#include <iostream>
using namespace std;

void searchPattern(char text[], char pattern[])
{
for (int i = 0;  i<= text[MAX]-pattern[MAX]; i++)
{
    
}
}

const int MAX = 500;

int getLen(char arr[])
{
    int count = 0;
    while( arr[count] != '\0' )
    count++;

    return count;
}

int main() {
     char text[MAX];
     char pattern[MAX];

     cout<<"Enter The Text in the Line: "<<endl;
     cin.getline(text, MAX);

     
     cout<<"Enter The pattern in the Line: "<<endl;
     cin.getline(pattern, MAX);

     cout<< text <<endl;
     cout<< pattern <<endl;

     //Getting Lengths without SLegnth Function...

     cout << getLen(text) << endl;
     cout << getLen(pattern) << endl;


    return 0;
}
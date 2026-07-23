#include <iostream>
using namespace std;

void convolution(int input[], int sizeInput, int filter[], int sizeFilter)
{
    for(int i = 0; i<sizeInput; i++)
    {
        for(int j = 0; j < sizeFilter; j++)
        {
            input[j]+= (input[j] * filter[j]);
        }
        
    }
    cout<<"Output"<<input[j]<<" ";
}

int main() {
    
    return 0;
}
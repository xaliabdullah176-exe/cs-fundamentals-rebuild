#include<iostream>
using namespace std;

void cubeByPtr(int* p);
void cubeByRef(int& r);

int main()
{
	int num_1,num_2;
	cout << "Enter The First Number for cubes" << endl;
	cin >> num_1;
	cout << "Enter The Second Number for cubes" << endl;
	cin >> num_2;
    int *ptr = &num_2;

    cubeByPtr(ptr);
	cubeByRef(num_1);

	cout << "The Cube of Number By Pointers is : " << *ptr << endl;
	cout << "The Cube of Number By Reference is : " << num_1<< endl;
	system("pause");
	return 0;
}

void cubeByPtr(int* p)
{
	*p = (*p)*(*p)*(*p);
	cout << "The Cube of Values By Pointers: " << endl;
}

void cubeByRef(int& r)
{
	cout << "It is the cube by References: " << endl;
    r = r * r * r;
	
}
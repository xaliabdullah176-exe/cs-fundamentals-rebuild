#include <iostream>
using namespace std;
int main() {
	int* a = new int(100);
	int* b = a;
	delete a;
	a = nullptr;
	b = nullptr;
	int* c = new int(200);
	c = new int(300);
	delete c;
	c = nullptr;
    system("pause");
	return 0;
}

// Identify :
//o memory leaks
//o dangling pointers
// Rewrite the code to :
//o fix all memory issues
//o follow proper dynamic memory management rules
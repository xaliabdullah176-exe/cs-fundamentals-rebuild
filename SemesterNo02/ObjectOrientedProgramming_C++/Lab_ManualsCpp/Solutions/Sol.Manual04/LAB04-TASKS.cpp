#include<iostream>
using namespace std;

class MysteryCase
{
public:
	int caseID;
	float rewardAmount;

	MysteryCase()
	{
		
		cout << "Default constructor Called" << endl;
	}
	MysteryCase(int id, float reward)
	{
		caseID = id;
		rewardAmount = reward;
		cout << "Parametrized Constructor Called" << endl;
	}

	// MysteryCase(int id , float reward = 2.7)
	// {
	// 	caseID = id;
	// 	rewardAmount = reward;
	// 	cout << "Default - Parametrized Constructor Called" << endl;
	// }

	MysteryCase(const MysteryCase &obj)
	{
		caseID = obj.caseID;
		rewardAmount = obj.rewardAmount;
		cout << "Copy Constructor is Called " << endl;
	}

	void display()
	{
		cout << "Case-ID: " << caseID << endl;
		cout << "Reward Amount: " << rewardAmount << endl;
	}

	~MysteryCase()
	{
		cout << "Destructor Is called " << endl;
	}

};

int main()
{
	MysteryCase M1;
	MysteryCase M2(2, 5.7);
	MysteryCase M4(M2);

	cout << "\nCase - 2: ";
	M2.display();

	{
		MysteryCase M3(M2);
		cout << "\nCase - 3: ";
		M3.display();
	}

	cout << "Case - 4: ";
		M4.display();

	cout << endl << endl;
	system("pause");

	return 0;
}




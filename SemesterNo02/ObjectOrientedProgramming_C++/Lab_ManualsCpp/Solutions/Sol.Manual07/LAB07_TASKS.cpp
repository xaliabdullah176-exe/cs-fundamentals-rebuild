//TASK 1


//#include <iostream>
//using namespace std;
//class Beyblade
//{
//private:
//	int beybladeId;
//	float powerLevel;
//public:
//	Beyblade()
//	{
//		beybladeId = 20;
//		powerLevel = 100.2;
//	}
//
//	Beyblade(int id, float power)
//	{
//		if (id > 0 && power > 0)
		//{

			//beybladeId = id;
			//powerLevel = power;
		//}
//	}
//
//
//	void setter(int valueID, float valuelevel)
//	{
//		beybladeId = valueID;
//		powerLevel = valuelevel;
//	}
//
//	int getID()
//	{
//		return beybladeId;
//	}
//
//	int getPowerLvl()
//	{
//		return powerLevel;
//	}
//
//	void display()
//	{
//		cout << "beybladeID: " << beybladeId << endl;
//		cout << "powerlevel: " << powerLevel << endl;
//	}
//
//
//};
//
//int main()
//{
//	Beyblade B1;
//	Beyblade* ptrB1 = &B1;
//
//	B1.display();
//
//	ptrB1->display();
//
//	system("pause");
//	return 0;
//}
//

//TASK 2

//#include <iostream>
//using namespace std;
//class Beyblade
//{
//private:
//
//	int beybladeId;
//	float powerLevel;
//
//public:
//	Beyblade()
//	{
//		beybladeId = 20;
//		powerLevel = 2000.5;
//	}
//
//	Beyblade(int id, float power)
//	{
//		if (id > 0 && power > 0)
//		{
//
//			beybladeId = id;
//			powerLevel = power;
//		}
//	}
//
//	void setter(int valueID, float valuelevel)
//	{
//		beybladeId = valueID;
//		powerLevel = valuelevel;
//	}
//
//	int getID()
//	{
//		return beybladeId;
//	}
//
//	int getPowerLvl()
//	{
//		return powerLevel;
//	}
//
//	void display()
//	{
//		cout << "beybladeID: " << beybladeId << endl;
//		cout << "powerlevel: " << powerLevel << endl;
//	}
//
//
//};
//
//int main(){
//	Beyblade B1;
//	Beyblade* ptrB2 = new Beyblade(120, 17.23);
//
//	B1.display();
//
//	ptrB2->display();
//
//	delete ptrB2;
//	ptrB2 = nullptr;
//
//	system("pause");
//	return 0;
//}

//TASK 3 

//#include <iostream>
//using namespace std;
//
//class Beyblade
//{
//private:
//
//	int beybladeId;
//	float powerLevel;
//
//public:
//	Beyblade()
//	{
//		beybladeId = 20;
//		powerLevel = 105.6;
//	}
//
//	Beyblade(int id, float power)
//	{
//		beybladeId = id;
//		powerLevel = power;
//	}
//
//	void setter(int valueID, float valuelevel)
//	{
//		beybladeId = valueID;
//		powerLevel = valuelevel;
//	}
//
//	int getID()
//	{
//		return beybladeId;
//	}
//
//	int getPowerLevel()
//	{
//		return powerLevel;
//	}
//
//	void display()
//	{
//		cout << "beybladeID: " << beybladeId << endl;
//		cout << "powerlevel: " << powerLevel << endl;
//	}
//
//
//};
//
//int main(){
//	int numOfBlades;
//	cout << "Enter the number of Beyblades: ";
//	cin >> numOfBlades;
//	Beyblade* B1 = new Beyblade[numOfBlades];
//
//	for (int i = 0; i < numOfBlades; i++)
//	{
//		int ID;
//		float Power;
//		cout << "Enter the id of Bayblade: ";
//		cin >> ID;
//		cout << "Enter the lvl of Bayblade: ";
//		cin >> Power;
//		B1[i].setter(ID, Power);
//	}
//
//	for (int i = 0; i < numOfBlades; i++)
//	{
//		B1[i].display();
//	}
//
//
//	system("pause");
//	return 0;
//}
//

//TASK 4

//#include <iostream>
//using namespace std;
//
//class Beyblade{
//private:
//	int beybladeId;
//
//public:
//
//	float powerLevel;
//
//	Beyblade()
//	{
//		beybladeId = 20;
//		powerLevel = 1092.46;
//	}
//
//	Beyblade(int id, float power)
//	{
//		beybladeId = id;
//		powerLevel = power;
//	}
//
//	void setter(int valueID, float valuelevel)
//	{
//		beybladeId = valueID;
//		powerLevel = valuelevel;
//	}
//
//	int getID()
//	{
//		return beybladeId;
//	}
//
//	int getLvl()
//	{
//		return powerLevel;
//	}
//
//	void display()
//	{
//		cout << "beybladeID: " << beybladeId << endl;
//		cout << "powerlevel: " << powerLevel << endl;
//	}
//
//
//};
//
//
//int main()
//{
//	float Beyblade::* ptrB1 = &Beyblade::powerLevel;
//
//	Beyblade b1;
//	b1.*ptrB1 = 90.5;
//
//	Beyblade* bp = &b1;
//	bp->*ptrB1 = 120.0;
//
//	b1.display();
//
//	system("pause");
//	return 0;
//}
//

//TASK 5

#include <iostream>
using namespace std;

class Beyblade
{
private:
	int beybladeId;

public:

	float powerLevel;
	Beyblade()
	{
		beybladeId = 90;
		powerLevel = 89.20;
	}

	Beyblade(int id, float power)
	{
		beybladeId = id;
		powerLevel = power;
	}

	void setter(int valueID, float valuelevel)
	{
		beybladeId = valueID;
		powerLevel = valuelevel;
	}

	int getID()
	{
		return beybladeId;
	}

	int getLvl()
	{
		return powerLevel;
	}

	void display(){
		cout << "beybladeID: " << beybladeId << endl;
		cout << "powerlevel: " << powerLevel << endl;
	}


};


int main(){
	void (Beyblade::*fp)() = &Beyblade::display;

	Beyblade b1;
	(b1.*fp)();


	Beyblade* bp = &b1;
	(bp->*fp)();

	system("pause");
	return 0;
}


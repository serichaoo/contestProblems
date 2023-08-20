/*
ID: sericha1
TASK: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct milk
{
	int uPrice;
	int uAvailable;
};

bool isCheaper(milk a, milk b)
{
	return (a.uPrice < b.uPrice);
}

int main()
{
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	//ostream& fout = cout;
	//istream& fin = cin;

	int milkGoal;
	int nFarmers;
	int totalSpent = 0;
	milk list[5000];
	fin >> milkGoal >> nFarmers;


	for (int i = 0; i < nFarmers; i++)
	{
		fin >> list[i].uPrice >> list[i].uAvailable;
	}

	sort(list, list + nFarmers, isCheaper);

	int counter = 0;
	while (milkGoal > 0)
	{
		if (list[counter].uAvailable <= milkGoal)
		{
			milkGoal -= list[counter].uAvailable;
			totalSpent += list[counter].uAvailable * list[counter].uPrice;
			counter++;
		}
		else
		{
			totalSpent += milkGoal * list[counter].uPrice;
			milkGoal = 0;
		}
	}

	fout << totalSpent << endl;

	return 0;
}


/*
ID: sericha1
TASK: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int dialMax;

struct Combination
{
	int dial1;
	int dial2;
	int dial3;
};

int mod(int number, int modulo)
{
	return (((number % modulo) + modulo) % modulo);
}

bool operator==(const Combination& one, const Combination& two)
{
	return (one.dial1 == two.dial1 && one.dial2 == two.dial2 && one.dial3 == two.dial3);
}

bool isIn(vector<Combination>& allCombo, Combination combo)
{
	for (int i = 0; i < allCombo.size(); i++)
		if (allCombo[i] == combo) return true;
	return false;
}

Combination map(Combination original, int key)
{
	Combination placeholder;
	placeholder.dial1 = mod((original.dial1 - 2 + ((key / 25) % 5)), dialMax);
	placeholder.dial2 = mod((original.dial2 - 2 + ((key / 5) % 5)), dialMax);
	placeholder.dial3 = mod((original.dial3 - 2 + (key % 5)), dialMax);
	return placeholder;
}

int main()
{
#ifndef TESTING
	ofstream fout("combo.out");
	ifstream fin("combo.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	Combination farmerCombo;
	Combination masterCombo;
	fin >> dialMax >> farmerCombo.dial1 >> farmerCombo.dial2 >> farmerCombo.dial3
		>> masterCombo.dial1 >> masterCombo.dial2 >> masterCombo.dial3;

	vector<Combination> allCombo;

	for (int i = 0; i < 125; i++)
	{
		if (!isIn(allCombo, map(farmerCombo, i)))
		{
			allCombo.push_back(map(farmerCombo, i));
		}
		if (!isIn(allCombo, map(masterCombo, i)))
		{
			allCombo.push_back(map(masterCombo, i));
		}
	}

	fout << allCombo.size() << endl;

	return 0;
}





/*
int dialMax;

int differenceToProduct(int difference)
{
	if (difference < 0) difference = -difference;
	if (difference > dialMax/2)
	if (5 - difference > 0) return 5 - difference;
	else return 0;
}

int main()
{
#ifndef TESTING
	ofstream fout("combo.out");
	ifstream fin("combo.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int farmerCombination[3];
	int masterCombination[3];
	fin >> dialMax >> farmerCombination[0] >> farmerCombination[1] >> farmerCombination[2]
		>> masterCombination[0] >> masterCombination[1] >> masterCombination[2];

	int product = 1;
	for (int i = 0; i < 3; i++)
	{
		product *= differenceToProduct((farmerCombination[i] - farmerCombination[i]));
	}
	fout << 250 - product;

	return 0;
}
*/
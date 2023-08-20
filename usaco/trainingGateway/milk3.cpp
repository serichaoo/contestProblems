/*
ID: sericha1
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct bucket
{
	int currentMilk;
	int capacity;
};

struct arrangement
{
	bucket A;
	bucket B;
	bucket C;
};

vector<int> validCCurrentMilkValues;

void pour(bucket& x, bucket& y)
{
	if (y.capacity - y.currentMilk >= x.currentMilk)
	{
		y.currentMilk += x.currentMilk;
		x.currentMilk = 0;
	}
	else
	{
		x.currentMilk -= (y.capacity - y.currentMilk);
		y.currentMilk = y.capacity;
	}
}

bool operator==(arrangement a, arrangement b)
{
	return (a.A.currentMilk == b.A.currentMilk && a.B.currentMilk == b.B.currentMilk && a.C.currentMilk == b.C.currentMilk);
}

bool isArrangementIn(arrangement element, vector<arrangement> arrangements)
{
	for (int i = 0; i < arrangements.size(); i++)
		if (element == arrangements[i]) return true;
	return false;
}

bool isIntIn(int element, vector<int> list)
{
	for (int i = 0; i < list.size(); i++)
		if (element == list[i]) return true;
	return false;
}

// DFS, keep track of all past arrangements, add all arrangements with A empty and stop when it goes through a past arrangement

void search(const arrangement& currentArrangement, vector<arrangement>& pastArrangements)
{
	if (!(isArrangementIn(currentArrangement, pastArrangements)))
	{
		if (currentArrangement.A.currentMilk == 0 && !(isIntIn(currentArrangement.C.currentMilk, validCCurrentMilkValues)))
			validCCurrentMilkValues.push_back(currentArrangement.C.currentMilk);

		pastArrangements.push_back(currentArrangement);

		arrangement newArrangement = currentArrangement;
		pour(newArrangement.A, newArrangement.B);
		search(newArrangement, pastArrangements);

		newArrangement = currentArrangement;
		pour(newArrangement.B, newArrangement.A);
		search(newArrangement, pastArrangements);

		newArrangement = currentArrangement;
		pour(newArrangement.A, newArrangement.C);
		search(newArrangement, pastArrangements);

		newArrangement = currentArrangement;
		pour(newArrangement.C, newArrangement.A);
		search(newArrangement, pastArrangements);

		newArrangement = currentArrangement;
		pour(newArrangement.B, newArrangement.C);
		search(newArrangement, pastArrangements);

		newArrangement = currentArrangement;
		pour(newArrangement.C, newArrangement.B);
		search(newArrangement, pastArrangements);
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	arrangement currentArrangement;
	vector<arrangement> pastArrangements;
	int aCapacity, bCapacity, cCapacity;
	fin >> aCapacity >> bCapacity >> cCapacity;
	currentArrangement = arrangement{ {0, aCapacity}, {0, bCapacity}, {cCapacity, cCapacity} };

	search(currentArrangement, pastArrangements);

	sort(validCCurrentMilkValues.begin(), validCCurrentMilkValues.end());

	for (int i = 0; i < validCCurrentMilkValues.size() - 1; i++)
		fout << validCCurrentMilkValues[i] << ' ';
	fout << validCCurrentMilkValues[validCCurrentMilkValues.size() - 1] << endl;

	return 0;
}


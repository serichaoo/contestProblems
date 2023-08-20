/*
ID: sericha1
TASK: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int findCostRaisingHeights(vector<int> hillHeights, int currentMinimum)
{
	int cost = 0;
	for (int i = 0; i < hillHeights.size(); i++)
	{
		if (hillHeights[i] < currentMinimum + 1)
		{
			cost += (currentMinimum - hillHeights[i]) * 2 + 1;
		}
	}
	return cost;
}

int findCostLoweringHeights(vector<int> hillHeights, int currentMaximum)
{
	int cost = 0;
	for (int i = 0; i < hillHeights.size(); i++)
	{
		if (hillHeights[i] > currentMaximum - 1)
		{
			cost += (hillHeights[i] - currentMaximum) * 2 + 1;
		}
	}
	return cost;
}

int main()
{
#ifndef TESTING
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int numHills;
	fin >> numHills;
	vector<int> hillHeights;
	for (int i = 0; i < numHills; i++)
	{
		int placeholder;
		fin >> placeholder;
		hillHeights.push_back(placeholder);
	}
	sort(hillHeights.begin(), hillHeights.end());

	int currentMinimum = hillHeights[0];
	int currentMaximum = hillHeights[numHills - 1];
	int totalCost = 0;

	while (currentMaximum - currentMinimum > 17)
	{
		int raisePrice = findCostRaisingHeights(hillHeights, currentMinimum);
		int lowerPrice = findCostLoweringHeights(hillHeights, currentMaximum);
		if (raisePrice < lowerPrice)
		{
			totalCost += raisePrice;
			currentMinimum++;
		}
		else
		{
			totalCost += lowerPrice;
			currentMaximum--;
		}
	}
	fout << totalCost << endl;

	return 0;
}

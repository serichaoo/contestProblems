#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxWidthToGetHere(1e5, -1);
vector<vector<pair<int, int>>> wormholes(1e5);
vector<int> cowLocations;

void findMinPath(int currentTile, int currentMax)
{
	if (currentMax <= maxWidthToGetHere[currentTile])
		return;
	maxWidthToGetHere[currentTile] = currentMax;
	for (int i = 0; i < wormholes[currentTile].size(); i++)
	{
		findMinPath(wormholes[currentTile][i].first, std::min(currentMax, wormholes[currentTile][i].second));
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("wormsort.out");
	ifstream fin("wormsort.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int nCows, nWorms;
	fin >> nCows >> nWorms;
	for (int i = 0; i < nCows; i++)
	{
		int a;
		fin >> a;
		cowLocations.push_back(a - 1); // cowLocations[i] tells me where the cow at i wants to go
	}
	for (int i = 0; i < nWorms; i++)
	{
		int a, b, c;
		fin >> a >> b >> c;
		wormholes[a - 1].push_back({ b - 1 ,c });
		wormholes[b - 1].push_back({ a - 1,c });
	}
	int maximum = 1e9 + 1;
	for (int i = 0; i < nCows; i++)
	{
		if (maxWidthToGetHere[i] == -1)
		{
			findMinPath(i, 1e9 + 1);
			if (maxWidthToGetHere[cowLocations[i]] < maximum)
				maximum = maxWidthToGetHere[cowLocations[i]];
		}
	}
	if (maximum == 1e9 + 1)
	{
		fout << -1;
		return 0;
	}
	fout << maximum;
	return 0;
}

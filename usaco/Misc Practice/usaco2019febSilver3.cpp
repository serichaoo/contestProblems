#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int nPasts, nCows;
vector<vector<pair<int, bool>>> pastureLinks(1e5 + 1);
vector<int> pastureColours(1e5 + 1, -1);
bool isPossible = 1;
vector<bool> isVisited(1e5 + 1, 0);

void dfs(int originalPasture, bool colour)
{
	if (isPossible)
	{
		if (pastureColours[originalPasture] != -1 && pastureColours[originalPasture] != colour)
			isPossible = 0;
		if (isVisited[originalPasture])
			return;
		isVisited[originalPasture] = 1;
		for (auto u : pastureLinks[originalPasture])
		{
			bool newColour;
			if (u.second)
				newColour = colour;
			else
				newColour = !colour;
			dfs(u.first, newColour);
		}
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("revegetate.out");
	ifstream fin("revegetate.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	fin >> nPasts >> nCows;

	for (int i = 0; i < nCows; i++)
	{
		char placeholder;
		fin >> placeholder;
		bool isSame = 0;
		if (placeholder == 'S')
			isSame = 1;
		int a, b;
		fin >> a >> b;
		pastureLinks[a - 1].push_back({ b - 1,isSame });
		pastureLinks[b - 1].push_back({ a - 1,isSame });
	}
	// now run a DFS to find num compoments
	int numCompoments = 0;
	for (int i = 0; i < nPasts; i++)
	{
		if (isPossible)
		{
			if (!isVisited[i])
			{
				numCompoments++;
				dfs(i, 0);
			}
		}
	}

	if (!isPossible)
		fout << 0;
	else
	{
		fout << 1;
		for (int i = 0; i < numCompoments; i++)
			fout << 0;
	}

	return 0;
}

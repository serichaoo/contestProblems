#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int numFactories;
vector<vector<int>> adjList;
vector<int> alreadyVisitedFactories;

bool isIn(int a, const vector<int>& b)
{
	for (int i = 0; i < b.size(); i++)
		if (a == b[i]) return true;
	return false;
}

void search(int start)
{
	alreadyVisitedFactories.push_back(start);
	for (int i = 0; i < adjList[start].size(); i++)
	{
		if (!isIn(adjList[start][i], alreadyVisitedFactories))
		{
			search(adjList[start][i]);
		}
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("factory.out");
	ifstream fin("factory.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	fin >> numFactories;
	adjList.resize(numFactories);
	for (int i = 0; i < numFactories - 1; i++)
	{
		int a, b;
		fin >> a >> b;
		adjList[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < numFactories; i++)
	{
		alreadyVisitedFactories = {};
		search(i);
		if (alreadyVisitedFactories.size() == numFactories)
		{
			fout << i + 1;
			return 0;
		}
	}

	fout << -1;

	return 0;
}
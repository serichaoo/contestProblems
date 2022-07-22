#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

int gridSize;
vector<vector<bool>> isVisited(100, vector<bool>(100, false));
vector<vector<bool>> cowLocations(100, vector<bool>(100, false));
map<pair<int, int>, vector<char>> roads;
int nCowsInComponent = 0;

bool isIn(char a, vector<char> b)
{
	for (int i = 0; i < b.size(); i++)
		if (a == b[i])
			return true;
	return false;
}

void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= gridSize || y >= gridSize || isVisited[x][y])
		return;
	isVisited[x][y] = true;
	if (cowLocations[x][y])
		nCowsInComponent++;
	if (!isIn('N', roads[{x, y}]))
		dfs(x, y + 1);
	if (!isIn('E', roads[{x, y}]))
		dfs(x + 1, y);
	if (!isIn('S', roads[{x, y}]))
		dfs(x, y - 1);
	if (!isIn('W', roads[{x, y}]))
		dfs(x - 1, y);
}

int main()
{
#ifndef TESTING
	ofstream fout("countcross.out");
	ifstream fin("countcross.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int nCows, nRoads;
	fin >> gridSize >> nCows >> nRoads;
	for (int i = 0; i < nRoads; i++)
	{
		int x1, y1, x2, y2;
		fin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
		{
			roads[{x1 - 1, y1 - 1}].push_back('W');
			roads[{x2 - 1, y2 - 1}].push_back('E');
		}
		else if (x1 < x2)
		{
			roads[{x1 - 1, y1 - 1}].push_back('E');
			roads[{x2 - 1, y2 - 1}].push_back('W');
		}
		else if (y1 < y2)
		{
			roads[{x1 - 1, y1 - 1}].push_back('N');
			roads[{x2 - 1, y2 - 1}].push_back('S');
		}
		else if (y1 > y2)
		{
			roads[{x1 - 1, y1 - 1}].push_back('S');
			roads[{x2 - 1, y2 - 1}].push_back('N');
		}
	}
	vector<pair<int, int>> cowCoords;
	for (int i = 0; i < nCows; i++)
	{
		int x, y;
		fin >> x >> y;
		cowLocations[x - 1][y - 1] = true;
		cowCoords.push_back({ x - 1,y - 1 });
	}
	int nNonDistantCows = 0;
	for (int i = 0; i < nCows; i++)
	{
		if (!isVisited[cowCoords[i].first][cowCoords[i].second])
		{
			dfs(cowCoords[i].first, cowCoords[i].second);
			nNonDistantCows += nCowsInComponent * (nCowsInComponent - 1) / 2;
			nCowsInComponent = 0;
		}
	}
	fout << (nCows * (nCows - 1) / 2) - nNonDistantCows;
	return 0;
}

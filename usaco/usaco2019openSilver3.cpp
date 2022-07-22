#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

vector<bool> isVisited(1e5, false);
vector < pair<ll, ll >> cowLocations;
vector<vector<int>> links(1e5);
ll xMax = 0;
ll xMin = 1e8 + 1;
ll yMax = 0;
ll yMin = 1e8 + 1;
ll minPerimeter = 4e8 + 1;

void dfs(int cowIndex)
{
	if (isVisited[cowIndex])
		return;
	if (cowLocations[cowIndex].first < xMin)
		xMin = cowLocations[cowIndex].first;
	if (cowLocations[cowIndex].first > xMax)
		xMax = cowLocations[cowIndex].first;
	if (cowLocations[cowIndex].second < yMin)
		yMin = cowLocations[cowIndex].second;
	if (cowLocations[cowIndex].second > yMax)
		yMax = cowLocations[cowIndex].second;
	isVisited[cowIndex] = true;
	for (int i = 0; i < links[cowIndex].size(); i++)
	{
		dfs(links[cowIndex][i]);
	}
}


int main()
{
#ifndef TESTING
	ofstream fout("fenceplan.out");
	ifstream fin("fenceplan.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int nCows, nLinks;
	fin >> nCows >> nLinks;
	for (int i = 0; i < nCows; i++)
	{
		int x, y;
		fin >> x >> y;
		cowLocations.push_back({ x - 1,y - 1 });
	}
	for (int i = 0; i < nLinks; i++)
	{
		int a, b;
		fin >> a >> b;
		links[a - 1].push_back(b - 1);
		links[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < nCows; i++)
	{
		if (!isVisited[i])
		{
			dfs(i);
			int currentPerimeter = 2 * (yMax - yMin + xMax - xMin);
			if (currentPerimeter < minPerimeter)
				minPerimeter = currentPerimeter;
			xMax = 0;
			xMin = 1e8 + 1;
			yMax = 0;
			yMin = 1e8 + 1;
		}
	}
	fout << minPerimeter;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

struct cow
{
	int index;
	int xCoord;
	int yCoord;
	int xNew;
	int yNew;
};

vector<cow> cows;
int numCows;
set<pair<int, int>> checkedCoords;
int minimumMax = 1001;
int xMax;
int yMax;

bool isNotChecked(int x, int y)
{
	return (checkedCoords.count({ x,y }) == 0);
}
bool compareX(cow a, cow b)
{
	return a.xCoord < b.xCoord;
}
bool compareY(cow a, cow b)
{
	return a.yCoord < b.yCoord;
}
bool compareIndex(cow a, cow b)
{
	return a.index < b.index;
}

int maxCows(int x, int y)
{
	int bottomLeft = 0;
	int bottomRight = 0;
	int topLeft = 0;
	int topRight = 0;
	for (int i = 0; i < numCows; i++)
	{
		if (cows[i].xNew < x)
		{
			if (cows[i].yNew < y)
				bottomLeft++;
			else
				topLeft++;
		}
		else
		{
			if (cows[i].yNew < y)
				bottomRight++;
			else
				topRight++;
		}
	}
	int tempMax = bottomLeft;
	if (bottomRight > tempMax) tempMax = bottomRight;
	if (topLeft > tempMax) tempMax = topLeft;
	if (topRight > tempMax) tempMax = topRight;
	return tempMax;
}

void minFinder(int x, int y, int currentMax)
{
	if (x<0 || x>xMax || y<0 || y>yMax)
	{
		checkedCoords.insert({ x,y });
		return;
	}
	if (isNotChecked(x, y))
	{
		checkedCoords.insert({ x, y });
		int positionValue = maxCows(x, y);
		if (positionValue > currentMax) return;
		if (positionValue < minimumMax) minimumMax = positionValue;
		int r = 25;
		for (int i = -r; i <= r; ++i)
			for (int j = -r; j <= r; ++j)
				minFinder(x + i, y + j, positionValue);
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("balancing.out");
	ifstream fin("balancing.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	// compress coordinates first
	fin >> numCows;
	for (int i = 0; i < numCows; i++)
	{
		cow a{ i, -1, -1, -1, -1 };
		fin >> a.xCoord >> a.yCoord;
		cows.push_back(a);
	}
	sort(cows.begin(), cows.end(), compareX);
	int tempCounter = 0;
	for (int i = 0; i < numCows; i++)
	{
		if (i == 0)
			cows[i].xNew = 0;
		else if (cows[i].xCoord == cows[i - 1].xCoord)
			cows[i].xNew = tempCounter;
		else
		{
			tempCounter++;
			cows[i].xNew = tempCounter;
		}
	}
	xMax = tempCounter;
	// x coords compressed
	sort(cows.begin(), cows.end(), compareY);
	tempCounter = 0;
	for (int i = 0; i < numCows; i++)
	{
		if (i == 0)
			cows[i].yNew = 0;
		else if (cows[i].yCoord == cows[i - 1].yCoord)
			cows[i].yNew = tempCounter;
		else
		{
			tempCounter++;
			cows[i].yNew = tempCounter;
		}
	}
	yMax = tempCounter;
	// y coords compressed
	sort(cows.begin(), cows.end(), compareIndex);

	//	for (int i = 0; i < numCows; i++)
	//	{
	//		fout << cows[i].xNew << ' ' << cows[i].yNew << endl;
	//	}

	for (int y = 0; y <= yMax; y++) {
		int minimumMaxThisRow = 1001;
		for (int x = 0; x <= xMax; x++)
		{
			int thisMax = maxCows(x, y);
			if (thisMax > minimumMaxThisRow) break;
			minimumMaxThisRow = thisMax;
			minimumMax = std::min(minimumMax, thisMax);
		}
	}
	fout << minimumMax;

	// start from center, check all 4 directions, if max is equal or less, recurse and check those directions

	//minFinder(xMax / 2, yMax / 2, 1001);
	//fout << minimumMax;

	return 0;
}
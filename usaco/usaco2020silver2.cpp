#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct cow
{
	int xOriginal;
	int yOriginal;
	int xNew;
	int yNew;
	int index;
};

struct whichCows
{
	bool isCowIn[2500];
};

bool operator<(const whichCows& a, const whichCows& b)
{
	for (int i = 0; i < 2500; i++)
	{
		if (a.isCowIn[i] < b.isCowIn[i]) return true;
		if (a.isCowIn[i] > b.isCowIn[i]) return false;
	}
	return false;
}

whichCows operator+(const whichCows& a, const whichCows& b)
{
	whichCows c{};
	for (int i = 0; i < 2500; i++)
		if (a.isCowIn[i] || b.isCowIn[i])
			c.isCowIn[i] = 1;
	return c;
}

bool compareX(const cow& a, const cow& b)
{
	return a.xOriginal < b.xOriginal;
}

bool compareY(const cow& a, const cow& b)
{
	return a.yOriginal < b.yOriginal;
}

int main()
{
	int nCows;
	cin >> nCows;
	vector<cow> cows;
	for (int i = 0; i < nCows; i++)
	{
		int a, b;
		cin >> a >> b;
		cow newCow;
		newCow.xOriginal = a;
		newCow.yOriginal = b;
		newCow.index = i + 1;
		cows.push_back(newCow);
	}
	sort(cows.begin(), cows.end(), compareX);
	for (int i = 0; i < nCows; i++)
	{
		cows[i].xNew = i;
	}
	sort(cows.begin(), cows.end(), compareY);
	for (int i = 0; i < nCows; i++)
	{
		cows[i].yNew = i;
	}

	vector<vector<int>> grid(nCows, vector<int>(nCows, 0));
	for (int i = 0; i < nCows; i++)
		grid[cows[i].xNew][cows[i].yNew] = cows[i].index;

	vector<vector<whichCows>> pSum(nCows + 1, vector<whichCows>(nCows + 1, whichCows{}));
	set<whichCows> allPSumValues;
	allPSumValues.insert(whichCows{});

	for (int i = 1; i < nCows + 1; i++)
		for (int j = 1; j < nCows + 1; j++)
		{
			pSum[i][j] = pSum[i][j - 1] + pSum[i - 1][j];
			if (grid[i - 1][j - 1] > 0) pSum[i][j].isCowIn[grid[i - 1][j - 1] - 1] = true;
			allPSumValues.insert(pSum[i][j]);
		}

	set<whichCows> allDifferences;
	for (auto it1 = allPSumValues.begin(); it1 != allPSumValues.end(); it1++)
		for (auto it2 = allPSumValues.begin(); it2 != allPSumValues.end(); it2++)
		{
			whichCows newDifference{};
			bool placeholder = true;
			for (int i = 0; i < 2500; i++)
			{
				if ((*it1).isCowIn[i] < (*it2).isCowIn[i])
				{
					placeholder = false;
					break;
				}
				newDifference.isCowIn[i] = (*it1).isCowIn[i] - (*it2).isCowIn[i];
			}
			if (placeholder)
				allDifferences.insert(newDifference);
		}
	cout << allDifferences.size();

	return 0;
}









//
//struct cow
//{
//	int xOriginal;
//	int yOriginal;
//	int xNew;
//	int yNew;
//	int index;
//};
//
//bool compareXCoord(cow a, cow b)
//{
//	return a.xOriginal < b.xOriginal;
//}
//
//bool compareYCoord(cow a, cow b)
//{
//	return a.yOriginal < b.yOriginal;
//}
//
//bool compareIndices(cow a, cow b)
//{
//	return a.index < b.index;
//}
//
//int convertToBinary(int a)
//{ // 2^a
//	if (a == 0) return 1;
//	else if (a == 1) return 2;
//	else
//	{
//		int placeholder = convertToBinary(a / 2);
//		if (a % 2 == 0)
//			return placeholder * placeholder;
//		else
//			return placeholder * placeholder * 2;
//	}
//}
//
//int main()
//{
//	//#ifndef TESTING
//	//	ofstream fout(".out");
//	//	ifstream fin(".in");
//	//#else
//	//	ostream& fout = cout;
//	//	istream& fin = cin;
//	//#endif
//	int nCows;
//	cin >> nCows;
//	vector<cow> cows;
//
//	for (int i = 0; i < nCows; i++)
//	{
//		cow placeholder;
//		placeholder.index = i;
//		cin >> placeholder.xOriginal >> placeholder.yOriginal;
//		cows.push_back(placeholder);
//	}
//
//	sort(cows.begin(), cows.end(), compareXCoord);
//	cows[0].xNew = 0;
//	for (int i = 1; i < nCows; i++)
//	{
//		if (cows[i].xOriginal == cows[i - 1].xOriginal)
//			cows[i].xNew = cows[i - 1].xNew;
//		else
//			cows[i].xNew = cows[i - 1].xNew + 1;
//	}
//	int xMax = cows[nCows - 1].xNew;
//
//	sort(cows.begin(), cows.end(), compareYCoord);
//	cows[0].yNew = 0;
//	for (int i = 1; i < nCows; i++)
//	{
//		if (cows[i].yOriginal == cows[i - 1].yOriginal)
//			cows[i].yNew = cows[i - 1].yNew;
//		else
//			cows[i].yNew = cows[i - 1].yNew + 1;
//	}
//	int yMax = cows[nCows - 1].yNew;
//
//	sort(cows.begin(), cows.end(), compareIndices);
//
//	set<int> gridValues;
//	set<int> distinctValues;
//
//	vector<vector<int>> grid(xMax + 2, vector<int>(yMax + 2, 0)); //[x][y]
//	for (int i = 0; i < nCows; i++)
//		grid[cows[i].xNew + 1][cows[i].yNew + 1] += convertToBinary(i);
//
//	// convert grid to prefix sum
//	gridValues.insert(0);
//	for (int i = 1; i < xMax + 2; i++)
//		for (int j = 1; j < yMax + 2; j++)
//		{
//			grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
//			gridValues.insert(grid[i][j]);
//		}
//	//for (int i = 0; i < xMax + 2; i++)
//	//{
//	//	for (int j = 0; j < yMax + 2; j++)
//	//		cout << grid[i][j] << ' ';
//	//	cout << endl;
//	//}
//	//for (int i = 0; i < xMax + 1; i++)
//	//	for (int j = 0; j < yMax + 1; j++)
//	//		for (int a = i; a < xMax + 1; a++)
//	//			for (int b = j; b < yMax + 1; b++)
//	//			{
//	//				distinctValues.insert(grid[a + 1][b + 1] - grid[i][b + 1] - grid[a + 1][j] + grid[i][j]);
//	//			}
//
//	distinctValues.insert(0);
//	for (auto it = gridValues.begin(); it != gridValues.end(); it++)
//	{
//		auto newIt = it;
//		newIt++;
//		for (auto it2 = newIt; it2 != gridValues.end(); it2++)
//			distinctValues.insert(*it2 - *it);
//	}
//
//	cout << distinctValues.size();
//
//	return 0;
//}
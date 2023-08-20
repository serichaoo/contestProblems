/*
ID: sericha1
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ariProg
{
	int start;
	int difference;
};

int progLength;
int maximumSquare;
vector<int> bisquares;
bool bisquaresMap[125001]{ 0 };
vector<int> perfectSquares;
vector<ariProg> ariProgs;

/*void createSquares(int maximum)
{
	for (int i = 0; i <= maximum; i++)
		perfectSquares.push_back(i * i);
}*/

/*bool isBisquare(int x)
{
	for (int i = 0; i < perfectSquares.size(); i++)
	{
		if (x >= perfectSquares[i])
		{
			for (int j = 0; j < perfectSquares.size(); j++)
			{
				if (x == perfectSquares[i] + perfectSquares[j]) return true;
			}
		}
	}
	return false;
}*/

bool isValidAriProg(int start, int difference)
{
	if (progLength <= 2) return true;
	for (int i = 2; i < progLength; i++)
		if (start + i * difference > 2 * maximumSquare * maximumSquare
			|| !(bisquaresMap[start + i * difference]))
			return false;
	return true;
}

bool compareAriProg(ariProg a, ariProg b)
{
	if (a.difference != b.difference)
		return a.difference < b.difference;
	else
		return a.start < b.start;
}

bool isIn(vector<int> list, int element)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i] == element) return true;
	return false;
}

int main()
{
#ifndef TESTING
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	fin >> progLength >> maximumSquare;

	for (int i = 0; i <= maximumSquare; i++)
	{
		for (int j = i; j <= maximumSquare; j++)
		{
			if (!isIn(bisquares, i * i + j * j))
			{
				bisquares.push_back(i * i + j * j);
				bisquaresMap[i * i + j * j] = true;
			}
		}
	}

	sort(bisquares.begin(), bisquares.end());

	/*
	for (int i = 0; i <= 2 * maximumSquare * maximumSquare; i++)
	{
		if (isBisquare(i))
		{
			bisquares.push_back(i);
			bisquaresMap[i] = true;
		}
	}
	*/

	//cout << isBisquare(1) << isBisquare(2) << isBisquare(3) << endl;

	for (int i = 0; i < bisquares.size(); i++)
		for (int j = i + 1; j < bisquares.size(); j++)
			if (isValidAriProg(bisquares[i], bisquares[j] - bisquares[i]))
				ariProgs.push_back({ bisquares[i], bisquares[j] - bisquares[i] });

	if (ariProgs.size() == 0)
	{
		fout << "NONE" << endl;
		return 0;
	}

	sort(ariProgs.begin(), ariProgs.end(), compareAriProg);

	for (int i = 0; i < ariProgs.size(); i++)
	{
		fout << ariProgs[i].start << ' ' << ariProgs[i].difference << endl;
	}

	return 0;
}

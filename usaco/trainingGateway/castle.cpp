/*
ID: sericha1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct modulePos
{
	int yPos;
	int xPos;
};

int abs(int a)
{
	if (a < 0) return -a;
	return a;
}

bool isWall(modulePos a, modulePos b)
{
	if (abs(a.xPos - b.xPos + a.yPos - b.yPos) == 1)
	{
		// check NESW of a and see if there's a wall
	}
}

int main()
{
#ifndef TESTING
	ofstream fout("castle.out");
	ifstream fin("castle.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
}

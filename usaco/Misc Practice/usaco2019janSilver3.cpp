#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct peak
{
	int x;
	int y;
};

bool compare(peak a, peak b)
{
	return a.y > b.y;
}

bool isCovered(peak tPeak, peak sPeak)
{
	int heightDiff = tPeak.y - sPeak.y;
	return (tPeak.x - heightDiff <= sPeak.x) && (tPeak.x + heightDiff >= sPeak.x);
}

int main()
{
#ifndef TESTING
	ofstream fout("mountains.out");
	ifstream fin("mountains.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int nMountains;
	vector<peak> mountains;
	fin >> nMountains;
	for (int i = 0; i < nMountains; i++)
	{
		int x, y;
		fin >> x >> y;
		mountains.push_back({ x,y });
	}

	sort(mountains.begin(), mountains.end(), compare);

	int totalVisible = 0;
	for (int i = 0; i < nMountains; i++)
	{
		bool placeholder = true;
		for (int j = 0; j < i; j++)
		{
			if (placeholder && isCovered(mountains[j], mountains[i]))
				placeholder = false;
		}
		if (placeholder) totalVisible++;
	}

	fout << totalVisible;

	return 0;
}

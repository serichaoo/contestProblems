#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct t
{
	int time;
	bool isStart;
	int index;
	bool operator<(const t& a) { return time < a.time; }
};

int main()
{
#ifndef TESTING
	ofstream fout("lifeguards.out");
	ifstream fin("lifeguards.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int nLifeguards;
	fin >> nLifeguards;

	vector<t> times;

	for (int i = 0; i < nLifeguards; i++)
	{
		int a, b;
		fin >> a >> b;
		times.push_back({ a, true, i });
		times.push_back({ b, false, i });
	}

	sort(times.begin(), times.end());

	unsigned long long lifeguardIndexSum = 0;
	int nLifeguardsCurrent = 0;
	vector<int> timeLostIfFireLifeguard(nLifeguards, 0);
	int totalCovered = 0;

	for (int i = 0; i < 2 * nLifeguards; i++)
	{
		if (times[i].isStart)
		{
			nLifeguardsCurrent++;
			lifeguardIndexSum += times[i].index;
		}
		else
		{
			nLifeguardsCurrent--;
			lifeguardIndexSum -= times[i].index;
		}
		if (nLifeguardsCurrent == 1)
		{
			timeLostIfFireLifeguard[lifeguardIndexSum] += (times[i + 1].time - times[i].time);
		}
		if (nLifeguardsCurrent > 0)
		{
			totalCovered += times[i + 1].time - times[i].time;
		}
	}

	int min = 1000000001;

	for (int i = 0; i < nLifeguards; i++)
		if (timeLostIfFireLifeguard[i] < min)
			min = timeLostIfFireLifeguard[i];

	fout << totalCovered - min;

	return 0;
}
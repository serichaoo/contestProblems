#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
#ifndef TESTING
	ofstream fout("div7.out");
	ifstream fin("div7.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int numCows;
	fin >> numCows;
	vector<int> prefixSums;
	prefixSums.push_back(0);
	for (int i = 1; i <= numCows; i++)
	{
		int a;
		fin >> a;
		prefixSums.push_back((a + prefixSums[i - 1]) % 7);
	}

	int maxSize = numCows;
	while (true)
	{
		for (int i = 0; i <= numCows - maxSize; i++)
		{
			if (prefixSums[i] == prefixSums[i + maxSize])
			{
				fout << maxSize;
				return 0;
			}
		}
		maxSize--;
	}

	return 0;
}
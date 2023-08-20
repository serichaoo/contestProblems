#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int numCows;

bool operator==(vector<int> a, vector<int> b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int minSwapsToRight(const vector<int>& posToHeight, int bessiePos)
{
	int currentHeight = 0;
	int numSwaps = 0;
	vector<int> currentLineup = posToHeight;
	vector<int> finalLineup = posToHeight;
	sort(finalLineup.begin(), finalLineup.end());
	int currentPos = bessiePos;
	while (currentLineup[bessiePos] > currentLineup[bessiePos + 1]) // while Bessie is taller than the one to the right move her to the right
	{
		int placeholder = currentLineup[bessiePos];
		currentLineup[bessiePos] = currentLineup[bessiePos + 1];
		currentLineup[bessiePos + 1] = placeholder;
		if (currentLineup[bessiePos] != currentHeight)
			numSwaps++;
		currentHeight = currentLineup[bessiePos];
		bessiePos++;
	}
	if (finalLineup == currentLineup)
		return numSwaps;
	else
		return 101;
}

int minSwapsToLeft(const vector<int>& posToHeight, int bessiePos)
{
	int currentHeight = 0;
	int numSwaps = 0;
	vector<int> currentLineup = posToHeight;
	vector<int> finalLineup = posToHeight;
	sort(finalLineup.begin(), finalLineup.end());
	int currentPos = bessiePos;
	while (currentLineup[bessiePos] < currentLineup[bessiePos - 1])
	{
		int placeholder = currentLineup[bessiePos];
		currentLineup[bessiePos] = currentLineup[bessiePos - 1];
		currentLineup[bessiePos - 1] = placeholder;
		if (currentLineup[bessiePos] != currentHeight)
			numSwaps++;
		currentHeight = currentLineup[bessiePos];
		bessiePos--;
	}
	if (currentLineup == finalLineup)
		return numSwaps;
	else
		return 101;
}

int main()
{
#ifndef TESTING
	ofstream fout("outofplace.out");
	ifstream fin("outofplace.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	// find Bessie, then make swaps one by one
	// if there are cows of the same height, swap Bessie with the furthest one

	vector<int> posToHeight;
	posToHeight.push_back(0);
	int bessiePos1 = -1;
	int bessiePos2 = -1;
	// to find Bessie, look for where the heights have a sudden decrease
	// move the cow on the left of the decrease to the right until it fits, then see
	// if it's sorted
	// move the cow on the right of the decrease to the left until it fits, then see if it's sorted
	// if both work, choose minimum
	fin >> numCows;
	int currentHeight = -1;
	for (int i = 0; i < numCows; i++)
	{
		int nextHeight;
		fin >> nextHeight;
		if (nextHeight < currentHeight)
		{
			bessiePos1 = i;
			bessiePos2 = i + 1;
		}
		currentHeight = nextHeight;
		posToHeight.push_back(nextHeight);
	}
	posToHeight.push_back(1000001);

	if (bessiePos1 == -1)
	{
		fout << 0;
		return 0;
	}

	int minimum = minSwapsToRight(posToHeight, bessiePos1);
	int placeholder = minSwapsToLeft(posToHeight, bessiePos2);
	if (placeholder < minimum) minimum = placeholder;

	fout << minimum;

	return 0;
}
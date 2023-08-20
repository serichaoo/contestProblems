#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int numExploded = 0;
//
//void explode(const vector<int>& hayLocations, int explodeIndex, int time)
//{
//	numExploded++;
//	int checkBelowIndex = explodeIndex - 1;
//	int checkAboveIndex = explodeIndex + 1;
//	vector<int> explodingIndices;
//	
//	while (checkBelowIndex >= 0)
//	{
//		if (hayLocations[explodeIndex] - hayLocations[checkBelowIndex] <= time)
//		{
//			explodingIndices.push_back(checkBelowIndex);
//			checkBelowIndex--;
//		}
//		else
//			break;
//	}
//	while (checkAboveIndex < hayLocations.size())
//	{
//		if (hayLocations[checkAboveIndex] - hayLocations[explodeIndex] <= time)
//		{
//			explodingIndices.push_back(checkAboveIndex);
//			checkAboveIndex++;
//		}
//	}
//
//}

int lowestIndex(const vector<int>& hayLocations, int explodeIndex, int time)
{
	int currentIndex = explodeIndex - 1;
	bool placeholder = true;
	while (currentIndex >= 0 && placeholder)
	{
		placeholder = false;
		if (hayLocations[explodeIndex] - hayLocations[currentIndex] <= time)
		{
			if (currentIndex == 0) return 0;
			currentIndex--;
			placeholder = true;
		}
	}
	if (currentIndex + 1 == explodeIndex)
		return currentIndex + 1;
	else
		return lowestIndex(hayLocations, currentIndex + 1, time + 1);
}

int highestIndex(const vector<int>& hayLocations, int explodeIndex, int time)
{
	int currentIndex = explodeIndex + 1;
	bool placeholder = true;
	while (currentIndex < hayLocations.size() && placeholder)
	{
		placeholder = false;
		if (hayLocations[currentIndex] - hayLocations[explodeIndex] <= time)
		{
			if (currentIndex == hayLocations.size() - 1) return currentIndex;
			currentIndex++;
			placeholder = true;
		}
	}
	if (currentIndex - 1 == explodeIndex)
		return currentIndex - 1;
	else
		return highestIndex(hayLocations, currentIndex - 1, time + 1);
}

int main()
{
#ifndef TESTING
	ofstream fout("angry.out");
	ifstream fin("angry.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int numBales;
	fin >> numBales;

	vector<int> hayLocations;
	for (int i = 0; i < numBales; i++)
	{
		int placeholder;
		fin >> placeholder;
		hayLocations.push_back(placeholder);
	}
	sort(hayLocations.begin(), hayLocations.end());

	int maximum = 0;
	for (int i = 0; i < hayLocations.size(); i++)
	{
		int placeholder = highestIndex(hayLocations, i, 1) - lowestIndex(hayLocations, i, 1) + 1;
		if (placeholder > maximum) maximum = placeholder;
	}

	fout << maximum;

	return 0;
}
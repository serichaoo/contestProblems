/*
ID: sericha1
TASK: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct emptyStalls
{
	int startPos;
	int length;
};

emptyStalls findLongestEmpty(int* cowPositions, int numElements)
{ // use only if number of boarded stalls > number of cows
	emptyStalls maximum;
	maximum.length = 0;
	maximum.startPos = -1;

	for (int i = 0; i < numElements - 1; i++)
	{
		if (cowPositions[i + 1] - cowPositions[i] - 1 > maximum.length)
		{
			maximum.length = cowPositions[i + 1] - cowPositions[i] - 1;
			maximum.startPos = cowPositions[i] + 1;
		}
	}
	if (maximum.startPos != -1) return maximum;
	throw(false);
}

int main()
{
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	//ostream& fout = cout;
	//istream& fin = cin;

	int totalBoards;
	int totalStalls;
	int numCows;

	fin >> totalBoards >> totalStalls >> numCows;

	int cowPositions[200];
	int numElements = numCows;

	for (int i = 0; i < numCows; i++)
		fin >> cowPositions[i];
	sort(cowPositions, cowPositions + numElements);

	int usedBoards = 1;
	int blockedStalls = cowPositions[numCows - 1] - cowPositions[0] + 1;

	while (usedBoards < totalBoards && blockedStalls > numCows)
	{
		emptyStalls placeholder = findLongestEmpty(cowPositions, numElements);
		blockedStalls -= placeholder.length;
		for (int i = 0; i < placeholder.length; i++)
		{
			cowPositions[numElements + i] = placeholder.startPos + i;
		}
		numElements += placeholder.length;
		usedBoards++;
		sort(cowPositions, cowPositions + numElements);
	}

	fout << blockedStalls << endl;

	return 0;
}

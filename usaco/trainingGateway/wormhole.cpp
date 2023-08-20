/*
ID: sericha1
TASK: wormhole
LANG: C++
*/
// if cow enters the same wormhole twice she will be in an infinite loop
// if cow's x coordinate passes the x coordinate of every wormhole she will not be in an infinite loop

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int totalCount = 0;

struct coord
{
	int xCoord;
	int yCoord;
};

vector<coord> wormholes;

struct wormholePair
{
	coord wormhole1;
	coord wormhole2;
};

const coord null{ -1, -1 };

bool compareXCoord(coord a, coord b)
{
	return (a.xCoord < b.xCoord);
}

bool operator==(coord a, coord b)
{
	return a.xCoord == b.xCoord && a.yCoord == b.yCoord;
}

coord findNextWormhole(coord currentWormhole)
{
	int nextWormholeX = -1;
	for (int i = 0; i < wormholes.size(); i++)
		if (wormholes[i].yCoord == currentWormhole.yCoord && wormholes[i].xCoord > currentWormhole.xCoord) {
			if (nextWormholeX == -1 || nextWormholeX > wormholes[i].xCoord) nextWormholeX = wormholes[i].xCoord;
		}

	if (nextWormholeX == -1) return null;
	else return { nextWormholeX, currentWormhole.yCoord };
}

coord findOppositePair(const vector<wormholePair>& pairings, coord wormhole)
{
	if (wormhole == null)
		return null;
	for (int i = 0; i < pairings.size(); i++)
	{
		if (pairings[i].wormhole1 == wormhole)
			return pairings[i].wormhole2;
		else if (pairings[i].wormhole2 == wormhole)
			return pairings[i].wormhole1;
	}
	throw(false);
}

bool willLoop(const vector<wormholePair>& pairings, coord& startingWormhole)
{
	coord position = findOppositePair(pairings, findNextWormhole(startingWormhole));
	while ((!(position == startingWormhole)) && !(position == null))
		position = findOppositePair(pairings, findNextWormhole(position));

	return (position == startingWormhole);
}

void checkPairings(const vector<wormholePair>& pairings)
{
	for (int i = 0; i < wormholes.size(); i++)
		if (willLoop(pairings, wormholes[i])) {
			totalCount++;
			return;
		}
}

void iterateThroughAllPairings(const vector<wormholePair>& currentPairings, const vector<coord>& remainingWormholes)
{
	if (remainingWormholes.size() > 0)
	{
		wormholePair newWormhole;
		for (int j = 1; j < remainingWormholes.size(); j++)
		{
			vector<wormholePair> newWormholePairings = currentPairings;
			vector<coord> newRemainingWormholes = remainingWormholes;
			newWormhole.wormhole1 = remainingWormholes[0];
			newWormhole.wormhole2 = remainingWormholes[j];
			newWormholePairings.push_back(newWormhole);
			newRemainingWormholes.erase(newRemainingWormholes.begin());
			newRemainingWormholes.erase(newRemainingWormholes.begin() + j - 1);
			iterateThroughAllPairings(newWormholePairings, newRemainingWormholes);
		}
	}
	else
		checkPairings(currentPairings);
}

int main()
{
#ifndef TESTING
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int numWormholes;
	fin >> numWormholes;
	for (int i = 0; i < numWormholes; i++)
	{
		coord placeholder;
		fin >> placeholder.xCoord;
		fin >> placeholder.yCoord;
		wormholes.push_back(placeholder);
	}
	vector<wormholePair> currentPairings;
	iterateThroughAllPairings(currentPairings, wormholes);

	fout << totalCount << endl;

	return 0;
}


/*
void insertNewWormholes(vector<vector<wormholePair>>& currentList, coord extra1, coord extra2)
{
	int currentLength = currentList.size();
	// if pairings are (1,2), (3,4) and i want to add (5,6), make the new list have
	// (1,2),(3,4),(5,6);(1,5),(2,6),(3,4); etc.
	// make the new elements pair each of the previous element, and have the second item pair with the second new wormhole
	for (int i = 0; i < currentLength; i++)
	{
		wormholePair newWormhole{};
		newWormhole.wormhole1 = extra1;
		newWormhole.wormhole2 = extra2;
		for (int j = 0; j < currentLength; i++)
		{
			coord placeholder;
			newWormhole.wormhole1 =
		}
	}
}
*/
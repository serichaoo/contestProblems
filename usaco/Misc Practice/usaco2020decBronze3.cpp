#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct cow
{
	bool isN;
	int xCoord;
	int yCoord;
	int minDistanceUntilBlock;
	int index;
};

void willBlock(cow& a, cow& b) // need to fix by checking the length that each cow travels and seeing if they intersect
// note: a will always be ahead of b or at the same position
{// if the directions are parallel
	if (a.xCoord + a.yCoord > b.xCoord + b.yCoord)
	{
		if (a.isN == b.isN)
		{
			if (a.isN == true)
			{
				if (a.xCoord == b.xCoord)
				{
					if (b.yCoord < a.yCoord)
						if (b.minDistanceUntilBlock > a.yCoord - b.yCoord)
							b.minDistanceUntilBlock = a.yCoord - b.yCoord;
					return;
				}
			}
			else if (a.yCoord == b.yCoord)
			{
				if (b.xCoord < a.xCoord)
					if (b.minDistanceUntilBlock > a.xCoord - b.xCoord)
						b.minDistanceUntilBlock = a.xCoord - b.xCoord;
				return;
			}
			return;
		}

		else // if the directions are perpendicular
		{
			if (b.isN)
			{
				if (a.xCoord <= b.xCoord && a.xCoord + a.minDistanceUntilBlock > b.xCoord)
					if (b.minDistanceUntilBlock > a.yCoord - b.yCoord)
						b.minDistanceUntilBlock = a.yCoord - b.yCoord;
				return;
			}
			else // if b goes east and a goes north
			{
				if (a.yCoord <= b.yCoord && a.yCoord + a.minDistanceUntilBlock > b.yCoord)
					if (b.minDistanceUntilBlock > a.xCoord - b.xCoord)
						b.minDistanceUntilBlock = a.xCoord - b.xCoord;
			}
		}
	}
}

bool comparePrecedence(cow a, cow b)
{
	return (a.xCoord + a.yCoord > b.xCoord + b.yCoord);
}

bool unsort(cow a, cow b)
{
	return a.index < b.index;
}

int main()
{
	//ofstream fout("censor.out");
	//ifstream fin("censor.in");
	//ostream& fout = cout;
	//istream& fin = cin;

	vector<cow> cows;
	int numCows;
	cin >> numCows;

	for (int i = 0; i < numCows; i++)
	{
		cow newCow;
		char placeholder;
		cin >> placeholder;
		if (placeholder == 'N')
			newCow.isN = true;
		else
			newCow.isN = false;
		cin >> newCow.xCoord >> newCow.yCoord;
		newCow.minDistanceUntilBlock = 1000000001;
		newCow.index = i;
		cows.push_back(newCow);
	}

	sort(cows.begin(), cows.end(), comparePrecedence);

	for (int i = 0; i < numCows; i++)
	{
		for (int j = i + 1; j < numCows; j++)
		{
			willBlock(cows[i], cows[j]);
		}
	}

	sort(cows.begin(), cows.end(), unsort);

	for (int i = 0; i < numCows; i++)
	{
		if (cows[i].minDistanceUntilBlock == 1000000001)
			cout << "Infinity" << endl;
		else
			cout << cows[i].minDistanceUntilBlock << endl;
	}

	return 0;
}

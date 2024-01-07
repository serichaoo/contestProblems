#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int numPastures;
int numCows;
vector<vector<int>> possiblePlantings(vector<int>(numPastures));
vector<vector<int>> cowsThatPrefer(numPastures); // cowsThatPrefer[i] gives vector of all cows that prefer pasture i
vector<vector<int>> preferredPastures(numCows); // preferredPastures[i] gives the two pastures that cow i prefers

string intVectorToString(vector<int> ints)
{
	string s = "";
	for (int i = 0; i < ints.size(); i++)
	{
		char c = ints[i];
		s += (c + '0');
	}
	return s;
}

void search(vector<int> pastureType, vector<int> filledPastures)
{// first check if any cow uses two of the same type of grass, if so then return
	// iterate through all cows from filled pastures
	// for each cow, go to its other preferred pasture and fill it (iterate through fillings)
	// then recurse
	for (int i = 0; i < numCows; i++) // check if cows are all good
	{ // preferredPastures[i] gives the two preferred pastures
		int a = preferredPastures[i][0];
		int b = preferredPastures[i][1];
		if ((a == b) && (a != -1) && (b != -1))
			return;
	}
	for (int i = 0; i < filledPastures.size(); i++)
	{ // see if any cows don't have the other preferred one filled yet

	}

}

int main()
{
#ifndef TESTING
	ofstream fout("revegetate.out");
	ifstream fin("revegetate.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	//fout << intVectorToString(vector<int>{1, 2, 3, 4, 5});
	fin >> numPastures >> numCows;
	for (int i = 0; i < numCows; i++)
	{
		int a, b;
		fin >> a >> b;
		cowsThatPrefer[a - 1].push_back(i);
		cowsThatPrefer[b - 1].push_back(i);
		preferredPastures[i].push_back(a - 1);
		preferredPastures[i].push_back(b - 1);
	}
	vector<int> pastureType(numPastures, -1);
	vector<int> filledPastures;
}

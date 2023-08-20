#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

struct farm
{
	int index;
	int colour = -1;
};

bool isIn(int a, vector<int> b)
{
	for (int i = 0; i < b.size(); i++)
		if (a == b[i]) return true;
	return false;
}

int main()
{
#ifndef TESTING
	ofstream fout("planting.out");
	ifstream fin("planting.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int numFarms;
	fin >> numFarms;
	vector<vector<int>> edgeList(numFarms); // edgeList[k] gives all farms connected to farm k

	for (int i = 0; i < numFarms - 1; i++)
	{
		int farm1, farm2;
		fin >> farm1 >> farm2;
		farm1--; farm2--;
		edgeList[farm1].push_back(farm2);
		edgeList[farm2].push_back(farm1);
	}

	//vector<vector<int>> fullEdgeList(numFarms);
	//// creates an edge list of all adjacent and distance-2 paths between nodes
	//for (int i = 0; i < numFarms; i++)
	//	for (int j = 0; j < edgeList[i].size(); j++)
	//	{
	//		fullEdgeList[i].push_back(edgeList[i][j]);
	//		for (int k = 0; k < edgeList[edgeList[i][j]].size(); k++)
	//			if (!isIn(edgeList[edgeList[i][j]][k], fullEdgeList[i]))
	//				fullEdgeList[i].push_back(edgeList[edgeList[i][j]][k]);
	//	}

	//vector<int> farmColour(numFarms, -1); // farmColour[index] gives colour

	/*for (int i = 0; i < numFarms; i++)
	{
		farmColour[i] = 0;
		bool placeholder = true;
		while (placeholder)
		{
			placeholder = false;
			for (int j = 0; j < fullEdgeList[i].size(); j++)
				if (farmColour[i] == farmColour[fullEdgeList[i][j]])
					farmColour[i]++;
		}
	}*/

	int maximum = 0;
	for (int i = 0; i < numFarms; i++)
		if (edgeList[i].size() > maximum) maximum = edgeList[i].size();

	fout << maximum + 1;

	/*for (int i = 0; i < numFarms; i++)
	{
		cout << i << ':';
		for (int j = 0; j < fullEdgeList[i].size(); j++)
			cout << fullEdgeList[i][j] << ' ';
		cout << endl;
	}*/
	return 0;
}
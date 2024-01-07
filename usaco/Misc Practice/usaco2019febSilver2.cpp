#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int nCoatsPerSquare[1002][1002]{ 0 }; // [x][y]
int invPreSum[1002][1002]{ 0 }; // [x][y]

int main()
{
#ifndef TESTING
	ofstream fout("paintbarn.out");
	ifstream fin("paintbarn.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int nRectangles, wantedOverlap;
	fin >> nRectangles >> wantedOverlap;

	for (int i = 0; i < nRectangles; i++)
	{
		int x1, y1, x2, y2;
		fin >> x1 >> y1 >> x2 >> y2;
		invPreSum[x1][y1]++;
		invPreSum[x1][y2]--;
		invPreSum[x2][y1]--;
		invPreSum[x2][y2]++;
	}

	int totalArea = 0;

	for (int i = 1; i <= 1001; i++)
		for (int j = 1; j <= 1001; j++)
		{
			nCoatsPerSquare[i][j] = nCoatsPerSquare[i][j - 1] + nCoatsPerSquare[i - 1][j]
				- nCoatsPerSquare[i - 1][j - 1] + invPreSum[i - 1][j - 1];
			if (nCoatsPerSquare[i][j] == wantedOverlap) totalArea++;
		}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//		cout << nCoatsPerSquare[j][i] << ' ';
	//	cout << endl;
	//}

	fout << totalArea;

	return 0;
}
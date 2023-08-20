/*
ID: sericha1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// build from bottom up somehow
vector<vector<int>> triangle(1000, vector<int>(1000)); // triangle[row number][element in row]

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

void removeRow()
{
	for (int i = 0; i < triangle.size() - 1; i++)
	{
		triangle[triangle.size() - 2][i] += max(triangle[triangle.size() - 1][i], triangle[triangle.size() - 1][i + 1]);
	}
	triangle.pop_back();
}

int main()
{
#ifndef TESTING
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif

	int numRows;
	fin >> numRows;

	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < i + 1; j++)
			fin >> triangle[i][j];

	while (triangle.size() > 1)
		removeRow();

	fout << triangle[0][0] << endl;

	return 0;
}

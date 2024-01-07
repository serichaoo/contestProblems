#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
#ifndef TESTING
	ofstream fout("lazy.out");
	ifstream fin("lazy.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int fieldSize, nSteps;
	fin >> fieldSize >> nSteps;

	vector<vector<int>> field(fieldSize + 2 * nSteps + 1, vector<int>(fieldSize + 2 * nSteps, 0));
	for (int i = 0; i < fieldSize; i++)
		for (int j = 0; j < fieldSize; j++)
			fin >> field[i + nSteps][j + nSteps];

	//for (int i = 0; i < fieldSize + 2 * nSteps; i++)
	//{
	//	for (int j = 0; j < fieldSize + 2 * nSteps; j++)
	//		fout << field[i][j] << ' ';
	//	fout << endl;
	//}

	vector<vector<int>> pSum(fieldSize + 2 * nSteps + 2, vector<int>(fieldSize + 2 * nSteps + 2, 0));
	//each element gives the total sum of the pyramid pointing down with the element as its vertex
	for (int i = 2; i <= fieldSize + 2 * nSteps + 1; i++)
	{
		pSum[i][0] = pSum[i - 1][1];
		pSum[i][fieldSize + 2 * nSteps + 1] = pSum[i - 1][fieldSize + 2 * nSteps];
		for (int j = 1; j <= fieldSize + 2 * nSteps; j++)
			pSum[i][j] = pSum[i - 1][j - 1] + pSum[i - 1][j + 1] - pSum[i - 2][j]
			+ field[i - 2][j - 1] + field[i - 1][j - 1];
	}
	/*fout << endl;
	for (int i = 0; i < fieldSize + 2 * nSteps + 2; i++)
	{
		for (int j = 0; j < fieldSize + 2 * nSteps + 2; j++)
			fout << pSum[i][j] << ' ';
		fout << endl;
	}*/

	vector<vector<int>> doublePSum(fieldSize + 2 * nSteps + 2, vector<int>(fieldSize + 2 * nSteps + 1, 0));
	for (int i = 2; i <= fieldSize + 2 * nSteps + 1; i++)
	{
		doublePSum[i][0] = pSum[i][1] + field[i - 1][0];
		doublePSum[i][fieldSize + 2 * nSteps] = pSum[i][fieldSize + 2 * nSteps]
			+ field[i - 2][fieldSize + 2 * nSteps - 1];
		for (int j = 1; j < fieldSize + 2 * nSteps; j++)
			doublePSum[i][j] = doublePSum[i - 1][j - 1] + doublePSum[i - 1][j + 1] - doublePSum[i - 2][j]
			+ field[i - 1][j - 1] + field[i - 1][j];
	}
	/*fout << endl;
	for (int i = 0; i < fieldSize + 2 * nSteps + 2; i++)
	{
		for (int j = 0; j < fieldSize + 2 * nSteps + 1; j++)
			fout << doublePSum[i][j] << ' ';
		fout << endl;
	}*/

	int maximum = 0;
	for (int i = 0; i < fieldSize; i++)
		for (int j = 0; j < fieldSize; j++)
		{
			int centerY = nSteps + 1 + i; // pSum[centerY][centerX]
			int centerX = nSteps + 1 + j;
			int placeholder;
			if (nSteps != 0)
			{
				placeholder = pSum[centerY + nSteps][centerX]
					- doublePSum[centerY - 1][centerX + nSteps]
					- doublePSum[centerY - 1][centerX - nSteps - 1]
					+ pSum[centerY - nSteps - 1][centerX];
			}
			else
				placeholder = field[i][j];
			if (placeholder > maximum) maximum = placeholder;
		}
	fout << maximum;
	return 0;
}
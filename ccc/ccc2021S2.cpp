#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<int, bool> paintedRow;
	map<int, bool> paintedColumn;
	int nRows;
	int nColumns;
	int nPaints;
	cin >> nRows >> nColumns >> nPaints;
	for (int i = 0; i < nPaints; i++)
	{
		char ROrC;
		cin >> ROrC;
		if (ROrC == 'R')
		{
			int rNumber;
			cin >> rNumber;
			if (paintedRow[rNumber])
				paintedRow.erase(rNumber);
			else
				paintedRow[rNumber] = true;
		}
		else
		{
			int cNumber;
			cin >> cNumber;
			if (paintedColumn[cNumber])
				paintedColumn.erase(cNumber);
			else
				paintedColumn[cNumber] = true;
		}
	}
	vector<int> rPainted;
	vector<int> cPainted;
	for (auto i : paintedRow)
	{
		rPainted.push_back(i.first);
	}
	for (auto i : paintedColumn)
	{
		cPainted.push_back(i.first);
	}
	int ans = (rPainted.size() * (nColumns - cPainted.size())) + (cPainted.size() * (nRows - rPainted.size()));
	cout << ans;
}

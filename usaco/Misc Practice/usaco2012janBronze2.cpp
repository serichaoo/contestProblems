#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

short int increaseOrDecrease[1000002]{ 0 };

int main()
{
	//#ifndef TESTING
		//	ofstream fout("stacking.out");
		//	ifstream fin("stacking.in");
		//#else
		//	ostream& fout = cout;
		//	istream& fin = cin;
	//#endif
	int nBales, nInstructions;
	cin >> nBales >> nInstructions;
	for (int i = 0; i < nInstructions; i++)
	{
		int a, b;
		cin >> a >> b;
		increaseOrDecrease[a]++;
		increaseOrDecrease[b + 1]--;
	}
	vector<short int> bayStacks(nBales + 1);
	for (int i = 1; i <= nBales; i++)
	{
		bayStacks[i] = bayStacks[i - 1] + increaseOrDecrease[i];
	}
	sort(bayStacks.begin() + 1, bayStacks.end());
	cout << bayStacks[(1 + nBales) / 2];

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main()
{
	int nIntervals, range;
	cin >> nIntervals >> range;
	vector<int> revPrefixSum(2 * range + 2, 0);
	vector<int> startValues;
	vector<int> endValues;
	for (int i = 0; i < nIntervals; i++)
	{
		int a, b;
		cin >> a >> b;
		startValues.push_back(a);
		endValues.push_back(b);
	}

	for (int i = 0; i < nIntervals; i++)
		for (int j = 0; j < nIntervals; j++)
		{
			int intervalStart = startValues[i] + startValues[j];
			int intervalEnd = endValues[i] + endValues[j] + 1;
			revPrefixSum[intervalStart]++;
			revPrefixSum[intervalEnd]--;
		}

	int currentValue = 0;
	for (int i = 0; i < 2 * range + 1; i++)
	{
		currentValue += revPrefixSum[i];
		cout << currentValue;
		if (i != 2 * range) cout << endl;
	}
	return 0;
}
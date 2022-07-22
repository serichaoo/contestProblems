#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
// soulmates

using namespace std;
using ll = long long;
int searchDepth = 0;
bool match = false;

void dfs(ll personality1, ll personality2, int depth)
{
	if (match)
		return;
	if (depth > searchDepth)
		return;
	if (personality1 == personality2)
	{
		match = true;
		return;
	}
	else
	{
		dfs(personality1 + 1, personality2, depth + 1);
		if (personality1 < personality2)
			dfs(personality1 * 2, personality2, depth + 1);
		if (personality1 % 2 == 0)
			dfs(personality1 / 2, personality2, depth + 1);
	}
}

int main()
{
	int nPairs;
	cin >> nPairs;
	ll personality1, personality2;
	for (int i = 0; i < nPairs; i++)
	{
		cin >> personality1 >> personality2;
		while (!match)
		{
			dfs(personality1, personality2, 0);
			searchDepth++;
		}
		cout << searchDepth - 1 << endl;
		searchDepth = 0;
		match = false;
	}

	return 0;
}

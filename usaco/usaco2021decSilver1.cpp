#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
//closest cow wins
// use ordered set to store farm locations and enemy cows
// use lower bound and upper bound to find nearest enemy cow
using namespace std;
using ll = long long;

struct patch
{
	int index;
	int location;
	int tastiness;
	int distFromEnemy;
};
bool operator<(patch a, patch b)
{
	return a.location < b.location;
}

int main()
{
	int nPatches, nEnemies, nGood;
	cin >> nPatches >> nEnemies >> nGood;
	vector<patch> patches;
	for (int i = 1; i < nPatches + 1; i++)
	{
		patch a;
		cin >> a.location >> a.tastiness;
		patches.push_back({ i, a.location * 2, a.tastiness, 1000000001 });
	}
	vector<int> enemyLocations;
	for (int i = 0; i < nEnemies; i++)
	{
		int a; cin >> a;
		enemyLocations.push_back(a * 2);
	}

	vector<int> patchRanges;
	map<int, vector<int>> whichPatchesStartAtWhichLocations; //map[location] = vector of patches
	for (int i = 1; i < nPatches + 1; i++)
	{
		int location = patches[i].location;
		int lower = *lower_bound(enemyLocations.begin(), enemyLocations.end(), location);
		int upper = *upper_bound(enemyLocations.begin(), enemyLocations.end(), location);
		int min = std::min(upper - location, location - lower) - 1;
		if (min == -1)
		{
			patches.erase(patches.begin() + i);
			i--;
			nPatches--;
		}
		else
		{
			patchRanges.push_back(min);
			whichPatchesStartAtWhichLocations[lower].push_back(i);
			whichPatchesStartAtWhichLocations[upper + 1].push_back(-i);
		}
	}

	ll ans = 0;

	for (int i = 0; i < nGood; i++)
	{
		vector<int> patchesBeingUsed;
		ll currentValue = 0;
		ll maxValue = 0;
		vector<int> maxPatchesUsedValue;
		for (auto it : whichPatchesStartAtWhichLocations)
		{//it.second is vector of all patches
			for (int j = 0; j < it.second.size(); j++)
			{
				if (it.second[j] > 0)
				{
					currentValue += patches[it.second[j]].tastiness;
					patchesBeingUsed.push_back(it.second[j]);
				}
				else
				{
					currentValue -= patches[it.second[j]].tastiness;
					patchesBeingUsed.erase(remove(patchesBeingUsed.begin(), patchesBeingUsed.end(), it.second[j]), patchesBeingUsed.end());
				}
				if (currentValue > maxValue)
				{
					maxValue = currentValue;
					maxPatchesUsedValue = patchesBeingUsed;
				}
			}
		}
		ans += maxValue;
		for (int j = 0; j < maxPatchesUsedValue.size(); j++)
		{ // need to remove it from patches and undo its effect on the whichPatchesStartAtWhichLocations
			int index = maxPatchesUsedValue[j];
			int location = patches[index].location;
			int range = patchRanges[index];
			whichPatchesStartAtWhichLocations[location - range].erase(
				remove(whichPatchesStartAtWhichLocations[location - range].begin(),
					whichPatchesStartAtWhichLocations[location - range].end(), index),
				whichPatchesStartAtWhichLocations[location - range].end());
			if (whichPatchesStartAtWhichLocations[location - range].size() == 0)
				whichPatchesStartAtWhichLocations.erase(location - range);
			whichPatchesStartAtWhichLocations[location + range + 1].erase(
				remove(whichPatchesStartAtWhichLocations[location + range + 1].begin(),
					whichPatchesStartAtWhichLocations[location + range + 1].end(), index),
				whichPatchesStartAtWhichLocations[location + range + 1].end());
			if (whichPatchesStartAtWhichLocations[location + range + 1].size() == 0)
				whichPatchesStartAtWhichLocations.erase(location + range + 1);
		}
	}
	cout << ans;
	return 0;





	//	int nPatches, nEnemies, nGood;
	//	cin >> nPatches >> nEnemies >> nGood;
	//	map<int, int> patches; // location, tastiness
	//	map<int, int> patchEffectiveRange; // location, effectiveRange
	//	// effective range is the range where if you place a cow in it, you'll get the patch
	//	// get patches
	//	for (int i = 0; i < nPatches; i++)
	//	{
	//		patch a;
	//		cin >> a.location >> a.tastiness;
	//		a.location *= 2;
	//		patches.insert({ a.location,a.tastiness });
	//	}
	//	// get enemy locations
	//	set<int> enemyLocations;
	//	for (int i = 0; i < nEnemies; i++)
	//	{
	//		int a;
	//		cin >> a;
	//		a *= 2;
	//		enemyLocations.insert(a);
	//	}
	//	// get patch ranges
	//	for (auto it = patches.begin(); it != patches.end(); it++)
	//	{
	//		int lower = *enemyLocations.lower_bound(it->first);
	//		int upper = *enemyLocations.upper_bound(it->first);
	//		int location = it->first;
	//		patchEffectiveRange.insert(it->first, std::max(upper - location, location - lower) - 1);
	//		if (patchEffectiveRange[location] == -1)
	//		{
	//			patches.erase(location);
	//			patchEffectiveRange.erase(location);
	//		}
	//	}
	//
	//	map<int, int> location; // location[t] gives a pair of location, tastiness added
	//	map<int, vector<int>> patchStartEndTimes;
	//
	//	ll ans = 0;
	//
	//	for (int i = 0; i < nGood; i++)
	//	{
	//
	//		for (auto it : patches)
	//		{
	//			int tStart = it.first - patchEffectiveRange[it.first];
	//			int tEnd = it.first + patchEffectiveRange[it.first];
	//			location[tStart] += it.second;
	//			patchStartEndTimes[tStart].push_back(it.first);
	//			location[tEnd] -= it.second;
	//			patchStartEndTimes[tEnd].push_back(-it.first);
	//		}
	//
	//
	//		ll max = 0;
	//		set<int> currentPatches;
	//		set<int> maxPatches;
	//		int currentValue = 0;
	//		for (auto it : location)
	//		{
	//			currentValue += it.second;
	//			for (int i = 0; i < patchStartEndTimes[it.first].size(); i++)
	//			{
	//				if (patchStartEndTimes[it.first][i] > 0)
	//				{
	//					currentPatches.insert(patchStartEndTimes[it.first][i]);
	//				}
	//				else
	//					currentPatches.erase(-patchStartEndTimes[it.first][i]);
	//			}
	//			if (currentValue > max)
	//			{
	//				max = currentValue;
	//				maxPatches = currentPatches;
	//			}
	//		}
	//		ans += max;
	//		for (auto it : maxPatches)
	//		{
	//			patches.erase(it);
	//		}
	//	}
	//	cout << ans;
	//	return 0;
}
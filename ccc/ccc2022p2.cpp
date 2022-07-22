#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<string, int> nameToIndex;

bool isInSameGroup(string a, string b)
{
	if (nameToIndex[a] / 3 == nameToIndex[b] / 3)
		return true;
	return false;
}

int main()
{
	int togetherPairs;
	cin >> togetherPairs;
	vector<pair<string, string>> togetherPairings;
	for (int i = 0; i < togetherPairs; i++)
	{
		string a, b;
		cin >> a >> b;
		togetherPairings.push_back({ a,b });
	}
	int separatePairs;
	cin >> separatePairs;
	vector<pair<string, string>> separatePairings;
	for (int i = 0; i < separatePairs; i++)
	{
		string a, b;
		cin >> a >> b;
		separatePairings.push_back({ a,b });
	}
	int nGroups;
	cin >> nGroups;
	int nameIndex = 0;
	for (int i = 0; i < 3 * nGroups; i++)
	{
		string a;
		cin >> a;
		nameToIndex[a] = nameIndex;
		nameIndex++;
	}
	int nViolations = 0;
	for (int i = 0; i < togetherPairings.size(); i++)
		if (!isInSameGroup(togetherPairings[i].first, togetherPairings[i].second))
			nViolations++;
	for (int i = 0; i < separatePairings.size(); i++)
		if (isInSameGroup(separatePairings[i].first, separatePairings[i].second))
			nViolations++;
	cout << nViolations;
	return 0;


	//int currentNameIndex = 1;
	//map<int, vector<int>> mustWorkTogether;
	//int nMustWorkTogethers;
	//cin >> nMustWorkTogethers;
	//for (int i = 0; i < nMustWorkTogethers; i++)
	//{
	//    string a, b;
	//    cin >> a >> b;
	//    if (nameToIndex[a] == 0)
	//    {
	//        nameToIndex[a] = currentNameIndex;
	//        currentNameIndex++;
	//    }
	//    if (nameToIndex[b] == 0)
	//    {
	//        nameToIndex[b] = currentNameIndex;
	//        currentNameIndex++;
	//    }
	//    mustWorkTogether[nameToIndex[a]].push_back(nameToIndex[b]);
	//    mustWorkTogether[nameToIndex[b]].push_back(nameToIndex[a]);
	//}
	//int nMustNotWorkTogethers;
	//cin >> nMustNotWorkTogethers;
	//map<int, vector<int>> mustNotWorkTogether;
	//for (int i = 0; i < nMustNotWorkTogethers; i++)
	//{
	//    string a, b;
	//    cin >> a >> b;
	//    if (nameToIndex[a] == 0)
	//    {
	//        nameToIndex[a] = currentNameIndex;
	//        currentNameIndex++;
	//    }
	//    if (nameToIndex[b] == 0)
	//    {
	//        nameToIndex[b] = currentNameIndex;
	//        currentNameIndex++;
	//    }
	//    mustNotWorkTogether[nameToIndex[a]].push_back(nameToIndex[b]);
	//    mustNotWorkTogether[nameToIndex[b]].push_back(nameToIndex[a]);
	//}

}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;
using ll = long long;

vector<int> wantGo(1e5);
vector<vector<int>> wantGoRev(1e5); // gives list of all cows that want to go to certain cow's place
vector<vector<int>> adjList(1e5);
vector<int> nMoos(1e5);
vector<int> compOfCow(1e5, -1);
vector<vector<int>> comps;
bool isAllUnique = true;

void dfs(int cow, int colour)
{
	if (compOfCow[cow] != -1)
		return;
	compOfCow[cow] = colour;
	comps[colour].push_back(cow);
	for (int i = 0; i < adjList[cow].size(); i++)
		dfs(adjList[cow][i], colour);
}

void traverseTree(int cow, int root, vector<int>& allIn)
{
	for (int i = 0; i < wantGoRev[cow].size(); i++)
	{
		int newCow = wantGoRev[cow][i];
		if (newCow != root)
		{
			allIn.push_back(newCow);
			traverseTree(newCow, root, allIn);
		}
	}
}

ll maximize(vector<int> comp)
{// root at each vertex
	// actually, find the cycle and cut the minimum edge of the cycle
	if (isAllUnique)
	{
		ll max = 0;
		int min = 1e9 + 1;
		for (int i = 0; i < comp.size(); i++)
		{
			max += nMoos[comp[i]];
			min = std::min(min, nMoos[comp[i]]);
		}
		return max - min;
	}
	int node = comp[0];
	unordered_set<int> visitedNodes;
	while (!visitedNodes.count(node))
	{
		visitedNodes.insert(node);
		node = wantGo[node];
	}
	unordered_set<int> cyclicNodes;
	while (!cyclicNodes.count(node))
	{
		cyclicNodes.insert(node);
		node = wantGo[node];
	}
	ll max = 0;
	int min = 1e9 + 1;
	for (int i = 0; i < comp.size(); i++)
	{
		max += nMoos[comp[i]];
		if (cyclicNodes.count(comp[i]))
			min = std::min(min, nMoos[comp[i]]);
	}
	return max - min;

	//ll max = 0;
	//for (int i = 0; i < comp.size(); i++)
	//{
	//	int root = comp[i];
	//	vector<int> allIn;
	//	traverseTree(root, root, allIn);
	//	ll tempMax = 0;
	//	for (int i = 0; i < allIn.size(); i++)
	//		tempMax += nMoos[allIn[i]];
	//	max = std::max(max, tempMax);
	//}
	//return max;
}

int main()
{
	int n;
	cin >> n;
	vector<bool> doesAnyCowWantToGoThere(n, false);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		wantGo[i] = a - 1;
		if (!doesAnyCowWantToGoThere[a - 1])
			doesAnyCowWantToGoThere[a - 1] = true;
		else
			isAllUnique = false;
		wantGoRev[a - 1].push_back(i);
		nMoos[i] = b;
		adjList[i].push_back(a - 1);
		adjList[a - 1].push_back(i);
	}
	int currentColour = 0;
	for (int i = 0; i < n; i++)
		if (compOfCow[i] == -1)
		{
			comps.push_back(vector<int> {});
			dfs(i, currentColour);
			currentColour++;
		}
	ll ans = 0;
	for (int i = 0; i < comps.size(); i++)
	{
		ans += maximize(comps[i]);
	}
	cout << ans;

	return 0;
}
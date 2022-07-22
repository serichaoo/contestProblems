#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<int>> adjList(2e5 + 1);
int n;
set<int> nodes;
vector<vector<int>> rootedTree(2e5 + 1); //rootedTree[k] gives all nodes at depth k
vector<bool> alreadyChecked(2e5 + 1, false);
map<int, int> toAncestor;
int maxDepth = 0;
int maxDepthNode;
void root(int node, int old, int depth)
{
	if (alreadyChecked[node])
		return;
	alreadyChecked[node] = true;
	rootedTree[depth].push_back(node);
	toAncestor[node] = old;
	if (nodes.count(node) >= 1)
	{
		if (depth > maxDepth)
		{
			maxDepth = depth;
			maxDepthNode = node;
		}
	}
	for (int i = 0; i < adjList[node].size(); i++)
	{
		root(adjList[node][i], node, depth + 1);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a - 1].push_back(b - 1);
		adjList[b - 1].push_back(a - 1);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int k;
		cin >> k;
		nodes.clear();
		int a;
		for (int i = 0; i < k; i++)
		{
			cin >> a;
			a--;
			nodes.insert(a);
		}
		maxDepthNode = a;
		root(a, a, 0);
		toAncestor[a] = a;
		set<int> path;
		alreadyChecked = vector<bool>(2e5 + 1, false);
		toAncestor.clear();
		rootedTree = vector<vector<int>>(2e5 + 1);
		maxDepth = 0;
		root(maxDepthNode, maxDepthNode, 0);
		for (int i = 0; i <= maxDepth; i++)
		{
			path.insert(maxDepthNode);
			maxDepthNode = toAncestor[maxDepthNode];
		}
		bool placeholder = true;
		for (auto x : nodes)
		{
			if (path.count(x) == 0)
				placeholder = false;
		}
		if (placeholder)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		alreadyChecked = vector<bool>(2e5 + 1, false);
		toAncestor.clear();
		rootedTree = vector<vector<int>>(2e5 + 1);
		maxDepth = 0;
	}
	return 0;
}

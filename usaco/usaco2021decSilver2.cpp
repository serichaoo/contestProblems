#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

void floodFill(const vector<vector<int>>& adjList, vector<int>& colours, int currentField, int currentColour)
{
	if (colours[currentField] == -1)
	{
		colours[currentField] = currentColour;
		for (int i = 0; i < adjList[currentField].size(); i++)
		{
			floodFill(adjList, colours, adjList[currentField][i], currentColour);
		}
	}
}

bool search(int highestColour, const vector<vector<int>>& connectCost, int currentColour, int wantedColour, int remainingBudget)
{
	if (currentColour == wantedColour)
		return true;
	bool placeholder = false;
	for (int i = 0; i < connectCost[currentColour].size(); i++)
	{
		if (i != currentColour && connectCost[currentColour][i] <= remainingBudget && (!placeholder))
		{
			if (search(highestColour, connectCost, i, wantedColour, remainingBudget - connectCost[currentColour][i]))
				placeholder = true;
		}
	}
	return placeholder;
}

int main()
{
	int nRepetitions;
	cin >> nRepetitions;
	for (int i = 0; i < nRepetitions; i++)
	{
		int nFields, nPaths;
		cin >> nFields >> nPaths;
		vector<vector<int>> adjList(nFields); // adjList[i] gives all fields adjacent to field i
		vector<int> colours(nFields, -1);

		// fill adjacency list
		for (int j = 0; j < nPaths; j++)
		{
			int f1, f2;
			cin >> f1 >> f2;
			adjList[f1 - 1].push_back(f2 - 1);
			adjList[f2 - 1].push_back(f1 - 1);
		}

		int highestColour = 0;
		bool placeholder = true;

		//floodfill algorithm
		while (placeholder)
		{
			placeholder = false;
			for (int i = 0; i < nFields; i++)
			{
				if (colours[i] == -1)
				{
					placeholder = true;
					floodFill(adjList, colours, i, highestColour);
					highestColour++;
				}
			}
		}
		int wantedColour = colours[nFields - 1];
		adjList = { {} };

		// want to go from colour 0 to colour colours[nFields-1]
		vector<vector<int>> fieldsWithColour(highestColour); // fieldsWithColour[i] gives all fields with colour i
		for (int i = 0; i < nFields; i++)
		{
			fieldsWithColour[colours[i]].push_back(i);
		}

		vector<vector<int>> connectCost(highestColour, vector<int>(highestColour)); // connectCost[i][j] gives cost of connecting islands of colour i and j
		for (int i = 0; i < highestColour; i++)
			for (int j = i + 1; j < highestColour; j++)
			{
				int min = INT8_MAX;
				for (int k = 0; k < fieldsWithColour[i].size(); k++)
				{
					int current = fieldsWithColour[i][k];
					auto lower = lower_bound((fieldsWithColour[j]).begin(), fieldsWithColour[j].end(), current);
					auto upper = upper_bound((fieldsWithColour[j]).begin(), fieldsWithColour[j].end(), current);
					if (lower != fieldsWithColour[j].end())
						min = std::min(min, (current - *lower) * (current - *lower));
					if (upper != fieldsWithColour[j].end())
						min = std::min(min, (*upper - current) * (*upper - current));
				}
				connectCost[i][j] = min;
				connectCost[j][i] = min;
			}
		// now, costs are all calculated. Do depth first search with iterative deepening on cost
		fieldsWithColour = { {} };
		colours = { {} };

		bool pathFound = false;
		int budget = 0;
		while (!pathFound) // look for path from 0 to colours[nFields-1]
		{
			pathFound = search(highestColour, connectCost, 0, wantedColour, budget);
			budget++;
		}
		cout << budget - 1;
		if (i != nRepetitions - 1)
			cout << endl;
	}
	return 0;
}
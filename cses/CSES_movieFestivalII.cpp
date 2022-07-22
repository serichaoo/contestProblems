#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

bool operator<(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return (a.second < b.second);
	else
		return a.first < b.first;
}

int main()
{
	vector<pair<int, int>> movies;
	int nMovies, nFriends;
	cin >> nMovies >> nFriends;
	vector<int> currentTimes(nFriends, 0);
	for (int i = 0; i < nMovies; i++)
	{
		pair<int, int> movie;
		cin >> movie.first >> movie.second;
		movies.push_back(movie);
	}
	sort()
		int currentFriend = 0;
	while (true)
	{// find movie after current time with closest end time
		auto it = movies.upper_bound({ 0, currentTimes[currentFriend] });
		currentTimes[currentFriend] = it->second;
	}
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct friends
{
	ll position;
	ll walkingSpeed;
	ll hearingDistance;
};

vector<friends> allFriends;

ll sumTimes(ll location)
{
	ll ans = 0;
	for (int i = 0; i < allFriends.size(); i++)
	{
		ll travelDistance = abs(location - allFriends[i].position) - allFriends[i].hearingDistance;
		if (travelDistance > 0)
			ans += travelDistance * allFriends[i].walkingSpeed;
	}
	return ans;
}

int main()
{
	int nFriends;
	cin >> nFriends;
	vector<ll> posToSearch;
	for (int i = 0; i < nFriends; i++)
	{
		ll pos, speed, hearing;
		cin >> pos >> speed >> hearing;
		allFriends.push_back({ pos, speed, hearing });
		posToSearch.push_back(pos - hearing);
		posToSearch.push_back(pos + hearing);
	}
	sort(posToSearch.begin(), posToSearch.end());
	int lowerBound = 0;
	int upperBound = posToSearch.size() - 1;
	int currentValue = (lowerBound + upperBound) / 2;
	while (lowerBound != upperBound)
	{
		int currentSum = sumTimes(currentValue);
		int lowerValue = sumTimes((lowerBound + currentValue) / 2);
		if (lowerValue < currentValue)
		{
			upperBound = currentValue;
			continue;
		}

		int upperValue = (currentValue + upperBound + 1) / 2;

	}
}
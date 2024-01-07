#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;

struct cow
{
	int height;
	int location;

};



bool operator<(cow a, cow b)
{
	if (a.location != b.location)
		return a.location < b.location;
	return a.height > b.height;
}

int main()
{
	int nCows;
	cin >> nCows;
	set<cow> cows; // based on position
	map<int, int> heightToLocation;
	ll ans = 0;
	for (int i = 0; i < nCows; i++)
	{
		int height;
		cin >> height;
		heightToLocation[height] = i;
		cows.insert({ height, i });
	}
	std::cout << (--cows.begin() == cows.end());
	for (int i = 0; i < nCows; i++)
	{
		int location = heightToLocation[i + 1];
		auto it = cows.find({ i + 1,location });
		it--;
		if (it != cows.end())
			ans += location - it->location + 1;
		it = cows.find({ i + 1,location });
		it++;
		if (it != cows.end())
			ans += it->location - location + 1;
		cows.erase({ i + 1, location });
	}


	//for (int i = 0; i < nCows; i++)
	//{
	//	int currentMax = 0;
	//	int j = i + 1;
	//	while (j < nCows && currentMax < cowHeights[i])
	//	{
	//		if (cowHeights[j] > currentMax)
	//		{
	//			ans += j - i + 1;
	//			currentMax = cowHeights[j];
	//		}
	//		j++;
	//	}
	//}
	cout << ans;
	return 0;
}

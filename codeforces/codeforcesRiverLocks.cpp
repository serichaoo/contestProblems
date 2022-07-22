#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

//plan: find min time for each number of open pipes
// optimal: open up all pipes at the front
// if min[i]=min[i+1] all remaining ones are equal
// min[i]=std::max(time to fill up locks 1 to i-1=fill[i-1], total volume/i)
// fill[i]=time to fill up locks 1 to i=std::max(fill[i-1], (sum from 1 to i)/i)

using namespace std;

using ll = long long;

vector<ll> minn(200002, 200000000000001);
vector<ll> fil(200002, -1);
vector<ll> volume(200002);
vector<ll> ps(200003); // ps[5] takes sum of volume[0] to volume[4]

int nLocks;

ll filll(int n)
{
	if (fil[n] != -1)
		return fil[n];
	if (n == 0)
	{
		fil[n] = 0;
		return fil[n];
	}
	fil[n] = std::max(filll(n - 1), (ps[n] + n - 1) / n);
	return fil[n];
}

ll m(int n)
{
	if (minn[n] != 200000000000001)
		return minn[n];
	if (n == 0)
	{
		minn[0] = 200000000000001;
		return minn[0];
	}
	if (n == 1)
	{
		minn[1] = ps[nLocks]; // i was struggling for so long until i noticed that i messed this line up
		return ps[nLocks];
	}
	else
	{
		minn[n] = std::max(filll(n - 1), (ps[nLocks] + n - 1) / n);
		return minn[n];
	}
}

int main()
{
	cin >> nLocks;
	for (int i = 0; i < nLocks; i++)
		cin >> volume[i];
	int nQ;
	cin >> nQ;
	vector<ll> timeLimits(200001);
	for (int i = 0; i < nQ; i++)
		cin >> timeLimits[i];
	ps[0] = 0;
	for (int i = 1; i <= nLocks; i++)
		ps[i] = ps[i - 1] + volume[i - 1];
	for (int i = 0; i <= nLocks; i++)
	{
		filll(i);
		m(i);
	}
	map<ll, ll> valToIndex;
	//flip sign of all minn values so that lower_bound works as intended
	minn.resize(nLocks + 1);
	for (int i = 0; i < minn.size(); i++)
		minn[i] *= -1;
	for (int i = 0; i < minn.size(); i++)
		if (valToIndex[minn[i]] == 0)
			valToIndex[minn[i]] = i;
	for (int i = 0; i < nQ; i++)
	{
		auto it = lower_bound(minn.begin(), minn.end(), -timeLimits[i]);
		if (it == minn.end())
			cout << -1 << endl;
		else
			cout << valToIndex[*it] << endl;
	}
}

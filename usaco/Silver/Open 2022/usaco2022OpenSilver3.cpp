#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;

vector<ll> cPrefixSum(2e5 + 1, 0);
vector<ll> oPrefixSum(2e5 + 1, 0);
vector<ll> wPrefixSum(2e5 + 1, 0);

bool query(ll a, ll b)
{// b - (a-1)
	ll x = cPrefixSum[b] - cPrefixSum[a - 1];
	ll y = oPrefixSum[b] - oPrefixSum[a - 1];
	ll z = wPrefixSum[b] - wPrefixSum[a - 1];
	if (((y + z) % 2 == 0) && ((x + y) % 2 == 1))
		return true;
	else
		return false;
}

int main()
{
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 'C')
		{
			cPrefixSum[i + 1] = cPrefixSum[i] + 1;
			oPrefixSum[i + 1] = oPrefixSum[i];
			wPrefixSum[i + 1] = wPrefixSum[i];
		}
		if (a[i] == 'O')
		{
			cPrefixSum[i + 1] = cPrefixSum[i];
			oPrefixSum[i + 1] = oPrefixSum[i] + 1;
			wPrefixSum[i + 1] = wPrefixSum[i];
		}
		if (a[i] == 'W')
		{
			cPrefixSum[i + 1] = cPrefixSum[i];
			oPrefixSum[i + 1] = oPrefixSum[i];
			wPrefixSum[i + 1] = wPrefixSum[i] + 1;
		}
	}
	ll q; cin >> q;
	string ans = "";
	for (ll i = 0; i < q; i++)
	{
		ll c, d;
		cin >> c >> d;
		if (query(c, d))
			cout << 'Y';
		else
			cout << 'N';
	}
	return 0;
}
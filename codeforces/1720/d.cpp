#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

map<int, int> longestPathLength;

bool operation(vi ints, int x, int y)
{
    return ((ints[x] ^ y) < ((ints[y]) ^ x));
}

int longestPath(vi ints, int start)
{
    if (longestPathLength[start] != 0)
        return longestPathLength[start];
    int n = sza(ints);
    vi possibleNextLocations;
    for (int i = start; i < min(start + 256, n); i++)
    {
        if (operation(ints, start, i))
            possibleNextLocations.push_back(i);
    }
    int maxLength = 1;
    for (int i = 0; i < sza(possibleNextLocations); i++)
    {
        maxLength = max(maxLength, longestPath(ints, possibleNextLocations[i]) + 1);
    }
    longestPathLength[start] = maxLength;
    return maxLength;
}

void solve()
{
    int n;
    cin >> n;
    vi ints(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ints[i];
    }
    int ans = 0;
    for (int i = 0; i < min(n, 256); i++)
    {
        ans = max(ans, longestPath(ints, i));
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
        longestPathLength.clear();
    }
    return 0;
}
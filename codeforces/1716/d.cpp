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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
        return x;

    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result <= x)
    {
        i++;
        result = i * i;
    }
    return i - 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<map<ll, ll>> ways(n + 1);
    ways[0][k] = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        ll ans = 0;
        for (auto it : ways[i])
        {
            ans += it.second;
            ans %= MOD;
            ll mod = it.first;
            for (int j = 0; j * mod < n + 1 - i; j += 1)
            {
                ways[j][mod + 1] += it.second;
                ways[j][mod + 1] %= MOD;
            }
        }
        if (i != 0)
            cout << ans << ' ';
    }

    ll ans = 0;
    for (auto it : ways[n])
    {
        ans += it.second;
        ans %= MOD;
    }
    cout << ans;

    return 0;
}
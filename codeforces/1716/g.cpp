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

int power(long long x, unsigned int y)
{
    int res = 1;

    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
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
            for (int j = i + mod; j < n + 1; j += mod)
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
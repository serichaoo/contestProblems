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

unordered_map<ll, unordered_map<ll, ll>> dp;
vll twoPowers;

ll func(int n, int k)
{
    if (n == 0 || k == 0)
        return 1;
    if (dp[n][k] != 0)
        return dp[n][k];
    if (k >= n)
    {
        return twoPowers[n];
    }
    if (k == n - 1)
    {
        return twoPowers[n] - 1;
    }
    ll ans = 1;
    for (int i = 0; i < n; i++)
        ans += func(i, k - 1);
    ans %= MOD;
    dp[n][k] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    ll curPower = 1;
    twoPowers.push_back(1);
    for (int i = 1; i < 1e5 + 2; i++)
    {
        curPower <<= 1;
        curPower %= MOD;
        twoPowers.push_back(curPower);
    }
    cout << func(n, k);

    return 0;
}
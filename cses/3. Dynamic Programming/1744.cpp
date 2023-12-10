#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

map<pll, ll> dp;
ll DP(ll a, ll b)
{
    if (a == b || a == 0 || b == 0)
        return 0;
    if (a == 1 || b == 1) return max(a, b)-1;
    if (a > b) swap(a, b);
    ll a1 = a, b1 = b;
    if (dp.find({a, b}) != dp.end()) return dp[{a, b}];
    ll ans = 0;
    ans += ((b - a)/a+1);
    b -= ans*a;
    ll val = INF;
    ll cnt = 0;
    while (b > 0)
    {
        val = min(val, DP(a, b) + cnt);
        b -= a;
        cnt++;
    }
    ans += val;
    dp[{a1, b1}] = ans;
    return ans;
}

void solve(int tt)
{
    ll a, b;
    cin >> a >> b;
    ll d = gcd(a, b);
    a /= d; b /= d;
    cout << DP(a, b);
}

signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
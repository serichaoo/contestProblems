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

vector<vector<bool>> calculated(5001, vector<bool>(5001));
vector<vll> val(5001, vll(5001));
vll x;
vll PS;
ll dp(ll a, ll b)
{
    if (a == b) return 0;
    if (calculated[a][b]) return val[a][b];
    ll ans = max(x[a] + (PS[b] - PS[a+1] - dp(a+1, b)), x[b-1] + (PS[b-1] - PS[a] - dp(a, b-1)));
    calculated[a][b] = 1;
    val[a][b] = ans;
    return ans;
}

void solve(int tt)
{
    ll n;
    cin >> n;
    x.resize(n);
    forn(i, n)
        cin >> x[i];
    PS.resize(n+1);
    forn(i, n)
        PS[i+1] = PS[i] + x[i];
    cout << dp(0, n);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
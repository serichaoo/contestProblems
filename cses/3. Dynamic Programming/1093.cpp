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

vector<vll> val(250*501+1, vll(501));
vector<vector<bool>> calculated(250 * 501 + 1, vector<bool>(501));

ll dp(ll sum, ll k)
{
    if (sum == 0) return 1;
    if (sum < 0 || k == 0 || k*(k+1) < 2 * sum) return 0;
    if (calculated[sum][k]) return val[sum][k];
    ll ans = (dp(sum, k-1) + dp(sum-k, k-1))%MOD;
    calculated[sum][k] = 1;
    val[sum][k] = ans;
    return ans;
}

void solve(int tt)
{
    ll n;
    cin >> n;
    if (n * (n+1)/2 % 2){
        cout << 0;
        return;
    }
    ll sum = n * (n+1)/4;
    cout << (dp(sum, n) * 500000004) % MOD;
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
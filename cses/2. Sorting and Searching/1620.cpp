#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;
#define forn(i, n) for (int i = 0; i < int(n); i++)

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

vector<__int128> k;
__int128 n;

__int128 numProduced(__int128 t)
{
    __int128 ans = 0;
    forn(i, n)
        ans += t / k[i];
    return ans;
}

void solve(int tt)
{
    __int128 t;
    ll a, b;
    cin >> a >> b;
    n = a;
    t = b;
    // cin >> n >> t;
    k = vector<__int128>(n, 0);
    forn(i, n)
    {
        cin >> a;
        k[i] = a;
    }
    ll lo = 0;
    ll hi = 1e18 + 1;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;
        if (numProduced(mid) >= t)
            hi = mid;
        else
            lo = mid;
    }
    cout << hi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
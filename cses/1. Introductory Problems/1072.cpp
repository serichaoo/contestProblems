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

void solve(int tt)
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (i == 2)
        {
            cout << 6 << endl;
            continue;
        }
        if (i == 3)
        {
            cout << 28 << endl;
            continue;
        }
        if (i == 4)
        {
            cout << 96 << endl;
            continue;
        }
        ll ans = ((i - 4) * (i - 4) * (i * i - 9)) / 2;
        // now add number of pairs of knights where one is on the edge
        ans += 2 * (i * i - 3);
        ans += 4 * (i * i - 4);
        ans += 2 * (i * i - 5);
        ans += (i - 4) * 2 * (i * i - 5);
        ans += (i - 4) * 2 * (i * i - 7);
        cout << ans << endl;
    }
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
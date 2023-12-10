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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int t = 0;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

void solve(int tt)
{
    ll n, k;
    cin >> n >> k;
    indexed_set vals;
    vll x(n);
    forn(i, n)
    {
        cin >> x[i];
    }
    forn(i, k)
    {
        vals.insert({x[i], t++});
    }
    ll med = (*vals.find_by_order((k - 1) / 2)).first;
    ll ans = 0;
    forn(i, k)
    {
        ans += abs(med - x[i]);
    }
    cout << ans << ' ';
    ll preMed;
    forn(i, n - k)
    {
        ans -= abs(med - x[i]);
        vals.erase(vals.lower_bound({x[i], 0}));
        vals.insert({x[k + i], t++});
        preMed = med;
        med = (*vals.find_by_order((k - 1) / 2)).first;
        // ans -= abs(x[k + i] - preMed);
        ans += abs(x[k + i] - med);
        if (!(k % 2))
            ans -= med - preMed;
        cout << ans << ' ';
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
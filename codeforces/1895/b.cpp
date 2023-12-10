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

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

void solve(int tt)
{
    ll n;
    cin >> n;
    vll a(2 * n);
    forn(i, 2 * n)
    {
        cin >> a[i];
    }
    sort(all(a));
    cout << a[2 * n - 1] - a[0] - a[n] + a[n - 1] << endl;
    forn(i, n)
    {
        cout << a[i] << ' ' << a[n + i] << endl;
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
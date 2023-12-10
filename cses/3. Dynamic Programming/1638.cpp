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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

void solve(int tt)
{
    ll n;
    cin >> n;
    vector<vector<bool>> isTrapped(n, vector<bool>(n));
    forn(i, n)
        forn(j, n)
    {
        char b;
        cin >> b;
        if (b == '*')
            isTrapped[i][j] = 1;
    }
    vector<vll> numPaths(n + 1, vll(n + 1));
    numPaths[1][1] = 1;
    if (isTrapped[0][0])
    {
        cout << 0;
        return;
    }
    forn(i, n)
        forn(j, n)
    {
        if (i == 0 && j == 0)
            continue;
        if (isTrapped[i][j])
            continue;
        numPaths[i + 1][j + 1] = (numPaths[i][j + 1] + numPaths[i + 1][j]) % MOD;
    }
    cout << numPaths[n][n];
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
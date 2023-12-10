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

vector<vector<bool>> isFree(8, vector<bool>(8));

bool isValid(vll a)
{
    forn(i, 8)
    {
        if (!isFree[i][a[i]])
            return 0;
    }
    map<ll, ll> xPlusY;
    forn(i, 8)
    {
        xPlusY[a[i] + i]++;
        if (xPlusY[a[i] + i] > 1)
            return 0;
    }
    map<ll, ll> xMinusY;
    forn(i, 8)
    {
        xMinusY[a[i] - i]++;
        if (xMinusY[a[i] - i] > 1)
            return 0;
    }
    return 1;
}

void solve(int tt)
{
    forn(i, 8)
        forn(j, 8)
    {
        char a;
        cin >> a;
        if (a == '.')
            isFree[i][j] = 1;
    }
    ll ans = 0;
    vll a = {0, 1, 2, 3, 4, 5, 6, 7};
    while (next_permutation(all(a)))
    {
        if (isValid(a))
            ans++;
    }
    cout << ans;
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
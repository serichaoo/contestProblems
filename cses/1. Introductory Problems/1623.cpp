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
const ll INF = 1e18;
const ld EPS = 1e-9;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

ll minDiff = INF;

ll n;
vll a;
vi subset;
ll sum = 0;
void search(ll k)
{
    if (k == n)
    {
        ll val = 0;
        forn(i, subset.size())
        {
            val += a[subset[i]];
        }
        minDiff = min(minDiff, max((sum - val) - val, val - (sum - val)));
    }
    else
    {
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}

void solve(int tt)
{
    cin >> n;
    a = vll(n);
    forn(i, n)
            cin >>
        a[i];
    forn(i, n)
        sum += a[i];
    search(0);
    cout << minDiff;
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
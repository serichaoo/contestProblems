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

bool multiTest = 1;

void solve(int tt)
{
    ll n;
    cin >> n;
    vll a(n);
    forn(i, n)
            cin >>
        a[i];
    multiset<ll> vals;
    forn(i, n)
        vals.insert(a[i]);
    if (vals.size() == 1)
    {
        cout << -1 << endl;
        return;
    }
    set<ll> validVals;
    for (ll x : vals)
    {
        if (vals.count(x) >= 2)
            validVals.insert(x);
    }
    if (validVals.size() < 2)
    {
        cout << -1 << endl;
        return;
    }
    vll b(n, 1);
    bool passedFirst = 0;
    ll a1 = *validVals.begin();
    ll a2 = *(++validVals.begin());
    bool passedSecond = 0;
    forn(i, n)
    {
        if (a[i] == a1)
        {
            if (passedFirst)
            {
                b[i] = 2;
            }
            passedFirst = 1;
        }
        else if (a[i] == a2)
        {
            if (passedSecond)
            {
                b[i] = 3;
            }
            passedSecond = 1;
        }
    }
    forn(i, n)
    {
        cout << b[i] << ' ';
    }
    cout << endl;
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
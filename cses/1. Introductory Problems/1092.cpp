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
    if ((n * (n + 1) % 4) != 0)
    {
        cout << "NO";
        return;
    }
    ll desired = (n * (n + 1)) / 4;
    ll val = 0;
    vector<bool> inFirst(n + 1);
    for (ll i = n; i > 0; i--)
    {
        if (val + i <= desired)
        {
            val += i;
            inFirst[i] = 1;
        }
        if (val == desired)
            break;
    }
    vll a;
    vll b;
    forn(i, n + 1)
    {
        if (i == 0)
            continue;
        if (inFirst[i])
            a.push_back(i);
        else
            b.push_back(i);
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    forn(i, a.size())
            cout
        << a[i] << ' ';
    cout << endl;
    cout << b.size() << endl;
    forn(i, b.size())
            cout
        << b[i] << ' ';
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
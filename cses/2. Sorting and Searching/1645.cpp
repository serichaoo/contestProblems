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
    vector<pll> a(n + 1);
    // map<ll, ll> valToIndex;
    forn(i, n)
    {
        ll b;
        cin >> b;
        a[i + 1] = {b, i + 1};
        // valToIndex[a[i + 1]] = i + 1;
    }
    set<ll> pos;
    sort(all(a));
    pos.insert(0);
    vll ans(n);
    ll preVal = 0;
    vll toInsert;
    forn(i, n)
    {
        ll newVal = a[i + 1].first;
        if (newVal > preVal)
        {
            preVal = newVal;
            forn(j, toInsert.size())
            {
                pos.insert(toInsert[j]);
            }
            toInsert.clear();
        }
        ll ind = a[i + 1].second;
        ans[ind - 1] = *(--pos.lower_bound(ind));
        toInsert.push_back(ind);
    }
    forn(i, n)
            cout
        << ans[i] << ' ';
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
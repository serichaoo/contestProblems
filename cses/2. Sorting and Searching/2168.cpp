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
    int n;
    cin >> n;
    set<tuple<ll, ll, ll>> xy;
    set<tuple<ll, ll, ll>> yx;
    forn(i, n)
    {
        ll x, y;
        cin >> x >> y;
        xy.insert({x, y, i});
        yx.insert({y, x, i});
    }
    vector<bitset<(int)2e5>> intervalsStartingLeft(n);
    vector<bitset<(int)2e5>> intervalsEndingRight(n);
    vector<bitset<(int)2e5>> intervalsStartingRight(n);
    vector<bitset<(int)2e5>> intervalsEndingLeft(n);
    ll preVal = get<2>(*xy.begin());
    ll preVal2 = get<2>(*yx.begin());
    intervalsStartingLeft[preVal] = bitset<(int)2e5>(0);
    intervalsEndingLeft[preVal2] = bitset<(int)2e5>(0);
    for (auto it = ++xy.begin(); it != xy.end(); it++)
    {
        intervalsStartingLeft[get<2>(*it)] = intervalsStartingLeft[preVal] | bitset<int(2e5)>(1 << get<2>(*it));
        preVal = get<2>(*it);
    }
    for (auto it = ++yx.begin(); it != yx.end(); it++)
    {
        intervalsEndingLeft[get<2>(*it)] = intervalsEndingLeft[preVal2] | bitset<int(2e5)>(1 << get<2>(*it));
        preVal2 = get<2>(*it);
    }
    preVal = get<2>(*(--yx.end()));
    preVal2 = get<2>(*(--xy.end()));
    for (auto it = --(--yx.end()); it != yx.begin(); it--)
    {
        intervalsEndingRight[get<2>(*it)] = intervalsEndingRight[preVal] | bitset<int(2e5)>(1 << get<2>(*it));
        preVal = get<2>(*it);
    }
    intervalsEndingRight[get<2>(*yx.begin())] = intervalsEndingRight[preVal] | bitset<int(2e5)>(1 << get<2>(*yx.begin()));
    for (auto it = --(--xy.end()); it != xy.begin(); it--)
    {
        intervalsStartingRight[get<2>(*it)] = intervalsStartingRight[preVal] | bitset<int(2e5)>(1 << get<2>(*it));
        preVal = get<2>(*it);
    }
    intervalsStartingRight[get<2>(*xy.begin())] = intervalsStartingRight[preVal] | bitset<int(2e5)>(1 << get<2>(*xy.begin()));
    forn(i, n)
    {
        intervalsStartingLeft[i][i] = 0;
        intervalsStartingRight[i][i] = 0;
        intervalsEndingLeft[i][i] = 0;
        intervalsEndingRight[i][i] = 0;
    }
    forn(i, n)
    {
        if ((intervalsStartingRight[i] & intervalsEndingLeft[i]) != bitset<(int)2e5>(0))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    cout << endl;
    forn(i, n)
    {
        if ((intervalsStartingLeft[i] & intervalsEndingRight[i]) != bitset<(int)2e5>(0))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
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
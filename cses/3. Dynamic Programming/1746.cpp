#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second

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

ll m;
vll possibilities;

ll returnVal(ll index)
{
    if (index < 0 || index >= m) return 0;
    return possibilities[index];
}

void solve(int tt)
{
    ll n;
    cin >> n >> m;
    ll ans = 1;
    possibilities.resize(m);
    vll x(n);
    forn(i, n)
        cin >> x[i];
    ll maxVal = 0;
    forn(i, n)
        maxVal = max(maxVal, x[i]);
    if (maxVal == 0) {
        possibilities = vll(m, 1);
        vll newPossibilities(m);
        forn(i, n-1) {
            forn(i, m) {
                newPossibilities[i] = (returnVal(i-1) + returnVal(i) + returnVal(i+1))%MOD;
            }
            possibilities = newPossibilities;
        }
        ll ans = 0;
        forn(i, m){
            ans += possibilities[i];
            ans %= MOD;
            }
        cout << ans << endl;
        return;
    }
    //check if first group of numbers are 0, then process them
    ll cnt = 0;
    if (x[0] == 0){
        cnt = 1;
        while (cnt < n && x[cnt] == 0)
            cnt++;
        possibilities = vll(m, 0);
        possibilities[x[cnt]-1] = 1;
        vll newPossibilities(m);
        forn(i, cnt){
            forn(j, m)
            newPossibilities[j] = (returnVal(j - 1) + returnVal(j) + returnVal(j + 1)) % MOD;
            possibilities=newPossibilities;
        }
        ll ways = 0;
        forn(i, m){
            ways += possibilities[i];
            ways %= MOD;
            }
        ans *= ways;
        ans %= MOD;
    }
    bool zeroStreak = 0;
    for (int i=cnt; i<n; i++)
    {
        if (x[i] != 0){
            if ((i > 0 && x[i - 1] != 0 && abs(x[i] - x[i - 1]) > 1) || (i < n - 1 && x[i + 1] != 0 && abs(x[i] - x[i + 1]) > 1))
                {
                    cout << 0;
                    return;
                }
            if (zeroStreak)
            {
                vll newPossibilities(m);
                forn(j, m)
                    newPossibilities[j] = (returnVal(j - 1) + returnVal(j) + returnVal(j + 1)) % MOD;
                possibilities = newPossibilities;
                ans *= possibilities[x[i] - 1];
                ans %= MOD;
                zeroStreak = 0;
            }
        }
        else{
            if (!zeroStreak){
                zeroStreak = 1;
                possibilities = vll(m, 0);
                possibilities[x[i-1]-1] = 1;
                vll newPossibilities(m);
                forn(j, m)
                    newPossibilities[j] = (returnVal(j - 1) + returnVal(j) + returnVal(j + 1)) % MOD;
                possibilities = newPossibilities;
            }
            else if (zeroStreak){
                vll newPossibilities(m);
                forn(j, m)
                    newPossibilities[j] = (returnVal(j - 1) + returnVal(j) + returnVal(j + 1)) % MOD;
                possibilities = newPossibilities;
            }
        }
    }
    if (zeroStreak)
    {
        ll ways = 0;
        forn(i, m)
        {
            ways += possibilities[i];
            ways %= MOD;
        }
        ans *= ways;
        ans %= MOD;
    }
    cout << ans;
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
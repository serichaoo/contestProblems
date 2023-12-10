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

bool multiTest = 1;

void solve(int tt) {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    forn(i, n)
        cin >> a[i];
    set<ll> oneLocations;
    forn(i, n){
        if (a[i] == 1)
            oneLocations.insert(i);
    }
    ll sum = 0;
    forn(i, n)
        sum += a[i];
    forn(i, q){
        ll op; cin >> op;
        if (op == 1){
            ll s; cin >> s;
            if (s > sum)
                {cout << "NO" << endl;
                continue;}
            ll fewestTwoRemovals = -1;
            if (!oneLocations.empty()){
                fewestTwoRemovals = INF;
                fewestTwoRemovals = min(fewestTwoRemovals, *oneLocations.begin());
                fewestTwoRemovals = min(fewestTwoRemovals, n-1-*(--oneLocations.end()));
            }
            if (fewestTwoRemovals == -1){
                if ((s+sum) % 2)
                    {cout << "NO" << endl;
                    continue;}
                else
                    {cout << "YES" << endl;
                    continue;}
            }
            else{
                if (s <= sum - 2 * fewestTwoRemovals){
                    cout << "YES" << endl;
                    continue;
                }
                else if ((s+sum) % 2){
                    cout << "NO" << endl;
                    continue;
                }
                else{
                    cout << "YES" << endl;
                    continue;
                }
            }
        }
        if (op == 2){
            ll i, v; cin >> i >> v; i--;
            if (a[i] == v)
                continue;
            if (a[i] == 1){
                oneLocations.erase(i);
                a[i] = 2;
                sum++;
            }
            else{
                oneLocations.insert(i);
                a[i] = 1;
                sum--;
            }
        }
    }
}

signed main() {
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
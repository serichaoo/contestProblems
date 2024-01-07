#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second
#define endl '\n'

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

vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};
vi d8x = {1, 0, -1, 0, 1, 1, -1, -1};
vi d8y = {0, 1, 0, -1, 1, -1, 1, -1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

void solve(int tt) {
    // do dp on if the first n numbers can be reduced to 1
    ll n; cin >> n;
    vll a(n); // dp(n, -1);
    forn(i, n) cin >> a[i];

    vll b;
    ll newN = 0;
    forn(i, n){
        if (i == 0 || a[i] != a[i-1]){
            b.push_back(a[i]);
            newN++;
        }
    }
    a = b;
    n = newN;
    
    map<ll, vll> indicesByVal;
    forn(i, n)
        indicesByVal[a[i]].pb(i);
    set<pll> maxSeg;
    vll maxValIndices = (--indicesByVal.end())->second;
    ll curVal = (--indicesByVal.end())->first;
    forn(i, maxValIndices.size()) maxSeg.insert({maxValIndices[i], maxValIndices[i]+1});
    while (curVal > 0){
        curVal--;
        set<pll> newMaxSeg;
        ll preR = -1;
        for (pll seg : maxSeg){
            ll l = seg.fi; ll r = seg.se;
            if (l > 0 && (a[l-1] == curVal)){
                newMaxSeg.insert({l-1, r});
                // if (preR == l){
                //     auto it = --newMaxSeg.end();
                //     newMaxSeg.insert({it->fi, r});
                //     newMaxSeg.erase(it);
                //     preR = r;
                // }
                // else{
                //     if (r < n && a[r] == curVal)
                //         preR = r+1;
                //     else preR = r;
                //     newMaxSeg.insert({l-1, preR});
                // }
            }
            else if (r < n && a[r] == curVal){
                newMaxSeg.insert({l, r+1});
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        vll maxValIndices = indicesByVal[curVal];
        forn(i, maxValIndices.size()) newMaxSeg.insert({maxValIndices[i], maxValIndices[i]+1});
        preR = -1;
        ll preL = -1;
        maxSeg.clear();
        for (auto it = newMaxSeg.begin(); it != newMaxSeg.end(); it++){
            pll seg = *it;
            if (seg.fi <= preR){
                ll newR = max(seg.se, preR);
                maxSeg.erase({preL, preR});
                maxSeg.insert({preL, newR});
                preR = newR;
            }
            else{
                preR = seg.se;
                preL = seg.fi;
                maxSeg.insert(seg);
            }
        }
    }
    if (maxSeg.size() == 1)
        cout << "YES" << endl;
    else cout << "NO" << endl;
}
// dp[0] = a[0];
    // for (int i=1; i<n; i++){
    //     if (dp[i-1] == -1){
    //         if (a[i] - a[i-1] == -1){
    //             // do a check with right new addition = a[i] and left side = dp[i-2]
    //             if (dp[i-2] == -1){
    //                 dp[i] == -1;
    //             }
    //             else if (a[i] + 1 == dp[i-2]){
    //                 dp[i] = a[i];
    //             }
    //             else if (dp[i-2] < a[i] && a[i] <= a[i-2]+1){
    //                 dp[i] = dp[i-2];
    //             }
    //         }
    //     }
    //     else if (a[i] + 1 == dp[i-1]){
    //         dp[i] = a[i];
    //     }
    //     else if (dp[i-1] < a[i] && a[i] <= a[i-1]+1){
    //         dp[i] = dp[i-1];
    //     }
    // }
    // if (dp[n-1] == 0) cout << "YES" << endl;
    // else cout << "NO" << endl;

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
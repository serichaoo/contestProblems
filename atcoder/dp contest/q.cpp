#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll MAX_N = 2e5+10;

vll t(4 * MAX_N);

ll n;
// void build(vll& a, ll x, ll tl, ll tr){
//     if (tr - tl == 1){
//         t[x] = a[tl];
//         return;
//     }
//     ll m = (tl + tr)/2;
//     build(a, 2*x+1, tl, m);
//     build(a, 2*x+2; m, tr);
//     t[x] = max(t[2*x+1], t[2*x+2]);
// }

void update(ll i, ll v, ll x, ll tl, ll tr){
    if (tr - tl == 1){
        t[x] = v;
        return;
    }
    ll m = (tl + tr)/2;
    if (i < m) update(i, v, 2*x+1, tl, m);
    else update(i, v, 2*x+2, m, tr);
    t[x] = max(t[2*x+1], t[2*x+2]);
}

void update(ll i, ll v){
    update(i, v, 0, 0, n+1);
}

ll query(ll l, ll r, ll x, ll tl, ll tr){
    if (tr <= l || tl >= r) return 0;
    if (tl >= l && tr <= r) return t[x];
    ll m = (tl + tr)/2;
    return max(query(l, r, 2*x+1, tl, m), query(l, r, 2*x+2, m, tr));
}

ll query(ll r){
    return query(0, r, 0, 0, n+1);
}

int main(){
    // segtree for range max
    cin >> n;
    vll dp(n+1); // dp[i] gives max value with ending height i
    // build(dp, 0, 0, n);
    vll h(n), a(n);

    for (int i=0; i<n; i++)
        cin >> h[i];
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    ll ans = 0;
    for (int i=0; i<n; i++){
        ll q = query(h[i]);
        if (q + a[i] > dp[h[i]]){
            dp[h[i]] = q + a[i];
            ans = max(ans, dp[h[i]]);
            update(h[i], dp[h[i]]);
        }
    }
    cout << ans;

    
    
    return 0;
}
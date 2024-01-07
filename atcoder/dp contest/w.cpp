#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll MAX_N = 2e5 + 5;
const ll INF = 1e18;

vll t(4 * MAX_N);
vll lazy(4 * MAX_N);

ll n;

void push(ll x){
    t[2*x+1] += lazy[x];
    t[2*x+2] += lazy[x];
    lazy[2*x+1] += lazy[x];
    lazy[2*x+2] += lazy[x];
    lazy[x] = 0;
}

void update(ll addend, ll l, ll r, ll x, ll tl, ll tr){
    if (l >= r) return;
    if (l == tl && r == tr){
        t[x] += addend;
        lazy[x] += addend;
    }
    else{
        push(x);
        ll tm = (tl + tr)/2;
        update(addend, l, min(r, tm), 2*x+1, tl, tm);
        update(addend, max(l, tm), r, 2*x+2, tm, tr);
        t[x] = max(t[2*x+1], t[2*x+2]);
    }
}

void update(ll addend, ll l, ll r){
    update(addend, l, r, 0, 0, n+2);
}

ll query(ll l, ll r, ll x, ll tl, ll tr){
    if (l >= r) return -INF;
    if (l == tl && r == tr) return t[x];
    push(x);
    ll tm = (tl + tr)/2;
    return max(
        query(l, min(r, tm), 2*x+1, tl, tm),
        query(max(l, tm), r, 2*x+2, tm, tr));
}

ll query(ll r){
    return query(0, r, 0, 0, n+2);
}

// ll tA[4*MAX_N];
// void updateTA(ll add, ll l, ll r, ll x, ll tl, ll tr){
//     if (l >= r) return;
//     if (l == tl && r == tr){
//         tA[x] += add;
//         return;
//     }
//     ll tm = (tl + tr)/2;
//     updateTA(add, l, min(tm, r), 2*x+1, tl, tm);
//     updateTA(add, max(l, tm), r, 2*x+2, tm, tr);
// }
// void updateTA(ll add, ll l, ll r){
//     updateTA(add, l, r, 0, MAX_N);
// }
// ll get(ll x, ll tl, ll tr, ll pos){
//     if (tr - tl == 1)
//         return t[x];
//     ll tm = (tl + tr)/2;
//     if (pos < tm)
//         return t[x] + get(2*x+1, tl, tm, pos);
//     else
//         return t[x] + get(2*x+2, tm, tr, pos);
// }
// ll get(ll pos){
//     return get(0, 0, MAX_N, pos);
// }

// use lazy segtree
// dp[i] = A_i + max(dp[j] - A_{ij})
// dp[i] - A_i = max(dp[j] - A{ij})

int main(){
    ll m; cin >> n >> m;
    vector<tuple<ll, ll, ll>> intervals;
    vll ADiff(n+2);
    map<ll, vector<pair<ll, ll>>> intervalsByRightValue;
    for (int i=0; i<m; i++){
        ll l, r, a; cin >> l >> r >> a;
        intervals.emplace_back(l, r+1, a);
        ADiff[l] += a;
        ADiff[r+1] -= a;
        intervalsByRightValue[r+1].push_back({l, a});
        // updateTA(a, l, r+1);
    }
    vll dp(n+2);
    ll curA = 0;
    ll ans = 0;
    for (int i=1; i<=n+1; i++){
        // dp[i] - A_i = max(dp[j] - A{ij})
        curA += ADiff[i];
        for (pair<ll, ll> x : intervalsByRightValue[i]){
            update(x.second, x.first, i);
        }
        ll newVal = query(i);
        update(newVal, i, i+1);
        ans = max(ans, newVal + curA);
    }
    cout << ans;
}
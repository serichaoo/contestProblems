#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<ll> a;
vector<vector<ll>> DP(3001, vector<ll>(3001, 1e18));
ll dp(ll l, ll r){
    if (l == r) return 0;
    if (DP[l][r] != 1e18) return DP[l][r];
    bool p = (l + n - r + 1)%2;
    ll v1, v2;
    ll v;
    if (p){
        v1 = a[l] + dp(l+1, r);
        v2 = a[r-1] + dp(l, r-1);
        v = max(v1, v2);
    }
    else{
        v1 = -a[l] + dp(l+1, r);
        v2 = -a[r-1] + dp(l, r-1);
        v = min(v1, v2);
    }
    DP[l][r] = v;
    return v;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        ll x; cin >> x;
        a.push_back(x);
    }
    cout << dp(0, n);
}
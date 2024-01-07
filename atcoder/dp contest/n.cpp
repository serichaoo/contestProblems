#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a;
vector<ll> ps;
vector<vector<ll>> DP(401, vector<ll>(401, -1));
ll dp(ll l, ll r){
    if (r - l == 1) return 0;
    if (DP[l][r] != -1) return DP[l][r];
    ll ans = 1e18;
    for (int i=l+1; i<r; i++){
        ans = min(ans, dp(l, i) + dp(i, r));
    }
    ans += ps[r] - ps[l];
    DP[l][r] = ans;
    return ans;
}

int main(){
    ll n; cin >> n;
    a.resize(n);
    ps.resize(n+1);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++){
        ps[i] = a[i-1] + ps[i-1];
    }
    cout << dp(0, n);
    return 0;
}
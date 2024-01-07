#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main(){
    ll n, W; cin >> n >> W;
    vll dp(W+1);
    for (int i=0; i<n; i++){
        ll w, v; cin >> w >> v;
        for (int i=W; i>=w; i--){
            dp[i] = max(dp[i], dp[i-w] + v);
        }
    }
    cout << dp[W];
}
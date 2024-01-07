#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll MOD = 1e9+7;

int main(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<bool> diff(n-1);
    for (int i=0; i<n-1; i++){
        if (s[i] == '<')
            diff[i] = 1;
    }
    vll dp(n);
    dp[0] = 1;
    for (int i=0; i<n-1; i++){
        vll newDp(n);
        if (diff[i]){
            ll add = 0;
            for (int j=0; j<i+1; j++){
                add += dp[j];
                add %= MOD;
                newDp[j+1] = add;
            }
        }
        else{
            ll add = 0;
            for (int j=i; j>=0; j--){
                add += dp[j];
                add %= MOD;
                newDp[j] = add;
            }
        }
        dp = newDp;
    }
    ll ans = 0;
    for (int i=0; i<n; i++){
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

int main(){
    int n; cin >> n;
    vector<vector<bool>> compat(n, vector<bool>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            int a; cin >> a;
            if (a) compat[i][j] = 1;
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll>(1 << n));
    dp[0][0] = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!compat[i][j])
                continue;
            for (int k=0; k<(1<<n); k++){
                if (k & (1 << j)){
                    k += (1 << j);
                    if (k >= (1<<n))
                        break;
                }
                if (__builtin_popcount(k) != i)
                    continue;
                //if (!(k && (1 << j))){
                dp[i+1][k + (1 << j)] += dp[i][k];
                dp[i+1][k + (1 << j)] %= MOD;
                //}
            }
        }
    }
    cout << dp[n][(1 << n) -1];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main(){
    ll n, W;
    cin >> n >> W;
    vll dp(1e5+1, 1e9+1); // dp[v] gives minimum weight required to get value v
    dp[0] = 0;
    for (int i=0; i<n; i++){
        ll w, v; cin >> w >> v;
        for (int j=1e5-v; j >= 0; j--){
            dp[j+v] = min(dp[j+v], dp[j]+w);
        }
    }
    ll ans = -1;
    for (int i=1e5; i>=0; i--)
        if (dp[i] <= W){
            cout << i;
            return 0;
        }
    return 0;
}


// map<ll, ll> dp;

// int main(){
//     ll n, W;
//     cin >> n >> W;
//     dp[0] = 0;
//     ll ans = 0;
//     for (int i=0; i<n; i++){
//         ll w, v; cin >> w >> v;
//         auto it = dp.end();
//         it--;
//         bool pl = 1;
//         while (pl){
//             if (it == dp.begin())
//                 pl = 0;
//             if (it->first <= W - w){
//                 if (dp.count(it->first + w))
//                     dp[it->first + w] = max(it->second + v, dp[it->first + w]);
//                 else
//                     dp[it->first + w] = it->second + v;
//                 ans = max(ans, dp[it->first + w]);
//             }
//             it--;
//         }
//         ll max = -1;
//         for (auto it = dp.begin(); it != dp.end(); it++){
//             if (it->second <= max){
//                 auto it2 = it;
//                 it--;
//                 dp.erase(it2);
//             }
//             else
//                 max = it->second;
//         }
//     }
//     cout << ans;
// }
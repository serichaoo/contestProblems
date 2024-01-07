#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

struct block{
    ll w, s, v;
};

bool comp(block x, block y){
    return (min(y.s - x.w, x.s) > min(x.s - y.w, y.s));
}

int main(){
    // optimize v over total weight w
    ll n; cin >> n;
    vector<block> blocks;
    for (int i=0; i<n; i++){
        ll w, s, v; cin >> w >> s >> v;
        blocks.push_back({w, s, v});
    }
    sort(blocks.begin(), blocks.end(), comp);
    vector<vll> dp(n+1, vll(2e4+10));
    ll ans = 0;
    for (int i=0; i<n; i++){
        bool pl = 0;
        for (int j=0; j<2e4+8; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (blocks[i].w <= j && blocks[i].s >= j - blocks[i].w)
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - blocks[i].w] + blocks[i].v);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
        }
    }
    for (int j=0; j<2e4+8; j++)
        ans = max(ans, dp[n][j]);
    cout << ans;
}
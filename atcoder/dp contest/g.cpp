#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> DP(1e5+1, -1);

int dp(int node){
    if (DP[node] != -1)
        return DP[node];
    int ret = 0;
    for (int i=0; i<g[node].size(); i++){
        ret = max(ret, 1 + dp(g[node][i]));
    }
    DP[node] = ret;
    return ret;
}

int main(){
    int n, m; cin >> n >> m;
    g.resize(n);
    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = max(ans, dp(i));
    }
    cout << ans;
    return 0;
}
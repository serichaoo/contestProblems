#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

vector<vector<ll>> adjList;
vector<ll> parents;
vector<bool> visited;

void dfs(ll node, ll parent){
    if (visited[node])
        return;
    visited[node] = 1;
    parents[node] = parent;
    for (ll x : adjList[node])
        dfs(x, node);
}

vector<ll> DP[2];
ll dp(ll node, bool color){ // color = 1 means black
    if (DP[color][node] != -1)
        return DP[color][node];
    ll ret = 1;
    for (ll x : adjList[node]){
        if (x == parents[node])
            continue;
        ll p = dp(x, 0);
        if (!color) p += dp(x, 1);
        p %= MOD;
        ret *= p;
        ret %= MOD;
    }
    DP[color][node] = ret;
    return ret;
}

int main(){
    int n; cin >> n;
    adjList.resize(n);
    parents.resize(n);
    visited = vector<bool>(n, 0);
    DP[0] = vector<ll>(n, -1);
    DP[1] = vector<ll>(n, -1);
    for (int i=0; i<n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(0, -1);
    cout << (dp(0, 0) + dp(0, 1)) % MOD;
    return 0;
}
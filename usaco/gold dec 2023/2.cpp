#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

const ll INF = 1e10;

vector<bool> visited;
vll topoSort;
vector<vector<pll>> adj;

void dfs(ll v) {
    visited[v] = true;
    for (pll u : adj[v]) {
        if (!visited[u.first])
            dfs(u.first);
    }
    topoSort.push_back(v);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    // topological sort
    ll n, m; cin >> n >> m;
    adj.resize(n);

    for (int i=0; i<m; i++){
        ll a, b, l; cin >> a >> b >> l;
        a--; b--;
        adj[a].push_back({b, l});
    }

    visited = vector<bool>(n, 0);
    for (int i=0; i<n; i++) {
        if (!visited[i])
            dfs(i);
    }

    vector<pll> ans(n);
    vector<pll> nextLocation(n, {-1, -1}); // .first is the next location, .second is the road value
    vector<map<ll, ll>> lexOrd(n); // lexOrd(n) gives node for start of node paths in lexicographical order 
    vector<map<ll, ll>> revLexOrd(n);
    ll oldLength = 0;
    for (int j=0; j<n; j++){
        ll i = topoSort[j];
        ll length = 0;
        ll minWeight = 1e10;
        vll optimalNextLoc;
        for (pll x : adj[i]){
            if (ans[x.first].first + 1 > length || (ans[x.first].first + 1 == length && x.second < minWeight)){
                optimalNextLoc.clear();
                optimalNextLoc.push_back(x.first);
                minWeight = x.second;
            }
            else if (ans[x.first].first + 1 == length && x.second == minWeight)
                optimalNextLoc.push_back(x.first);
            length = max(length, ans[x.first].first + 1);
        }
        if (optimalNextLoc.size() > 0){
            ll minLexOrd = 1e9;
            for (int i=0; i<optimalNextLoc.size(); i++)
                minLexOrd = min(minLexOrd, revLexOrd[length-1][optimalNextLoc[i]]);
            nextLocation[j]={lexOrd[length-1][minLexOrd], minWeight};
        }
        lexOrd[length][j] = minWeight;
    }
}

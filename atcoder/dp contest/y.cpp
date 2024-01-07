#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll MAX_N = 2e5+5;
const ll MOD = 1e9+7;

vll fact(MAX_N);
vll invFact(MAX_N);

ll binom(ll a, ll b){ // a choose b
    return (((fact[a] * invFact[b])%MOD) * invFact[a-b]) % MOD;
}

ll binExp(ll a, ll b){
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    return (binExp((a*a) % MOD, b/2) * binExp(a, b%2))%MOD;
}

vector<vector<pair<ll, ll>>> graph;

vll topoOrder;
vll processed;

void dfs(ll node){
    if (processed[node] != 0)
        return;
    processed[node] = 1;
    for (auto x : graph[node]){
        dfs(x.first);
    }
    processed[node] = 2;
    topoOrder.push_back(node);
}

int main(){
    fact[0] = 1;
    for (ll i=1; i<MAX_N; i++)
        fact[i] = (fact[i-1] * i) % MOD;
    // cerr << fact[MAX_N - 1] << endl;
    invFact[MAX_N - 1] = binExp(fact[MAX_N - 1], MOD-2);
    // cerr << invFact[MAX_N - 1] << endl;
    for (ll i=MAX_N-1; i>0; i--){
        invFact[i-1] = (invFact[i] * i) % MOD;
        // cerr << invFact[i-1] << endl;
    }

    // maybe construct a graph?
    ll h, w, n; cin >> h >> w >> n;
    graph.resize(n+2); // make sure to include (1, 1) and (h, w)
    vector<pair<ll, ll>> processedPoints = {{1, 1}};
    for (int i=0; i<=n; i++){
        ll r, c;
        if (i < n)
            cin >> r >> c;
        else{
            r = h; c = w;
        }
        for (int j=0; j<=i; j++){
            ll r1 = processedPoints[j].first, c1 = processedPoints[j].second;
            if (r1 >= r && c1 >= c){
                graph[i+1].push_back({j, binom((r1 - r + c1 - c), r1 - r)});
            }
            else if (r1 <= r && c1 <= c){
                graph[j].push_back({i+1, binom(r - r1 + c - c1, r - r1)});
            }
        }
        processedPoints.emplace_back(r, c);
    }
    // bfs using dp
    // process in topological order
    processed.resize(n+2);
    dfs(0);
    reverse(topoOrder.begin(), topoOrder.end());
    // ans = paths length 1 - paths length 2 + paths length 3 - ...
    vll dp(n+2);
    // dp[node] gives number of paths of length t from start to node, with sign based on parity of length
    dp[0] = -1;
    for (int t=0; t<n+1; t++){
        ll i = topoOrder[t];
        for (pair<ll, ll> x : graph[i]){
            ll node = x.first; ll weight = x.second;
            dp[node] -= (dp[i] * weight) % MOD;
            dp[node] %= MOD; dp[node] += MOD; dp[node] %= MOD;
        }
    }
    cout << dp[n+1];
    return 0;
}
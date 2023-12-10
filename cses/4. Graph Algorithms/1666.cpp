#include <bits/stdc++.h>
using namespace std;
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<vll> adj;
vector<bool> isVisited;

void dfs(ll node){
    if (isVisited[node]) return;
    isVisited[node] = 1;
    for (ll x : adj[node])
        dfs(x);
}

int main(){
    ll n, m;
    cin >> n >> m;
    adj.resize(n);
    isVisited.resize(n);
    forn(i, m){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = 0;
    vector<pll> edgesToAdd;
    forn(i, n){
        if (!isVisited[i]){dfs(i);
        if (i != 0){
            ans++;
            edgesToAdd.pb(make_pair(0, i));
        }}
    }
    cout << ans << endl;
    forn(i, ans)
        cout << edgesToAdd[i].fi +1<< ' ' << edgesToAdd[i].se +1 << endl;
}
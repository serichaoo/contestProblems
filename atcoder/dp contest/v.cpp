#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

ll n, MOD;
vector<vll> graph;
vll parent;
vll g, h;
const ll MAX_N = 2e5 + 10;

bool useCurSegTree = 0;
ll t[4*MAX_N];
map<ll, ll> indexOfNode;

void build(vll &a, ll x, ll tl, ll tr){
    if (tr - tl == 1){
        t[x] = g[a[tl]]+1;
        return;
    }
    ll m = (tl + tr)/2;
    build(a, 2*x+1, tl, m);
    build(a, 2*x+2, m, tr);
    t[x] = (t[2*x+1] * t[2*x+2]) % MOD;
}

ll query(ll l, ll r, ll x, ll tl, ll tr){
    if (tl >= l && tr <= r) return t[x];
    if (tl >= r || tr <= l) return 1;
    ll m = (tl + tr)/2;
    return (query(l, r, 2*x+1, tl, m) * query(l, r, 2*x+2, m, tr))%MOD;
}

ll query(ll l, ll r){
    return query(l, r, 0, 0, indexOfNode.size());
}

// ll binExp(ll base, ll exp){
//     base %= MOD;
//     if (exp == 0) return 1;
//     if (exp == 1) return base;
//     return (binExp(base*base, exp/2) * binExp(base, exp%2))%MOD;
// }
// ll inv(ll x){
//     return binExp(x, MOD-2);
// }

void dfsParents(ll node = 0, ll parentVal = -1){
    parent[node] = parentVal;
    for (ll x : graph[node]){
        if (x != parentVal)
            dfsParents(x, node);
    }
}

ll G(ll node){
    if (g[node] != -1) return g[node];
    ll ret = 1;
    for (ll x : graph[node]){
        if (x == parent[node])
            continue;
        ret *= G(x)+1;
        ret %= MOD;
    }
    g[node] = ret;
    return ret;
}

ll H(ll node){
    if (h[node] != -1) return h[node];
    ll p = parent[node];
    // ll ret = (1 + ((g[p] * H(p))%MOD) * inv(g[node]+1))%MOD;
    // use a segtree???
    ll ret = H(p);
    // for (ll x : graph[p]){
    //     if (x != node && x != parent[p]){
    //         ret *= g[x]+1;
    //         ret %= MOD;
    //     }
    // }
    if (!useCurSegTree){
        vll siblings;
        indexOfNode.clear();
        for (ll x : graph[p]){
            if (x != parent[p]){
                siblings.push_back(x);
                indexOfNode[x] = siblings.size()-1;
            }
        }
        build(siblings, 0, 0, siblings.size());
        useCurSegTree = 1;
        ret *= query(0, indexOfNode[node]);
        ret %= MOD;
        ret *= query(indexOfNode[node]+1, indexOfNode.size());
        ret++;
        ret %= MOD;
        h[node] = ret;
        for (ll x : siblings)
            H(x);
        useCurSegTree = 0;
    }
    if (useCurSegTree){
        ret *= query(0, indexOfNode[node]);
        ret %= MOD;
        ret *= query(indexOfNode[node]+1, indexOfNode.size());
        ret++;
        ret %= MOD;
        h[node] = ret;
    }
    return ret;
}

int main(){
    // root the tree
    // for each node, answer the question for all nodes in its subtree
    // and for all nodes outside its subtree, then multiply
    // let f(x) be the answer for a node
    // g(x) is the answer for the node's subtree
    // h(x) is the answer for all nodes outside the subtree of x
    // f(x) = g(x) * h(x)
    // g(x) = prod(g(child_i)+1), child_i are children
    // let p be x's parent, s_i be x's siblings
    // h(x) = 1 + (prod(g(s_i)+1) * h(p)) = g(p) * h(p) / (g(x)+1)
    cin >> n >> MOD;
    graph.resize(n); parent.resize(n);
    g = vll(n, -1); h = vll(n, -1);
    for (int i=0; i<n-1; i++){
        ll x, y; cin >> x >> y; x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // calculate parents
    dfsParents();
    // calculate g
    G(0);
    // calculate h
    h[0] = 1;
    for (ll i=1; i<n; i++)
        H(i);
    for (ll i=0; i<n; i++){
        cout << (g[i] * h[i]) % MOD << '\n';
    }
}


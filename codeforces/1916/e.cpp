#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second
#define endl '\n'

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};
vi d8x = {1, 0, -1, 0, 1, 1, -1, -1};
vi d8y = {0, 1, 0, -1, 1, -1, 1, -1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

vll parent;
vector<vll> children;
vll a;
stack<ll> order;
// vector<bool> isVisited;
vll pSumTree;

void solve(int tt) {
    parent.clear();
    a.clear();
    order.clear();
    children.clear();
    //isVisited.clear();
    pSumTree.clear();
    ll n; cin >> n;
    parent.resize(n);
    a.resize(n);
    //isVisited.resize(n);
    children.reseize(n);
    pSumTree.resize(n);
    parent[0] = -1;
    forn(i, n){
        cin >> parent[i+1];
        parent[i+1]--;
        children[parent[i+1]].push_back(i+1);
    }
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        if (children[i].size() == 0){
            pSumTree[i] = a[i];
        }
    }

    // do bfs to find order of processing
    queue<ll> q;
    q.push(0);
    while (!q.empty()){
        ll node = q.front();
        q.pop();
        order.push(node);
        for (ll x : children[node])
            q.push(x);
    }

    ll ans = 0;
    while (!order.empty()){
        ll node = order.top();
        order.pop();
        if (node == 0)
            continue;
        if (pSumTree[parent[node]] == 0){
            pSumTree[parent[node]] = pSumTree[node] + a[parent[node]];
        }
        else{
            ans = max(ans, pSumTree[node] )
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
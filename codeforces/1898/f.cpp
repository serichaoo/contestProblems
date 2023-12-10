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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

pll exit1 = make_pair(-1, -1);
pll exit2 = make_pair(-1, -1);
ll exitsFound = 0;

void solve(int tt) {
    ll n, m;
    cin >> n >> m;
    exitsFound = 0;
    vector<vector<bool>> grid(n, vector<bool>(m));
    vector<vector<pll>> parent(n, vector<pll>(m));
    ll startX, startY;
    ll numEmpty = 0;
    forn(i, n){
        str s;
        cin >> s;
        forn(j, m){
            if (s[j] != '#'){
                grid[i][j] = 1;
                numEmpty++;
                }
            if (s[j] == 'V'){
                startX = i;
                startY = j;
            }
        }
    }

    queue<pll> q;
    vector<vector<bool>> isVisited(n, vector<bool>(m));
    q.push(make_pair(startX, startY));
    while (!q.empty()){
        pll p = q.front();
        q.pop();
        if (!grid[p.fi][p.se] || isVisited[p.fi][p.se] || exitsFound == 2) continue;
        isVisited[p.fi][p.se] = 1;
        if (p.fi == 0 || p.se == 0 || p.fi == n-1 || p.se == m-1){
            if (exitsFound == 0)
                exit1 = make_pair(p.fi, p.se);
            else
                exit2 = make_pair(p.fi, p.se);
            exitsFound++;
        }
        if (p.fi > 0 && !isVisited[p.fi-1][p.se]){
            parent[p.fi-1][p.se] = p;
            q.push(make_pair(p.fi-1, p.se));
        }
        if (p.fi < n-1 && !isVisited[p.fi+1][p.se]){
            parent[p.fi+1][p.se] = p;
            q.push(make_pair(p.fi+1, p.se));
        }
        if (p.se > 0 && !isVisited[p.fi][p.se-1]){
            parent[p.fi][p.se-1] = p;
            q.push(make_pair(p.fi, p.se-1));
        }
        if (p.se < n-1 && !isVisited[p.fi][p.se+1]){
            parent[p.fi][p.se+1] = p;
            q.push(make_pair(p.fi, p.se+1));
        }
    }
    if (exitsFound == 0){
        cout << numEmpty - 1 << endl;
        return;
    }
    set<pll> pathElements;
    pll start = make_pair(startX, startY);
    pathElements.insert(start);
    while (exit1 != start){
        pathElements.insert(exit1);
        exit1 = parent[exit1.fi][exit1.se];
    }
    if (exit2.fi != -1){
        while (exit2 != start){
            pathElements.insert(exit2);
            exit2 = parent[exit2.fi][exit2.se];
        }
    }
    cout << numEmpty - pathElements.size() << endl;
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
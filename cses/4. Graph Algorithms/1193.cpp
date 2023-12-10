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

bool multiTest = 0;
ll n, m;
vector<vector<bool>> isVisited;
vector<vector<bool>> grid;
pll start;
pll final;

vector<vector<pair<pll, char>>> parent;
vector<vector<char>> parentDirection;

void solve(int tt) {
    cin >> n >> m;
    grid = vector<vector<bool>>(n, vector<bool>(m));
    isVisited = vector<vector<bool>>(n, vector<bool>(m));
    parent = vector<vector<pair<pll, char>>>(n, vector<pair<pll,char>>(m));
    forn(i, n)
        forn(j, m) {
            char a; cin >> a;
            if (a != '#') grid[i][j] = 1;
            if (a == 'A') start = {i, j};
            if (a == 'B') final = {i, j};
        }
    isVisited[start.fi][start.se] = 1;
    queue<pll> q;
    q.push(start);
    while (!q.empty()) {
        pll p = q.front();
        if (p == final) {
            cout << "YES" << endl;
            pll location = final;
            str path;
            while (location != start) {
                path += parent[location.fi][location.se].se;
                location = parent[location.fi][location.se].fi;
            }
            cout << path.size() << endl;
            forn(i, path.size())
                cout << path[path.size()-1-i];
            return;
        }
        q.pop();
        if (p.fi > 0 && grid[p.fi-1][p.se] && !isVisited[p.fi-1][p.se]) {
            isVisited[p.fi-1][p.se] = 1;
            parent[p.fi-1][p.se] = make_pair(p, 'U');
            q.push({p.fi-1, p.se});
        }
        if (p.fi < n-1 && grid[p.fi+1][p.se] && !isVisited[p.fi+1][p.se]) {
            isVisited[p.fi+1][p.se] = 1;
            parent[p.fi+1][p.se] = make_pair(p, 'D');
            q.push({p.fi+1, p.se});
        }
        if (p.se > 0 && grid[p.fi][p.se-1] && !isVisited[p.fi][p.se-1]) {
            isVisited[p.fi][p.se-1] = 1;
            parent[p.fi][p.se-1] = make_pair(p, 'L');
            q.push({p.fi, p.se-1});
        }
        if (p.se < m-1 && grid[p.fi][p.se+1] && !isVisited[p.fi][p.se+1]) {
            isVisited[p.fi][p.se+1] = 1;
            parent[p.fi][p.se+1] = make_pair(p, 'R');
            q.push({p.fi, p.se+1});
        }
    }
    cout << "NO";
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
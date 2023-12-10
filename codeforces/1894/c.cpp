#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;
#define forn(i, n) for (int i = 0; i < int(n); i++)

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

vector<vll> adjList;
vll colors;
bool isPossible;
bool findCycle;
ll k;
vector<bool> isVisited;
queue<pll> q;

void dfs(ll node, ll depth)
{
    if (isPossible)
        return;
    if (depth == k)
    {
        isPossible = 1;
        return;
    }
    if (colors[node] == 2)
        return;
    if (colors[node] == 1)
    {
        isPossible = 1;
        return;
    }
    colors[node] = 1;
    for (ll x : adjList[node])
    {
        if (isPossible)
            return;
        dfs(x, depth + 1);
    }
    colors[node] = 2;
}

void bfs(ll node, ll depth)
{
    if (isPossible)
        return;
    if (depth == k)
    {
        isPossible = 1;
        return;
    }
    if (isVisited[node])
        return;
    isVisited[node] = 1;
    for (auto x : adjList[node])
    {
        q.push({x, depth + 1});
    }
    if (q.empty())
        return;
    ll a = q.front().first;
    ll b = q.front().second;
    q.pop();
    bfs(a, b);
}

void solve(int tt)
{
    ll n;
    cin >> n >> k;
    if (k > n)
        findCycle = 1;
    else
        findCycle = 0;
    adjList.clear();
    adjList.resize(n);
    colors.clear();
    colors.resize(n);
    q = queue<pll>();
    isVisited = vector<bool>(n, 0);
    isPossible = 0;
    vll a(n);
    forn(i, n)
            cin >>
        a[i];
    // for element a[i], connection from position where a[i] is at a[n-1] to where a[i] is at
    // a[a[i]-1]
    // connection from (n-1-i) to (a[i]-1 - i)
    forn(i, n)
    {
        if (a[i] <= n)
            adjList[n - 1 - i].push_back(((a[i] - 1 - i) + n) % n);
    }
    dfs(0, 0);
    if (!isPossible)
        bfs(0, 0);
    if (isPossible)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
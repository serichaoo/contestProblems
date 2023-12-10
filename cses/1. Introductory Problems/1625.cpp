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

bool multiTest = 0;
str s;
ll ans = 0;

void dfs(vector<vector<bool>> isVisited, pll pos, ll depth)
{
    if (isVisited[pos.first][pos.second])
        return;
    isVisited[pos.first][pos.second] = 1;
    if (depth == 48 && pos.first == 6 && pos.second == 0)
    {
        ans++;
        return;
    }
    if (s[depth] == 'U')
    {
        if (pos.first > 0)
            dfs(isVisited, {pos.first - 1, pos.second}, depth + 1);
        return;
    }
    if (s[depth] == 'D')
    {
        if (pos.first < 6)
            dfs(isVisited, {pos.first + 1, pos.second}, depth + 1);
        return;
    }
    if (s[depth] == 'R')
    {
        if (pos.second < 6)
            dfs(isVisited, {pos.first, pos.second + 1}, depth + 1);
        return;
    }
    if (s[depth] == 'L')
    {
        if (pos.second > 0)
            dfs(isVisited, {pos.first, pos.second - 1}, depth + 1);
        return;
    }
    else
    {
        if (pos.first > 0)
            dfs(isVisited, {pos.first - 1, pos.second}, depth + 1);
        if (pos.first < 6)
            dfs(isVisited, {pos.first + 1, pos.second}, depth + 1);
        if (pos.second < 6)
            dfs(isVisited, {pos.first, pos.second + 1}, depth + 1);
        if (pos.second > 0)
            dfs(isVisited, {pos.first, pos.second - 1}, depth + 1);
    }
}

void solve(int tt)
{
    cin >> s;
    vector<vector<bool>> a(7, vector<bool>(7, 0));
    dfs(a, {0, 0}, 0);
    cout << ans;
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
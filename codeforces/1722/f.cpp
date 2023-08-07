#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int sum(vector<vector<bool>> grid, int i, int j)
{
    int ans = 0;
    if (grid[i][j])
        ans++;
    if (grid[i + 1][j])
        ans++;
    if (grid[i][j + 1])
        ans++;
    if (grid[i + 1][j + 1])
        ans++;
    return ans;
}
int threeSum(vector<vector<bool>> grid, int i, int j)
{
    int ans = 0;
    if (grid[i][j])
        ans++;
    if (grid[i + 1][j])
        ans++;
    if (grid[i][j + 1])
        ans++;
    if (grid[i + 1][j + 1])
        ans++;
    if (grid[i - 1][j - 1])
        ans++;
    if (grid[i - 1][j])
        ans++;
    if (grid[i - 1][j + 1])
        ans++;
    if (grid[i][j - 1])
        ans++;
    if (grid[i + 1][j - 1])
        ans++;
    return ans;
}

bool check(vector<vector<bool>> grid, int i, int j)
{
    if (threeSum(grid, i, j) != 3)
        return false;
    if (!(sum(grid, i, j) == 3 || sum(grid, i - 1, j) == 3 || sum(grid, i - 1, j - 1) == 3 || sum(grid, i, j - 1) == 3))
    {
        return false;
    }
    return true;
}
//
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n + 2, vector<bool>(m + 2, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            if (a == '*')
                grid[i][j] = 1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j])
                if (!check(grid, i, j))
                {
                    cout << "NO" << endl;
                    return;
                }
        }
    cout << "YES" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
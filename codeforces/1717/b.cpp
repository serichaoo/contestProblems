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

void solve()
{
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--;
    c--;
    vector<vector<bool>> grid(n, vector<bool>(n, 0));
    vector<pii> startPositions;
    pii start = {r, c};
    for (int i = 0; i < n / k; i++)
    {
        startPositions.push_back({(start.second + i * k) % n, start.first});
    }
    for (auto it : startPositions)
    {
        for (int i = 0; i < n; i++)
            grid[(it.second + i) % n][(it.first + i) % n] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
                cout << 'X';
            else
                cout << '.';
        }
        cout << endl;
    }
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
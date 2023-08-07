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
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> pSum(1002, vll(1002, 0));
    vector<vector<ll>> grid(1002, vll(1002, 0));
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        grid[h][w] += h * w;
    }
    for (int i = 1; i < 1002; i++)
        for (int j = 1; j < 1002; j++)
        {
            pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1] + grid[i][j];
        }
    for (int i = 0; i < q; i++)
    {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << pSum[hb - 1][wb - 1] - pSum[hb - 1][ws] - pSum[hs][wb - 1] + pSum[hs][ws] << endl;
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
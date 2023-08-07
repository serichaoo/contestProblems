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

int onesInSquare(vector<vector<int>> matrix, int x, int y)
{
    int totalOnes = matrix[x][y] + matrix[x][y + 1] + matrix[x + 1][y] + matrix[x + 1][y + 1];
    return totalOnes;
}
int onesRemove(vector<vi> matrix, int x, int y)
{
    int totalOnes = onesInSquare(matrix, x, y);
    if (totalOnes == 0)
        return INF;
    if (totalOnes == 1)
        return 1;
    else
        return totalOnes - 1;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    vector<vi> matrix(x, vi(y));
    ll totalSum = 0;
    ll ans = 0;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        {
            char a;
            cin >> a;
            a -= '0';
            matrix[i][j] = a;
            if (matrix[i][j] == 1)
                totalSum++;
        }
    if (totalSum > 0)
    {
        ans++;
        int minX = 0;
        int minY = 0;
        int minRemove = onesRemove(matrix, minX, minY);
        for (int i = 0; i < x - 1; i++)
        {
            if (minRemove != 1)
                for (int j = 0; j < y - 1; j++)
                {
                    if (minRemove != 1)
                    {
                        int remove = onesRemove(matrix, i, j);
                        if (remove < minRemove)
                        {
                            minRemove = remove;
                            minX = i;
                            minY = j;
                        }
                    }
                }
        }
        int ones = onesInSquare(matrix, minX, minY);
        totalSum -= minRemove;
        ans += totalSum;
    }
    cout << ans << endl;
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
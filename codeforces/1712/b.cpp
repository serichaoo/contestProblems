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

map<int, vll> dp;

vll findDp(int n)
{
    vll ans(n);
    if (sza(dp[n]) > 0)
        return dp[n];
    else
    {
        if ((n % 2) == 1)
        {
            ans[0] = 1;
            for (int i = 1; i < (n + 1) / 2; i++)
            {
                ans[2 * i - 1] = 2 * i + 1;
                ans[2 * i] = 2 * i;
            }
            return ans;
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                ans[2 * i] = 2 * i + 2;
                ans[2 * i + 1] = 2 * i + 1;
            }
            return ans;
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vll ans = findDp(n);
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << ' ';
    cout << ans[n - 1] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = {1};
    dp[2] = {2, 1};
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
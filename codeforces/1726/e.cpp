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
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

vll ans(3e5 + 1, -1);

ll num(ll index)
{
    if (ans[index] != -1)
        return ans[index];
    ll number = num(index - 1) + (index - 1) * num(index - 2);
    number %= MOD;
    ans[index] = number;
    return number;
}

void solve()
{
    ll n;
    cin >> n;
    cout << num(n) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans[0] = 1;
    ans[1] = 1;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
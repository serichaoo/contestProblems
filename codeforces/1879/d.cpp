#include <bits/stdc++.h>
// codeforces general template taken from https://ncduy0303.github.io/Competitive-Programming/Contest%20Template/main.cpp
// template snippet prepared ahead of time, not during the contest
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

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
{ // iterate over all bits
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    ll bitVal = 1;
    for (int i = 0; i < 31; i++)
    {
        vll nums(n);
        for (int i = 0; i < n; i++)
            nums[i] = a[i] % 2;
        vll pSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            pSum[i + 1] = (pSum[i] + nums[i]);
        vll pSumDiff(n + 1);
        for (int i = 0; i < n + 1; i++)
            pSumDiff[i] = (pSum[i] - pSum[n - i]);
        ll val = 0;
        for (int i = n; i > n / 2; i--)
            val += pSumDiff[i] * (n * (n + 1) / 2 - (n + 1));
        ans += val * bitVal;
        bitVal *= 2;
        for (int i = 0; i < n; i++)
            a[i] /= 2;
    }
    cout << ans << endl;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++)
    solve();

    return 0;
}
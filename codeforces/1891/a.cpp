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
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    int n;
    cin >> n;
    vll a(n + 1);
    ll curVal = -1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 3; i <= min(4, n); i++)
    {
        if (curVal > a[i])
        {
            cout << "NO" << endl;
            return;
        }
        curVal = a[i];
    }
    curVal = -1;
    for (int i = 5; i <= min(8, n); i++)
    {
        if (curVal > a[i])
        {
            cout << "NO" << endl;
            return;
        }
        curVal = a[i];
    }
    curVal = -1;
    for (int i = 9; i <= min(16, n); i++)
    {
        if (curVal > a[i])
        {
            cout << "NO" << endl;
            return;
        }
        curVal = a[i];
    }
    curVal = -1;
    for (int i = 17; i <= min(20, n); i++)
    {
        if (curVal > a[i])
        {
            cout << "NO" << endl;
            return;
        }
        curVal = a[i];
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
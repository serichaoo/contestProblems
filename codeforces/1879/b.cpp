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
{ // find min going column by column, then find min going row by row
    int n;
    cin >> n;
    ll sumA, sumB, minA, minB;
    minA = INF;
    minB = INF;
    sumA = 0;
    sumB = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        minA = min(minA, a);
        sumA += a;
    }
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        minB = min(minB, b);
        sumB += b;
    }

    ll ans = n * minB + sumA;
    ans = min(ans, n * minA + sumB);
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
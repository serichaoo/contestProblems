#include <bits/stdc++.h>
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
{
    int n;
    cin >> n;
    // should have form 1, 2, ..., k, n, n-1, ..., k+1
    ll trueMax = 0;
    ll maxSum = 0;
    for (int k = 0; k < n; k++)
    { // max value is n+k+1/2 * n+k+2/2
        maxSum += (k) * (k + 1) * (2 * k + 1) / 6;
        for (int i = k + 1; i <= n; i++)
            maxSum += (n + k + 1 - i) * i;
        maxSum -= ll((n + k + 1) / 2) * ll((n + k + 2) / 2);
        trueMax = max(trueMax, maxSum);
        maxSum = 0;
    }
    cout << trueMax << endl;
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
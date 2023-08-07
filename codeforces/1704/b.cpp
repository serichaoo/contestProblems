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
ll x;

ll check(vi a)
{
    ll ans = 0;
    ll mn = a[0] - x;
    ll mx = a[0] + x;
    for (int i = 1; i < sza(a); i++)
    {
        mn = max(a[i] - x, mn);
        mx = min(a[i] + x, mx);
        if (mn > mx)
        {
            ans++;
            mn = a[i] - x;
            mx = a[i] + x;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n >> x;
        vi a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        cout << check(a) << endl;
    }
    return 0;
}
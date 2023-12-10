#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 1;
    while (n > 26)
    {
        n -= 26;
        ans = ans << 26;
        ans %= MOD;
    }
    ans = ans << n;
    ans %= MOD;
    cout << ans;
    return 0;
}
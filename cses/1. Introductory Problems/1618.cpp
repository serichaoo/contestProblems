#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll ans = 0;
    while (n != 0)
    {
        ans += n / 5;
        n /= 5;
    }
    cout << ans;

    return 0;
}
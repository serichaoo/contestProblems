#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using ll = long long;
using vll = vector<ll>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vll ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];
    vll pSum(n + 1);
    pSum[0] = 0;
    for (int i = 0; i < n; i++)
        pSum[i + 1] = pSum[i] + ints[i];

    vll minOfFirstN(n + 1);
    vll maxOfLastN(n + 1);
    minOfFirstN[0] = 0;
    maxOfLastN[n] = pSum[n];
    for (int i = 1; i <= n; i++)
    {
        minOfFirstN[i] = min(minOfFirstN[i - 1], pSum[i]);
        maxOfLastN[n - i] = max(maxOfLastN[n - i + 1], pSum[n - i]);
    }
    ll ans = -1e10;
    for (int i = 0; i <= n - 1; i++)
        ans = max(ans, maxOfLastN[i + 1] - minOfFirstN[i]);
    cout << ans;
    return 0;
}
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
{ // Alice does not move the chip after placing it down on her first move

    int n;
    cin >> n;
    vi ints(n);
    for (int i = 0; i < n; i++)
        cin >> ints[i];

    int curMin = 3e5 + 5;
    vi winLocations;
    vector<bool> isWinLocation(n, false);
    int ans = 0;
    set<int> setInts;
    for (int i = 0; i < n; i++)
    {
        if (ints[i] < curMin)
        {
            curMin = ints[i];
            winLocations.push_back(i);
            isWinLocation[i] = true;
        }
        // ans++ if all left of current index with value less than curVal is a winLocation
        // so there has to be no value between curVal and ints[0]
    }
    int minNonWinPositionValue = 3e5 + 5;
    for (int i = 0; i < n; i++)
    {
        if (!isWinLocation[i])
        {
            if (ints[i] < minNonWinPositionValue)
            {
                ans++;
                minNonWinPositionValue = ints[i];
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (!isWinLocation[i])
    //     {
    //         if (*(--setInts.upper_bound(ints[i])) == ints[0])
    //             ans++;
    //     }
    //     setInts.insert(ints[i]);
    // }
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
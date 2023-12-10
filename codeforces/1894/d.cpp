#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;
#define forn(i, n) for (int i = 0; i < int(n); i++)

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

void solve(int tt)
{
    ll n, m;
    cin >> n >> m;
    vll a(n);
    vll b(m);
    forn(i, n)
            cin >>
        a[i];
    forn(i, m)
            cin >>
        b[i];
    sort(all(b));
    reverse(all(b));
    // find LIS(a), and then while elements of b are larger than next element in LIS(a)
    // keep inserting elements of b
    // vector<ll> dp(n + 1, INF);
    // dp[0] = -INF;
    // map<ll, ll> indices;
    // indices[-INF] = -1;
    // vll parent(n, -1);
    // forn(i, n)
    // {
    //     ll length = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    //     if (a[i] < dp[length] && dp[length - 1] < a[i])
    //     {
    //         dp[length] = a[i];
    //         indices[a[i]] = i;
    //         parent[i] = indices[dp[length - 1]];
    //     }
    // }
    // ll maxLength = 0;
    // forn(length, n + 1)
    // {
    //     if (dp[length] < INF)
    //         maxLength = length;
    //     else
    //         break;
    // }
    // vll path;
    // ll index = indices[dp[maxLength]];
    // while (index != -1)
    // {
    //     path.push_back(index);
    //     index = parent[index];
    // }
    // reverse(all(path));
    // path.push_back(n);
    // a.push_back(INF);
    vll c(n + m);
    ll aPointer = 0;
    // ll pathPointer = 0;
    ll bPointer = 0;
    forn(i, n + m)
    {
        if (bPointer < b.size() && (aPointer == a.size() || b[bPointer] >= a[aPointer]))
        {
            c[i] = b[bPointer];
            bPointer++;
        }
        else
        {
            c[i] = a[aPointer];
            aPointer++;
        }
    }
    forn(i, n + m)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
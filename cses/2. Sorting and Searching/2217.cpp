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

bool multiTest = 0;

void solve(int tt)
{
    ll n, m;
    cin >> n >> m;
    vll x(n);
    forn(i, n)
    {
        ll a;
        cin >> a;
        x[i] = a - 1;
    }
    vll index(n);
    forn(i, n)
        index[x[i]] = i;
    ll ans = 1;
    ll ind = -1;
    ll num = 0;
    while (num < n)
    {
        ll newIndex = index[num];
        if (newIndex < ind)
            ans++;
        num++;
        ind = newIndex;
    }
    // cout << ans;
    forn(i, m)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        ll change = 0;
        if (a != b)
        {
            if (x[a] > x[b])
                swap(a, b);
            if (x[a] == 0)
            {
                if (a <= index[1] && b >= index[1])
                    change++;
                else if (a >= index[1] && b <= index[1])
                    change--;
            }
            else
            {
                if (a <= index[x[a] + 1] && b >= index[x[a] + 1])
                    change++;
                else if (a >= index[x[a] + 1] && b <= index[x[a] + 1])
                    change--;
                if (b <= index[x[a] - 1] && a >= index[x[a] - 1])
                    change++;
                else if (b >= index[x[a] - 1] && a <= index[x[a] - 1])
                    change--;
            }
            if (x[b] == n - 1)
            {
                if (a <= index[n - 2] && b >= index[n - 2])
                    change++;
                else if (a >= index[n - 2] && b <= index[n - 2])
                    change--;
            }
            else
            {
                if (a <= index[x[b] + 1] && b >= index[x[b] + 1])
                    change--;
                else if (a >= index[x[b] + 1] && b <= index[x[b] + 1])
                    change++;
                if (b <= index[x[b] - 1] && a >= index[x[b] - 1])
                    change--;
                else if (b >= index[x[b] - 1] && a <= index[x[b] - 1])
                    change++;
            }
            if (x[a] + 1 == x[b])
            {
                if (a < b)
                    change--;
                else
                    change++;
            }
            swap(index[x[a]], index[x[b]]);
            swap(x[a], x[b]);
            ans += change;
        }
        cout << ans << endl;
    }
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
    return 0;
}
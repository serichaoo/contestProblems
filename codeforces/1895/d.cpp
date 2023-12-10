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

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 0;

void solve(int tt)
{

    ll n;
    cin >> n;
    vll a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    ll val = 0;
    // cout << val << ' ';
    vll pastLimit;
    vll notPastLimit;
    vector<bool> pastLimitIndex;
    ll bitsToTurnOff = 262144 - 1;
    forn(i, n - 1)
    {
        val ^= a[i];
        if (val >= n)
        {
            pastLimit.push_back(val);
            pastLimitIndex[val] = true;
            for (int i = 0; i < 19; i++)
            {
                if ((bitsToTurnOff & (1 << i)))
                    if (val & (1 << i) > n)
                        bitsToTurnOff -= (1 << i);
            }
            bitsToTurnOff &= val;
        }
        else
            notPastLimit.push_back(val);
        // cout << val << ' ';
    }
    // cout << endl;
    if (pastLimit.size() == 0)
    {
        val = 0;
        cout << val << ' ';
        forn(i, n - 1)
        {
            val ^= a[i];
            if (val >= n)
                pastLimit.push_back(val);
            cout << val << ' ';
        }
        return;
    }
    forn(i, notPastLimit.size())
    {
        if (notPastLimit[i] & bitsToTurnOff == 0)
            continue;
        bool isValid = 1;
        val = notPastLimit[i];
        // cout << val << ' ';
        forn(i, n - 1)
        {
            val ^= a[i];
            if (val >= n)
            {
                isValid = 0;
                break;
            }
        }
        if (isValid)
        {
            val = notPastLimit[i];
            cout << val << ' ';
            forn(i, n - 1)
            {
                val ^= a[i];
                cout << val << ' ';
            }
            return;
        }
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
}
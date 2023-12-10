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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool AWins = 0;
    bool BWins = 0;
    bool undetermined = 0;
    for (int i = 1; i <= 20; i++)
    {
        ll aCount = 0;
        ll bCount = 0;
        ll aSets = 0;
        ll bSets = 0;
        forn(j, n)
        {
            if (s[j] == 'A')
            {
                aCount++;
                if (aCount == i)
                {
                    aCount = 0;
                    bCount = 0;
                    aSets++;
                }
            }
            else
            {
                bCount++;
                if (bCount == i)
                {
                    aCount = 0;
                    bCount = 0;
                    bSets++;
                }
            }
        }
        if (aCount == 0 && bCount == 0 && aSets != bSets)
        {
            if (aSets > bSets && s[n - 1] == 'A')
                AWins = 1;
            else if (aSets < bSets && s[n - 1] == 'B')
                BWins = 1;
        }
    }
    if (AWins && BWins)
        cout << '?' << endl;
    else if (AWins)
        cout << 'A' << endl;
    else
        cout << 'B' << endl;
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
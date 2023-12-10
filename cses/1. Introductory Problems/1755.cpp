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
    str s;
    cin >> s;
    vll chars(26);
    forn(i, s.size())
    {
        chars[s[i] - 'A']++;
    }
    ll numOdd = 0;
    ll oddIndex = -1;
    forn(i, 26) if (chars[i] % 2)
    {
        numOdd++;
        oddIndex = i;
    }
    if (numOdd > 1)
    {
        cout << "NO SOLUTION";
        return;
    }
    ll n = s.size();
    vector<char> t(n);
    ll index = 0;
    forn(i, 26)
    {
        ll a = chars[i] / 2;
        forn(j, a)
        {
            t[index] = 'A' + i;
            t[n - 1 - index] = 'A' + i;
            index++;
        }
        if (i == oddIndex)
            t[n / 2] = 'A' + i;
    }
    forn(i, n)
            cout
        << t[i];
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
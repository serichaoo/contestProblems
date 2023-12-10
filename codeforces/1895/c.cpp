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
    vector<string> s(n);
    forn(i, n)
            cin >>
        s[i];
    map<pll, ll> sumLengthToIndex;
    forn(i, n)
    {
        ll cnt = 0;
        for (int j = 0; j < (int)s[i].size(); j++)
            cnt += (s[i][j] - '0');
        sumLengthToIndex[{cnt, s[i].size()}]++;
    }
    ll ans = 0;
    forn(i, n)
    {
        ll cnt1 = 0;
        ll cnt2 = 0;
        forn(j, s[i].size())
        {
            cnt1 += s[i][j] - '0';
        }
        int k = 0;
        for (int j = s[i].size() - 1; j >= (s[i].size() - 1) / 2; j--)
        {
            if (j < 0)
                break;
            // cout << s[i].size() << endl;
            // make total length
            ans += sumLengthToIndex[{cnt1 - cnt2, (j + 1) - k}];
            cnt1 -= s[i][j] - '0';
            cnt2 += s[i][j] - '0';
            k++;
        }
        cnt1 = 0;
        cnt2 = 0;
        forn(j, s[i].size())
        {
            cnt1 += s[i][j] - '0';
        }
        k = 0;
        cnt1 -= s[i][0] - '0';
        cnt2 += s[i][0] - '0';
        for (int j = 1; j <= (s[i].size() - 1) / 2; j++)
        {
            if (j < 0)
                break;
            // cout << s[i].size() << endl;
            // make total length
            ans += sumLengthToIndex[{cnt1 - cnt2, (s[i].size() - j) * 2 - s[i].size()}];
            cnt1 -= s[i][j] - '0';
            cnt2 += s[i][j] - '0';
            k++;
        }
    }
    cout << ans << endl;
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
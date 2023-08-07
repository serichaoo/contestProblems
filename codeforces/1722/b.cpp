#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

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
{
    int n;
    cin >> n;
    vector<char> row1;
    vector<char> row2;
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (a == 'G')
            a = 'B';
        row1.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (a == 'G')
            a = 'B';
        row2.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (row1[i] != row2[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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
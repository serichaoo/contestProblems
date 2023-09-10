
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
{
    int n, k;
    cin >> n >> k;
    vector<char> word(n);
    if ((k) % 2 == 0)
    {
        for (int i = 0; i < n; i++)
            cin >> word[i];
        sort(all(word));
        for (int i = 0; i < n; i++)
            cout << word[i];
        cout << endl;
    }
    else
    {
        vector<char> evenIndex;
        vector<char> oddIndex;
        for (int i = 0; i < n; i++)
        {
            char a;
            cin >> a;
            if (i % 2 == 0)
                evenIndex.push_back(a);
            else
                oddIndex.push_back(a);
        }
        sort(all(evenIndex));
        sort(all(oddIndex));
        for (int i = 0; i < oddIndex.size(); i++)
            cout << evenIndex[i] << oddIndex[i];
        if (evenIndex.size() != oddIndex.size())
            cout << evenIndex[evenIndex.size() - 1];
        cout << endl;
    }
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
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

void check(string a, string b)
{
    for (int i = 0; i < sza(b) - 1; i++)
    {
        if (a[i] != b[i])
        {
            cout << "no" << endl;
            return;
        }
    }
    if (a[sza(b) - 1] != b[sza(b) - 1])
    {
        char x = b[sza(b) - 1];
        for (int j = sza(b) - 1; j < sza(a); j++)
            if (a[j] == x)
            {
                cout << "yes" << endl;
                return;
            }
        cout << "no" << endl;
        return;
    }
    cout << "yes" << endl;
    return;
}

int main()
{
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int aS, bS;
        cin >> aS >> bS;
        string a;
        string b;
        cin >> a >> b;
        string aR = string(a.rbegin(), a.rend());
        string bR = string(b.rbegin(), b.rend());
        check(aR, bR);
    }
    return 0;
}
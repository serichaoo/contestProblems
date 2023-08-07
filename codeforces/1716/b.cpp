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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        cout << a << endl;
        vi ints(a);
        for (int j = 0; j < a; j++)
        {
            ints[j] = j + 1;
        }
        for (int j = a - 1; j >= 0; j--)
        {
            int pl = j;
            for (int k = 0; k < a - 2; k++)
            {
                if (k != pl)
                    cout << ints[k] << ' ';
                else
                {
                    cout << a << ' ';
                    pl = -1;
                    k--;
                }
            }
            int k = a - 2;
            if (k != pl)
            {
                cout << ints[k];
                if (pl == -1)
                    cout << endl;
                else
                    cout << ' ';
            }
            else
            {
                cout << a << ' ' << a - 1 << endl;
            }
            if (pl == a - 1)
                cout << a << endl;
        }
    }
    return 0;
}
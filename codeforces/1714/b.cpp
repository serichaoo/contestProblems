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
        int n;
        cin >> n;
        vi ints(n);
        for (int j = 0; j < n; j++)
            cin >> ints[j];
        reverse(all(ints));
        map<int, bool> alreadyUsed;
        bool pl = true;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (pl)
            {
                if (alreadyUsed[ints[j]])
                    pl = false;
                else
                {
                    alreadyUsed[ints[j]] = true;
                    count++;
                }
            }
        }
        cout << n - count << endl;
    }
    return 0;
}
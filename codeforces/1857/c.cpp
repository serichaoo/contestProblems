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
// map<int, int> triangularNumbers;
// map<int, int> inverse;
void solve()
{
    // start with max value, then work down
    int n;
    cin >> n;
    int bsz = n * (n - 1) / 2;
    vi a;
    vi b(bsz);
    for (int i = 0; i < bsz; i++)
    {
        cin >> b[i];
    }
    sort(all(b));
    for (int i = bsz - 1; i >= 0; i--)
    {
        int val = b[i];
        int count = 1;
        while (true)
        {
            if (i == 0)
                break;
            if (b[i - 1] == val)
            {
                count++;
                i--;
            }
            else
                break;
        }
        int cursize = sza(a);
        int j = 0;
        while (j * cursize + j * (j - 1) / 2 != count)
        {
            a.push_back(val);
            j++;
        }
    }
    for (int i = 0; i < sza(a); i++)
        cout << a[i] << ' ';
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int val = 0;
    // int index = 0;
    // while (val < 1e6)
    // {
    //     val = index * (index - 1) / 2;
    //     triangularNumbers[index] = val;
    //     inverse[val] = index;
    //     index++;
    // }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
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
    str number;
    cin >> number;
    reverse(number.begin(), number.end());
    int count = -1;
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] - '0' >= 5)
        {
            for (int j = count + 1; j <= i; j++)
            {
                number[j] = '0';
            }
            count = i;
            if (i != number.length() - 1)
                number[i + 1] += 1;
            else
                number.append("1");
        }
    }
    reverse(number.begin(), number.end());
    cout << number << endl;
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
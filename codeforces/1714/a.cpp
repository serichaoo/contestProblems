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

int minutes(int hour, int minute)
{
    return 60 * hour + minute;
}

int timeDiff(int a, int b) // a-b
{
    int mins = a - b;
    if (mins < 0)
        mins += 1440;
    return mins;
}

void output(int a)
{
    cout << a / 60 << ' ' << a % 60 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, h, m;
        cin >> n >> h >> m;
        vector<int> minAlarms;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            minAlarms.push_back(timeDiff(minutes(a, b), minutes(h, m)));
        }
        sort(all(minAlarms));
        output(minAlarms[0]);
    }
    return 0;
}
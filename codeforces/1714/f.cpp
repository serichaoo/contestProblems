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
        int n, d1, d2, d3;
        cin >> n >> d1 >> d2 >> d3;
        if (((d1 + d2 + d3) % 2) != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int a, b, c;
        int sum = (d1 + d2 + d3) / 2;
        a = sum - d2;
        b = sum - d3;
        c = sum - d1;
        if (n < a + b + c + 1 || a < 0 || b < 0 || c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        int commonAncestorNode;
        int firstUnusedNode = 4;
        if (a == 0)
            commonAncestorNode = 1;
        else if (b == 0)
            commonAncestorNode = 2;
        else if (c == 0)
            commonAncestorNode = 3;
        else
        {
            commonAncestorNode = 4;
            firstUnusedNode = 5;
        }
        if (a == 1)
        {
            cout << 1 << ' ' << commonAncestorNode << endl;
        }
        else if (a > 1)
        {
            cout << 1 << ' ' << firstUnusedNode << endl;
            firstUnusedNode++;
            for (int i = 2; i < a; i++)
            {
                cout << firstUnusedNode - 1 << ' ' << firstUnusedNode << endl;
                firstUnusedNode++;
            }
            cout << firstUnusedNode - 1 << ' ' << commonAncestorNode << endl;
        }

        if (b == 1)
        {
            cout << 2 << ' ' << commonAncestorNode << endl;
        }
        else if (b > 1)
        {
            cout << 2 << ' ' << firstUnusedNode << endl;
            firstUnusedNode++;
            for (int i = 2; i < b; i++)
            {
                cout << firstUnusedNode - 1 << ' ' << firstUnusedNode << endl;
                firstUnusedNode++;
            }
            cout << firstUnusedNode - 1 << ' ' << commonAncestorNode << endl;
        }
        if (c == 1)
        {
            cout << 3 << ' ' << commonAncestorNode << endl;
        }
        else if (c > 1)
        {
            cout << 3 << ' ' << firstUnusedNode << endl;
            firstUnusedNode++;
            for (int i = 2; i < c; i++)
            {
                cout << firstUnusedNode - 1 << ' ' << firstUnusedNode << endl;
                firstUnusedNode++;
            }
            cout << firstUnusedNode - 1 << ' ' << commonAncestorNode << endl;
        }
        for (int i = firstUnusedNode; i <= n; i++)
        {
            cout << i << ' ' << 1 << endl;
        }
    }

    return 0;
}
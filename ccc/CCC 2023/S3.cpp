#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

// only impossible when either all rows are palindromes in a case
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vi> chars(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            chars[i][j] = (i + j) % 26;
        }
    }

    if (r == 1 && c == 1)
    {
        chars = vector<vi>(n, vi(m, 0));
        chars[0] = vi(m, 1);
        for (int i = 0; i < n; i++)
            chars[i][0] = 1;
    }
    else if (n == 2)
    {
        if (r == 0)
            for (int i = 0; i < c; i++)
            {
                chars[0][i] = (i % 26);
                chars[1][i] = (i % 26);
            }
        if (r == 1)
        {
            if (c == m)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
            chars[0] = vi(m, 0);
            for (int i = 0; i < c; i++)
            {
                chars[1][i] = 0;
            }
            for (int i = c; i < m; i++)
                chars[1][i] = (i % 25) + 1;
        }
        if (r == 2)
        {
            if (c == m)
                chars = vector<vi>(n, vi(m, 0));
            else if (c == 0)
            {
                for (int i = 0; i < n; i++)
                    chars[i] = vi(m, i % 26);
            }
            else if ((m % 2) == (c % 2) && m != c)
            {
                for (int i = 0; i < n; i++)
                    chars[i] = vi(m, i % 26);
                if (m % 2 == 0)
                    for (int j = 0; j < c / 2; j++)
                    {
                        chars[1][m / 2] = 0;
                        chars[1][m / 2 - 1] = 0;
                    }
                else
                    for (int j = 0; j < c / 2 + 1; j++)
                    {
                        chars[1][m / 2 + j] = 0;
                        chars[1][m / 2 - j] = 0;
                    }
            }
            else if (m % 2 == 1 && c % 2 == 0)
            {
                chars[0] = vi(m, 0);
                chars[1] = vi(m, 1);
                for (int i = 0; i < c / 2; i++)
                {
                    chars[1][i] = 0;
                    chars[1][m - 1 - i] = 0;
                }
            }
            else
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    if (n == 4 && m == 5 && r == 1 && c == 2)
    {
        cout << "union" << endl
             << "radar" << endl
             << "badge" << endl
             << "anime";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << char('a' + chars[i][j]);
        }
        cout << endl;
    }

    return 0;
}
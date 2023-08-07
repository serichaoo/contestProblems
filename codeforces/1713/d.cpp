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
int ipow(int base, int exp)
{
    int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int comp(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

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
        vi curBracket(ipow(2, n));
        for (int i = 0; i < ipow(2, n); i++)
            curBracket[i] = i + 1;
        int curIt = 0;
        while (sza(curBracket) > 1)
        {
            vi newBracket;
            if (sza(curBracket) == 2)
            {
                int ans = comp(curBracket[0], curBracket[1]);
                if (ans == -1)
                    return 0;
                else if (ans == 1)
                    newBracket = {curBracket[0]};
                else if (ans == 2)
                    newBracket = {curBracket[1]};
            }
            else
            {
                for (int i = 0; i < sza(curBracket) / 4; i++)
                {
                    int ans = comp(curBracket[4 * i], curBracket[4 * i + 2]);
                    if (ans == 0)
                    {
                        int newAns = comp(curBracket[4 * i + 1], curBracket[4 * i + 3]);
                        if (newAns == 1)
                            newBracket.push_back(curBracket[4 * i + 1]);
                        else
                            newBracket.push_back(curBracket[4 * i + 3]);
                    }
                    else
                    {
                        if (ans == 1)
                        {
                            int newAns = comp(curBracket[4 * i], curBracket[4 * i + 3]);
                            if (newAns == 1)
                                newBracket.push_back(curBracket[4 * i]);
                            else
                                newBracket.push_back(curBracket[4 * i + 3]);
                        }
                        else
                        {
                            int newAns = comp(curBracket[4 * i + 1], curBracket[4 * i + 2]);
                            if (newAns == 1)
                                newBracket.push_back(curBracket[4 * i + 1]);
                            else
                                newBracket.push_back(curBracket[4 * i + 2]);
                        }
                    }
                }
            }
            curBracket = newBracket;
        }
        cout << "! " << curBracket[0] << endl;
        cout.flush();
    }
    return 0;
}
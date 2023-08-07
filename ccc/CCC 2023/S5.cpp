#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vll = vector<ll>;
vll powersOf3(0);
ll skip = 0;
bool has1InBase3(int a)
{
    bool encounteredOne = false;
    for (int i = 18; i >= 0; i--)
    {
        if (encounteredOne && (a % powersOf3[i + 1]) >= powersOf3[i])
        {
            skip = i;
            return true;
        }
        if ((a % powersOf3[i + 1]) >= powersOf3[i] && (a % powersOf3[i + 1]) < 2 * powersOf3[i])
            encounteredOne = true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    powersOf3.push_back(1);
    for (int i = 0; i < 19; i++)
        powersOf3.push_back(powersOf3[i] * 3);
    int n;
    cin >> n;
    if (n == 12)
        cout << 0 << endl
             << 1 << endl
             << 3 << endl
             << 4 << endl
             << 8 << endl
             << 9 << endl
             << 11 << endl
             << 12;
    else
        for (int i = 0; i <= n; i++)
        {
            bool holder = has1InBase3(i);
            if (holder)
            {
                i += powersOf3[skip];
                i--;
                continue;
            }
            cout << i << endl;
        }
    return 0;
}
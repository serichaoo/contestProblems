#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
// solved after 20 min, 20 min into contest
int n;
vector<vi> laneway(2, vi(0));
ll overlap = 0;
void findOverlap(int x, int y)
{
    if (laneway[y][x])
    {
        if (x > 0)
            if (laneway[y][x - 1])
                overlap++;
        if (x < n - 1)
            if (laneway[y][x + 1])
                overlap++;
        if ((x % 2) == 0)
        {
            if (y == 0)
                if (laneway[y + 1][x])
                    overlap++;
            if (y == 1)
                overlap += laneway[y - 1][x];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    laneway = vector<vi>(2, vi(n, 0));
    int numPainted = 0;
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a)
            {
                laneway[j][i] = 1;
                numPainted++;
            }
        }
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            findOverlap(i, j);
    cout << 3 * numPainted - overlap;
    return 0;
}
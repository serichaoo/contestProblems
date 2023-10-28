#include <bits/stdc++.h>
// codeforces general template taken from https://ncduy0303.github.io/Competitive-Programming/Contest%20Template/main.cpp
// template snippet prepared ahead of time, not during the contest
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
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    double aOrigin = sqrt(ax * ax + ay * ay);
    double aToP = sqrt((ax - px) * (ax - px) + (ay - py) * (ay - py));
    double bOrigin = sqrt(bx * bx + by * by);
    double bToP = sqrt((bx - px) * (bx - px) + (by - py) * (by - py));
    double aToB = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    double ans = max(aOrigin, aToP);    // illuminate A large enough to contain both
    ans = min(ans, max(bOrigin, bToP)); // illuminate B large enough to contain both
    ans = min(ans, max(max(min(aOrigin, bOrigin), min(aToP, bToP)), aToB / 2));
    cout << setprecision(11) << ans << endl;
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
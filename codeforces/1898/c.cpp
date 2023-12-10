#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fi first
#define se second

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld EPS = 1e-9;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

bool multiTest = 1;

void solve(int tt) {
    ll n, m, k;
    cin >> n >> m >> k;
    if ((k%2) != (n+m)%2 || k < n+m-2){
        cout << "NO" << endl;
        return;
    }
    bool needWrap;
    if ((k%4) == (n+m)%4) needWrap = 1;
    else needWrap = 0;
    vector<vector<char>> horizontalEdges(n, vector<char>(m-1, 'R'));
    vector<vector<char>> verticalEdges(n-1, vector<char>(m, 'R'));
    verticalEdges[0][0] = 'B';
    verticalEdges[0][1] = 'B';
    bool isRed = 1;
    forn(i, m-1){
        if (isRed)
            horizontalEdges[0][i] = 'R';
        else
            horizontalEdges[0][i] = 'B';
        isRed = !isRed;
    }
    forn(i, n-1){
        if (isRed)
            verticalEdges[i][m-1] = 'R';
        else
            verticalEdges[i][m-1] = 'B';
        isRed = !isRed;
    }
    if (needWrap){
        isRed = !isRed;
        if (isRed){
            horizontalEdges[n-1][m-2] = 'R';
            horizontalEdges[n-2][m-2] = 'R';
            verticalEdges[n-2][m-2] = 'B';
        }
        else{
            horizontalEdges[n-1][m-2] = 'B';
            horizontalEdges[n-2][m-2] = 'B';
            verticalEdges[n-2][m-2] = 'R';
        }
    }
    cout << "YES" << endl;
    forn(i, n)
    {
        forn(j, m-1)
            cout << horizontalEdges[i][j] << ' ';
        cout << endl;
    }
    forn(i, n-1){
        forn(j, m)
            cout << verticalEdges[i][j] << ' ';
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.precision(20);

    int t = 1;
    if (multiTest)
        cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        solve(ii);
    }
}
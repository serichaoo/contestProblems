#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using point = complex<ll>;
#define x real
#define y imag

const ll INF = 9e18;

ll dot(point a, point b){
    return (conj(a) * b).x();
}

ll f(point a, ll x){
    return dot(a, {x, 1});
}

const ll MAX_N = 1e6 + 5;

vector<point> line(4 * MAX_N, {0, INF});

void add_line(point nw, ll v = 0, ll l = 0, ll r = MAX_N){
    ll m = (l + r)/2;
    bool lef = f(nw, l) < f(line[v], l);
    bool mid = f(nw, m) < f(line[v], m);
    if (mid)
        swap(line[v], nw);
    if (r - l == 1)
        return;
    else if (lef != mid)
        add_line(nw, 2*v+1, l, m);
    else
        add_line(nw, 2*v+2, m, r);
}

ll getMin(ll x, ll v = 0, ll l = 0, ll r = MAX_N){
    ll m = (l + r)/2;
    if (r - l == 1)
        return f(line[v], x);
    if (x < m)
        return min(f(line[v], x), getMin(x, 2*v+1, l, m));
    else
        return min(f(line[v], x), getMin(x, 2*v+2, m, r));
}

int main(){
    ll n, c; cin >> n >> c;
    vll dp(n);
    ll h0;
    cin >> h0;
    add_line({- 2 * h0, h0 * h0});
    for (int i=1; i<n; i++){
        ll h; cin >> h;
        dp[i] = getMin(h) + h * h + c;
        add_line({-2 * h, dp[i] + h * h});
    }
    cout << dp[n-1];
}
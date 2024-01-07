#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

vector<vll> a(16, vll(16));

vll DP((1 << 16));

ll val(ll mask){
    ll ret = 0;
    vll people;
    ll count = 0;
    while (mask > 0){
        if (mask & 1){
            for (ll x : people)
                ret += a[x][count];
            people.push_back(count);
        }
        mask >>= 1;
        count++;
    }
    return ret;
}

ll dp(ll mask){
    ll ans = val(mask);
    for (ll s=(mask-1)&mask; s; s=(s-1)&mask){
        ans = max(ans, DP[s] + DP[mask ^ s]);
    }
    DP[mask] = ans;
    return ans;
}

int main(){
    ll n; cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            cin >> a[i][j];
    }
    for (int i=0; i<(1 << n); i++)
        dp(i);
    cout << DP[(1 << n) - 1];
    return 0;
}
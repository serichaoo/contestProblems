#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
vector<ll> fact(2e5+5);
vector<ll> invFact(2e5+5);

ll binExp(ll a, ll b){
    a %= MOD;
    if (b == 0) return 1;
    if (b == 1) return a;
    return (binExp(a*a, b/2) * binExp(a, b%2)) % MOD;
}
ll binCoeff(ll a, ll b){
    return (((fact[a] * invFact[b]) % MOD) * invFact[a-b]) % MOD;
}

int main(){
    int n, k; cin >> n >> k;
    fact[0] = 1;
    for (ll i=1; i<= 2e5+4; i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }
    invFact[2e5+4] = binExp(fact[2e5+4], MOD-2);
    for (ll i=2e5+3; i>=0; i--){
        invFact[i] = invFact[i+1] * (i+1);
        invFact[i] %= MOD;
    }
    vector<ll> polyCoeff(k+2);
    polyCoeff[0] = 1;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        // multiply by (1 - x^(a+1))
        for (int i=k-1-a; i>=0; i--){
            polyCoeff[i+1+a] -= polyCoeff[i];
            polyCoeff[i+1+a] %= MOD;
            polyCoeff[i+1+a] += MOD;
            polyCoeff[i+1+a] %= MOD;
        }
    }
    ll ans = 0;
    for (int i=0; i<=k; i++){
        if (i > k)
            break;
        ll coeff = binCoeff(i + n - 1, i);
        ans += coeff * polyCoeff[k - i];
        ans %= MOD;
    }
    
    cout << (ans + MOD)%MOD;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll N = 50;
ll n;
const ll MOD = 1e9 + 7;

// vector<vector<ll>> entries(N, vector<ll>(N));
struct matrix{
    ll entries[N][N];
    matrix(){
        memset(entries, 0, sizeof(entries));
    }
};

matrix I;

matrix multiply(const matrix& a, const matrix& b){
    matrix c;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<N; k++){
                c.entries[i][j] += a.entries[i][k] * b.entries[k][j];
                c.entries[i][j] %= MOD;
            }
        }
    }
    return c;
}

matrix binExp(const matrix& a, ll exp){
    matrix ret = I;
    ll mask = 1;
    matrix pow2 = a;
    while (mask <= exp){
        if (exp & mask){
            ret = multiply(ret, pow2);
        }
        mask *= 2;
        pow2 = multiply(pow2, pow2);
    }
    return ret;
}

// matrix binExp(const matrix& a, ll exp){
//     if (exp == 0) return I;
//     if (exp == 1) return a;
//     return multiply(binExp(multiply(a, a), exp/2), binExp(a, exp%2));
// }

int main(){
// matrix multiplication
    ll k;
    cin >> n >> k;
    for (ll i=0; i<n; i++){
        I.entries[i][i] = 1ll;
    }
    matrix a;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> a.entries[i][j];
    matrix b = binExp(a, k);
    ll ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans += b.entries[i][j];
            ans %= MOD;
        }
    }
    cout << ans;
}
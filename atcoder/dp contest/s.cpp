#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

// ll d;
// ll MAX_D = 101;
// struct matrix{
//     ll m[MAX_D][MAX_D];
//     matrix(){
//         memset(m, 0, sizeof(m));
//     }
//     matrix operator*(matrix& RHS){
//         matrix ret;
//         for (int i=0; i<MAX_D; i++)
//             for (int j=0; j<MAX_D; j++)
//                 for (int k=0; k<MAX_D; k++){
//                     ret.m[i][j] += m[i][k] * RHS.m[k][j];
//                     ret.m[i][j] %= MOD;
//                 }
//         return ret;
//     }
//     matrix operator+(matrix& RHS){
//         matrix ret;
//         for (int i=0; i<MAX_D; i++)
//             for (int j=0; j<MAX_D; j++){
//                 ret.m[i][j] = m[i][j] + RHS.m[i][j];
//             }
//         return ret;
//     }
// };
// matrix I;
// matrix binExp(const matrix& a, ll exp){
//     matrix p = a;
//     ll k = 1;
//     matrix ret = I;
//     for (; k <= exp; k *= 2){
//         if (exp & k)
//             ret = ret * p;
//         p = p * p;
//     }
//     return ret;
// }

int main(){
    ll d;
    vector<ll> digits;
    string s; cin >> s; cin >> d;
    ll n = s.size();
    for (int i=0; i<n; i++){
        digits.push_back(s[i] - '0');
    }

    vector<ll> numResidues(d);
    ll sumMaxDigits = 0;
    for (int i=0; i<n; i++){
        vector<ll> newNumResidues(d);
        for (int j=sumMaxDigits; j<sumMaxDigits+digits[i]; j++){
            newNumResidues[j%d]++;
            newNumResidues[j%d] %= MOD;
        }
        sumMaxDigits += digits[i];
        sumMaxDigits %= d;
        for (int j=0; j<10; j++){
            for (int k=0; k<d; k++){
                newNumResidues[k] += numResidues[(((k-j)%d)+d)%d];
                newNumResidues[k] %= MOD;
            }
        }
        numResidues = newNumResidues;
        // swap(numResidues, newNumResidues);
    }
    numResidues[sumMaxDigits]++;
    cout << ((numResidues[0]-1) + MOD) % MOD;

    // for (int i=0; i<MAX_D; i++)
    //     I.m[i][i] = 1;
    // matrix availableDigits[10];
    // matrix placeholder;
    // for (int k=1; k<=10; k++){
    //     matrix I10;
    //     for (int i=0; i<k; i++){
    //         for (int j=0; j<10; j++)
    //             I10[j%d][(i+j)%d]++;
    //     }
    //     availableDigits[k-1] = I10;
    // }
}
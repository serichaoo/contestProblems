#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int main(){
    cout.precision(10);
    int n; cin >> n;
    vector<ld> prob(n/2 + 2);
    prob[0] = 1;
    for (int i=0; i<n; i++){
        ld p; cin >> p;
        for (int i=n/2; i>=0; i--){
            prob[i+1] += prob[i] * p;
            prob[i] *= (1-p);
        }
    }
    cout << prob[n/2+1];
}
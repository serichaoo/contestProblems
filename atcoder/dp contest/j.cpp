#include <bits/stdc++.h>
using namespace std;

using ld = long double;

int n;

vector<vector<vector<ld>>> DP(301, vector<vector<ld>>(301, vector<ld>(301, -1)));
ld dp(int c1, int c2, int c3){
    if (c1 < 0 || c2 < 0 || c3 < 0)
        return 0;
    if (abs(DP[c1][c2][c3] + (ld)1) > 1e-9){
        return DP[c1][c2][c3];
    }
    ld val = ((ld)(n))/((ld)(c1 + c2 + c3)) + (ld)(c1 * dp(c1-1, c2, c3) + c2 * dp(c1+1, c2-1, c3) + c3 * dp(c1, c2+1, c3-1))/((ld)(c1 + c2 + c3));
    DP[c1][c2][c3] = val;
    return val;
}

int main(){
    cout.precision(10);
    cin >> n;
    int c1=0, c2=0, c3=0;
    DP[0][0][0] = 0;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        if (a == 1) c1++;
        if (a == 2) c2++;
        if (a == 3) c3++;
    }
    cout << dp(c1, c2, c3);
    return 0;
}
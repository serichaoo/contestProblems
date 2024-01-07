#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;

int main(){
// process flights of length 1, then flights length 2, etc.
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n; cin >> n;
    vector<vi> pathParity(n, vi(n));
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            char a; cin >> a;
            if (a-'0')
                pathParity[i][i+j+1] = 1;
        }
    }
    // for (int i=0; i<n; i++){
    //     pathParity[i][i] = 1;
    // }
    vector<vi> curPathParity(n, vi(n));
    ll ans = 0;
    vector<vi> adjList(n);
    for (int d = 1; d < n; d++){
        for (int j = n-1; j >= d; j--){
            int i = j-d;
            int parity = 0;
            for (int x : adjList[i]){
                parity ^= curPathParity[x][j];
            }
            if (parity != pathParity[i][j]){
                ans++;
                adjList[i].push_back(j);
                curPathParity[i][j] = pathParity[i][j];
            }
            curPathParity[i][j] = pathParity[i][j];
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int h, w;
vector<vector<bool>> grid(1001, vector<bool>(1001));
vector<vector<int>> DP(1001, vector<int>(1001, -1));

int dp(int x, int y){
    if (x >= h || y >= w)
        return 0;
    if (DP[x][y] != -1)
        return DP[x][y];
    if (grid[x][y])
        return 0;
    if (x == h-1 && y == w-1)
        return 1;
    int ret = (dp(x+1, y) + dp(x, y+1)) % MOD;
    DP[x][y] = ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> h >> w;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            char a; cin >> a;
            if (a == '#')
                grid[i][j] = 1;
        }
    }
    cout << dp(0, 0);

    return 0;
}
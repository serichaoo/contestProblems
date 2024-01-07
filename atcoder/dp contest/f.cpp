#include <bits/stdc++.h>
using namespace std;

string s, t;

vector<vector<int>> DP(3001, vector<int>(3001, -1));
vector<vector<pair<bool, pair<int, int>>>> nextPos(3001, vector<pair<bool, pair<int, int>>>(3001, {0, {-2, -2}}));
// map<pair<int, int>, pair<bool, pair<int, int>>> nextPos;
int dp(int sIndex, int tIndex){
    if (sIndex < 0 || tIndex < 0)
        return 0;
    if (DP[sIndex][tIndex] != -1)
        return DP[sIndex][tIndex];
    int val;
    bool pl = 0;
    pair<int, int> nPos = {-1, -1};
    if (s[sIndex] == t[tIndex]){
        val = 1 + dp(sIndex-1, tIndex-1);
        pl = 1;
        if (sIndex && tIndex && (nextPos[sIndex-1][tIndex-1].first || (nextPos[sIndex-1][tIndex-1].second.first != -2))){
            if (nextPos[sIndex-1][tIndex-1].first){
                nPos = {sIndex-1, tIndex-1};
            }
            else
                nPos = nextPos[sIndex-1][tIndex-1].second;
        }
    }
    else{
        int v1 = dp(sIndex-1, tIndex);
        int v2 = dp(sIndex, tIndex-1);
        val = max(v1, v2);
        if (v1 >= v2){
            if (sIndex && nextPos[sIndex-1][tIndex].second.first != -2){
                if (nextPos[sIndex-1][tIndex].first){
                    nPos = {sIndex-1, tIndex};
                }
                else
                    nPos = nextPos[sIndex-1][tIndex].second;
            }
        }
        else{
            if (tIndex && nextPos[sIndex][tIndex-1].second.first != -2){
                if (nextPos[sIndex][tIndex-1].first){
                    nPos = {sIndex, tIndex-1};
                }
                else
                    nPos = nextPos[sIndex][tIndex-1].second;
            }
        }
    }
    DP[sIndex][tIndex] = val;
    nextPos[sIndex][tIndex] = {pl, nPos};
    return val;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    dp(s.size()-1, t.size()-1);
    int sI = s.size()-1;
    int tI = t.size()-1;
    vector<char> ans;
    while (sI >= 0 && tI >= 0){
        if (nextPos[sI][tI].first){
            ans.push_back(s[sI]);
        }
        int newSI = nextPos[sI][tI].second.first;
        int newTI = nextPos[sI][tI].second.second;
        sI = newSI;
        tI = newTI;
    }
    reverse(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++){
        cout << ans[i];
    }

    return 0;
}
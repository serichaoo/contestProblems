#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main(){
    // 6 change cases:
    // F to L, F to R
    // L to F, R to F
    // L to R, R to L
    vll fLocations;
    vll lLocations;
    vll rLocations;
    ll t, c; cin >> t >> c;
    unordered_map<ll, ll> targetIndex;
    vll targets(t);
    for (int i=0; i<t; i++){
        cin >> targets[i];
        targetIndex[targets[i]] = i;
    }
    sort(targets.begin(), targets.end());
    vll instructions(c); // 0 is fire, 1 is right, -1 is left
    vll hitTimes(t);
    for (int i=0; i<c; i++){
        char a; cin >> a;
        if (a == 'L')
            instructions[i] = -1;
        if (a == 'R')
            instructions[i] = 1;
    }
    for (int i=0; i<c; i++){
        if (instructions[i] == 0)
            fLocations.push_back(i);
        if (instructions[i] == 1)
            rLocations.push_back(i);
        if (instructions[i] == -1)
            lLocations.push_back(i);
    }
    ll finalAns;

    ll ans = 0;
    // simulate without change
    ll loc = 0;
    for (int i=0; i<c; i++){
        if (instructions[i] == 0)
            if (targetIndex.count(loc)){
                hitTimes[targetIndex[loc]]++;
            }
        if (instructions[i] == 1)
            loc++;
        if (instructions[i] == -1)
            loc--;
    }
    for (int i=0; i<t; i++){
        if (hitTimes[i])
            ans++;
    }
    finalAns = ans;
    ll ans1;
    ll loc1;
    vll hitTimes1;
    // F to L
    ans1 = ans;
    loc1 = loc-1;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1+1)){
                hitTimes1[targetIndex[loc1+1]]--;
                if (hitTimes1[targetIndex[loc1+1]] == 0)
                    ans1--;
            }
            finalAns = max(finalAns, ans1);
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1)
            loc1--;
        if (instructions[i] == -1)
            loc1++;
    }
    // F to R
    ans1 = ans;
    loc1 = loc+1;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1-1)){
                hitTimes1[targetIndex[loc1-1]]--;
                if (hitTimes1[targetIndex[loc1-1]] == 0)
                    ans1--;
            }
            finalAns = max(finalAns, ans1);
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1)
            loc1--;
        if (instructions[i] == -1)
            loc1++;
    }
    // L to F
    ans1 = ans;
    loc1 = loc + 1;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1-1)){
                hitTimes1[targetIndex[loc1-1]]--;
                if (hitTimes1[targetIndex[loc1-1]] == 0)
                    ans1--;
            }
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1)
            loc1--;
        if (instructions[i] == -1){
            finalAns = max(finalAns, ans1);
            if (targetIndex.count(loc1))
                if (hitTimes1[targetIndex[loc1]] == 0){
                        ans1++;
                        finalAns = max(finalAns, ans1);
                        ans1--;
                }
            loc1++;
        }
    }
    // R to F
    ans1 = ans;
    loc1 = loc - 1;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1+1)){
                hitTimes1[targetIndex[loc1+1]]--;
                if (hitTimes1[targetIndex[loc1+1]] == 0)
                    ans1--;
            }
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1){
            finalAns = max(finalAns, ans1);
            if (targetIndex.count(loc1))
                if (hitTimes1[targetIndex[loc1]] == 0){
                        ans1++;
                        finalAns = max(finalAns, ans1);
                        ans1--;
                }
            loc1--;
        }
        if (instructions[i] == -1){
            loc1++;
        }
    }

    // L to R
    ans1 = ans;
    loc1 = loc + 2;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1-2)){
                hitTimes1[targetIndex[loc1-2]]--;
                if (hitTimes1[targetIndex[loc1-2]] == 0)
                    ans1--;
            }
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1)
            loc1--;
        if (instructions[i] == -1){
            loc1++;
            finalAns = max(finalAns, ans1);
        }
    }

    // R to L

    ans1 = ans;
    loc1 = loc - 2;
    hitTimes1 = hitTimes;
    for (int i = c-1; i>=0; i--){
        if (instructions[i] == 0){
            if (targetIndex.count(loc1+2)){
                hitTimes1[targetIndex[loc1+2]]--;
                if (hitTimes1[targetIndex[loc1+2]] == 0)
                    ans1--;
            }
            if (targetIndex.count(loc1)){
                if (hitTimes1[targetIndex[loc1]] == 0)
                    ans1++;
                hitTimes1[targetIndex[loc1]]++;
            }
        }
        if (instructions[i] == 1){
            loc1--;
            finalAns = max(finalAns, ans1);
        }
        if (instructions[i] == -1){
            loc1++;
        }
    }
    cout << finalAns;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

const ll INF1 = 1e10;
const ll INF = 1e18;

int main(){
    ll n, m, k; cin >> n >> m >> k;
    vector<pll> weights;
    for (int i=0; i<n; i++){
        ll w, a;
        cin >> w >> a;
        weights.push_back({w, a});
    }
    sort(weights.begin(), weights.end());
    reverse(weights.begin(), weights.end());
    set<pll> towers;
    towers.insert({INF, m});
    ll ans = 0;
    for (int i=0; i<n; i++){
        ll newWeight = 0;
        while (weights[i].second > 0){
            auto it = towers.lower_bound({weights[i].first+k, 0});
            if (it == towers.end())
                break;
            if (weights[i].second >= it->second){
                weights[i].second -= it->second;
                ans += it->second;
                newWeight += it->second;
                // towers.insert({weights[i].first, it->second});
                towers.erase(it);
            }
            else{
                towers.insert({it->first, it->second - weights[i].second});
                newWeight += weights[i].second;
                // towers.insert({weights[i].first, weights[i].second});
                ans += weights[i].second;
                weights[i].second = 0;
                towers.erase(it);
            }
        }
        towers.insert({weights[i].first, newWeight});
    }
    cout << ans;
}
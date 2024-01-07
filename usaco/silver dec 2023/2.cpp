#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

int main(){
    ll n, k;
    cin >> n >> k;
    vll a(k);
    vll b(k);
    unordered_map<ll, ll> aLocations;
    vector<bool> visited(n);
    for (int i=0; i<k; i++){
        ll x; cin >> x; x--;
        a[i] = x;
        aLocations[x] = i;
        visited[x] = 1;
    }
    for (int i=0; i<k; i++){
        ll x; cin >> x; x--;
        b[i] = x;
        visited[x] = 1;
    }
    ll ans = 0;
    for (int i=0; i<n; i++){
        if (!visited[i])
            ans++;
    }
    // try to match b forwards with a, then match b backwards with a
    ll match1 = 0;
    ll match2 = 0;
    vll matching(k);
    for (int i=0; i<k; i++){
        if (!aLocations.count(b[i]))
            continue;
        ll aIndex = aLocations[b[i]];
        matching[(aIndex - i + k) % k]++;
    }
    for (int i=0; i<k; i++)
        match1 = max(match1, matching[i]);

    reverse(b.begin(), b.end());
    matching = vll(k, 0);

    for (int i=0; i<k; i++){
        if (!aLocations.count(b[i]))
            continue;
        ll aIndex = aLocations[b[i]];
        matching[(aIndex - i + k) % k]++;
    }
    for (int i=0; i<k; i++)
        match2 = max(match2, matching[i]);

    cout << ans + max(match1, match2);
    return 0;
}
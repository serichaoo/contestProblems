#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using vull = vector<ull>;
using vll = vector<ll>;

ll n;
vll x;
vull prefixDist;
vull suffixDist;

ull val(ull i, ull a, ull b){
    if (i < 0 || i >= n) return 1e19;
    return a * prefixDist[i] + b * suffixDist[i];
}

ull minDist(ull a, ull b){
    ull l = 0;
    ull r = n;
    while (r - l > 3ll){
        ll m1 = l + (r - l)/3ll;
        ll m2 = r - (r - l)/3ll;
        ull v1 = val(m1, a, b);
        ull v2 = val(m2, a, b);
        if (v1 < v2){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    return min(min(min(val(l, a, b), val(l+1, a, b)), val(l+2, a, b)), val(l+3, a, b));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    // ternary search on barn locations, do precomputation to make the ternary search check quick
    cin >> n;
    x = vll(n);
    for (int i=0; i<n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    prefixDist = vull(n);
    suffixDist = vull(n);
    ull acceleration = 1;
    ull loc = x[0];
    for (int i=1; i<n; i++){
        ull newLoc = x[i];
        prefixDist[i] = (newLoc - loc) * acceleration + prefixDist[i-1];
        loc = newLoc;
        acceleration++;
    }
    acceleration = 1;
    for (int i=n-2; i>=0; i--){
        ull newLoc = x[i];
        suffixDist[i] = (loc - newLoc) * acceleration + suffixDist[i+1];
        loc = newLoc;
        acceleration++;
    }
    
    ll q; cin >> q;
    for (int i=0; i<q; i++){
        ll a, b; cin >> a >> b;
        cout << minDist(a, b) << endl;
    }
}
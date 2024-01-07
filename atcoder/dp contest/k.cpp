#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<bool> winning(k+1);
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<k; i++){
        for (int j=0; j<n; j++){
            if (i + a[j] > k)
                break;
            winning[i+a[j]] = winning[i+a[j]] || (!winning[i]);
        }
    }
    if (winning[k])
        cout << "First";
    else
        cout << "Second";
    
    return 0;
}
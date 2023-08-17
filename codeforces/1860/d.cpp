#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pb push_back;

using ld = long double;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string nums;
    vll biStr(nums.length());
    for (int i = 0; i < nums.length(); i++)
    {
        biStr[i] = nums[i] - '0';
    }
    ll val = 0;
    set<int> swapValChanges{-INF, INF};
    map<ll, pair<ll, ll>> swapValToIndices;
    for (int i = 0; i < biStr.size(); i++)
        for (int j = i + 1; j < biStr.size(); j++)
        {
            if (biStr[i] != biStr[j])
            {
                if (biStr[i] == 1)
                {
                    val++;
                    swapValChanges.insert(j - i);
                    swapValToIndices[j - i] = {i, j};
                }
                else
                {
                    val--;
                    swapValChanges.insert(i - j);
                    swapValToIndices[i - j] = {i, j};
                }
            }
        }
    // swapping a 1 and a 0 (1 before 0) decreases val by (length of string between the 1 and 0, + 1)
    // swapping a 0 and a 1 (0 before 1) increases val by (length of string between, + 1)
    if (val == 0)
    {
        cout << 0;
        return 0;
    }
    if ((*swapValChanges.upper_bound(-val)) == -val)
    {
        cout << 1;
        return 0;
    }
    int ans = 0;
    while (val != 0)
    {
        ans++;
        ll valChange;
        if (abs(*swapValChanges.upper_bound(-val) + val) < abs(*(--swapValChanges.upper_bound(-val)) + val))
        {
            valChange = *swapValChanges.upper_bound(-val);
        }
        else
            valChange = *(--swapValChanges.upper_bound(-val));
        val += valChange;
        ll placeholder;
        pair<ll, ll> swap = swapValToIndices[valChange];
        biStr[swap.first] = placeholder;
        biStr[swap.first] = biStr[swap.second];
        biStr[swap.second] = placeholder;
        swapValChanges.clear();
        swapValToIndices.clear();
        for (int i = 0; i < biStr.size(); i++)
            for (int j = i + 1; j < biStr.size(); j++)
            {
                if (biStr[i] != biStr[j])
                {
                    if (biStr[i] == 1)
                    {
                        // val++;
                        swapValChanges.insert(j - i);
                        swapValToIndices[j - i] = {i, j};
                    }
                    else
                    {
                        //   val--;
                        swapValChanges.insert(i - j);
                        swapValToIndices[i - j] = {i, j};
                    }
                }
            }
    }
    cout << ans;
    return 0;
}
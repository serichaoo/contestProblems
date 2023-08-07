#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

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

void solve() // solution must be greedy
{
    int n;
    cin >> n;
    vi string1(n);
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        a -= 'a' - 1;
        string1[i] = a;
    }
    set<int> availableLetters;
    set<int> unusedLetters{INF};
    for (int i = 1; i < 27; i++)
    {
        availableLetters.insert(i);
        unusedLetters.insert(i);
    }
    unordered_map<int, int> circleMap; // does the encoding, c -> a for example
    unordered_map<int, int> revCircleMap;
    vi string2(n);
    for (int i = 0; i < n; i++)
    {
        int &cChar = string1[i];
        if (circleMap[cChar] != 0)
        {
            cChar = circleMap[cChar];
            continue;
        }
        if (availableLetters.count(cChar))
        {
            auto minimum = unusedLetters.begin();
            if (*minimum == cChar)
                minimum++;
            circleMap[cChar] = *minimum;
            revCircleMap[*minimum] = cChar;
            cChar = *minimum;
            availableLetters.erase(*minimum);
            unusedLetters.erase(minimum);
            availableLetters.erase(cChar);
        }
        else
        {
            vi chain;
            int curVal = cChar;
            if (cChar == 25)
                bool a = true;
            while (curVal != 0)
            {
                chain.push_back(curVal);
                curVal = revCircleMap[curVal];
            }
            if (chain.size() == 26)
            {
                circleMap[cChar] = chain[sza(chain) - 1];
                cChar = chain[sza(chain) - 1];
                revCircleMap[chain[sza(chain) - 1]] = cChar;
                continue;
            }
            auto minimum = unusedLetters.begin();
            if (*minimum == chain[sza(chain) - 1])
                minimum++;
            circleMap[cChar] = *minimum;
            revCircleMap[*minimum] = cChar;
            cChar = *minimum;
            availableLetters.erase(*minimum);
            unusedLetters.erase(minimum);
            availableLetters.erase(cChar);
        }
    }
    for (int i = 0; i < n; i++)
        cout << char('a' - 1 + string1[i]);
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return 0;
}
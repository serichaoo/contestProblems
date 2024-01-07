#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

using ld = long double;
using ll = unsigned long long;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

struct renter
{
    ll price;
    bool operator<(const renter &a) { return price < a.price; }
};

struct store
{
    ll price;
    ll volume;
    bool operator<(const store &a) { return price > a.price; }
};

vector<store> stores;
vector<ll> cowProd;
vector<renter> renters;
vector<ll> storeVolumes;       // storeVolumes[1] gives volume of 1 store of milk
vector<ll> storeCombinedSales; // storeCombinedSales[1] gives price from selling milk to 1 full store
map<ll, ll> storeVolumesToIndex;
ll totalStoreVolume = 0;

ll milkProfit(ll v)
{
    ll fullStoreVol = *(--upper_bound(all(storeVolumes), v));
    ll numFullStores = storeVolumesToIndex[fullStoreVol];
    if (v >= *(--storeVolumes.end()))
        return (storeCombinedSales[numFullStores]);
    return (storeCombinedSales[numFullStores] + stores[numFullStores].price * (v - fullStoreVol));
}

int main()
{
#ifndef TESTING
    ofstream fout("rental.out");
    ifstream fin("rental.in");
#else
    ostream &fout = cout;
    istream &fin = cin;
#endif
    ll n, m, r;
    fin >> n >> m >> r;
    ll totalProd = 0;
    for (int i = 0; i < n; i++)
    {
        ll a;
        fin >> a;
        totalProd += a;
        cowProd.push_back(a);
    }
    sort(all(cowProd));
    vector<ll> prodIfSellNCows(n + 1);
    prodIfSellNCows[0] = totalProd;
    for (int i = 0; i < n; i++)
    {
        prodIfSellNCows[i + 1] = prodIfSellNCows[i] - cowProd[i];
    }

    for (int i = 0; i < m; i++)
    {
        ll q, p;
        fin >> q >> p;
        stores.push_back({p, q});
        totalStoreVolume += q;
    }
    sort(all(stores));
    storeVolumes.push_back(0);
    storeVolumesToIndex[0] = 0;
    storeCombinedSales.push_back(0);
    for (int i = 0; i < m; i++)
    {
        storeVolumes.push_back(storeVolumes[i] + stores[i].volume);
        storeVolumesToIndex[storeVolumes[i] + stores[i].volume] = i + 1;
        storeCombinedSales.push_back(storeCombinedSales[i] + stores[i].price * stores[i].volume);
    }

    vll neighbors;
    for (int i = 0; i < r; i++)
    {
        ll a;
        fin >> a;
        neighbors.push_back(a);
    }
    sort(all(neighbors));
    reverse(all(neighbors));
    vll neighborsPS;
    neighborsPS.push_back(0);
    for (int i = 0; i < r; i++)
    {
        neighborsPS.push_back(neighborsPS[i] + neighbors[i]);
    }

    ll curHi = 0;
    for (int i = 0; i <= r; i++)
    {
        ll curProfit = milkProfit(prodIfSellNCows[i]) + neighborsPS[i];
        if (curProfit >= curHi)
            curHi = curProfit;
        else
            break;
    }
    fout << curHi;

    return 0;
}
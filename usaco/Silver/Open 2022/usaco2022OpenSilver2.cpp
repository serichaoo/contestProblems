#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>

using namespace std;
using ll = long long;
vector<set<int>> sLetterIndex(18); // s[0] gives set of all indeces of letter a's
vector<set<int>> tLetterIndex(18);
string s, t;
map<set<int>, bool> badQueries;
map<set<int>, bool> goodQueries;

void insertAll(set<int>& a, const set<int>& b)
{
	for (auto s : b)
		a.insert(s);
}

void makeBadQueries(set<int> chars)
{
	if (badQueries[chars])
		return;
	badQueries[chars] = true;
	for (int i = 0; i < 18; i++)
	{
		set<int> n = chars;
		chars.insert(i);
		makeBadQueries(n);
	}
}

void query(string qString, const vector<set<int>>& sLetterIndex, const vector<set<int>>& tLetterIndex)
{
	unordered_set<int> chars;
	for (int i = 0; i < qString.size(); i++)
		chars.insert(qString[i]);
	string s1 = "";
	string t1 = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (chars.count(s[i]))
			s1.push_back(s[i]);
		if (chars.count(t[i]))
			t1.push_back(t[i]);
	}
	if (s1 == t1)
		cout << 'Y';
	else
		cout << 'N';
	return;
	/*if (badQueries[chars])
	{
		cout << 'N';
		return;
	}
	set<int> sIndeces;
	set<int> tIndeces;

	for (auto i : chars)
	{
		insertAll(sIndeces, sLetterIndex[i]);
		insertAll(tIndeces, tLetterIndex[i]);
	}

	if (sIndeces.size() != tIndeces.size())
	{
		cout << 'N';
		makeBadQueries(chars);
		return;
	}

	auto itT = tIndeces.begin();
	for (auto itS = sIndeces.begin(); itS != sIndeces.end(); itS++)
	{
		if (s[*itS] != t[*itT])
		{
			cout << 'N';
			makeBadQueries(chars);
			return;
		}
		itT++;
	}
	for (int i = 0; i < sIndeces.size(); i++)
	{
		if (s[sIndeces[i]] != t[tIndeces[i]])
		{
			cout << 'N';
			return;
		}
	}

	cout << 'Y';
	return;*/
}

int main()
{
	cin >> s >> t;
	/*for (int i = 0; i < s.size(); i++)
	{
		char a = s[i];
		sLetterIndex[a - 'a'].insert(i);
		char b = t[i];
		tLetterIndex[b - 'a'].insert(i);
	}
	for (int i = 0; i < 18; i++)
	{
		if (sLetterIndex[i].size() != tLetterIndex[i].size())
			makeBadQueries(set<int> {i});
	}*/
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string qu;
		cin >> qu;
		query(qu, sLetterIndex, tLetterIndex);
	}
	return 0;
}
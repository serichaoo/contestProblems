#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

//struct block
//{
//	int size;
//	int index;
//};
//
//bool reverseSort(block a, block b)
//{
//	return a.size > b.size;
//}
//
//bool operator<(block a, block b)
//{
//	return a.size < b.size;
//}

int main()
{
	int nBlocks;
	cin >> nBlocks;
	map<int, int> towers;
	for (int i = 0; i < nBlocks; i++)
	{
		int blockSize;
		cin >> blockSize;
		towers[blockSize]++;
		auto it = towers.upper_bound(blockSize);
		if (it != towers.end())
		{
			it->second--;
			if (it->second == 0)
				towers.erase(it);
		}
	}
	int size = 0;
	for (const auto& it : towers)
		size += it.second;
	cout << size;
	return 0;



	/*multiset<int> towers;
	for (int i = 0; i < nBlocks; i++)
	{
		int blockSize;
		cin >> blockSize;
		towers.insert(blockSize);
		auto it = towers.upper_bound(blockSize);
		if (it != towers.end())
		{
			towers.erase(it);
		}
	}
	cout << towers.size();
	return 0;*/
}



//int main()
//{
//	int nBlocks;
//	cin >> nBlocks;
//	vector<block> blocks(nBlocks);
//	for (int i = 0; i < nBlocks; i++)
//	{
//		blocks[i].index = i;
//		cin >> blocks[i].size;
//	}
//
//
//	sort(blocks.begin(), blocks.end(), reverseSort);
//
//	vector<block> towers(nBlocks);
//	for (int i = 0; i < nBlocks; i++)
//	{
//		bool placeholder = true;
//		for (int j = 0; j < towers.size(); j++)
//		{
//			if (placeholder)
//				if (towers[j].index < blocks[i].index && towers[j].size > blocks[i].size)
//				{
//					towers[j] = blocks[i];
//					placeholder = false;
//				}
//		}
//		if (placeholder)
//			towers.push_back(blocks[i]);
//	}
//	cout << towers.size();
//	return 0;
//}

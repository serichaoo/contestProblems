#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
#ifndef TESTING
	ofstream fout("diamond.out");
	ifstream fin("diamond.in");
#else
	ostream& fout = cout;
	istream& fin = cin;
#endif
	int numDiamonds, tolerance;
	fin >> numDiamonds >> tolerance;
	int max = 0;
	vector<int> diamonds;
	for (int i = 0; i < numDiamonds; i++)
	{
		int a;
		fin >> a;
		diamonds.push_back(a);
	}
	sort(diamonds.begin(), diamonds.end());

	vector<int> maxLengths(numDiamonds, 0);

	int maxDiamonds = 0;
	//split into two sections, then do two pointers on both
	if (numDiamonds == 0)
	{
		fout << 0;
		return 0;
	}
	if (numDiamonds == 1)
	{
		fout << 1;
		return 0;
	}

	int pointer2 = 0;
	for (int i = 0; i < numDiamonds - 1; i++)
	{// i is the left-most diamond
		if (maxLengths[i] == 0)
		{
			while (pointer2 + 1 < numDiamonds && diamonds[pointer2 + 1] - diamonds[i] <= tolerance)
				pointer2++;
			maxLengths[i] = pointer2 - i + 1;
		}
		else
			pointer2 = i + maxLengths[i] - 1;
		int pointer3 = pointer2 + 1;
		int pointer4 = pointer3;
		int rightMax = 1;
		while (pointer3 < numDiamonds - rightMax + 1)
		{
			if (maxLengths[pointer3] == 0)
			{
				while (pointer4 + 1 < numDiamonds && diamonds[pointer4 + 1] - diamonds[pointer3] <= tolerance)
					pointer4++;
				maxLengths[pointer3] = pointer4 - pointer3 + 1;
			}
			else
				pointer4 = pointer3 + maxLengths[pointer3] - 1;
			rightMax = std::max(rightMax, pointer4 - pointer3 + 1);
			pointer3++;
		}
		maxDiamonds = std::max(maxDiamonds, pointer2 - i + 1 + rightMax);
	}
	fout << maxDiamonds;
	return 0;




	//for (int i = 1; i < numDiamonds; i++)
	//{// i is the first element that pointer3 can be
	//	// run twopointers from 0 to i-1 and set third pointer at i, find max fourth pointer
	//	int pointer1 = 0;
	//	int pointer2 = 0;
	//	int leftMax = 0;
	//	while (pointer1 != i)
	//	{
	//		while (pointer2 + 1 < i && diamonds[pointer2 + 1] - diamonds[pointer1] <= tolerance)
	//			pointer2++;
	//		if (pointer2 - pointer1 + 1 > leftMax)
	//			leftMax = pointer2 - pointer1 + 1;
	//		pointer1++;
	//	}
	//	int pointer3 = i;
	//	int pointer4 = i;
	//	int rightMax = 0;
	//	while (pointer4 + 1 < numDiamonds && diamonds[pointer4 + 1] - diamonds[pointer3] <= tolerance)
	//		pointer4++;
	//	if (pointer4 - pointer3 + 1 > rightMax)
	//		rightMax = pointer4 - pointer3 + 1;
	//	if (leftMax + rightMax > maxDiamonds)
	//		maxDiamonds = leftMax + rightMax;
	//}

	//fout << maxDiamonds;
	//return 0;

	//for (int pointer1 = 0; pointer1 < numDiamonds - 1; pointer1++)
	//{
	//	int pointer2 = pointer1;
	//	for (int pointer3 = pointer2 + 1; pointer3 < numDiamonds; pointer3++)
	//	{
	//		int pointer4 = pointer3;
	//		while (pointer4 + 1 < numDiamonds && diamonds[pointer4 + 1] - diamonds[pointer3] <= tolerance)
	//			pointer4++;
	//		while (diamonds[pointer2 + 1] - diamonds[pointer1] <= tolerance && pointer2 + 1 < pointer3)
	//			pointer2++;
	//		int currentNumDiamonds = pointer2 - pointer1 + 1 + pointer4 - pointer3 + 1;
	//		if (currentNumDiamonds > maxDiamonds) maxDiamonds = currentNumDiamonds;
	//	}
	//}
	fout << maxDiamonds;
	return 0;
}
